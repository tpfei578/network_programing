#include <unistd.h>
#include <iostream>
#include <errno.h>
#include "readn.h"

ssize_t readn(int fd, void *vptr, size_t size)
{
    size_t nleft;
    ssize_t nread;
    char *ptr;

    ptr = (char *)vptr;
    nleft = size;

    while (nleft > 0)
    {
        if ((nread = read(fd, ptr, nleft)) < 0)
        {
            if (errno == EINTR)
                nread = 0; /*非阻塞I/O情况下，没有数据，继续调用read*/
            else
                return -1;
        }
        else if (nread == 0)
            break;

        nleft -= nread;
        ptr += nread;
    }
    return (size - nleft);
}