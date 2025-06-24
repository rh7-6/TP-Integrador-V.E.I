#ifndef ARCHIVO_TEMPLATE_H_INCLUDED
#define ARCHIVO_TEMPLATE_H_INCLUDED
#include "cadena.h"

class ArchivoTemplate{

public:

    int CantidadRegistros(int tamObj);
    void SetNombreArchivo(const char *nombre);
    const char *GetNombreArchivo();

private:
    Cadena _NombreArchivo;
};

#endif // ARCHIVO_TEMPLATE_H_INCLUDED
