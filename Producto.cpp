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

    void Producto::SetEstado(bool estado){
        _Estado=estado;
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

    Producto::Producto(){}

    Producto::Producto(int id, char *nombre, float precio, char *descripcion, char *marca, int tipo, int stock, bool estado){

        _IdProducto=id;
        _NombreProducto.setTexto(nombre);
        _Precio=precio;
        SetDescripcion(descripcion);
        _Marca.setTexto(marca);
        _TipoEquipo=tipo;
        _Stock=stock;
        _Estado=estado;
    }

///--------------------------------------------------------------------------------------------------

void Producto::CargarProducto()
{
int id,tipo,stock;
float precio;
char nombre[50]{},descripcion[500]{}, marca[20]{};
bool estado;

 cout<<"Ingrese el id del producto o equipo igual o mayor a 0: ";
 cin>>id;
 SetIdProducto(id);
 cout<<endl;
 cin.ignore(numeric_limits<streamsize>::max(), '\n');///limpiador del buffer///
 cout << "Ingrese nombre del producto: ";
 cin.getline(nombre, 50);
 SetNombreProducto(nombre);
 cout << endl;
 cout<<"Ingrese el precio del producto tienen que ser igual o mayor a 100: ";
 cin>>precio;
 SetPrecio(precio);
 cout<<endl;
 cin.ignore(numeric_limits<streamsize>::max(), '\n');///limpiador del buffer///
 cout<<"Ingrese la descripcion del producto(terminada en el caracter #): ";
 cin.getline(descripcion,500, '#');
 SetDescripcion(descripcion);
 cout<<endl;
 cin.ignore(numeric_limits<streamsize>::max(), '\n');///limpiador del buffer///
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
 cout<<"Ingrese el estado del producto: ";
 cin>>estado;
 SetEstado(estado);
 cout<<endl;
}

void Producto::MostrarProducto()
{
 cout<<"Id del producto: "<<GetIdProducto()<<endl<< endl;
 cout<<"Precio del producto: $"<<fixed << setprecision(0)<<GetPrecio()<<endl<< endl;
 cout<<"Descripcion del producto: "<< endl << GetDescripcion();
 cout<< endl << endl;
 cout<<"Marca del producto: "<<GetMarca()<<endl<< endl;

 switch(_TipoEquipo){
case 1:
    cout << "Tipo de producto: Equipo" << endl;
    break;
case 2:
    cout << "Tipo de producto: Notebook" << endl;
    break;
case 3:
    cout << "Tipo de producto: Procesador" << endl;
    break;
case 4:
    cout << "Tipo de producto: Mother" << endl;
    break;
case 5:
    cout << "Tipo de producto: Placa de video" << endl;
    break;
case 6:
    cout << "Tipo de producto: Memoria Ram" << endl;
    break;
case 7:
    cout << "Tipo de producto: Gabinete" << endl;
    break;
case 8:
    cout << "Tipo de producto: Fuente" << endl;
    break;
case 9:
    cout << "Tipo de producto: Monitor" << endl;
    break;
case 10:
    cout << "Tipo de producto: Periferico" << endl;
    break;
default:{}
    }
    cout << endl;
 }















