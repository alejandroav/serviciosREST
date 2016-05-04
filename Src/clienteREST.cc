#include "cabecera.h"

int main (int argc, char *argv[]) {
	
	char *servidor_ip;
	char *servidor_puerto;
	char *mensaje, respuesta[1024];
	struct sockaddr_in direccion;
	int s;
	int n, enviados, recibidos;

	// Comprobar los argumentos y tomarlos
	int opcion = manageArguments(argc, argv);

	switch(opcion){
		case (1):{ break; }
		case (2):{ break; }
		case (3):{ break; }
		case (4):{ break; }
		case (5):{ break; }
		default: { break; }
	}
	
	string ip = "193.145.231.149";
	servidor_ip = const_cast<char*>(ip.c_str());
	string puerto = "80";
	servidor_puerto = const_cast<char*>(puerto.c_str());

	string missatge = pedirEdificiosSinOcupantes();
	mensaje = const_cast<char*>(missatge.c_str());
	
    
	printf("\n\rEnviar mensaje \"%s\" a %s:%s...\n\r\n\r", mensaje, servidor_ip, servidor_puerto);

	// Paso 1: Abrir el socket

	s = socket(AF_INET, SOCK_STREAM, 0); // Creo el socket
	if (s == -1)
	{
		fprintf(stderr, "Error. No se puede abrir el socket\n\r");
		return 1;
	}
	printf("Socket abierto\n\r");

	// Paso 2: Conectar al servidor		

	// Cargar la direccion
	direccion.sin_family = AF_INET; // socket familia INET
	direccion.sin_addr.s_addr = inet_addr(servidor_ip);
	direccion.sin_port = htons(atoi(servidor_puerto));
	if (connect(s, (struct sockaddr *)&direccion, 	sizeof (direccion)) == -1)
	{
		fprintf(stderr, "Error. No se puede conectar al servidor\n\r");
		close(s);
		return 1;
	}
	printf("Conexion establecida\n\r");

	// Paso 3: Enviar mensaje

	n = strlen(mensaje);
	enviados = write(s, mensaje, n);
	if (enviados == -1 || enviados < n)
	{
		fprintf(stderr, "Error enviando el mensaje\n\r");
		close(s);
		return 1;
	}

	printf("Mensaje enviado\n\r");

	// Paso 4: Recibir respuesta

	n = sizeof(respuesta) - 1;
	recibidos = read(s, respuesta, n);
	if (recibidos == 1)
	{
		fprintf(stderr, "Error recibiendo respuesta\n\r");
		close(s);
		return 1;
	}
	respuesta[recibidos] = '\0';
	string cuerpo = leerCuerpo(respuesta);
	cout<<"Respuesta: "<<cuerpo<<endl;
	cuerpo = CorregirJSON(cuerpo);
	SepararJSON(cuerpo, 1);


    //Crear objeto json
    //Guardar los valores en variables
    //Crear tablas
    
	// Paso 5: Cerrar el socket
	close(s);
	printf("Socket cerrado. Comunicacion finalizada\n\r");

	return 0;
}
