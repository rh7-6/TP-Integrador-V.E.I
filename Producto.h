#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED
#include "cstring"
#include <iomanip>
#include <limits>///libreria que utiliza el limpiador de buffer///
#include "cadena.h"

class Producto {
public:
int SetIdProducto(int num);
void SetNombreProducto(char *palabra);
int SetPrecio(float num);
void SetDescripcion(char *palabra);
void SetMarca(char *palabra);
int SetTipoEquipo(int num);
int SetStock(int num);
void SetEstado(bool estado);

int GetIdProducto();
const char *GetNombreProducto();
float GetPrecio();
const char *GetDescripcion();
const char *GetMarca();
int GetTipoEquipo();
int GetStock();
bool GetEstado();

Producto();
Producto(int Id, char *nombre, float precio, char *descripcion, char *marca, int tipo, int stock, bool estado);

void CargarProducto();
void MostrarProducto();

private:

    int _IdProducto;
    Cadena _NombreProducto;
    float _Precio;
    char _Descripcion[500];
    Cadena _Marca;
    int _TipoEquipo;
    int _Stock;
    bool _Estado;

};
#endif // PRODUCTO_H_INCLUDED
