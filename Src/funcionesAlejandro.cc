#include "cabecera.h"

// recupera todos los edificios
string pedirEdificios() {
    return "GET /api/pub/edificio/all/items"+peticion();
}

// recupera un edificio especifico
string pedirEdificioEspecifico(string edificio) {
    return "GET /api/pub/estancia/edificio/"+edificio+peticion();
}

// recupera las estancias de un edificio especifico
string pedirEstanciasEdificio(string edificio) {
    return "GET /api/pub/estancia/edificio/"+edificio+"/items"+peticion();
}

// recupera los edificios que contienen despachos vacios
string pedirEdificiosSinOcupantes() {
    return "GET /api/pub/edificio/despachos_vacios/items"+peticion();
}
    
// recupera el numero de estancias y ocupantes por edificio
string pedirEstanciasOcupantesEdificio() {
    return "GET /api/agregados/seo/edificio/all/items"+peticion();
}

// devuelve los valores comunes a todas las peticiones
string peticion() {
    return " HTTP/1.1\r\nHost: 193.145.231.149:80\r\nUser-Agent: Mozilla/5.0 (Windows NT 10.0; WOW64; rv:45.0) Gecko/20100101 Firefox/45.0\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\nAccept-Encoding: gzip, deflate\r\nConnection: keep-alive";
}
