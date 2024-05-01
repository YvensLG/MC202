CFLAGS = -std=c99 -Wall -Werror -Werror=vla -g
LDFLAGS = -lm

.PHONY: all clean

all: classificar consultas

classificar: classificar.c
	gcc $(CFLAGS) classificar.c -o classificar $(LDFLAGS)

consultas: consultas.o pacientes.o
	gcc $(CFLAGS) consultas.o pacientes.o -o consultas $(LDFLAGS)

consultas.o: consultas.c pacientes.h
	gcc $(CFLAGS) -c consultas.c $(LDFLAGS)

pacientes.o: pacientes.c pacientes.h
	gcc $(CFLAGS) -c pacientes.c $(LDFLAGS)

clean:
	rm -f classificar consultas
