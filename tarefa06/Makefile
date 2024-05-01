CFLAGS = -std=c99 -Wall -Werror -Werror=vla -g
LDFLAGS = -lm

.PHONY: all clean

all: otimizar calculadora

otimizar: otimizar.o arvore.o
	gcc $(CFLAGS) otimizar.o arvore.o -o otimizar $(LDFLAGS)

otimizar.o: otimizar.c arvore.h
	gcc $(CFLAGS) -c otimizar.c $(LDFLAGS)

arvore.o: arvore.c arvore.h
	gcc $(CFLAGS) -c arvore.c $(LDFLAGS)

calculadora: calculadora.o arvore.o
	gcc $(CFLAGS) calculadora.o arvore.o -o calculadora $(LDFLAGS)

calculadora.o: calculadora.c arvore.h
	gcc $(CFLAGS) -c calculadora.c $(LDFLAGS)

clean:
	rm -f otimizar calculadora
