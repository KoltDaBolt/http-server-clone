#ifndef HTTP_H
#define HTTP_H

#include <stdio.h>
#include <stddef.h>

#define HTTP_MAX_REQUEST_LEN 8192 * 4
#define HTTP_METHOD_MAX_LEN 8
#define HTTP_PATH_MAX_LEN 2048
#define HTTP_PROTOCOL_MAX_LEN 16

typedef enum {
    HTTP_PARSE_OK,
    HTTP_PARSE_INVALID
} HttpParseStatus;

typedef struct {
    char method[HTTP_METHOD_MAX_LEN];
    char path[HTTP_PATH_MAX_LEN];
    char protocol[HTTP_PROTOCOL_MAX_LEN];
} HttpRequest;

HttpParseStatus read_http_request(int, HttpRequest*);

#endif