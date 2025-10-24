#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
测试数据发送功能
验证应变数据计算和发送
"""

import json

def calculate_strain_from_wavelength(wavelength, initial_wavelength=1537.2540):
    """根据波长计算应变值（微应变με）"""
    K1 = 3.0  # 降低应变系数，使应变值在50以内
    wavelength_change = wavelength - initial_wavelength
    strain = wavelength_change * K1
    strain = max(-50.00, min(50.00, strain))
    return strain

def test_data_classification():
    """测试数据分类"""
    print("测试数据分类和应变计算")
    print("=" * 50)
    
    # 从CSV文件中读取一些实际波长数据
    test_wavelengths = [
        1552.729248,  # 来自CSV的实际数据
        1555.184326,
        1554.069580,
        1553.416382,
        1553.374756,
        1545.541016,
        1550.731445
    ]
    
    print(f"{'波长(nm)':<15} {'应变(με)':<12} {'分类':<10}")
    print("-" * 50)
    
    strain_count = 0
    move_count = 0
    temp_count = 0
    
    for i, wavelength in enumerate(test_wavelengths):
        strain_value = calculate_strain_from_wavelength(wavelength)
        
        # 模拟分类逻辑（修正前）
        if 1535.0 <= wavelength <= 1540.0:
            classification = "应变传感器"
            strain_count += 1
        elif 1540.0 < wavelength <= 1550.0:
            classification = "位移传感器"
            move_count += 1
        elif 1550.0 < wavelength <= 1580.0:
            classification = "温度传感器"
            temp_count += 1
        else:
            classification = "未知"
        
        print(f"{wavelength:<15.6f} {strain_value:<12.2f} {classification:<10}")
    
    print(f"\n分类统计:")
    print(f"应变传感器: {strain_count}个")
    print(f"位移传感器: {move_count}个") 
    print(f"温度传感器: {temp_count}个")
    
    print(f"\n问题分析:")
    print(f"CSV数据中的波长主要在1550-1580nm范围")
    print(f"这被分类为温度传感器，但您需要的是应变数据")
    print(f"解决方案: 将所有波长数据都作为应变数据处理")

def test_json_data_format():
    """测试JSON数据格式"""
    print("\n测试JSON数据格式")
    print("=" * 50)
    
    # 模拟构建TCP数据包
    wavelengths = [1552.729248, 1555.184326, 1554.069580]
    timestamp = "2025-08-31 11:42:50.731"
    
    strain_data = []
    wl_data = []
    
    for i, wavelength in enumerate(wavelengths):
        ch_num = i + 1
        sensor_id = f"{ch_num:03d}01"
        sensor_name = f"传感器{ch_num}"
        strain_value = calculate_strain_from_wavelength(wavelength)
        
        # 所有数据都作为应变数据处理
        strain_data.append({
            "ChNum": ch_num,
            "ID": sensor_id,
            "Name": f"{sensor_name}_应变",
            "Val": f"{strain_value:.2f}"
        })
        
        wl_data.append([ch_num, f"{wavelength:.6f}"])
    
    tcp_data = {
        "type": 0,
        "sync": f"sync header {timestamp}",
        "body": {
            "VER": "1.0",
            "MSG": "REALTIME",
            "ERR": 0,
            "PARAM": {
                "Strain": strain_data,
                "Move": [],
                "Temp": [],
                "WLG": [],
                "a": [],
                "P": [],
                "WL": wl_data
            }
        }
    }
    
    print("构建的JSON数据包:")
    print(json.dumps(tcp_data, ensure_ascii=False, indent=2))
    
    print(f"\n应变数据统计:")
    print(f"应变传感器数量: {len(strain_data)}")
    print(f"位移传感器数量: 0")
    print(f"温度传感器数量: 0")

if __name__ == "__main__":
    test_data_classification()
    test_json_data_format()
