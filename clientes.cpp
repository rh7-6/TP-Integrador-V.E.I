#include <iostream>
#include "cstring"
#include "cadena.h"
#include "Clientes.h"
#include "Archivo_Clientes.h"
#include <limits>
using namespace std;

    void Cliente::SetNumeroDeCliente(int tc){

        _NumeroDeCliente=tc;

    }

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

/// incluir funciones para setear direccion

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

    void Cliente::SetEstado(bool estado){
        _Estado=estado;
    }

///--------------------------------------------------------------------------------------------------
    int Cliente::GetNumeroDeCliente(){

        return _NumeroDeCliente;

    }

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


    int Cliente::GetTipoCliente(){

        return _TipoCliente;

    }

    bool Cliente::GetEstado(){

        return _Estado;
    }

    Cliente::Cliente(){
        _NumeroDeCliente=1;
        _Cuit.setTexto("");
        _Nombre.setTexto("");
        _Apellido.setTexto("");
        _Telefono.setTexto("");
        _Mail.setTexto("");
        //_Direccion.setTexto(""); no olvidarse de seteralo vacio
        _TipoCliente=1;
        _Estado=true;
    }
    Cliente::Cliente(int NumeroDeCliente, const char *CUIT, const char *nombre, const char *apellido, const char *telefono, const char *mail, const char *direccion, int tipoCliente, bool estado){

        _NumeroDeCliente=NumeroDeCliente;
        _Cuit.setTexto(CUIT);
        _Nombre.setTexto(nombre);
        _Apellido.setTexto(apellido);
        _Telefono.setTexto(telefono);
        _Mail.setTexto(mail);
        //_Direccion.setTexto(direccion); yamentiende
        _TipoCliente=tipoCliente;
        _Estado=estado;
    }

///--------------------------------------------------------------------------------------------------

void Cliente::CargarCliente(){
ArchivoClientes arch("Clientes.dat");
int tc,NumeroDeCliente=1;
bool bandera=true;
char *cuil= new char[31], *nombre= new char[31], *apellido= new char[31], *telefono= new char[31], *mail=new char[31], *direccion= new char[31];

do{
if(arch.BuscarCliente(NumeroDeCliente)==-2)
{
 SetNumeroDeCliente(NumeroDeCliente);
 bandera=false;
}
else
{
if(arch.BuscarCliente(NumeroDeCliente)==-1)
    {
     SetNumeroDeCliente(1);
     bandera=false;
    }
    else
    {
     NumeroDeCliente++;
    }
}

}while(bandera==true);




cout<<"Ingrese el cuit del cliente: ";
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
//SetDireccion(direccion); ---------------------- y aca
cout<<endl;
cout<<"ingrese el tipo de cliente 1-particular o 2-empresa: ";
cin>>tc;
SetTipoCliente(tc);
cout<<endl;
cin.ignore(numeric_limits<streamsize>::max(), '\n');
delete[] cuil; delete[] nombre; delete[] apellido; delete[] telefono; delete[] mail; delete[] direccion;
}

void Cliente::MostrarCliente(){
cout<<"Cuil del cliente: "<<GetCuit()<<endl;
cout<<"Nombre del cliente: "<<GetNombre()<<endl;
cout<<"Apellido del cliente: "<<GetApellido()<<endl;
cout<<"Telefono del cliente: "<<GetTelefono()<<endl;
cout<<"Mail del cliente: "<<GetMail()<<endl;
//cout<<"Direccion del cliente: "<<GetDireccion()<<endl; -------- tambien aca
if(GetTipoCliente()==1)
{
cout<<"tipo de cliente Particular"<<endl;
}
else
{
cout<<"tipo de cliente Empresa"<<endl;
}
}




