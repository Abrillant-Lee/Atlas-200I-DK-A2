#include <stdio.h>
#include <unistd.h>

#include "cmsis_os2.h"
#include "ohos_init.h"

#include "lwip/sockets.h"
#include "wifi_connect.h"

#define TASK_STACK_SIZE (1024 * 10)
#define TASK_DELAY_2S 2
#define CONFIG_WIFI_SSID "xxx"    // 要连接的WiFi 热点账号
#define CONFIG_WIFI_PWD "xxxxxxxxx"  // 要连接的WiFi 热点密码
#define CONFIG_SERVER_IP            "192.168.43.18"                     // 要连接的服务器IP
#define CONFIG_SERVER_PORT          8000                                // 要连接的服务器端口
#define TCP_BACKLOG 10

char recvbuf[512];
char *buf = "Hello! I'm BearPi-HM_Nano TCP Client!";

static void TCPClientTask(void)
{
    /* 服务端地址信息 */
    struct sockaddr_in server_sock;
    /* 客户端地址信息 */
    struct sockaddr_in client_sock;
    int sin_size;
    int sock_fd;
    int addr_length;

    struct sockaddr_in *cli_addr;
    /* 连接Wifi */
    WifiConnect(CONFIG_WIFI_SSID, CONFIG_WIFI_PWD);

    /**
    * 1.创建socket
    * AF_INET:ipv4
    * SOCK_STRAM:tcp协议
    */
   if((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("socket is error\r\n");
        exit(1);
    }

    // 初始化预连接的服务端地址
    bzero(&server_sock,sizeof(server_sock));
    server_sock.sin_family = AF_INET;
    server_sock.sin_addr.s_addr = inet_addr(CONFIG_SERVER_IP);
    server_sock.sin_port = htons(CONFIG_SERVER_PORT);
    addr_length = sizeof(server_sock);

    if(connect(sock_fd, (struct sockaddr *)&server_sock, addr_length) == -1) {
        perror("connect error\r\n");
        exit(1);
    }

    ssize_t ret;

    if((ret = send(sock_fd, buf, strlen(buf) + 1, 0)) == -1)
    {
        perror("send : ");
        closesocket(sock_fd);
        exit(1);
    }
    sleep(2);

    while(1)
    {
        if((ret = recv(sock_fd, recvbuf, sizeof(recvbuf), 0)) == -1)
        {
            perror("recv error \r\n");
            break;
        }
        printf("recv :%s\r\n",recvbuf); //recvbuf是接收到的数据
        sleep(2);

        printf("%d",(int)recvbuf[0]);

        if((int)recvbuf[0] == 49 )
        {
            printf("我接受到你的数据，数据为1\r\n");
            break;
        }
    }
    //关闭这个 socket
    closesocket(sock_fd);
}

static void TCPClientDemo(void)
{
    osThreadAttr_t attr;

    attr.name = "TCPServerTask";
    attr.attr_bits = 0U;
    attr.cb_mem = NULL;
    attr.cb_size = 0U;
    attr.stack_mem = NULL;
    attr.stack_size = TASK_STACK_SIZE;
    attr.priority = osPriorityNormal;

    if (osThreadNew((osThreadFunc_t)TCPClientTask, NULL, &attr) == NULL) {
        printf("[TCPClientDemo] Failed to create TCPServerTask!\n");
    }
}

APP_FEATURE_INIT(TCPClientDemo);
