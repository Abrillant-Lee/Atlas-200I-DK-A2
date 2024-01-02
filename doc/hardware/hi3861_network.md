# 昇腾和小熊派网络socket通信

## 一、硬件

- 昇腾
- 小熊派
- [USB WiFi网卡](https://www.hiascend.com/document/detail/zh/Atlas200IDKA2DeveloperKit/23.0.RC1/Hardware%20Interfaces/hiug/hiug_0059.html)

    <img src="../../img/socket_接线.jpg" width="500">

## 二、网络编程程序

- [昇腾服务端程序](./socket/server.py)
- [小熊派客户端程序](./socket/client.c)

## 三、通信

- 昇腾服务端程序运行

    ```bash
    python3 server.py
    ```

    <img src="../../img/server_run.png">

-  小熊派烧录代码，并用串口调试器打开串口，查看打印信息


    <img src="../../img/socket_result.png">


