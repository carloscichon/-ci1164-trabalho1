    CC     = gcc -g -std=c11
    CFLAGS = 
    LFLAGS = -lm

      PROG = matrixInv
      OBJS = lib_matriz.o \
             lib_lu.o \
			 lib_sTri.o \
			 utils.o

.PHONY: limpa faxina clean purge all

%.o: %.c %.h utils.h
	$(CC) -c $(CFLAGS) $<

$(PROG) : % :  $(OBJS) %.o
	$(CC) -o $@ $^ $(LFLAGS)

all: $(PROG)

limpa clean:
	@rm -f *~ *.bak

faxina purge:   limpa
	@rm -f *.o core a.out
	@rm -f $(PROG)