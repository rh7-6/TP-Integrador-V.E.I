#include <iostream>
#include "Archivo_Ventas.h"
using namespace std;

    ///ventas///
    bool ArchivoVentas::GuardarVenta(Venta &v){

        int pos=BuscarVenta(v.GetNumeroVenta());
        if(pos>=0){

            FILE *pfile;
            pfile = fopen(GetNombreArchivo(),"rb+");
            if(pfile == NULL){
                return false;
            }

            fseek(pfile, sizeof(Venta) *pos, SEEK_SET);
            fwrite(&v, sizeof(Venta), 1, pfile);
            fclose(pfile);
            return true;
        }

        FILE *pfile;
        pfile = fopen(GetNombreArchivo(),"ab");
        if(pfile == NULL){
         return false;
        }


        fwrite(&v, sizeof(Venta), 1, pfile);
        fclose(pfile);
        return true;
    }

    int ArchivoVentas::BuscarVenta(int Num){

        FILE *pfile;
        pfile = fopen(GetNombreArchivo(),"rb");

        if(pfile==NULL){
            return -1;
        }

        Venta v;
        int posVenta=0, cantReg=CantidadRegistros(sizeof(v));

        for(int i=0; i<cantReg; i++){
            fread(&v, sizeof(Venta), 1, pfile);
            if(v.GetNumeroVenta()==Num){
                fclose(pfile);
                return posVenta;
            }
            posVenta++;
        }
        fclose(pfile);
        return -2;
    }

    Venta ArchivoVentas::LeerVenta(int pos){

        FILE *pfile;
        pfile = fopen(GetNombreArchivo(),"rb");

        if(pfile==NULL){
            return Venta();
        }

        Venta v;

        fseek(pfile, sizeof(Venta) * pos, SEEK_SET);
        fread(&v, sizeof(Venta), 1, pfile);
        fclose(pfile);
        return v;
    }

    int ArchivoVentas::LeerVenta(int pos, Venta &v){

        FILE *pfile;
        pfile = fopen(GetNombreArchivo(),"rb");

        if(pfile==NULL){
            return -1;
        }


        fseek(pfile, sizeof(Venta) * pos, SEEK_SET);
        int lectura= fread(&v, sizeof(Venta), 1, pfile);
        fclose(pfile);
        return lectura;
    }

    /// Constructores ///

    ArchivoVentas::ArchivoVentas(const char *nombre){

        SetNombreArchivo(nombre);
    }
    ArchivoVentas::ArchivoVentas(){}
