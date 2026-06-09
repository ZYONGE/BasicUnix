
TARGET  = main_so main_a
WDIR     = .

CC	 = gcc

CFLAGS   = -Wall -O3 -D_REENTRANT
CFLAGS  += -I${WDIR} -I./include

LFLAGS  = -L./ -L./lib
LFLAGS  += -lmylib


SRCS    = $(wildcard *.c)
OBJS	= $(SRCS:.c=.o)

#====================================================
all: ${TARGET} clean
#====================================================
main_so : $(SRCS)
	  $(CC) -shared $(CFLAGS) -o $@ $? $(LFLAGS)

main_a : $(SRCS)
	  $(CC) -static $(CFLAGS) -o $@ $? $(LFLAGS)
#-----------------------------------------------------
clean:
	rm -f core *.o a.out 
#=====================================================
