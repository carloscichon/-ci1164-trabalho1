    CC     = gcc -g -std=c11
    CFLAGS = -DLIKWID_PERFMON
    LFLAGS = -lm -llikwid

      PROG = matrixInv
      OBJS = lib_matriz.o \
             lib_lu.o \
			 lib_sTri.o \
			 lib_interpolacao.o \
			 lib_ajuste.o \
			 utils.o 

.PHONY: limpa faxina clean purge all

%.o: %.c %.h utils.h
	$(CC) -c $(CFLAGS) -O3 -mavx2 -march=native $<

$(PROG) : % :  $(OBJS) %.o
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

all: $(PROG)

limpa clean:
	@rm -f *~ *.bak

faxina purge:   limpa
	@rm -f *.o core a.out
	@rm -f $(PROG)