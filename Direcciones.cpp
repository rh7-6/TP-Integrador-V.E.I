#include <iostream>
#include "cstring"
#include "Direcciones.h"
#include <limits>
using namespace std;

void Direccion::SetCalle(const char *t){

        _Calle.setTexto(t);

}

void Direccion::SetAltura(int tc){

        _Altura=tc;

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

int Direccion::GetAltura(){
    return _Altura;
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
        _Altura=0;
        _Piso=0;
        _Localidad.setTexto("");
}

Direccion::Direccion(const char *Calle, int Altura, int Piso, const char *Localidad){

    _Calle.setTexto(Calle);
    _Altura=Altura;
    _Piso=Piso;
    _Localidad.setTexto(Localidad);
}

///--------------------------------------------------------------------------------------------------

void Direccion::CargarDireccion()
{
int piso=0, altura=0;
char *calle= new char[31], *localidad= new char[31];

cout<<"Ingrese la calle del cliente: ";
cin.getline(calle, 31);
SetCalle(calle);
cout<<endl;

cout<<"Ingrese la altura del cliente: ";
cin>>altura;
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
