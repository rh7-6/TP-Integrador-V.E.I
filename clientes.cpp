#include <iostream>
#include <string>
#include "cadena.h"
#include "Clientes.h"
using namespace std;

    void Cliente::SetCuil(const char *t){

        _Cuit.setTexto(t);

    }

    void Cliente::SetNombre(const char *t){

        _Nombre.setTexto(t);

    }

    void Cliente::SetApellido(const char *t){

        _Apellido.setTexto(t);

    }

    void Cliente::SetTelefono(const char *t){

        _Telefono.setTexto(t);

    }

    void Cliente::SetMail(const char *t){

        _Mail.setTexto(t);

    }

    void Cliente::SetDireccion(const char *t){

        _Direccion.setTexto(t);

    }

    void Cliente::SetTipoCliente(int tc){
        bool a=false;
        while(a==false)
        {
            if(tc==1||tc==2)
            {
            _TipoCliente= tc;
            a=true;
            }
            else
            {
            cout<<"por favor ingrese una de las dos opciones correspondientes";
            cout<<endl;
            cout<<"1-particular o 2-empresa: ";
            cin>>tc;
            cout<<endl;
             a=false;
            }
        }
    }

///--------------------------------------------------------------------------------------------------

    const char *Cliente::GetCuil(){

        return _Cuit.getTexto();

    }

    const char *Cliente::GetNombre(){

        return _Nombre.getTexto();

    }

    const char *Cliente::GetApellido(){

        return _Apellido.getTexto();

    }

    const char *Cliente::GetTelefono(){

        return _Telefono.getTexto();

    }

    const char *Cliente::GetMail(){

        return _Mail.getTexto();

    }

    const char *Cliente::GetDireccion(){

        return _Direccion.getTexto();

    }

    int Cliente::GetTipoCliente(){

        return _TipoCliente;

    }

    Cliente::Cliente(){
        _Cuit.setTexto("");
        _Nombre.setTexto("");
        _Apellido.setTexto("");
        _Telefono.setTexto("");
        _Mail.setTexto("");
        _Direccion.setTexto("");
        _TipoCliente=1;
        _Estado=true;
    }
    Cliente::Cliente(const char *CUIT, const char *nombre, const char *apellido, const char *telefono, const char *mail, const char *direccion, int tipoCliente, bool estado){
        _Cuit.setTexto(CUIT);
        _Nombre.setTexto(nombre);
        _Apellido.setTexto(apellido);
        _Telefono.setTexto(telefono);
        _Mail.setTexto(mail);
        _Direccion.setTexto(direccion);
        _TipoCliente=tipoCliente;
        _Estado=estado;
    }

///--------------------------------------------------------------------------------------------------

void Cliente::CargarCliente(){
int tc;
char *cuil= new char[31], *nombre= new char[31], *apellido= new char[31], *telefono= new char[31], *mail=new char[31], *direccion=new char[31];

cout<<"Ingrese el cuil del cliente: ";
cin.getline(cuil, 31);
SetCuil(cuil);
cout<<endl;
cout<<"Ingrese el nombre del cliente: ";
cin.getline(nombre, 31);
SetNombre(nombre);
cout<<endl;
cout<<"Ingrese el apellido del cliente: ";
cin.getline(apellido, 31);
SetApellido(apellido);
cout<<endl;
cout<<"Ingrese el telefono del cliente: ";
cin.getline(telefono, 31);
SetTelefono(telefono);
cout<<endl;
cout<<"Ingrese el mail del cliente: ";
cin.getline(mail, 31);
SetMail(mail);
cout<<endl;
cout<<"Ingrese la direccion del cliente: ";
cin.getline(direccion, 31);
SetDireccion(direccion);
cout<<endl;
cout<<"ingrese el tipo de cliente 1-particular o 2-empresa: ";
cin>>tc;
SetTipoCliente(tc);
cout<<endl;
delete[] cuil; delete[] nombre; delete[] apellido; delete[] telefono; delete[] mail; delete[] direccion;
}

void Cliente::MostrarCliente(){
cout<<"Cuil del cliente: "<<GetCuil()<<endl;
cout<<"Nombre del cliente: "<<GetNombre()<<endl;
cout<<"Apellido del cliente: "<<GetApellido()<<endl;
cout<<"Telefono del cliente: "<<GetTelefono()<<endl;
cout<<"Mail del cliente: "<<GetMail()<<endl;
cout<<"Direccion del cliente: "<<GetDireccion()<<endl;
if(GetTipoCliente()==1)
{
cout<<"tipo de cliente Particular"<<endl;
}
else
{
cout<<"tipo de cliente Empresa"<<endl;
}
}




