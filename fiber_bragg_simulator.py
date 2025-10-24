#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
光纤光栅分析软件模拟器
根据通信协议发送CSV数据到监测系统
"""

import socket
import json
import time
import csv
import threading
import struct
from datetime import datetime
import sys

class FiberBraggSimulator:
    def __init__(self, host='192.168.3.90', tcp_port=5555, udp_port=6666):
        self.host = host
        self.tcp_port = tcp_port
        self.udp_port = udp_port
        self.tcp_socket = None
        self.udp_socket = None
        self.running = False
        self.heartbeat_thread = None
        self.data_thread = None
        
    def connect_tcp(self):
        """连接TCP服务端"""
        try:
            self.tcp_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.tcp_socket.connect((self.host, self.tcp_port))
            print(f"✅ TCP连接成功: {self.host}:{self.tcp_port}")
            return True
        except Exception as e:
            print(f"❌ TCP连接失败: {e}")
            return False
    
    def connect_udp(self):
        """连接UDP接收器"""
        try:
            self.udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
            print(f"✅ UDP连接准备完成: {self.host}:{self.udp_port}")
            return True
        except Exception as e:
            print(f"❌ UDP连接失败: {e}")
            return False
    
    def send_udp_start_command(self):
        """发送UDP启动命令"""
        try:
            # 启动命令: FFFFFFFFEEEEEEEE
            start_command = bytes.fromhex('FFFFFFFFEEEEEEEE')
            self.udp_socket.sendto(start_command, (self.host, self.udp_port))
            print("📡 发送UDP启动命令: FFFFFFFFEEEEEEEE")
        except Exception as e:
            print(f"❌ 发送UDP启动命令失败: {e}")
    
    def send_heartbeat(self):
        """发送TCP心跳包"""
        while self.running:
            try:
                if self.tcp_socket:
                    # 心跳包格式
                    heartbeat = {
                        "type": 1,
                        "sync": "heartbeat",
                        "body": {
                            "VER": "1.0",
                            "MSG": "HEARTBEAT",
                            "ERR": 0,
                            "PARAM": {}
                        }
                    }
                    message = json.dumps(heartbeat, ensure_ascii=False).encode('utf-8')
                    self.tcp_socket.send(message)
                    print("💓 发送心跳包")
            except Exception as e:
                print(f"❌ 发送心跳包失败: {e}")
                break
            time.sleep(30)  # 每30秒发送一次心跳
    
    def process_csv_data(self, csv_file):
        """处理CSV数据并发送"""
        try:
            with open(csv_file, 'r', encoding='utf-8') as file:
                reader = csv.reader(file)
                next(reader)  # 跳过标题行
                
                for row in reader:
                    if not self.running:
                        break
                    
                    if len(row) < 2:
                        continue
                    
                    timestamp = row[0].strip()
                    wavelengths = []
                    
                    # 解析波长数据（每3列为一组：波长,传感器名称,物理量）
                    for i in range(1, len(row), 3):
                        if i + 1 < len(row) and row[i].strip():
                            try:
                                wavelength = float(row[i])
                                wavelengths.append(wavelength)
                            except ValueError:
                                continue
                    
                    if wavelengths:
                        # 发送TCP数据
                        self.send_tcp_data(timestamp, wavelengths)
                        
                        # 发送UDP数据
                        self.send_udp_data(wavelengths)
                    
                    time.sleep(1)  # 每秒发送一次数据
                    
        except Exception as e:
            print(f"❌ 处理CSV数据失败: {e}")
    
    def calculate_strain_from_wavelength(self, wavelength, initial_wavelength=1537.2540):
        """根据波长计算应变值（微应变με）"""
        # 使用应变计算公式: 微应变(με) = ((NowWL - OriWL) - ((NowTempWL - OriTempWL)*Temp_a)/K2)*K1
        # 简化版本: 微应变(με) = (NowWL - OriWL) * K1
        # 调整K1系数，使应变值在合理范围内
        K1 = 3.0  # 降低应变系数，使应变值在50以内
        wavelength_change = wavelength - initial_wavelength
        strain = wavelength_change * K1
        
        # 确保应变值在合理范围内 (-50.00 到 50.00)
        strain = max(-50.00, min(50.00, strain))
        return strain
    
    def calculate_displacement_from_wavelength(self, wavelength, initial_wavelength=1537.2540):
        """根据波长计算位移值"""
        # 位移计算（简化）
        wavelength_change = wavelength - initial_wavelength
        displacement = wavelength_change * 1000  # 放大系数
        return displacement
    
    def calculate_temperature_from_wavelength(self, wavelength, initial_wavelength=1537.2540):
        """根据波长计算温度值"""
        # 温度计算（简化）
        wavelength_change = wavelength - initial_wavelength
        temperature = wavelength_change * 100  # 放大系数
        return temperature

    def send_tcp_data(self, timestamp, wavelengths):
        """发送TCP数据"""
        try:
            if not self.tcp_socket:
                return
            
            # 构建TCP数据包
            strain_data = []
            move_data = []
            temp_data = []
            wl_data = []
            
            # 根据波长值分类数据并计算物理量
            for i, wavelength in enumerate(wavelengths):
                ch_num = i + 1
                sensor_id = f"{ch_num:03d}01"
                sensor_name = f"传感器{ch_num}"
                
                # 计算物理量值
                strain_value = self.calculate_strain_from_wavelength(wavelength)
                displacement_value = self.calculate_displacement_from_wavelength(wavelength)
                temperature_value = self.calculate_temperature_from_wavelength(wavelength)
                
                # 将所有波长数据都作为应变数据处理
                strain_data.append({
                    "ChNum": ch_num,
                    "ID": sensor_id,
                    "Name": f"{sensor_name}_应变",
                    "Val": f"{strain_value:.2f}"  # 应变值，保留2位小数
                })
                
                # 可选：添加位移和温度数据（如果需要）
                # move_data.append({
                #     "ChNum": ch_num,
                #     "ID": sensor_id,
                #     "Name": f"{sensor_name}_位移",
                #     "Val": f"{displacement_value:.2f}"
                # })
                # temp_data.append({
                #     "ChNum": ch_num,
                #     "ID": sensor_id,
                #     "Name": f"{sensor_name}_温度",
                #     "Val": f"{temperature_value:.2f}"
                # })
                
                # 波长数据
                wl_data.append([ch_num, f"{wavelength:.6f}"])
            
            # 构建JSON数据包
            tcp_data = {
                "type": 0,
                "sync": f"sync header {timestamp}",
                "body": {
                    "VER": "1.0",
                    "MSG": "REALTIME",
                    "ERR": 0,
                    "PARAM": {
                        "Strain": strain_data,
                        "Move": move_data,
                        "Temp": temp_data,
                        "WLG": [],
                        "a": [],
                        "P": [],
                        "WL": wl_data
                    }
                }
            }
            
            message = json.dumps(tcp_data, ensure_ascii=False).encode('utf-8')
            self.tcp_socket.send(message)
            print(f"TCP数据发送: {timestamp} - {len(wavelengths)}个波长数据")
            if strain_data:
                print(f"   应变数据: {len(strain_data)}个传感器")
                # 显示前几个应变值
                for i, strain in enumerate(strain_data[:3]):
                    print(f"   传感器{strain['ChNum']}: {strain['Val']} με")
            if move_data:
                print(f"   位移数据: {len(move_data)}个传感器")
            if temp_data:
                print(f"   温度数据: {len(temp_data)}个传感器")
            
        except Exception as e:
            print(f"❌ 发送TCP数据失败: {e}")
    
    def send_udp_data(self, wavelengths):
        """发送UDP数据"""
        try:
            if not self.udp_socket:
                return
            
            # 构建UDP数据包
            # 包头(4字节) + 帧类型(1字节) + 传感器数据
            header = struct.pack('>I', 0x12345678)  # 包头
            frame_type = struct.pack('B', 0x01)     # 帧类型
            
            # 传感器数据（每个传感器40字节）
            sensor_data = b''
            for wavelength in wavelengths:
                # 每个传感器数据：波长(8字节) + 频率(8字节) + 其他数据(24字节)
                wavelength_bytes = struct.pack('>d', wavelength)
                frequency_bytes = struct.pack('>d', 1000.0 + wavelength * 0.1)  # 模拟频率
                other_data = b'\x00' * 24  # 其他数据填充
                sensor_data += wavelength_bytes + frequency_bytes + other_data
            
            udp_packet = header + frame_type + sensor_data
            self.udp_socket.sendto(udp_packet, (self.host, self.udp_port))
            print(f"📡 UDP数据发送: {len(wavelengths)}个传感器数据")
            
        except Exception as e:
            print(f"❌ 发送UDP数据失败: {e}")
    
    def start(self, csv_file):
        """启动模拟器"""
        print("🚀 启动光纤光栅分析软件模拟器")
        print(f"📁 数据文件: {csv_file}")
        print(f"🎯 目标地址: {self.host}:{self.tcp_port} (TCP), {self.host}:{self.udp_port} (UDP)")
        
        # 连接TCP
        if not self.connect_tcp():
            return False
        
        # 连接UDP
        if not self.connect_udp():
            return False
        
        # 发送UDP启动命令
        self.send_udp_start_command()
        
        # 启动心跳线程
        self.running = True
        self.heartbeat_thread = threading.Thread(target=self.send_heartbeat, daemon=True)
        self.heartbeat_thread.start()
        
        # 处理CSV数据
        try:
            self.process_csv_data(csv_file)
        except KeyboardInterrupt:
            print("\n⏹️ 用户中断，停止发送数据")
        except Exception as e:
            print(f"❌ 处理数据时出错: {e}")
        finally:
            self.stop()
    
    def stop(self):
        """停止模拟器"""
        print("🛑 停止光纤光栅分析软件模拟器")
        self.running = False
        
        if self.tcp_socket:
            self.tcp_socket.close()
            print("🔌 TCP连接已关闭")
        
        if self.udp_socket:
            self.udp_socket.close()
            print("🔌 UDP连接已关闭")

def main():
    """主函数"""
    print("=" * 60)
    print("🔬 光纤光栅分析软件模拟器")
    print("=" * 60)
    
    # 检查命令行参数
    if len(sys.argv) > 1:
        csv_file = sys.argv[1]
    else:
        csv_file = "CH8_Day_20250831114240.csv"
    
    # 检查CSV文件是否存在
    import os
    if not os.path.exists(csv_file):
        print(f"❌ CSV文件不存在: {csv_file}")
        print("💡 使用方法: python fiber_bragg_simulator.py [CSV文件路径]")
        return
    
    # 创建模拟器实例
    simulator = FiberBraggSimulator()
    
    try:
        # 启动模拟器
        simulator.start(csv_file)
    except Exception as e:
        print(f"❌ 模拟器运行出错: {e}")
    finally:
        simulator.stop()

if __name__ == "__main__":
    main()
