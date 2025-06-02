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
    ///descripcion=cargar cadena///
}

void Producto::SetMarca(const char *palabra)
{
    ///marca=cargar cadena///
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

int GetIdProducto(){

}

float GetPrecio(){

}

const char *GetDescripcion(){

}

const char *GetMarca(){

}

int GetTipoEquipo(){

}

int GetStock(){

}

