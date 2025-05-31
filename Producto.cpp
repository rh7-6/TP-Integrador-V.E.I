#include <iostream>
using namespace std;
#include "Producto.h"

void Producto::set_numero_de_producto(int num)
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
            numero_de_producto=a;
        }
    }
}

void Producto::set_precio(float num)
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
            precio=a;
        }
    }
}

void Producto::set_descripcion(const char palabra)
{
    ///descripcion=cargar cadena///
}

void Producto::set_marca(const char palabra)
{
    ///marca=cargar cadena///
}

void Producto::set_tipo_de_equipo(int num)
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
            precio=a;
        }
    }
}

void Producto::set_stock(int num)
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
            precio=a;
        }
    }
}
