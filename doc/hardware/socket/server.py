import socket

def start_server():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_address = ('192.168.43.18', 8000)
    server_socket.bind(server_address)

    server_socket.listen(1)
    print("服务器正在等待连接...")

    while True:
        client_socket, client_address = server_socket.accept()
        print(f"接收到来自 {client_address} 的连接")

        data = client_socket.recv(1024)
        print(f"接收到的数据: {data.decode('utf-8')}")

        client_socket.sendall("1".encode('utf-8'))
        client_socket.sendall("Hello , I am Ascend".encode('utf-8'))
        client_socket.close()

if __name__ == "__main__":
    start_server()