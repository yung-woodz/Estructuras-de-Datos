
# Para Linux/i386

OBJECTS= nodo.o main.o
CFLAGS= -g -Wall # Para incorporar en el ejecutable información para depuración.
BIN= main

#all: $(BIN)

.SUFFIXES:
.SUFFIXES: .o .c

.c.o:
	gcc -c $(CFLAGS) $<

$(BIN): $(OBJECTS)
	gcc -o $(BIN) $(OBJECTS)

clean:
	rm -f *.o *~

