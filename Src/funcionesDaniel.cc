#include "cabecera.h"

int menu(){
	int toRet = 0;
	cout<<"Menu de peticiones:\n\r1.- Listado de edificios\n\r2.- Edificios con estancias sin ocupantes\n\r3.- Edificios + Estancias + Numero de Ocupantes\n\r";
	cin>>toRet;
	if (toRet <= 0 || toRet >= 4) toRet = menu();
	return(toRet);
}

int manageArguments(int argc, char *argv[]){

	int toRet = 0;
	string idEdificio, idActividad = idEdificio = "";

	string err = "ERROR. Sintaxis: "; err += + argv[0]; err += " [-e id_edificio [-a id_actividad]]\n\r";
	err += "Ejemplo: "; err += + argv[0]; err += " -e 0001 -a 20\n\r";

	if(argc == 2 || argc == 4 || argc >= 6) { toRet = -1; }

	else if(argc == 3) { 
		if(strcmp(argv[1],"-e") == 0){
			idEdificio = argv[2];
			toRet = 2;
		} else toRet = -1;
	}

	else if(argc == 5) {
		if(strcmp(argv[1],"-e") == 0 && strcmp(argv[3],"-a") == 0){
			idEdificio = argv[2];
			idActividad = argv[4];
			toRet = 5;
		} else toRet = -1;
	}

	if (toRet == 0) toRet = menu();
	if (toRet == -1) cout<<err; return(toRet);
	
}
