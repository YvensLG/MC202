CFLAGS = -std=c99 -Wall -Werror -Werror=vla -g
LDFLAGS = -lm

.PHONY: all clean

all: calendario diferenca sela

calendario: calendario.c
	gcc $(CFLAGS) calendario.c -o calendario $(LDFLAGS)

diferenca: diferenca.c
	gcc $(CFLAGS) diferenca.c -o diferenca $(LDFLAGS)

diferenca: sela.c
	gcc $(CFLAGS) sela.c -o sela $(LDFLAGS)

clean:
	rm -f calendario diferenca sela