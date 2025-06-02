#ifndef ARCHIVO_PRODUCTOS_H_INCLUDED
#define ARCHIVO_PRODUCTOS_H_INCLUDED
#include "Producto.h"

class ArchivoProductos {
public:

    void GuardarProducto();
    int CantidadRegistros();
    int BuscarProducto(const char *IdProducto);
    void MostrarProducto(int pos);
    Producto LeerProducto(int pos);
    void SetNombre(const char *nombre);
    const char *GetNombre();

    /// pendiente declarar constructor para crear el archivo .dat
private:

    Cadena _NombreArchivo;

};

#endif // ARCHIVO_PRODUCTOS_H_INCLUDED
