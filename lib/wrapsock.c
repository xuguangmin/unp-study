#include "unp.h"

int 
Socket(int family, int type, int proto)
{
	int n;
	if( (n = socket(family, type, proto)) < 0) 
		err_sys("socket error");
	return (n);
}
void 
Bind(int fd, const struct sockaddr *sa, socklen_t salen)
{
	if(bind(fd, sa, salen) < 0)
		err_sys("bind error");
}
int 
Accept(int fd, struct sockaddr *sa, socklen_t *salenptr)
{
	int n;
again:

	if((n = accept(fd, sa, salenptr)) < 0) {
#ifdef EPROTO
		if(errno == EPROTO || errno == ECONNABORTED)
#else
		if(errno == ECONNABORTED)
#endif
			goto again;
		else
			err_sys("accept error");
	}
	return (n);
}

void 
Listen(int fd, int backlog)
{
	char *ptr = NULL;
	if( (ptr = getenv("LISTENQ")) != NULL)
		backlog = atoi(ptr);
	
	if(listen(fd, backlog) < 0)
		err_sys("listen error");
}


