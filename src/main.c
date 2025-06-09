#include "log.h"
#include "tcp.h"

int main() {
    TcpServer server = {0};
    TcpServerStatus status = bind_tcp_port(&server, 8080);
    if (status != SERVER_OK) {
        debug_log("Server Initialization Failed");
        exit(EXIT_FAILURE);
    }

    int client_fd = accept_client(server.socket_fd);
    if (client_fd == -1) {
        debug_log("Failed to Accept Client Connection");
        close(server.socket_fd);
        exit(EXIT_FAILURE);
    }

    debug_log("Client Connected");
    close(client_fd);
    close(server.socket_fd);

    return 0;
}