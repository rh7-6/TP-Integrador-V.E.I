#include <iostream>
#include "Archivo_Productos.h"
using namespace std;


    bool ArchivoProductos::GuardarProducto(Producto &pr){

        if(int pos=BuscarProducto(pr.GetIdProducto())>=0){

            FILE *pfile;
            pfile = fopen(GetNombreArchivo(),"rb+");
            if(pfile == NULL){
            return false;
            }

            fseek(pfile, sizeof(Producto) *pos, SEEK_SET);
            fwrite(&pr, sizeof(Producto), 1, pfile);
            fclose(pfile);
            return true;
        }

        FILE *pfile;
        pfile = fopen(GetNombreArchivo(),"ab");
        if(pfile == NULL){
         return false;
        }

        fwrite(&pr, sizeof(Producto), 1, pfile);
        fclose(pfile);
        return true;
    }


    int ArchivoProductos::BuscarProducto(int IdProducto){

        FILE *pfile;
        pfile = fopen(GetNombreArchivo(),"rb");

        if(pfile==NULL){
            return -1;
        }

        Producto p;
        int posProducto=0, cantReg=CantidadRegistros(sizeof(Producto));

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
        pfile = fopen(GetNombreArchivo(),"rb");

        if(pfile==NULL){
            return Producto();
        }

        Producto p;

        fseek(pfile, sizeof(Producto) * pos, SEEK_SET);
        fread(&p, sizeof(Producto), 1, pfile);
        fclose(pfile);
        return p;
    }

    int ArchivoProductos::LeerProducto(int pos, Producto &p){

        FILE *pfile;
        pfile = fopen(GetNombreArchivo(),"rb");

        if(pfile==NULL){
            return -1;
        }


        fseek(pfile, sizeof(Producto) * pos, SEEK_SET);
        int lectura= fread(&p, sizeof(Producto), 1, pfile);
        fclose(pfile);
        return lectura;
    }


    ArchivoProductos::ArchivoProductos(const char *nombre){

        SetNombreArchivo(nombre);
    }

    ArchivoProductos::ArchivoProductos(){
    }
