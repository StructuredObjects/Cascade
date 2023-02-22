#ifndef NET_H
#define NET_H
typedef struct Info *Socket;
struct Info setup_tcp_socket(int port);
void write_string(int sock, const char *str);
void read_line(int sock, char *dest);
#endif