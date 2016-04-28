#include <cstring>
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
void SepararJSON(string frase);
