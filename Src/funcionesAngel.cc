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

void EstanciaPorEdificio(string frase, string edificio){
    auto j = json::parse(frase);
    string id = "";
    string nombre = "";
    string estancias = "";
    for(json::iterator it = j.begin(); it != j.end(); ++it){
        if(it.key().compare("id")==0){
            id = it.value();
        }
        if(it.key().compare("nombre")==0){
            nombre = itoa(it.value());
        }
        if(it.key().compare("estancias")==0){
            estancias = itoa(it.value());
        }
    }
    id = ArreglarId(id);
    if(id.compare(edificio)==0){
        //Linea Superior
        for(int i=0;i<50;i++){
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
        for(int i=0;i<50;i++){
            cout<<"-";
        }
        cout<<endl;
    }
}

void SeleccionMetodo(string frase, int num, bool final, string edificio){
	switch(num){
		case 1: ListaEdificios(frase, final);
			break;
		case 2: EstanciasOcupantesEdificio(frase, final);
			break;
		case 3:	ListaEdificiosVacios(frase, final);
			break;
        case 4:	EstanciaPorEdificio(frase, edificio);
			break;
		case 5: //Tratar quinto json
			break;
	}
}

void SepararJSON(string frase, int num, string edificio){
	PintarCaja(num);
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
            SeleccionMetodo(json, num, false, edificio);
            json = "";
            i++;
        }
	else if(temp[i]=='}' && temp[i+1]==']' && leer){ 
		json += temp[i];
		SeleccionMetodo(json, num, true, edificio);
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
