#include <iostream>
#include "Archivo_Productos.h"
using namespace std;


    void ArchivoProductos::GuardarProducto(Producto pr, int pos){
        FILE *pfile;
        pfile = fopen(_NombreArchivo.getTexto(),"ab");
        if(pfile == NULL)
        {
         cout<<"no se pudo crear el archibo"<<endl;
        }


        fclose(pfile);
}

    int ArchivoProductos::CantidadRegistros(){

    }

    int ArchivoProductos::BuscarProducto(int IdProducto){

    }

    void ArchivoProductos::MostrarProducto(int pos){

    }

    Producto ArchivoProductos::LeerProducto(int pos){

    }

    void ArchivoProductos::SetNombreProducto(const char *nombre){

    }

    const char *ArchivoProductos::GetNombreProducto(){

    }

    /// pendiente desarrollar el constructor para crear el archivo .dat
