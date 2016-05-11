#include "cabecera.h"
#include <string.h>
using namespace nlohmann;

void angel(){

    auto j = json::parse("{\"id\":\"{0000,CAMPUS (ZONAS COMUNES)}\",\"superficie\":\"647577.39067068\",\"estancias\":372,\"ocupantes\":0}");
    
    cout<<"hola"<<endl;
	cout<<j.size()<<endl;
    
    for(json::iterator it = j.begin(); it != j.end(); ++it){
        cout << it.key() << " : " << it.value() << endl;
    }

}

void tratarMetodo5(string frase, string idActividad){
	char temp[frase.size()+1];
	strcpy(temp, frase.c_str());
	size_t total = strlen(temp);
	string codigo = "";
	string actividad = "";
	string nombre = "";
	bool cabecera = false;
	for(size_t i = 0; i<total;i++){
		if(temp[i]=='c'&&temp[i+1]=='o'&&temp[i+2]=='d'&&temp[i+3]=='i'&&temp[i+4]=='g'&&temp[i+5]=='o'){
			codigo = "";
			codigo += temp[i+9];
			codigo += temp[i+10];
			codigo += temp[i+11];
			codigo += temp[i+12];
			codigo += temp[i+13];
			codigo += temp[i+14];
			codigo += temp[i+15];
			codigo += temp[i+16];
			codigo += temp[i+17];
		}
		else if(temp[i]=='i'&&temp[i+1]=='d'&&temp[i+2]=='_'&&temp[i+3]=='a'&&temp[i+4]=='c'&&temp[i+5]=='t'&&temp[i+6]=='i'&&temp[i+7]=='v'&&temp[i+8]=='i'&&temp[i+9]=='d'&&temp[i+10]=='a'&&temp[i+11]=='d'){
			actividad = "";
			for(int k=i+14;temp[k]!=',';k++){
				actividad += temp[k];
				i=k;
			}
		}
		else if(temp[i]=='c'&&temp[i+1]=='r'&&temp[i+2]=='u'&&temp[i+3]=='e'){
			nombre = "";
			for(int k=i+7;temp[k]!='"';k++){
				nombre += temp[k];
				i=k;
			}
		}
		else if(temp[i]=='}'&&temp[i+1]==','&&temp[i+2]=='{'){
			if(actividad.compare(idActividad)==0){
				if(!cabecera){
					//CABECERA
					for(int i=0;i<13;i++){
						cout<<"-";
					}
					cout<<endl;
					cout<<"|    I D    |"<<endl;
					cabecera = true;
				}


				for(int i=0;i<13;i++){
					cout<<"-";
				}
				cout<<endl;
				cout<<"| "<<codigo<<" | "<<endl;
			}
		}
		
	}
	if(cabecera){
		for(int i=0;i<13;i++){
			cout<<"-";
		}
		cout<<endl;
	}
}


void PintarCaja(int num){
	switch(num){
		case 1:{ 
			//Linea de separacion 57=1+4+1+50+1
			for(int i=0;i<59;i++){
				cout<<"-";
			}
			cout<<endl;
			cout<<"|  ID  | NOMBRE";
			int espacios = 50 -1 -6;
			for(int j=0;j<espacios;j++){
				cout<<" ";		
			}
			cout<<"|"<<endl;
			break;}
		case 2:{
			//Linea de separacion
			for(int i=0;i<20;i++){
				cout<<"-";
			}
			cout<<endl;
			cout<<"|  ID  | EST | OCU |"<<endl;
			break;}
		case 3:{
			//Linea de separacion 57=1+4+1+50+1
			for(int i=0;i<59;i++){
				cout<<"-";
			}
			cout<<endl;
			cout<<"|  ID  | NOMBRE";
			int espacios = 50 -1 -6;
			for(int j=0;j<espacios;j++){
				cout<<" ";		
			}
			cout<<"|"<<endl;
			break;}
		case 4:{
			//Linea de separacion
			for(int i=0;i<65;i++){
				cout<<"-";
			}
			cout<<endl;
			cout<<"|  ID  | NOMBRE";
			int espacios = 50 -1 -6;
			for(int j=0;j<espacios;j++){
				cout<<" ";		
			}
			cout<<"|  N  |"<<endl;
			break;}
		case 5:{
			break;}
	}
}

int ContadorCaracteres(string frase){
	char temp[frase.size()+1];
	strcpy(temp, frase.c_str());
	int h=0;
	for(size_t i=0;i<strlen(temp);i++){
		if((temp[i]<32 || temp[i]>126)){
		h++;}
	}
	return h/2;
}

string ArreglarId(string frase){
	string id = "";
	bool guardado = false;
	char temp[frase.size()+1];
	strcpy(temp, frase.c_str());
	for(size_t i=0; i<strlen(temp) && !guardado;i++){
		if(temp[i]>=48 && temp[i]<=57 && temp[i+1]>=48 && temp[i+1]<=57){
			id+=temp[i];		
		}
		else if(temp[i]>=48 && temp[i]<=57 && !(temp[i+1]>=48 && temp[i+1]<=57)){
			id += temp[i];
			guardado = true;
		}
	}

	return id;
}

string ArreglarNombre(string frase){
	string nombre = "";
	bool guardado = false;
	char temp[frase.size()+1];
	strcpy(temp, frase.c_str());
	for(size_t i=0; i<strlen(temp);i++){
		if(temp[i]>=65 && temp[i]<=90){
			guardado = true;
		}
		if(guardado){
			if(temp[i]!=92 && temp[i]!=34 && temp[i]!='}'){
				nombre += temp[i];
			}
		}
	}
	return nombre;
}

//PETICION 1
void ListaEdificios(string frase, bool final){
	auto j = json::parse(frase);
	string id = "";
	string nombre = "";
	//Guardo los valores en variables
	for(json::iterator it = j.begin(); it != j.end(); ++it){
		if(it.key().compare("id")==0){
			id = it.value();
		}
		else if(it.key().compare("nombre")==0){
			nombre = it.value();
		}
	}
	//Linea de separacion 57=1+4+1+50+1
	for(int i=0;i<58;i++){
		cout<<"-";
	}
	cout<<endl;
	//Linea de informacion
	cout<<"| "<<id<<" | "<<nombre;
	int espacios = 50 - 1 - nombre.size()+ContadorCaracteres(nombre);
	for(int j=0;j<espacios;j++){
		cout<<" ";		
	}
	cout<<"|"<<endl;
	//Linia final de tabla
	if(final){
		for(int i=0;i<59;i++){
			cout<<"-";
		}
		cout<<endl;
	}
}

//PETICION 3
void ListaEdificiosVacios(string frase, bool final){
	
	auto j = json::parse(frase);
	string id = "";
	string nombre = "";
	//Guardo los valores en variables
	for(json::iterator it = j.begin(); it != j.end(); ++it){
		if(it.key().compare("id")==0){
			id = it.value();
		}
		else if(it.key().compare("nombre")==0){
			nombre = it.value();
		}
	}
	//Linea de separacion 59=1+6+1+50+1
	for(int i=0;i<58;i++){
		cout<<"-";
	}
	cout<<endl;
	//Linea de informacion
	cout<<"| "<<id<<" | "<<nombre;
	int espacios = 50 - 1 - nombre.size() + ContadorCaracteres(nombre);
	for(int j=0;j<espacios;j++){
		cout<<" ";
	}
	cout<<"|"<<endl;
	//Linia final de tabla
	if(final){
		for(int i=0;i<59;i++){
			cout<<"-";
		}
		cout<<endl;
	}
}

string itoa(int num){
	stringstream s;
	s<<num;
	return s.str();
}

//PETICION 2
void EstanciasOcupantesEdificio(string frase, bool final){
	auto j = json::parse(frase);
	string id = "";
	string estancias = "";
	string ocupantes = "";
	for(json::iterator it = j.begin(); it != j.end(); ++it){
		if(it.key().compare("id")==0){
			id = it.value();
		}
		if(it.key().compare("ocupantes")==0){
			ocupantes = itoa(it.value());
		}
		if(it.key().compare("estancias")==0){
			estancias = itoa(it.value());
		}
	}
	
	//Arreglar id
	id = ArreglarId(id);
	//LInea de separacion 1 + 6 + 1 + 5 + 1 + 5 + 1 = 30
	for(int i = 0;i<20;i++){
		cout<<"-";
	}
	cout<<endl;
	//Linea de informacion
	cout<<"| "<<id<<" | "<<estancias;
	if(estancias.size()==2){cout<<" ";}
	else if(estancias.size()==1){cout<<"  ";}
	cout<<" | "<<ocupantes;
	if(ocupantes.size()==2){cout<<" ";}
	else if(ocupantes.size()==1){cout<<"  ";}
	cout<<" |"<<endl;
	//Linea final
	if(final){
		for(int i=0;i<20;i++){
			cout<<"-";
		}
		cout<<endl;
	}
}
//PETICION 4
bool EstanciaPorEdificio(string frase, string edificio){

	bool toRET = false;

    auto j = json::parse(frase);
    string id = "";
    string nombre = "";
    string estancias = "";
    for(json::iterator it = j.begin(); it != j.end(); ++it){
        if(it.key().compare("id")==0){
            id = it.value();
        }
        if(it.key().compare("estancias")==0){
            estancias = itoa(it.value());
        }
    }
    nombre = ArreglarNombre(id);
    id = ArreglarId(id);
    if(id.compare(edificio)==0){

	toRET = true;
	PintarCaja(4);
        //Linea Superior
        for(int i=0;i<65;i++){
            cout<<"-";
        }
        cout<<endl;
        cout<<"| "<<id<<" | "<<nombre;
        int espacios = 50 - 1 - nombre.size() + ContadorCaracteres(nombre);
        for(int j=0;j<espacios;j++){
            cout<<" ";
        }
        cout<<"| "<<estancias<<" |"<<endl;
        //Linea Inferior
        for(int i=0;i<65;i++){
            cout<<"-";
        }
        cout<<endl;
    }
	return(toRET);
}

bool SeleccionMetodo(string frase, int num, bool final, string edificio){

	bool toRET = false;

	switch(num){
		case 1: ListaEdificios(frase, final);
			toRET = true;
			break;
		case 2: EstanciasOcupantesEdificio(frase, final);
			toRET = true;
			break;
		case 3:	ListaEdificiosVacios(frase, final);
			toRET = true;
			break;
		case 4:	toRET = EstanciaPorEdificio(frase, edificio);
			break;
		case 5: //Tratar quinto json
			toRET = true;
			break;
	}

	return(toRET);

}

void SepararJSON(string frase, int num, string edificio){
	bool edificioEncontrado = false;
	if(num != 4)PintarCaja(num);
    //Creamos una variable donde guardaremos cada JSON por separado
    string json = "";
    bool leer = false;
    //Pasamos a char el string que recibimos por parametros
    char temp[frase.size()+1];
    strcpy(temp, frase.c_str());
    
    //Recorremos el char
    for(size_t i=0; i<strlen(temp) && !edificioEncontrado;i++){
        //No leemos los corchetes del principio y el final
        if(temp[i]=='[' || temp[i]==']'){leer = true;}
        //En el caso de final del objeto pasamos el json al método y lo reseteamos para la lectura del siguiente
        else if(temp[i]=='}' && temp[i+1]==',' && temp[i+2]=='{' && leer){
            json += temp[i];
            edificioEncontrado = SeleccionMetodo(json, num, false, edificio);
            json = "";
            i++;
        }
	else if(temp[i]=='}' && temp[i+1]==']' && leer){ 
		json += temp[i];
		edificioEncontrado = SeleccionMetodo(json, num, true, edificio);
	}
        //Guardamos el caracter en el json
        else{
		if(leer){
            		json += temp[i];
		}
        }
    }
    if(!edificioEncontrado) cout<<"SYSMSG --> Edificio no encontrado, por favor asegurese de que el eficicio es correcto."<<endl;
}

string leerCuerpo(char mensaje[]){
	string cuerpo = "";
	bool fin = false;
	for(size_t i=0; i<strlen(mensaje); i++){
		//Lee el cuerpo
		if(fin){
			if(mensaje[i]!=13 && mensaje[i]!=10){
				cuerpo+=mensaje[i];
			}
		}
		//Le primera linea y cabeceras
		else{
			//Doble salto de linea, donde empieza el cuerpo
			if((mensaje[i]==13 || mensaje[i]==10) && (mensaje[i+1]==13 || mensaje[i+1]==10) && ((mensaje[i+2]==13 || mensaje[i+2]==10))){
				fin = true;
			}
		}	
	}
	return cuerpo;
}
