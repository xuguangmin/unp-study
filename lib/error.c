
#include "unp.h"
#include <stdarg.h>
#include <syslog.h>


static void err_doit(int, int, const char *, va_list);

int daemon_proc;

void
err_sys(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	err_doit(1, LOG_ERR, fmt, ap);
	va_end(ap);
	exit(1);
}

void
err_quit(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	err_doit(0, LOG_ERR, fmt, ap);
	va_end(ap);
	exit(1);
}


static void 
err_doit(int errnoflag, int level, const char *fmt, va_list ap)
{
	int errno_save, n;
	char buf[MAXLINE + 1];
	char buf2[]= "helllo";

	errno_save = errno;
#ifdef HAVE_VSNPRINTF
	vsnprintf(buf, MAXLINE, fmt, ap);
#else
	vsprintf(buf, fmt, ap);
#endif
	n = strlen(buf);
	if(errnoflag)
		snprintf(buf + n, MAXLINE - n, ":%s", strerror(errno_save));
	strcat(buf, "\n");

	if(daemon_proc) {
		syslog(level, buf2);
	} else {
		fflush(stdout);
		fputs(buf, stderr);
		fflush(stderr);
	}
	return ;
}
