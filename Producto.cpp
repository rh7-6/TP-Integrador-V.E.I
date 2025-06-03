#include <iostream>
using namespace std;
#include "Producto.h"

void Producto::SetIdProducto(int num)
{
    bool a=true;
    while(a==true)
    {
        if(num<=0)
        {
            cout<<"el numero tiene que ser mayor o igual a 0 por favor vuelva a cargar el numero"<<endl;
            a=true;
        }
        else
        {
            a=false;
            _IdProducto=num;
        }
    }
}

void Producto::SetPrecio(float num)
{
    bool a=true;
    while(a==true)
    {
        if(num<=100)
        {
            cout<<"el precio tiene que ser minimo 100 por favor vuelva a cargar el precio"<<endl;
            a=true;
        }
        else
        {
            a=false;
            _Precio=num;
        }
    }
}

void Producto::SetDescripcion(const char *palabra)
{
    _Descripcion.setTexto(palabra);
}

void Producto::SetMarca(const char *palabra)
{
    _Marca.setTexto(palabra);
}

void Producto::SetTipoEquipo(int num)
{
  bool a=true;
    while(a==true)
    {
        if(num==1||num==2)
        {
            cout<<"el tipo de equipo tiene que ser de 1-productos o 2-equipos"<<endl;
            a=true;
        }
        else
        {
            a=false;
            _TipoEquipo=num;
        }
    }
}

void Producto::SetStock(int num)
{
    bool a=true;
    while(a==true)
    {
        if(num<=0)
        {
            cout<<"el stock no puede ser menor a 0"<<endl;
            a=true;
        }
        else
        {
            a=false;
            _Stock=num;
        }
    }
}

///--------------------------------------------------------------------------------------------------

int Producto::GetIdProducto(){

    return _IdProducto;

}

float Producto::GetPrecio(){

    return _Precio;

}

const char *Producto::GetDescripcion(){

    return _Descripcion.getTexto();

}

const char *Producto::GetMarca(){

    return _Marca.getTexto();

}

int Producto::GetTipoEquipo(){

    return _TipoEquipo;

}

int Producto::GetStock(){

    return _Stock;

}

