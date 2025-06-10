#include "http.h"
#include <string.h>
#include <unistd.h>

HttpParseStatus read_http_request(int socket_fd, HttpRequest* request) {
    char buffer[HTTP_MAX_REQUEST_LEN] = {0};
    ssize_t bytes_read = read(socket_fd, buffer, sizeof(buffer) - 1);

    if (bytes_read <= 0) return HTTP_PARSE_INVALID;

    buffer[bytes_read] = '\0';

    if (sscanf(buffer, "%7s %2047s %15s", request->method, request->path, request->protocol) != 3) return HTTP_PARSE_INVALID;

    return HTTP_PARSE_OK;
}