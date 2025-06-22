#ifndef ARCHIVO_CLIENTES_H_INCLUDED
#define ARCHIVO_CLIENTES_H_INCLUDED
#include "Archivo_Template.h"
#include "Clientes.h"

class ArchivoClientes: public ArchivoTemplate{
public:

    bool GuardarCliente(Cliente cl);
    int BuscarCliente(const char *CUIT);
    Cliente LeerCliente(int pos);

    ArchivoClientes(const char *t);
    ArchivoClientes();

};
#endif // ARCHIVO_CLIENTES_H_INCLUDED
