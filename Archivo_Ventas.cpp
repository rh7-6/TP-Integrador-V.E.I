#include <iostream>
#include "Archivo_Ventas.h"
using namespace std;

    ///ventas///
    bool ArchivoVentas::GuardarVenta(Venta v){

        FILE *pfile;
        pfile = fopen(_NombreArchivoVentas.getTexto(),"ab");
        if(pfile == NULL)
        {
         return false;
        }

        ArchivoVentas av;
        if(int pos=av.BuscarVenta(v.GetNumeroVenta())>=0){

            fseek(pfile, sizeof(Venta) *pos, SEEK_SET);
            fwrite(&v, sizeof(Venta), 1, pfile);
            fclose(pfile);
            return true;
        }

        fwrite(&v, sizeof(Venta), 1, pfile);
        fclose(pfile);
        return true;
    }

    int ArchivoVentas::CantidadRegistrosVentas(){

        FILE *pfile;
        pfile = fopen(_NombreArchivoVentas.getTexto(),"rb");

        if(pfile==NULL){
            return -1;
        }

        int contReg=0;
        Venta v;
        while(fread(&v, sizeof(Venta), 1, pfile)==1){
            contReg++;
        }
        fclose(pfile);
        return contReg;
    }

    int ArchivoVentas::BuscarVenta(int Num){

        FILE *pfile;
        pfile = fopen(_NombreArchivoVentas.getTexto(),"rb");

        if(pfile==NULL){
            return -1;
        }

        Venta v;
        ArchivoVentas av;
        int posVenta=0, cantReg=av.CantidadRegistrosVentas();

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
        pfile = fopen(_NombreArchivoVentas.getTexto(),"rb");

        if(pfile==NULL){
            return Venta();
        }

        Venta v;

        fseek(pfile, sizeof(Venta) * pos, SEEK_SET);
        fread(&v, sizeof(Venta), 1, pfile);
        fclose(pfile);
        return v;
    }

    void ArchivoVentas::SetNombreVenta(const char *nombre){
        _NombreArchivoVentas.setTexto(nombre);
    }

    const char *ArchivoVentas::GetNombreVenta(){
        return _NombreArchivoVentas.getTexto();
    }


    ///deatlle de Venta///

    bool ArchivoVentas::GuardarDetalleVenta(DetalleVenta dv){

    }

    int ArchivoVentas::CantidadRegistrosDetalleDeVentas(){

    }

    int ArchivoVentas::BuscarDetalleDeVenta(int NumeroDeVenta){

    }

    DetalleVenta ArchivoVentas::LeerDetalleDeVenta(int pos){

    }

    void ArchivoVentas::SetNombreDetalleDeVenta(const char *nombre){

    }

    const char *ArchivoVentas::GetNombreDetalleDeVenta(){

    }
