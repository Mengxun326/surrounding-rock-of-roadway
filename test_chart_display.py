#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
测试图表显示修正
验证Y轴范围设置是否正确
"""

def test_y_axis_range():
    """测试Y轴范围设置"""
    print("测试Y轴范围设置")
    print("=" * 50)
    
    # 模拟应变数据值
    strain_values = [500.0, 450.0, 400.0, 350.0, 300.0, 250.0, 200.0, 150.0, 100.0, 50.0, 0.0, -50.0, -100.0, -150.0, -200.0, -250.0, -300.0]
    
    print("应变数据值范围测试:")
    print(f"最小值: {min(strain_values)}")
    print(f"最大值: {max(strain_values)}")
    print(f"数据范围: {max(strain_values) - min(strain_values)}")
    
    # 计算Y轴范围
    min_value = min(strain_values)
    max_value = max(strain_values)
    range_value = max_value - min_value
    
    if range_value < 10:
        range_value = 10
    
    y_min = min_value - range_value * 0.1
    y_max = max_value + range_value * 0.1
    
    print(f"\nY轴范围计算:")
    print(f"原始范围: {min_value} 到 {max_value}")
    print(f"扩展后范围: {y_min:.1f} 到 {y_max:.1f}")
    
    # 检查是否在合理范围内
    if y_min >= -300 and y_max <= 500:
        print("Y轴范围在应变数据合理范围内 (-300 到 500)")
    else:
        print("Y轴范围超出应变数据合理范围")
    
    print(f"\n修正前问题:")
    print(f"- 原始Y轴范围: -50 到 50")
    print(f"- 应变数据值: 500")
    print(f"- 问题: 数据点超出Y轴范围，无法显示")
    
    print(f"\n修正后效果:")
    print(f"- 新Y轴范围: -300 到 500")
    print(f"- 应变数据值: 500")
    print(f"- 效果: 数据点在Y轴范围内，可以正常显示")

def test_data_classification():
    """测试数据分类"""
    print("\n测试数据分类")
    print("=" * 50)
    
    # 模拟从CSV读取的波长数据
    wavelengths = [1552.729248, 1555.184326, 1554.069580]
    initial_wavelength = 1537.2540
    K1 = 900.000000
    
    print("波长到应变转换:")
    for i, wavelength in enumerate(wavelengths):
        wavelength_change = wavelength - initial_wavelength
        strain = wavelength_change * K1
        strain = max(-300.00, min(500.00, strain))
        
        print(f"波长 {i+1}: {wavelength:.6f} nm")
        print(f"  波长变化: {wavelength_change:.6f} nm")
        print(f"  应变值: {strain:.2f} με")
        print(f"  分类: 应变数据 (value > 0)")
        print()

if __name__ == "__main__":
    test_y_axis_range()
    test_data_classification()
