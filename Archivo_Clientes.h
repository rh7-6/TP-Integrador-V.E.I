#ifndef ARCHIVO_CLIENTES_H_INCLUDED
#define ARCHIVO_CLIENTES_H_INCLUDED
#include "cadena.h"
#include "Clientes.h"

class ArchivoClientes {
public:

    void GuardarCliente();
    int BuscarCliente();
    void MostrarCliente(int pos);
    Cliente LeerCliente(int pos);

    /// pendiente declarar constructor para crear el archivo .dat
private:

    Cadena _NombreArchivo;

};
#endif // ARCHIVO_CLIENTES_H_INCLUDED
