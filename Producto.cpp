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

void Producto::SetDescripcion(char *palabra)
{
    _Descripcion.setTexto(palabra);
}

void Producto::SetMarca(char *palabra)
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

void Producto::cargarproducto()
{int id;
float precio;
char descripcion[80];

 cout<<"coloque el id del producto igual o mayor a 0"<<endl;
 cin>>id;
 SetIdProducto(id);
 cout<<"coloque el precio del producto igual o mayor a 100"<<endl;
 cin>>precio;
 SetPrecio(precio);
 cout<<"coloque la descripcion del producto"<<endl;
 cin>>descripcion;
 SetDescripcion(descripcion);

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

