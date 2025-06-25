#include <iostream>
#include <cstring>
#include "cadena.h"
using namespace std;

Cadena::Cadena(){
    _Texto[0]= '\0';
}

Cadena::Cadena(const char *t){
    strncpy(_Texto,t, tam-1);
    _Texto[tam-1]= '\0';
}

const char *Cadena::getTexto(){
    return _Texto;
}

void Cadena::setTexto(const char *t){
    strncpy(_Texto,t, tam-1);
    _Texto[tam-1]= '\0';
}
