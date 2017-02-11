#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>


#define HAVE_VSNPRINTF

#define MAXLINE	4096
void err_quit(const char *, ...);

