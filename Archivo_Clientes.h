#ifndef ARCHIVO_CLIENTES_H_INCLUDED
#define ARCHIVO_CLIENTES_H_INCLUDED
#include "cadena.h"
#include "Clientes.h"

class ArchivoClientes {
public:

    void GuardarCliente(Cliente &cl, int pos);
    int CantidadRegistros();
    int BuscarCliente(const char *CUIT);
    void MostrarCliente(int pos);
    Cliente LeerCliente(int pos);
    void SetNombre(const char *nombre);
    const char *GetNombre();

    /// pendiente declarar constructor para crear el archivo .dat
private:
    ///objeto cadena///
    Cadena _NombreArchivo;

};
#endif // ARCHIVO_CLIENTES_H_INCLUDED
