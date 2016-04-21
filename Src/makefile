all: clienteREST clean

http_server: clienteREST.o funcionesDaniel.o funcionesAlejandro.o funcionesAngel.o
	g++ -o http_server clienteREST.o funcionesDaniel.o funcionesAlejandro.o funcionesAngel.o

clienteREST.o: clienteREST.cc cabecera.h
	g++ -c clienteREST.cc

funcionesDaniel.o: funcionesDaniel.cc cabecera.h
	g++ -c funcionesDaniel.cc

funcionesAlejandro.o: funcionesAlejandro.cc cabecera.h
	g++ -c funcionesAlejandro.cc

funcionesAngel.o: funcionesAngel.cc cabecera.h
	g++ -c funcionesAngel.cc

clean:
	rm -rf *.o
	rm -rf *~
