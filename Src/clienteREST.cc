#include "cabecera.h"

int main (int argc, char *argv[]) {
	
	char *servidor_ip;
	char *servidor_puerto;
	char respuesta[1024];
    	const char* mensaje;
	struct sockaddr_in direccion;
	int s;
	int n, enviados, recibidos;
	string idEdificio, idActividad = idEdificio = "";
	
	// Comprobar los argumentos y tomarlos
	int opcion = manageArguments(argc, argv);
	if (opcion == -1) return(1);
	
	switch(opcion){
		case (1):{ 
			string missatge = pedirEdificios();
			mensaje = const_cast<char*>(missatge.c_str());
			break; }
		case (2):{ 
			string missatge = pedirEstanciasOcupantesEdificio();
			mensaje = const_cast<char*>(missatge.c_str());
			break; }
		case (3):{
			string missatge = pedirEdificiosSinOcupantes();
			mensaje = const_cast<char*>(missatge.c_str());
			break; }
		case (4):{
			if(argc == 1){ cout << "ID Edificio: "; cin>>idEdificio; }
			else idEdificio = argv[2];
			string missatge = pedirEstanciasOcupantesEdificio();
			mensaje = const_cast<char*>(missatge.c_str());
			break; }
		case (5):{
			if(argc == 1){ cout << "ID Edificio: "; cin>>idEdificio; cout << "ID Actividad: "; cin>>idActividad; }
			else{ idEdificio = argv[2]; idActividad = argv[4]; }
			string missatge = "hola";
			//mensaje = const_cast<char*>(missatge.c_str());
			mensaje = &missatge[0];
			break; }
		default:{
			string missatge = "hola";
			mensaje = const_cast<char*>(missatge.c_str());
			break; }
	}

	string ip = "193.145.231.149";
	servidor_ip = const_cast<char*>(ip.c_str());
	string puerto = "80";
	servidor_puerto = const_cast<char*>(puerto.c_str());

	
	//printf("\n\rSYSMSG --> Enviando el siguiente mensaje a %s:%s:\n\r\"%s\"", servidor_ip, servidor_puerto, mensaje);

	// Paso 1: Abrir el socket
	s = socket(AF_INET, SOCK_STREAM, 0); // Creo el socket
	if (s == -1){ fprintf(stderr, "\n\rSYSMSG --> Error. No se puede abrir el socket\n\r"); return 1; }
	printf("\n\rSYSMSG --> Socket abierto\n\r");
	
	// Paso 2: Conectar al servidor		
	// Cargar la direccion
	direccion.sin_family = AF_INET;

	/*hostent *h = gethostbyname("sigua.ua.es");
	unsigned char *addr = reinterpret_cast<unsigned char *>(h->h_addr_list[0]);
	std::copy(addr, addr+4, infix_ostream_iterator<unsigned int>(std::cout, "."));*/

	direccion.sin_addr.s_addr = inet_addr(const_cast<char*>(servidor_ip));
	direccion.sin_port = htons(atoi(servidor_puerto));
	if (connect(s, (struct sockaddr *)&direccion, sizeof (direccion)) == -1){
		fprintf(stderr, "\n\rSYSMSG --> Error. No se puede conectar al servidor\n\r");
		close(s); return 1;
	}
	printf("\n\rSYSMSG --> Conexion establecida\n\r");

	// Paso 3: Enviar mensaje
	n = strlen(mensaje);
	enviados = write(s, mensaje, n);
	if (enviados == -1 || enviados < n){
		fprintf(stderr, "\n\rSYSMSG --> Error enviando el mensaje\n\r");
		close(s); return 1;
	}
	printf("\n\rSYSMSG --> Mensaje enviado\n\r");

	// Paso 4: Recibir respuesta
	n = sizeof(respuesta) - 1;
	recibidos = read(s, respuesta, n);
	if (recibidos == 1){
		fprintf(stderr, "\n\rSYSMSG --> Error recibiendo respuesta\n\r");
		close(s); return 1;
	}
	string cuerpo = leerCuerpo(respuesta);
	//cout<<respuesta<<endl;
	while(respuesta[recibidos-1]!='\n'){
		n = sizeof(respuesta) - 1;
		recibidos = read(s, respuesta, n);
		if (recibidos == 1){
			fprintf(stderr, "\n\rSYSMSG --> Error recibiendo respuesta\n\r");
			close(s); return 1;
		}
		respuesta[recibidos] = '\0';
		cuerpo += respuesta;
		//cout<<respuesta<<endl;
	}

	cuerpo = CorregirJSON(cuerpo);
	SepararJSON(cuerpo, opcion, idEdificio);


	//Crear objeto json
	//Guardar los valores en variables
	//Crear tablas
    
	// Paso 5: Cerrar el socket
	close(s);
	printf("\n\rSYSMSG --> Socket cerrado. Comunicacion finalizada\n\r");

	return 0;
}
