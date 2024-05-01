CFLAGS = -std=c99 -Wall -Werror -Werror=vla -g
LDFLAGS = -lm

.PHONY: all clean

all: centros

centros: util.h util.c red_black.h red_black.c centros.c
	gcc $(CFLAGS) util.c red_black.c centros.c -o centros $(LDFLAGS)

clean:
	rm -f centros
