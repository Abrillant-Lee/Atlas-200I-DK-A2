import socket

def start_server():
    # 创建一个 socket 对象
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # 定义服务器地址和端口
    server_address = ('192.168.43.18', 8000)

    # 绑定 socket 到服务器地址
    server_socket.bind(server_address)

    # 开始监听连接
    server_socket.listen(1)
    print("服务器正在等待连接...")

    while True:
        # 接受客户端连接
        client_socket, client_address = server_socket.accept()
        print(f"接收到来自 {client_address} 的连接")

        # 接收客户端发送的数据
        data = client_socket.recv(1024)
        print(f"接收到的数据: {data.decode('utf-8')}")

        # 向客户端发送数据
        client_socket.sendall("1".encode('utf-8'))
        client_socket.sendall("Hello , I am Ascend".encode('utf-8'))

        # 关闭客户端连接
        client_socket.close()

if __name__ == "__main__":
    # 启动服务器
    start_server()