#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import socket
import json
import time

def test_tcp_connection():
    """测试TCP连接到光纤光栅监测系统"""
    
    # 连接到TCP服务端
    host = '127.0.0.1'
    port = 5555
    
    try:
        # 创建socket连接
        client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        client_socket.connect((host, port))
        print(f"成功连接到 {host}:{port}")
        
        # 发送测试数据
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
                            "Val": "15.24"
                        }
                    ],
                    "Move": [
                        {
                            "ChNum": 1,
                            "ID": "00201",
                            "Name": "位移传感器1",
                            "Val": "3.45"
                        }
                    ],
                    "Temp": [
                        {
                            "ChNum": 1,
                            "ID": "00301",
                            "Name": "温度传感器1",
                            "Val": "25.6"
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
        
    except Exception as e:
        print(f"连接失败: {e}")

if __name__ == "__main__":
    print("开始测试TCP连接...")
    test_tcp_connection()
    print("测试完成")
