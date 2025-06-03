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

    bool Cliente::SetTipoCliente(int tc){

        if(tc==1||tc==2){
            _TipoCliente= tc;
            return true;
        }else{
            return false;
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
