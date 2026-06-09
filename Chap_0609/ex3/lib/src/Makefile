
TARGET  = libmylib.a libmylib.so

WDIR     = ../..
LDIR    = ${WDIR}/lib

SHARED   = -shared -fPIC

CFLAGS   = -Wall -o32 -O2 -D_REENTRANT
CFLAGS  += -I$(WDIR) -I${WDIR}/include 

SRCS    = $(wildcard *.c)
OBJS	= $(SRCS:.c=.o)


#===========================================================================
all: ${TARGET} clean
#===========================================================================
libmylib.a : $(OBJS)
	ar -rscv $@ $?
	mv $@ ${LDIR}

libmylib.so : ${SRCS}
	$(CC) ${SHARED} $(CFLAGS) -o $@ $? $(LFLAGS)
	mv $@ ${LDIR}
#---------------------------------------------------------------------------
clean:
	rm -f core *.o *~ a.out 
#===========================================================================
