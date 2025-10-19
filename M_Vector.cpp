#include <iostream>
#include "M_Vector.h"
using namespace std;

    void MVector::Agregar(Cadena &cd){
        _TamCad++;
        Cadena *NCad= new Cadena[_TamCad];
        if(_TamCad!=0){for(int i=0; i<_TamCad-1; i++){NCad[i]=_Cad[i];}}
        NCad[_TamCad-1]=cd;
        if(_Cad!=nullptr){delete[] _Cad;}
        _Cad=NCad;
    }

    void MVector::Agregar(const char *t){
        Cadena cd(t);
        _TamCad++;
        Cadena *NCad= new Cadena[_TamCad];
        if(_TamCad!=0){for(int i=0; i<_TamCad-1; i++){NCad[i]=_Cad[i];}}
        NCad[_TamCad-1]=cd;
        if(_Cad!=nullptr){delete[] _Cad;}
        _Cad=NCad;
    }

    Cadena* MVector::GetCd(){
        return _Cad;
    }

    void MVector::Agregar(Producto &pr){
        _TamProd++;
        Producto *NProd= new Producto[_TamProd];
        if(_TamProd!=0){for(int i=0; i<_TamProd-1; i++){NProd[i]=_Prod[i];}}
        NProd[_TamProd-1]=pr;
        if(_Prod!=nullptr){delete[] _Prod;}
        _Prod=NProd;
    }


    Producto *MVector::GetPr(){
        return _Prod;
    }

    void MVector::Agregar(Cliente &cl){
        _TamCl++;
        Cliente *NCl= new Cliente[_TamCl];
        if(_TamCl!=0){for(int i=0; i<_TamCl-1; i++){NCl[i]=_Cl[i];}}
        NCl[_TamCl-1]=cl;
        if(_Cl!=nullptr){delete[] _Cl;}
        _Cl=NCl;
    }

    Cliente *MVector::GetCl(){
        return _Cl;
    }

    void MVector::Agregar(Venta &vt){
        _TamVt++;
        Venta *NVt= new Venta[_TamVt];
        if(_TamVt!=0){for(int i=0; i<_TamVt-1; i++){NVt[i]=_Vt[i];}}
        NVt[_TamVt-1]=vt;
        if(_Vt!=nullptr){delete[] _Vt;}
        _Vt=NVt;
    }

    Venta *MVector::GetVt(){
        return _Vt;
    }

    void MVector::Agregar(DetalleVenta &dtv){
        _TamDtV++;
        DetalleVenta *NDtV= new DetalleVenta[_TamDtV];
        if(_TamDtV!=0){for(int i=0; i<_TamDtV-1; i++){NDtV[i]=_DtV[i];}}
        NDtV[_TamDtV-1]=dtv;
        if(_DtV!=nullptr){delete[] _DtV;}
        _DtV=NDtV;
    }

    DetalleVenta *MVector::GetDtV(){
        return _DtV;
    }

    int MVector::GetTam(int sizeOfObj){

        if(sizeOfObj==sizeof(Cadena)){return _TamCad;}
        if(sizeOfObj==sizeof(Producto)){return _TamProd;}
        if(sizeOfObj==sizeof(Cliente)){return _TamCl;}
        if(sizeOfObj==sizeof(Venta)){return _TamVt;}
        if(sizeOfObj==sizeof(DetalleVenta)){return _TamDtV;}
        return -1;
    }

    int MVector::GetTam(){

        if(_TamCad>0){return _TamCad;}
        else if(_TamProd>0){return _TamProd;}
        else if(_TamCl>0){return _TamCl;}
        else if(_TamVt>0){return _TamVt;}
        else if(_TamDtV>0){return _TamDtV;}
        else return 0;
    }

    void MVector::operator=(MVector &mvec){
        _TamCad=mvec.GetTam(sizeof(Cadena)); _TamProd=mvec.GetTam(sizeof(Producto)); _TamCl=mvec.GetTam(sizeof(Cliente)); _TamVt=mvec.GetTam(sizeof(Venta)); _TamDtV=mvec.GetTam(sizeof(DetalleVenta));

        Cadena *arrCd=mvec.GetCd(); Producto *arrPr=mvec.GetPr(); Cliente *arrCl=mvec.GetCl(); Venta *arrVt=mvec.GetVt(); DetalleVenta *arrDtV=mvec.GetDtV();

        _Cad= new Cadena[_TamCad]; _Prod= new Producto[_TamProd]; _Cl= new Cliente[_TamCl]; _Vt= new Venta[_TamVt]; _DtV= new DetalleVenta[_TamDtV];

        for(int i=0; i<_TamCad; i++){_Cad[i]=arrCd[i];}
        for(int i=0; i<_TamProd; i++){_Prod[i]=arrPr[i];}
        for(int i=0; i<_TamCl; i++){_Cl[i]=arrCl[i];}
        for(int i=0; i<_TamVt; i++){_Vt[i]=arrVt[i];}
        for(int i=0; i<_TamDtV; i++){_DtV[i]=arrDtV[i];}
    }

    MVector::~MVector(){
        delete[] _Cad;
        delete[] _Prod;
        delete[] _Cl;
        delete[] _Vt;
        delete[] _DtV;
    }
