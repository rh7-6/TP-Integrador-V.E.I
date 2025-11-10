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
    _Localidad.setTexto(Localidad);
}

///--------------------------------------------------------------------------------------------------

void Direccion::CargarDireccion()
{
int piso=0;
char *calle= new char[31], *altura= new char[31], *localidad= new char[31];

cout<<"Ingrese la calle del cliente: ";
cin.getline(calle, 31);
SetCalle(calle);
cout<<endl;

cout<<"Ingrese la altura del cliente: ";
cin.getline(altura, 31);
SetAltura(altura);
cout<<endl;

cout<<"Ingrese el piso del cliente: ";
cin>>piso;
SetPiso(piso);
cout<<endl;

cout<<"Ingrese la localidad del cliente: ";
cin.getline(localidad, 31);
SetLocalidad(localidad);
cout<<endl;

cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Direccion::MostrarDireccion()
{

  cout<<"Calle del cliente: "<<GetCalle()<<endl;
  cout<<"Altura del cliente: "<<GetAltura()<<endl;
  cout<<"Piso del cliente: "<<GetPiso()<<endl;
  cout<<"Localidad del cliente: "<<GetLocalidad()<<endl;

}
