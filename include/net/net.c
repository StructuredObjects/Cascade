#pragma once

#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include "net.h"

typedef struct Info
{
    int                     main_socket;
    int                     clients;
    struct sockaddr_in      sock;
} Inet;

void err_exit(const char *msg)
{ 
    printf("%s", msg); exit(0); 
}

struct Info setup_tcp_socket(int port) {
    struct Info s;

    s.main_socket          = socket(AF_INET, SOCK_STREAM, 0);
    (s.main_socket == -1 ? err_exit("Unable to create socket\n") : printf("\x1b[92m[+]\x1b[0m Socket succesfully created....\n") );

    bzero(&s.sock, sizeof(s.sock));

    s.sock.sin_family      = AF_INET;
    s.sock.sin_addr.s_addr = htonl(INADDR_ANY);
    s.sock.sin_port        = htons(port);

    (bind(s.main_socket, (struct sockaddr_in*)&s.sock, sizeof(s.sock)) != 0 ? err_exit("\x1b[31m[!]\x1b[0m Socket bind failed...\n") : 0 );

    (listen(s.main_socket, 500*500) != 0 ? err_exit("\x1b[31m[!]\x1b[0m Listen failed...\n") : 0 );
    return s;
}

// void listen(struct Socket *s) {
//     int len;
//     struct sockaddr_in cli;

//     while(1)
//     {
//         len = sizeof(cli);
//         int con = accept(s->main_socket, (struct sockaddr_in*)&cli, &len);
//         (con < 0 ? err_exit("Unable to accept client!\n") : printf("Client accepted\n") );
//     }
// }