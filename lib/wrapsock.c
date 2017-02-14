#include "unp.h"

int 
Socket(int family, int type, int proto)
{
	int n;
	if( (n = socket(family, type, proto)) < 0) 
		err_sys("socket error");
	return (n);
	

}
