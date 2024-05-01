CFLAGS = -std=c99 -Wall -Werror -Werror=vla -g
LDFLAGS = -lm

.PHONY: all clean

all: matrioscas

matrioscas: matrioscas.o pilha.o
	gcc $(CFLAGS) matrioscas.o pilha.o -o matrioscas $(LDFLAGS)

matrioscas.o: matrioscas.c pilha.h
	gcc $(CFLAGS) -c matrioscas.c $(LDFLAGS)

pilha.o: pilha.c pilha.h
	gcc $(CFLAGS) -c pilha.c $(LDFLAGS)

clean:
	rm -f matrioscas
