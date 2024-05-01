CFLAGS = -std=c99 -Wall -Werror -Werror=vla -g
LDFLAGS = -lm

.PHONY: all clean

all: editor

editor: editor.o lista_ligada.o
	gcc $(CFLAGS) editor.o lista_ligada.o -o editor $(LDFLAGS)

editor.o: editor.c lista_ligada.h
	gcc $(CFLAGS) -c editor.c $(LDFLAGS)

lista_ligada.o: lista_ligada.c lista_ligada.h
	gcc $(CFLAGS) -c lista_ligada.c $(LDFLAGS)

clean:
	rm -f editor
