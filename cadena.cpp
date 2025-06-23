#include <iostream>
#include "cstring"
#include "cadena.h"
using namespace std;

Cadena::Cadena(){
}

Cadena::Cadena(const char *t){
    _Texto= t;
}

const char *Cadena::getTexto(){
    return _Texto.c_str();
}

void Cadena::setTexto(const char *t){
    _Texto= t;
}
void Cadena::Concatenar(const char *t){
    _Texto += t;
}
