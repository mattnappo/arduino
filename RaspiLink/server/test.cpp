#include "serial.h"

int main()
{
    unsigned char WRITE_BYTES[] = "T";
    char PORT[] = "/dev/ttyACM0";

    int fd = serial_com::open_port(PORT);
    serial_com::configure_port(fd);
    serial_com::write(fd, WRITE_BYTES);
    
    return 0;
}