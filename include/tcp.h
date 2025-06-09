#ifndef TCP_H
#define TCP_H

#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include "log.h"

typedef enum {
    SERVER_OK,
    SERVER_SOCKET_ERROR,
    SERVER_BIND_ERROR,
    SERVER_LISTEN_ERROR,
    SERVER_ACCEPT_ERROR
} TcpServerStatus;

typedef struct {
    int socket_fd;
    struct sockaddr_in address;
} TcpServer;

TcpServerStatus bind_tcp_port(TcpServer*, int);
int accept_client(int server_fd);

#endif