#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <time.h>
#include <sys/select.h>

#include "serial.h"

int serial_com::open_port(char *port)
{
    int fd;
    fd = open(port, O_RDWR | O_NOCTTY | O_NDELAY);
    
    if (fd != 0)
    {
        printf("open_port: failed to open %s\n", port);
    }
    else
    {
        fcntl(fd, F_SETFL, 0);
        printf("open_port: opened %s\n", port);
    }
    return fd;
}

int serial_com::configure_port(int fd)
{
    struct termios port_settings;

    cfsetispeed(&port_settings, B115200);
    cfsetospeed(&port_settings, B115200);

    port_settings.c_cflag &= ~PARENB;
    port_settings.c_cflag &= ~CSTOPB;
    port_settings.c_cflag &= ~CSIZE;
    port_settings.c_cflag |= ~CS8;

    tcsetattr(fd, TCSANOW, &port_settings);
    return fd;
}

int serial_com::write(int fd, unsigned char *bytes)
{
    char n;
    fd_set rdfs;
    struct timeval timeout;

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    write(fd, bytes);
    printf("write: wrote to fd\n");

    n = select(fd + 1, &rdfs, NULL, NULL, &timeout);

    if (n == 0)
        printf("write: timeout\n");
    else if (n < 0)
        printf("write: select failed\n");
    else
        printf("write: bytes detected on port\n");

    return n;
}
