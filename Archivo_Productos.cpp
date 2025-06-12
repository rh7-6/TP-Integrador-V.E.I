#include <iostream>
#include "Archivo_Productos.h"
using namespace std;


    bool ArchivoProductos::GuardarProducto(Producto pr){
        FILE *pfile;
        pfile = fopen(_NombreArchivo.getTexto(),"ab");
        if(pfile == NULL)
        {
         return false;
        }

        ArchivoProductos ap;
        if(int pos=ap.BuscarProducto(pr.GetIdProducto())>=0){

            fseek(pfile, sizeof(Producto) *pos, SEEK_SET);
            fwrite(&pr, sizeof(Producto), 1, pfile);
            fclose(pfile);
            return true;
        }

        fwrite(&pr, sizeof(Producto), 1, pfile);
        fclose(pfile);
        return true;
    }

    int ArchivoProductos::CantidadRegistros(){

        FILE *pfile;
        pfile = fopen(_NombreArchivo.getTexto(),"rb");

        if(pfile==NULL){
            return -1;
        }

        int contReg=0;
        Producto p;
        while(fread(&p, sizeof(Producto), 1, pfile)==1){
            contReg++;
        }
        fclose(pfile);
        return contReg;
    }

    int ArchivoProductos::BuscarProducto(int IdProducto){

        FILE *pfile;
        pfile = fopen(_NombreArchivo.getTexto(),"rb");

        if(pfile==NULL){
            return -1;
        }

        Producto p;
        ArchivoProductos ap;
        int posProducto=0, cantReg=ap.CantidadRegistros();

        for(int i=0; i<cantReg; i++){
            fread(&p, sizeof(Producto), 1, pfile);
            if(p.GetIdProducto()==IdProducto){
                fclose(pfile);
                return posProducto;
            }
            posProducto++;
        }
        fclose(pfile);
        return -2;
    }


    Producto ArchivoProductos::LeerProducto(int pos){

        FILE *pfile;
        pfile = fopen(_NombreArchivo.getTexto(),"rb");

        if(pfile==NULL){
            return Producto();
        }

        Producto p;

        fseek(pfile, sizeof(Producto) * pos, SEEK_SET);
        fread(&p, sizeof(Producto), 1, pfile);
        fclose(pfile);
        return p;
    }

    void ArchivoProductos::SetNombreProducto(const char *nombre){

        _NombreArchivo.setTexto(nombre);
    }

    const char *ArchivoProductos::GetNombreProducto(){

        return _NombreArchivo.getTexto();
    }

    /// pendiente desarrollar el constructor para crear el archivo .dat
