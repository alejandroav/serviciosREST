#include <cstring>
#include <string.h>
#include <fstream>
#include <sstream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <arpa/inet.h>
#include <netdb.h>
#include "infix_iterator.h"
#include <iostream>
#include <iterator>
#include <exception>
#include <algorithm>
#include <iomanip>
#include "json.hpp"
using namespace std;

int manageArguments(int argc, char *argv[]);
string pedirEdificios();
string pedirEdificioEspecifico(string edificio);
string pedirEstanciasEdificio(string edificio);
string pedirEdificiosSinOcupantes();
string pedirEstanciasOcupantesEdificio();
string peticion();
string CorregirJSON(string frase);
void SepararJSON(string frase, int num, string edificio);
bool SeleccionMetodo(string frase, int num, bool final, string edificio);
int menu();
void ListaEdificios(string frase, bool final);
void ListaEdificiosVacios(string frase, bool final);
string leerCuerpo(char mensaje[]);
void tratarMetodo5(string frase, string idActividad);
bool detectar404(string msg);
