CFLAGS = -std=c99 -Wall -Werror -Werror=vla -g
LDFLAGS = -lm

.PHONY: all clean

all: 01_a 01_b 01_c

01_a: 01_a.o lista_ligada.o
	gcc $(CFLAGS) 01_a.o lista_ligada.o -o 01_a $(LDFLAGS)

01_a.o: 01_a.c lista_ligada.h
	gcc $(CFLAGS) -c 01_a.c $(LDFLAGS)

01_b: 01_b.o lista_ligada.o
	gcc $(CFLAGS) 01_b.o lista_ligada.o -o 01_b $(LDFLAGS)

01_b.o: 01_b.c lista_ligada.h
	gcc $(CFLAGS) -c 01_b.c $(LDFLAGS)

01_c: 01_c.o lista_ligada.o
	gcc $(CFLAGS) 01_c.o lista_ligada.o -o 01_c $(LDFLAGS)

01_c.o: 01_c.c lista_ligada.h
	gcc $(CFLAGS) -c 01_c.c $(LDFLAGS)

lista_ligada.o: lista_ligada.c lista_ligada.h
	gcc $(CFLAGS) -c lista_ligada.c $(LDFLAGS)

clean:
	rm -f 01_a 01_b 01_c