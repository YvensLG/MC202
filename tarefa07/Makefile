CFLAGS = -std=c99 -Wall -Werror -Werror=vla -g
LDFLAGS = -lm

.PHONY: all clean

all: selecionar

selecionar: selecionar.o heap.o
	gcc $(CFLAGS) selecionar.o heap.o -o selecionar $(LDFLAGS)

selecionar.o: selecionar.c heap.h
	gcc $(CFLAGS) -c selecionar.c $(LDFLAGS)

heap.o: heap.c heap.h
	gcc $(CFLAGS) -c heap.c $(LDFLAGS)

clean:
	rm -f selecionar


