#include <iostream>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>

void send_data(FILE *fp, int sockfd);

void err_quit(const char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
    int sockfd;
    struct sockaddr_in servaddr;

    if (argc != 2)
        err_quit("usage: tcpclient <IPaddress");

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(12345);
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
    connect(sockfd, (sockaddr *)&servaddr, sizeof(servaddr));
    send_data(stdin, sockfd);
}
#define MESSAGE_SIZE 1024000
void send_data(FILE *fp, int sockfd)
{
    size_t remaining = 0;
    char *query;
    query = (char *)malloc(MESSAGE_SIZE + 1);
    for (int i = 0; i < MESSAGE_SIZE; i++)
    {
        query[i] = 'a';
    }
    query[MESSAGE_SIZE] = '\0';

    const char *cp;
    cp = query;
    remaining = strlen(query);

    while (remaining)
    {
        size_t n_written = send(sockfd, cp, remaining, 0);
        fprintf(stdout, "send into buffer %ld\n", n_written);
        if (n_written <= 0)
        {
            perror("send");
            return;
        }
        remaining -= n_written;
        cp += n_written;
    }
    return;
}