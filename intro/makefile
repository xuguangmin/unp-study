include ../Make.defines

SRCS = $(wildcard *.c)
TARGETS = $(SRCS:%.c=%)

all:
	#for循环生成多个可执行文件
	@for target in $(TARGETS); \
	do \
	${CC} ${CFLAGS} -o $$target $$target.c ${LIBUNP_NAME}; \
	done

clean:
	@rm -f  $(TARGETS) *.o
