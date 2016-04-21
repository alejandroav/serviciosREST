all: clienteREST clean

OPTS=-Wall -g -std=c++11 -"I."
OBJS=funcionesDaniel.o funcionesAlejandro.o funcionesAngel.o
CC=g++

clienteREST: $(OBJS) clienteREST.o
	$(CC) $(OPTS) $(OBJS) clienteREST.o -o clienteREST

clienteREST.o: clienteREST.cc cabecera.h
	$(CC) $(OPTS) -c clienteREST.cc

funcionesDaniel.o: funcionesDaniel.cc cabecera.h
	$(CC) $(OPTS) -c funcionesDaniel.cc

funcionesAngel.o: funcionesAngel.cc cabecera.h
	$(CC) $(OPTS) -c funcionesAngel.cc

funcionesAlejandro.o: funcionesAlejandro.cc cabecera.h
	$(CC) $(OPTS) -c funcionesAlejandro.cc

clean:
	rm -rf *.o
	rm -rf *~
