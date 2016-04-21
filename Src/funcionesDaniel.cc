#include "cabecera.h"

int manageArguments(int argc, char *argv[]){

	int toRet = 0;

	/*string err = "Error. Se debe indicar el puerto del servidor y la ruta al archivo de configuracion\n\rSintaxis: http_server [puerto] [-c fichero_configuracion]\n\r";

	if(argc == 2) puerto = atoi(argv[1]);
	
	if(argc == 3){ if(strcmp(argv[1],"-c") == 0){ rutaConf = argv[2]; } else toRet = 1; }

	if(argc == 4){
		if(strcmp(argv[1],"-c") == 0){ rutaConf = argv[2]; puerto = atoi(argv[3]); }
		else if(strcmp(argv[2],"-c") == 0){ rutaConf = argv[3]; puerto = atoi(argv[1]); }
		else toRet = 1;
	}

	if(toRet == 1 || argc > 4){ toRet = 1; cout << err; }*/

	
	/*if (argc !=  4){
		fprintf(stderr, "Error. Debe indicar la direccion del servidor (IP y Puerto) y el mensaje a enviar\r\n");
		fprintf(stderr, "Sintaxis: %s <ip> <puerto> <mensaje>\n\r", argv[0]);
		fprintf(stderr, "Ejemplo : %s 192.168.6.7 8574 \"Esto es un mensaje\"\n\r", argv[0]);
		return 1;
	}	
	servidor_ip = argv[1];
	servidor_puerto = argv[2];
	mensaje = argv[3];

	printf("\n\rEnviar mensaje \"%s\" a %s:%s...\n\r\n\r", mensaje, servidor_ip, servidor_puerto);*/

	return toRet;

}
