#include "cabecera.h"

// recupera todos los edificios
string pedirEdificios() {
    return
    "GET /api/pub/edificio/all/items HTTP/1.1\r\n" +
    "Host: 193.145.231.149:80\r\n" +
    "User-Agent: Mozilla/5.0 (Windows NT 10.0; WOW64; rv:45.0) Gecko/20100101 Firefox/45.0\r\n" +
    "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\n" +
    "Accept-Encoding: gzip, deflate\r\n" +
    "Connection: keep-alive";
}

// recupera un edificio especifico
string pedirEdificioEspecifico(string edificio) {
    return
    "GET /api/pub/estancia/edificio/"+edificio+" HTTP/1.1\r\n" +
    "Host: 193.145.231.149:80\r\n" +
    "User-Agent: Mozilla/5.0 (Windows NT 10.0; WOW64; rv:45.0) Gecko/20100101 Firefox/45.0\r\n" +
    "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\n" +
    "Accept-Encoding: gzip, deflate\r\n" +
    "Connection: keep-alive";
}

// recupera las estancias de un edificio especifico
string pedirEstanciasEdificio(string edificio) {
    return
    "GET /api/pub/estancia/edificio/"+edificio+"/items HTTP/1.1\r\n" +
    "Host: 193.145.231.149:80\r\n" +
    "User-Agent: Mozilla/5.0 (Windows NT 10.0; WOW64; rv:45.0) Gecko/20100101 Firefox/45.0\r\n" +
    "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\n" +
    "Accept-Encoding: gzip, deflate\r\n" +
    "Connection: keep-alive";
}

// recupera los edificios que contienen despachos vacios
string pedirEdificiosSinOcupantes() {
    return
    "GET /api/pub/edificio/despachos_vacios/items HTTP/1.1\r\n" +
    "Host: 193.145.231.149:80\r\n" +
    "User-Agent: Mozilla/5.0 (Windows NT 10.0; WOW64; rv:45.0) Gecko/20100101 Firefox/45.0\r\n" +
    "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\n" +
    "Accept-Encoding: gzip, deflate\r\n" +
    "Connection: keep-alive";
}

// recupera el numero de estancias y ocupantes por edificio
string pedirEstanciasOcupantesEdificio() {
    return
    "GET /api/agregados/seo/edificio/all/items HTTP/1.1\r\n" +
    "Host: 193.145.231.149:80\r\n" +
    "User-Agent: Mozilla/5.0 (Windows NT 10.0; WOW64; rv:45.0) Gecko/20100101 Firefox/45.0\r\n" +
    "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\n" +
    "Accept-Encoding: gzip, deflate\r\n" +
    "Connection: keep-alive";
}