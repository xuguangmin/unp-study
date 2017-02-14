#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <sys/types.h>          /* See NOTES */
 #include <arpa/inet.h>


#define HAVE_VSNPRINTF

#define MAXLINE	4096	
#define LISTENQ	1024	//监听队列最大值

#define SA	struct sockaddr


void err_quit(const char *, ...);
void err_sys(const char *, ...);

