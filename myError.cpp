#include <stdio.h>
#include <stdarg.h>


#define MAXBUF 256

const char* const logPath = "log.txt";

FILE *log = NULL;

enum LOG_LEVEL {
	LOG_INFO,
	LOG_ERROR,
	LOG_DEBUG,
	LOG_WARN,
};

void log_doit(const char *fmt, va_list ap)
{
	char buf[MAXBUF] = {};
	int length = vsnprintf_s(buf, MAXBUF, fmt, ap);
	if (length >= MAXBUF) {
		buf[MAXBUF - 1] = '\0';
	}
	fprintf_s(log, buf);
}

void log_error(enum LOG_LEVEL level, const char *fmt, ...) 
{
	va_list ap;
	va_start(ap, fmt);
	log_doit(fmt, ap);
	va_end(ap);
}

void log_info(enum LOG_LEVEL level,const char *fmt,...)
{
	
}