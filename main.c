#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "include/os/main.c"
#include "include/net/net.c"
#include "include/str_utils/str.c"

#define HOSTNAME "\x1b[106m\x1b[30m[Dosville@Manager]#~ $\x1b[0m\x1b[49m "

void handle_client(int socket);

int main(int argc, char *argv[])
{
    (argc < 2 ? err_exit("\x1b[31m[!]\x1b[0m Error, Invalid arguments provided\n") : 0);
    // (!isdigit(argv[1]) ? err_exit("\x1b[31m[!]\x1b[0m Error, Invalid arguments provided\n") : 0);
    struct Info s;
    s = setup_tcp_socket(atoi(argv[1]));
    
    int len;
    struct sockaddr_in cli;

    while(1)
    {
        len = sizeof(cli);
        int con = accept(s.main_socket, (struct sockaddr_in*)&cli, &len);
        (con < 0 ? err_exit("Unable to accept client!\n") : printf("\x1b[92m[+]\x1b[0m Client accepted\n") );
        
        pthread_t pid;
        pthread_create(&pid, NULL, handle_client, con);
    }

    return 0;
}

void handle_client(int socket) {

    char buffer[1024]; char last_buffer[1024]; char resp[100]; int spam = 0;
    bzero(buffer, 1024);

    while(1)
    {
        write(socket, HOSTNAME, strlen(HOSTNAME));
        read(socket, buffer, sizeof(buffer));

        char *buf = trim_newline(buffer);
        if(strlen(buffer) > 3) {

            if(strstr("help", buf) != NULL) {
                write(socket, "Worked", strlen("Worked"));
                spam = 0;
            } else if(strstr("help", buffer) == 0) {
                write(socket, "Test", strlen("Test"));
                spam = 0;
            } else {
                
                sprintf(resp, "\x1b[31m[!]\x1b[0m Command %s not found!\r\n", buffer);
                write(socket, resp, strlen(resp));
                bzero(resp, 1024);
                spam++;
                
                if(spam == 5) {
                    printf("\x1b[31m[!]\x1b[0m Closing socket: %d....\n", socket);
                    close(socket);
                }

            }
        } else { 
            spam++;
            if(spam == 5) {
                printf("\x1b[31m[!]\x1b[0m Closing socket: %d....\n", socket);
                close(socket);
            }
        }

        printf("\x1b[92m[+]\x1b[0m Buffer [%d]: %s", socket, strdup(buf));
        bzero(buffer, 1024);
        bzero(buf, 1024);
    }
}