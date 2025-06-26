#include <iostream>
#include "cstring"
#include <limits>///libreria que utiliza el limpiador de buffer///
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
            cin>>num;
            a=true;
        }
        else
        {
            a=false;
            _IdProducto=num;
        }
    }
}

    void Producto::SetNombreProducto(char *nombre){

        _NombreProducto.setTexto(nombre);
    }

void Producto::SetPrecio(float num)
{
    bool a=true;
    while(a==true)
    {
        if(num<100)
        {
            cout<<"el precio tiene que ser minimo 100 por favor vuelva a cargar el precio"<<endl;
            cin>>num;
            a=true;
        }
        else
        {
            a=false;
            _Precio=num;
        }
    }
}

    void Producto::SetDescripcion(char *descripcion){

        strncpy(_Descripcion,descripcion, 499);
        _Descripcion[499]= '\0';
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
        if(num<0||num>10)
        {
            cout<<"el tipo de equipo tiene que ser entre 1 y 10"<<endl;
            cin>>num;
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
        if(num<0)
        {
            cout<<"el stock no puede ser menor a 0"<<endl;
            cin>>num;
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

    const char *Producto::GetNombreProducto(){

        return _NombreProducto.getTexto();
    }

    float Producto::GetPrecio(){

        return _Precio;
    }

    const char *Producto::GetDescripcion(){

        return _Descripcion;
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

    bool Producto::GetEstado(){

        return _Estado;
    }

///--------------------------------------------------------------------------------------------------

void Producto::CargarProducto()
{
int id,tipo,stock;
float precio;
char nombre[50]{},descripcion[500]{}, marca[20]{};

 cout<<"Ingrese el id del producto o equipo igual o mayor a 0: ";
 cin>>id;
 SetIdProducto(id);
 cout<<endl;
 cin.ignore(numeric_limits<streamsize>::max(), '\n');///limpiador del buffer///
 cout << "Ingrese nombre del producto: " << endl;
 cin.getline(nombre, 50);
 SetNombreProducto(nombre);
 cout<<"Ingrese el precio del producto tienen que ser igual o mayor a 100: ";
 cin>>precio;
 SetPrecio(precio);
 cout<<endl;
 cin.ignore(numeric_limits<streamsize>::max(), '\n');///limpiador del buffer///
 cout<<"Ingrese la descripcion del producto o equipo: ";
 cin.getline(descripcion,500);
 SetDescripcion(descripcion);
 cout<<endl;
 cout<<"Ingrese la marca a la que pertenece el producto: ";
 cin.getline(marca,20);
 SetMarca(marca);
 cout<<endl;
 cout<<"Ingrese el tipo de producto: ";
 cin>>tipo;
 SetTipoEquipo(tipo);
 cout<<endl;
 cout<<"Ingrese el stock del producto: ";
 cin>>stock;
 SetStock(stock);
 cout<<endl;
}

void Producto::MostrarProducto()
{
 cout<<"El id del producto o equipo es: "<<GetIdProducto()<<endl;
 cout<<"El precio del producto o equipo es: $"<<GetPrecio()<<endl;
 cout<<"La descripcion del producto o equipo: "<<GetDescripcion()<<endl;
 cout<<"La marca a la que pertenece el producto o equipo: "<<GetMarca()<<endl;
 if(GetTipoEquipo()==1)
{
 cout<<"El tipo es un Producto"<<endl;
}
else
{
 cout<<"El tipo es un Equipo"<<endl;
}
 cout<<"La cantidad de stock del equipo o producto: "<<GetStock()<<endl;
}


