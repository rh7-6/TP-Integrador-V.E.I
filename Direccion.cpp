#include <iostream>
#include "cstring"
#include "cadena.h"
#include "Direccion.h"
#include <limits>
using namespace std;

void Direccion::SetCalle(const char *t){

        _Calle.setTexto(t);

}

void Direccion::SetAltura(const char *t){

        _Altura.setTexto(t);

}

void Direccion::SetPiso(int tc){

        _Piso=tc;

}

void Direccion::SetLocalidad(const char *t){

        _Localidad.setTexto(t);

}

///--------------------------------------------------------------------------------------------------

const char *Direccion::GetCalle(){
    return _Calle.getTexto();
}

const char *Direccion::GetAltura(){
    return _Altura.getTexto();
}

int Direccion::GetPiso(){

        return _Piso;

}

const char *Direccion::GetLocalidad(){
    return _Localidad.getTexto();
}

///--------------------------------------------------------------------------------------------------

Direccion::Direccion(){
        _Calle.setTexto("");
        _Altura.setTexto("");
        _Piso=0;
        _Localidad.setTexto("");
}

Direccion::Direccion(const char *Calle, const char *Altura, int Piso, const char *Localidad){

    _Calle.setTexto(Calle);
    _Altura.setTexto(Altura);
    _Piso=Piso;
//    _Localida.setTexto(Localidad);
}

///--------------------------------------------------------------------------------------------------




