#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import socket
import json
import time

def test_network_connection():
    """测试从192.168.3.69到192.168.3.90的网络连接"""
    
    # 连接到TCP服务端
    host = '192.168.3.90'  # 您的机器IP
    port = 5555
    
    try:
        # 创建socket连接
        client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        client_socket.settimeout(10)  # 设置10秒超时
        client_socket.connect((host, port))
        print(f"成功连接到 {host}:{port}")
        
        # 发送测试数据（模拟设备数据）
        test_data = {
            "type": 0,
            "sync": "sync header date",
            "body": {
                "VER": "1.0",
                "MSG": "REALTIME",
                "ERR": 0,
                "PARAM": {
                    "Strain": [
                        {
                            "ChNum": 1,
                            "ID": "00101",
                            "Name": "应变传感器1",
                            "Val": "25.8"
                        }
                    ],
                    "Move": [
                        {
                            "ChNum": 1,
                            "ID": "00201",
                            "Name": "位移传感器1",
                            "Val": "4.2"
                        }
                    ],
                    "Temp": [
                        {
                            "ChNum": 1,
                            "ID": "00301",
                            "Name": "温度传感器1",
                            "Val": "28.5"
                        }
                    ]
                }
            }
        }
        
        # 发送JSON数据
        json_data = json.dumps(test_data, ensure_ascii=False)
        client_socket.send(json_data.encode('utf-8'))
        print(f"发送测试数据: {json_data}")
        
        # 等待响应
        time.sleep(2)
        
        # 发送心跳响应
        heartbeat_response = {
            "type": 0,
            "sync": "sync header date",
            "body": {
                "VER": "1.0",
                "MSG": "ACK-HEARTBEAT",
                "ERR": 0,
                "PARAM": "heartbeat_ack"
            }
        }
        
        json_heartbeat = json.dumps(heartbeat_response, ensure_ascii=False)
        client_socket.send(json_heartbeat.encode('utf-8'))
        print(f"发送心跳响应: {json_heartbeat}")
        
        # 保持连接一段时间
        time.sleep(5)
        
        client_socket.close()
        print("连接已关闭")
        
    except socket.timeout:
        print(f"连接超时: 无法连接到 {host}:{port}")
        print("请检查:")
        print("1. 防火墙是否阻止了连接")
        print("2. 程序是否正在运行")
        print("3. 网络连接是否正常")
    except ConnectionRefusedError:
        print(f"连接被拒绝: {host}:{port}")
        print("请检查程序是否正在运行")
    except Exception as e:
        print(f"连接失败: {e}")

if __name__ == "__main__":
    print("开始测试网络连接...")
    print("从设备IP 192.168.3.69 连接到主机 192.168.3.90:5555")
    test_network_connection()
    print("测试完成")
