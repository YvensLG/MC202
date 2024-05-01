CFLAGS = -std=c99 -Wall -Werror -Werror=vla -g
LDFLAGS = -lm

.PHONY: all clean

all: caminho

caminho: imagem.h imagem.c matriz.h matriz.c fila.h fila.c caminho.c
	gcc $(CFLAGS) imagem.c matriz.c fila.c caminho.c -o caminho $(LDFLAGS)

clean:
	rm -f caminho
