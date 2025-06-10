#include "log.h"
#include "tcp.h"
#include "http.h"

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

    HttpRequest request = {0};

    if (read_http_request(client_fd, &request) != HTTP_PARSE_OK) {
        debug_log("Failed to read or parse HTTP request");
        close(client_fd);
        return 0;
    }

    debug_log("HTTP Request Parsed Successfully");
    debug_log(request.method);
    debug_log(request.path);
    debug_log(request.protocol);

    close(client_fd);
    close(server.socket_fd);

    return 0;
}