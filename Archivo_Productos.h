#ifndef ARCHIVO_PRODUCTOS_H_INCLUDED
#define ARCHIVO_PRODUCTOS_H_INCLUDED
#include "Producto.h"

class ArchivoProductos {
public:

    bool GuardarProducto(Producto pr);
    int CantidadRegistros();
    int BuscarProducto(int IdProducto);
    Producto LeerProducto(int pos);
    void SetNombreArchivoProductos(const char *nombre);
    const char *GetNombreArchivoProductos();

    ArchivoProductos(const char *t);
    ArchivoProductos();
private:

    Cadena _NombreArchivo;

};

#endif // ARCHIVO_PRODUCTOS_H_INCLUDED
