#include <iostream>
#include "Archivo_Detalle_Ventas.h"
using namespace std;

bool ArchivoDetalleVentas::GuardarDetalleVenta(DetalleVenta dv){

        FILE *pfile;
        pfile = fopen(GetNombreArchivo(),"ab");
        if(pfile == NULL)
        {
         return false;
        }

        ArchivoDetalleVentas av;
        if(int pos=av.BuscarDetalleDeVenta(dv.GetNumeroVentaDT())>=0){

            fseek(pfile, sizeof(DetalleVenta) *pos, SEEK_SET);
            fwrite(&dv, sizeof(DetalleVenta), 1, pfile);
            fclose(pfile);
            return true;
        }

        fwrite(&dv, sizeof(DetalleVenta), 1, pfile);
        fclose(pfile);
        return true;
    }


    int ArchivoDetalleVentas::BuscarDetalleDeVenta(int NumeroDTV){

        FILE *pfile;
        pfile = fopen(GetNombreArchivo(),"rb");

        if(pfile==NULL){
            return -1;
        }

        DetalleVenta dv;
        int posDTV=0, cantReg= CantidadRegistros(sizeof(dv));

        for(int i=0; i<cantReg; i++){
            fread(&dv, sizeof(DetalleVenta), 1, pfile);
            if(dv.GetNumeroVentaDT()==NumeroDTV){
                fclose(pfile);
                return posDTV;
            }
            posDTV++;
        }
        fclose(pfile);
        return -2;
    }

    DetalleVenta ArchivoDetalleVentas::LeerDetalleDeVenta(int pos){

        FILE *pfile;
        pfile = fopen(GetNombreArchivo(),"rb");

        if(pfile==NULL){
            return DetalleVenta();
        }

        DetalleVenta dv;

        fseek(pfile, sizeof(DetalleVenta) * pos, SEEK_SET);
        fread(&dv, sizeof(DetalleVenta), 1, pfile);
        fclose(pfile);
        return dv;
    }

/// constructores///

    ArchivoDetalleVentas::ArchivoDetalleVentas(const char *nombre){

        SetNombreArchivo(nombre);
    }
    ArchivoDetalleVentas::ArchivoDetalleVentas(){}
