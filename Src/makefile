all: clienteREST clean

http_server: clienteREST.o funcionesDaniel.o funcionesAlejandro.o funcionesAngel.o
	g++ -lstdc++ -g -std=c++11 -Wall -pedantic -o http_server clienteREST.o funcionesDaniel.o funcionesAlejandro.o funcionesAngel.o

clienteREST.o: clienteREST.cc cabecera.h
	g++ -lstdc++ -g -std=c++11 -Wall -pedantic -c clienteREST.cc

funcionesDaniel.o: funcionesDaniel.cc cabecera.h
	g++ -lstdc++ -g -std=c++11 -Wall -pedantic -c funcionesDaniel.cc

funcionesAlejandro.o: funcionesAlejandro.cc cabecera.h
	g++ -lstdc++ -g -std=c++11 -Wall -pedantic -c funcionesAlejandro.cc

funcionesAngel.o: funcionesAngel.cc cabecera.h
	g++ -lstdc++ -g -std=c++11 -Wall -pedantic -c funcionesAngel.cc

clean:
	rm -rf *.o
	rm -rf *~
