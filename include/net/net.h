#ifndef NET_H
#define NET_H
typedef struct Info *Socket;
struct Info setup_tcp_socket(int port);
#endif