#include "cabecera.h"
using namespace nlohmann;

void angel(){

    auto j = json::parse("{\"id\":\"00\",\"nombre\":\"CAMPUS DE SAN VICENTE DEL RASPEIG\",\"count_edificios\":47,\"bbox\":\"-0.520911377238477,38.3796107687567,-0.505397344484967,38.3899821866561\"}");
    
    cout<<"hola"<<endl;
    
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
    for(int i=0;i<strlen(temp);i++){
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

void SeleccionMetodo(string frase, int num, bool final){  
	switch(num){
		case 1: //Tratar primer json
			break;
		case 2: //Tratar segundo json
			break;
		case 3:	//Tratar tercer json
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
    
    //Pasamos a char el string que recibimos por parametros
    char temp[frase.size()+1];
    strcpy(temp, frase.c_str());
    
    //Recorremos el char
    for(int i=0; i<strlen(temp);i++){
        //No leemos los corchetes del principio y el final
        if(temp[i]=='[' || temp[i]==']'){}
        //En el caso de final del objeto pasamos el json al método y lo reseteamos para la lectura del siguiente
        else if(temp[i]=='}' && temp[i+1]==',' && temp[i+2]=='{'){
            json += temp[i];
            SeleccionMetodo(json, num, false);
            json = "";
            i++;
        }
	else if(temp[i]=='}' && temp[i+1]==']'){ 
		json += temp[i];
		SeleccionMetodo(json, num, true);	
	}
        //Guardamos el caracter en el json
        else{
            json += temp[i];
        }
    }
}
