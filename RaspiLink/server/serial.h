#ifndef SERIAL_H
#define SERIAL_H

namespace serial_com
{
    int open_port(char *port);
    int configure_port(int fd);
    int write(int fd, unsigned char *bytes);
}

#endif