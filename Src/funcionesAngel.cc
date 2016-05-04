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

string CorregirJSON(string frase){
    //Creamos la variable donde guardaremos el json corregido
    string correcion = "";
    //Pasamos el json a char para poder tratarlo mejor en un bucle
    char temp[frase.size()+1];
    strcpy(temp, frase.c_str());
    //Transformamos todas las comillas dobles en \"
    for(size_t i=0;i<strlen(temp);i++){
        //34 --> "
        if(temp[i]==34){
            correcion+="\"";
        }
        else{
            correcion+=temp[i];
        }
    }
    return correcion;
}

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
	for(int i=0;i<57;i++){
		cout<<"-";
	}
	cout<<endl;
	//Linea de informacion
	cout<<"| "<<id<<" | "<<nombre;
	int espacios = 50 - 1 - nombre.size();
	for(int j=0;j<espacios;j++){
		cout<<" ";		
	}
	cout<<"|"<<endl;
	//Linia final de tabla
	if(final){
		for(int i=0;i<57;i++){
			cout<<"-";
		}
		cout<<endl;
	}
}

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
	for(int i=0;i<59;i++){
		cout<<"-";
	}
	cout<<endl;
	//Linea de informacion
	cout<<"| "<<id<<" | "<<nombre;
	int espacios = 50 - 1 - nombre.size();
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

void SeleccionMetodo(string frase, int num, bool final){  
	switch(num){
		case 1: ListaEdificios(frase, final);
			break;
		case 2: //Tratar segundo json
			break;
		case 3:	ListaEdificiosVacios(frase, final);
			break;
		case 4:	//Tratar cuarto json
			break;
		case 5: //Tratar quinto json
			break;
	}
}

void SepararJSON(string frase, int num){
    //Creamos una variable donde guardaremos cada JSON por separado
    string json = "";
    bool leer = false;
    //Pasamos a char el string que recibimos por parametros
    char temp[frase.size()+1];
    strcpy(temp, frase.c_str());
    
    //Recorremos el char
    for(size_t i=0; i<strlen(temp);i++){
        //No leemos los corchetes del principio y el final
        if(temp[i]=='[' || temp[i]==']'){leer = true;}
        //En el caso de final del objeto pasamos el json al método y lo reseteamos para la lectura del siguiente
        else if(temp[i]=='}' && temp[i+1]==',' && temp[i+2]=='{' && leer){
            json += temp[i];
            SeleccionMetodo(json, num, false);
            json = "";
            i++;
        }
	else if(temp[i]=='}' && temp[i+1]==']' && leer){ 
		json += temp[i];
		SeleccionMetodo(json, num, true);	
	}
        //Guardamos el caracter en el json
        else{
		if(leer){
            		json += temp[i];
		}
        }
    }
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
