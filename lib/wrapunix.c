#include "unp.h"


void
Close(int fd)
{
	if(close(fd) == -1)
		err_sys("close error");
}
void
Write(int fd, void *ptr, size_t nbytes)
{
	if(write(fd, ptr, nbytes) != nbytes)
		err_sys("write error");
}
