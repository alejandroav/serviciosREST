#include "cabecera.h"

int menu(){
	int toRet = 0;
	cout << "Menu de peticiones:\n\r1.- Listado de edificios\n\r2.- Numero de estancias y ocupantes por edificio\n\r";
	cout << "3.- Edificios con estancias sin ocupantes\n\r4.- Estancias por edificio\n\r5.- Estancias por edificio y actividad\n\r";
	cin >> toRet;
	if (toRet <= 0 || toRet >= 6) toRet = menu();
	return(toRet);
}

int manageArguments(int argc, char *argv[]){

	int toRet = 0;

	string err = "ERROR. Sintaxis: "; err += + argv[0]; err += " [-e id_edificio [-a id_actividad]]\n\r";
	err += "Ejemplo: "; err += + argv[0]; err += " -e 0001 -a 20\n\r";

	if(argc == 2 || argc == 4 || argc >= 6) { toRet = -1; }

	else if(argc == 3) { 
		if(strcmp(argv[1],"-e") == 0) toRet = 4;
		else toRet = -1;
	}

	else if(argc == 5) {
		if(strcmp(argv[1],"-e") == 0 && strcmp(argv[3],"-a") == 0) toRet = 5;
		else toRet = -1;
	}

	if (toRet == 0) toRet = menu();
	if (toRet == -1) cout<<err; return(toRet);
	
}

bool detectar404(string msg){
	bool toRET = false;
	if((int)msg.at(9) != '2') toRET = true;
	return (toRET);
}
