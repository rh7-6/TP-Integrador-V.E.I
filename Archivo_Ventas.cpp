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

    void ArchivoVentas::SetNombreArchVentas(const char *nombre){
        _NombreArchivoVentas.setTexto(nombre);
    }

    const char *ArchivoVentas::GetNombreArchVentas(){
        return _NombreArchivoVentas.getTexto();
    }


    ///deatlle de Venta///

    bool ArchivoVentas::GuardarDetalleVenta(DetalleVenta dv){

        FILE *pfile;
        pfile = fopen(_NombreArchivoDetalleVentas.getTexto(),"ab");
        if(pfile == NULL)
        {
         return false;
        }

        ArchivoVentas av;
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

    int ArchivoVentas::CantidadRegistrosDetalleDeVentas(){

        FILE *pfile;
        pfile = fopen(_NombreArchivoDetalleVentas.getTexto(),"rb");

        if(pfile==NULL){
            return -1;
        }

        int contReg=0;
        DetalleVenta dv;
        while(fread(&dv, sizeof(DetalleVenta), 1, pfile)==1){
            contReg++;
        }
        fclose(pfile);
        return contReg;
    }

    int ArchivoVentas::BuscarDetalleDeVenta(int NumeroDTV){

        FILE *pfile;
        pfile = fopen(_NombreArchivoDetalleVentas.getTexto(),"rb");

        if(pfile==NULL){
            return -1;
        }

        DetalleVenta dv;
        ArchivoVentas av;
        int posDTV=0, cantReg=av.CantidadRegistrosDetalleDeVentas();

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

    DetalleVenta ArchivoVentas::LeerDetalleDeVenta(int pos){

        FILE *pfile;
        pfile = fopen(_NombreArchivoDetalleVentas.getTexto(),"rb");

        if(pfile==NULL){
            return DetalleVenta();
        }

        DetalleVenta dv;

        fseek(pfile, sizeof(DetalleVenta) * pos, SEEK_SET);
        fread(&dv, sizeof(DetalleVenta), 1, pfile);
        fclose(pfile);
        return dv;
    }

    void ArchivoVentas::SetNombreAchDetalleVentas(const char *nombre){

        _NombreArchivoDetalleVentas.setTexto(nombre);
    }

    const char *ArchivoVentas::GetNombreArchDetalleVentas(){

        return _NombreArchivoDetalleVentas.getTexto();
    }
    /// Constructores ///

    ArchivoVentas::ArchivoVentas(const char *nombre, int ventaOdetalle){

        if(ventaOdetalle==1){
            _NombreArchivoVentas.setTexto(nombre);
        }else if(ventaOdetalle==2){
            _NombreArchivoDetalleVentas.setTexto(nombre);
        }
    }

    ArchivoVentas::ArchivoVentas(){}
