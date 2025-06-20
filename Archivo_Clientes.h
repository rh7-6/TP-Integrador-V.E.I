#ifndef ARCHIVO_CLIENTES_H_INCLUDED
#define ARCHIVO_CLIENTES_H_INCLUDED
#include "cadena.h"
#include "Clientes.h"

class ArchivoClientes {
public:

    bool GuardarCliente(Cliente &cl);
    int CantidadRegistros();
    int BuscarCliente(const char *CUIT);
    Cliente LeerCliente(int pos);
    void SetNombreArchivoClientes(const char *nombre);
    const char *GetNombreArchivoClientes();

    ArchivoClientes(const char *t);
    ArchivoClientes();

private:

    Cadena _NombreArchivo;

};
#endif // ARCHIVO_CLIENTES_H_INCLUDED
