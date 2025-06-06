#include <iostream>
#include "Archivo_Clientes.h"
using namespace std;


    void ArchivoClientes::GuardarCliente(Cliente &cl, int pos){
        FILE *pfile;
        pfile = fopen(_NombreArchivo.getTexto(),"ab");

        Cliente b;

        fseek(pfile, sizeof(Cliente) * pos, SEEK_SET);

        fwrite(&cl, sizeof(Cliente), 1, pfile);

        fclose(pfile);

    }

    int ArchivoClientes::CantidadRegistros(){


    }

    int ArchivoClientes::BuscarCliente(const char *CUIT){

    }

    void ArchivoClientes::MostrarCliente(int pos){

    }

    Cliente ArchivoClientes::LeerCliente(int pos){

    }

    void ArchivoClientes::SetNombre(const char *nombre){

    }

    const char *ArchivoClientes::GetNombre(){

    }

    /// pendiente desarrollar el constructor para crear el archivo .dat
