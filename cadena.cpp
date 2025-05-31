#include <iostream>
#include "cstring"
#include "cadena.h"
using namespace std;

Cadena::Cadena(){
texto= {};
}
Cadena::Cadena(const char *t){
    tam = strlen(t);
    texto = new char[tam+1];
    if(texto == nullptr) exit(-1);
    strcpy(texto, t);
}

Cadena::~Cadena(){
    delete[] texto;
}

const char *Cadena::getTexto(){
    return texto;
}

void Cadena::setTexto(const char *t){
    delete[] texto;
    tam = strlen(t);
    texto = new char[tam + 1];
    if(texto == nullptr) exit(-1);
    strcpy(texto, t);
}
void Cadena::Concatenar(const char *t){
    tam += strlen(t);
    char *tex= new char[tam+1];
    strcpy(tex, texto);
    delete[] texto;
    strcat(tex,t);
    texto = tex;
}
