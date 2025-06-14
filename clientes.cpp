#include <iostream>
#include "cadena.h"
#include "Clientes.h"
using namespace std;

    void Cliente::SetCuit(const char *t){

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

    const char *Cliente::GetCuit(){

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

///--------------------------------------------------------------------------------------------------

void Cliente::CargarCliente(){
int tc;
char cuil[20],nombre[10],apellido[15],telefono[20],mail[30],direccion[30];
cout<<"Ingrese el cuil del cliente: ";
cin>>cuil;
SetCuit(cuil);
cout<<endl;
cout<<"Ingrese el nombre del cliente: ";
cin>>nombre;
SetNombre(nombre);
cout<<endl;
cout<<"Ingrese el apellido del cliente: ";
cin>>apellido;
SetApellido(apellido);
cout<<endl;
cout<<"Ingrese el telefono del cliente: ";
cin>>telefono;
SetTelefono(telefono);
cout<<endl;
cout<<"Ingrese el mail del cliente: ";
cin>>mail;
SetMail(mail);
cout<<endl;
cout<<"Ingrese la direccion del cliente: ";
cin>>direccion;
SetDireccion(direccion);
cout<<endl;
cout<<"ingrese el tipo de cliente 1-particular o 2-empresa: ";
cin>>tc;
SetTipoCliente(tc);
cout<<endl;
}

//void cli




