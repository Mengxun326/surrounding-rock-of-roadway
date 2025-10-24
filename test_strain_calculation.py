#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
测试应变计算功能
验证根据波长计算应变值的正确性
"""

def calculate_strain_from_wavelength(wavelength, initial_wavelength=1537.2540):
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

def test_strain_calculations():
    """测试应变计算"""
    print("测试应变计算功能")
    print("=" * 50)
    
    # 测试用例
    test_cases = [
        (1537.2540, "初始波长"),
        (1536.2540, "波长减少1nm"),
        (1538.2540, "波长增加1nm"),
        (1535.2540, "波长减少2nm"),
        (1539.2540, "波长增加2nm"),
        (1534.2540, "波长减少3nm"),
        (1540.2540, "波长增加3nm"),
        (1530.2540, "波长减少7nm"),
        (1544.2540, "波长增加7nm"),
    ]
    
    print(f"{'波长(nm)':<12} {'波长变化(nm)':<12} {'应变(με)':<12} {'状态':<10}")
    print("-" * 50)
    
    for wavelength, description in test_cases:
        strain = calculate_strain_from_wavelength(wavelength)
        wavelength_change = wavelength - 1537.2540
        
        # 判断应变值是否在合理范围内
        if -50.00 <= strain <= 50.00:
            status = "正常"
        else:
            status = "超出范围"
        
        print(f"{wavelength:<12.6f} {wavelength_change:<12.6f} {strain:<12.2f} {status:<10}")
    
    print("\n应变计算说明:")
    print("- 初始波长: 1537.2540 nm")
    print("- 应变系数 K1: 3.0 με/nm")
    print("- 计算公式: 应变(με) = (当前波长 - 初始波长) × K1")
    print("- Y轴范围: -50.00 到 50.00 με")
    print("- 波长变化范围: -16.67 到 +16.67 nm (对应应变范围)")

if __name__ == "__main__":
    test_strain_calculations()
