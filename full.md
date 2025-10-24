# 光纤光栅分析软件通信协议

山东星冉信息科技有限公司

# 1 传输端口

默认网络输出端口为5555，网络传输端口可配置。

# 2 通信协议

连接方式：采用点对点方式，安装的客户端作为 Tcp 服务端，Tcp 客户端连接成功后，将波长数据和计算出物理量发送到连接的客户端。

# 1、心跳格式包

```json
序号 字段 类型 描述  
1 HEARTBEAT 整型 固定值 1，每隔30S向服务端发送一次，服务端收到心跳后也会向客户端回复心跳，如果不发送心跳，会将客户端踢掉格式如下：  
客户端向服务端发送：{"type":0, "sync":"sync header date", //无作用，随意发送"body": {"VER":"1.0", "MSG":"HEARTBEAT", "PARAM":"1710377783000", //时间戳（可发可不发）}  
}服务端回复：{"type":0, "sync":"sync header date", //按原值返回即可，不用解析处理"body": {"VER":"1.0", "MSG":"ACK-HEARTBEAT", "ERR":0 //0：时间同步成功1：时间同步失败"PARAM":"1710377783000" //时间戳（可发可不发）}  
}
```

# 2、数据传输

<table><tr><td>序号</td><td>字段</td><td>类型</td><td>描述</td></tr><tr><td>1</td><td>Strain</td><td>数组</td><td>应变数组，储存N个对象
ChNum:通道号（整型）</td></tr><tr><td></td><td></td><td></td><td>ID:传感器ID(字符串)Name:传感器名称(字符串)Val:物理量(浮点型)</td></tr><tr><td>2</td><td>Move</td><td>数组</td><td>位移数组,储存N个对象</td></tr><tr><td>3</td><td>Temp</td><td>数组</td><td>温度数组,储存N个对象</td></tr><tr><td>4</td><td>WLG</td><td>数组</td><td>水位数组,储存N个对象</td></tr><tr><td>5</td><td>a</td><td>数组</td><td>加速度数组,储存N个对象</td></tr><tr><td>6</td><td>P</td><td>数组</td><td>压力数组,储存N个对象</td></tr><tr><td>7</td><td>WL</td><td>数组</td><td>波长数组,每个通道一个数组整型代表通道号,字符串代表波长(nm)</td></tr><tr><td>{"type":0,"sync":"sync header date", //按原值返回即可,不用解析处理"body":{
    "VER":"1.0",
    "MSG":"REALTIME",
    "ERR":0
    "PARAM":{
        //应变"Strain":[1,
        "ChNum":2,
        "ID":"00201",
        "Name":"传感器名称",
        "Val":"15.24"},
        {"ChNum":3,
        "ID":"00301",
        "Name":"传感器名称",
        "Val":"15.24"},
        ],//位移"Move":[1,
        "ChNum":2,
        "ID":"00201",
        "Name":"传感器名称",
        "Val":"15.24"]}</td><td></td><td></td><td></td></tr></table>

```json
{ "ChNum":3, "ID":"00301", "Name":"传感器名称", "Val":"15.24" } ], //温度 "Temp":[ { "ChNum":2, "ID":"00201", "Name":"传感器名称", "Val":"15.24" }, { "ChNum":3, "ID":"00301", "Name":"传感器名称", "Val":"15.24" } ], //水位 "WLG":[ { "ChNum":2, "ID":"00201", "Name":"传感器名称", "Val":"15.24" }, { "ChNum":3, "ID":"00301", "Name":"传感器名称", "Val":"15.24" } ],
```

```json
//加速度
"a": [ 
{ "ChNum": 2, 
"SensorID": "00201", 
"Value": 1897.0550537109375 }, 
{ "ChNum": 3, 
"SensorID": "00301", 
"Value": 1897.0550537109375 } 
], //压力
"P": [ 
{ "ChNum": 2, 
"ID": "00201", 
"Name":"传感器名称", 
"Val":"15.24" }, 
{ "ChNum": 3, 
"ID":"00301", 
"Name":"传感器名称", 
"Val":"15.24" }, 
], //波长
"WL": [ 
[ 1, 
"1535.9597", 
"1553.1787" ], 
[ 2, 
"1553.7931" ] 
] }
```

<table><tr><td>}</td></tr></table>

# 3、振动传感器数据通过 UDP 进行发送，端口号为 6666

（1）发送FFFFFFEEEEEEEE，开启数据发送

# （2）实时数据发送

<table><tr><td></td><td></td><td>类型</td><td>描述</td></tr><tr><td>包头</td><td>0xFF 0xFF 0xFF 0xFF</td><td></td><td>整帧的包头</td></tr><tr><td>帧类型</td><td>0x03</td><td></td><td>实时数据</td></tr><tr><td>通道编号1</td><td>0x0X</td><td></td><td>通道编号</td></tr><tr><td>ID1</td><td>0x0X</td><td></td><td>传感器ID</td></tr><tr><td>波长1</td><td>0XXX 0XXX 0XXX0XXX</td><td>Int</td><td>高位在前,低位在后,将计算出的数据/1000得出波长</td></tr><tr><td>主频1</td><td>0XXX 0XXX 0XXX0XXX</td><td>int</td><td>高位在前,低位在后,将计算出的数据/1000得出主频</td></tr><tr><td>预留</td><td></td><td></td><td>预留8组,总共32个字节</td></tr><tr><td>......</td><td>......</td><td>......</td><td>......</td></tr><tr><td>通道编号N</td><td>0x0X</td><td></td><td>通道编号</td></tr><tr><td>IDN</td><td>0x0X</td><td></td><td>传感器ID</td></tr><tr><td>波长N</td><td>0XXX 0XXX 0XXX0XXX</td><td>Int</td><td>高位在前,低位在后,将计算出的数据/1000得出波长</td></tr><tr><td>主频N</td><td>0XXX 0XXX 0XXX0XXX</td><td>int</td><td>高位在前,低位在后,将计算出的数据/1000得出主频</td></tr><tr><td>预留</td><td></td><td></td><td>预留8组,总共32个字节</td></tr><tr><td>包尾</td><td>0xE0EE 0xE0EE0xEEE</td><td></td><td>整帧的包尾</td></tr></table>

# （3）频谱数据发送

<table><tr><td></td><td></td><td>类型</td><td>详细</td></tr><tr><td>包头</td><td>0xFF 0xFF 0xFF 0xFF</td><td></td><td>整帧的包头</td></tr><tr><td>帧类型</td><td>0x04</td><td></td><td>实时数据</td></tr><tr><td>通道号</td><td>0xxx</td><td></td><td></td></tr><tr><td>ID</td><td>0xxx</td><td></td><td></td></tr><tr><td>采样率</td><td>0XXX 0XXX</td><td>Uint16</td><td>高位在前,低位在后</td></tr><tr><td>有效数据大小</td><td>0XXX 0XXX</td><td>Uint16</td><td>高位在前,地位在后</td></tr><tr><td>总包数量</td><td>0XXX</td><td>Uint8</td><td></td></tr><tr><td>当前帧</td><td>0XXX</td><td>Uint8</td><td></td></tr><tr><td>有效频谱数据</td><td>0XXX 0XXX 0XXX 0XXX</td><td>Uint32</td><td>高位在前,低位在后,将计算出的结果/100000000得出频谱数据</td></tr><tr><td>包尾</td><td>0EEE 0EEE 0EEE 0EEE</td><td></td><td>帧尾</td></tr></table>

注：由于一次性无法传输一整包数据，需要通过分包传输，当接收完成后进行组包即可得到一整包的数据。