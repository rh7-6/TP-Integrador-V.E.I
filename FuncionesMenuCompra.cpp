#include <iostream>
#include "menu.h"
using namespace std;


                                ///COMPRA///
//------------------------------------------------------------------------//
    void CopiarYOrdenarProductos(MVector &vecPrMod, int tipoPr, bool estado){

        ArchivoProductos archPr("Productos.dat");
        int cantReg=archPr.CantidadRegistros(sizeof(Producto));

        int tamVecProd=vecPrMod.GetTam(sizeof(Producto));
        Producto pr;
        for(int i=0; i<cantReg; i++){
            archPr.LeerProducto(i, pr);
            if(tipoPr==-1){
                if(pr.GetEstado()==estado&&pr.GetStock()>0){
                    vecPrMod.Agregar(pr);
                    }
            }else{
                if(pr.GetTipoEquipo()==tipoPr&&pr.GetEstado()==estado&&pr.GetStock()>0){
                    //MostrarProducto(pr);
                    vecPrMod.Agregar(pr);
                    }
                }
        }

        bool ban=true;
        tamVecProd=vecPrMod.GetTam(sizeof(Producto));
        Producto *arrPrMod=vecPrMod.GetPr();
        while(ban){

                int contPrOrdenados=0;
            for(int i=0; i<tamVecProd; i++){

                if(i!=tamVecProd-1){
                    if(arrPrMod[i].GetStock()<arrPrMod[i+1].GetStock()){
                        Producto p;
                        p= arrPrMod[i+1];
                        arrPrMod[i+1]=arrPrMod[i];
                        arrPrMod[i]=p;
                        contPrOrdenados++;
                    }
                }
            }
            if(contPrOrdenados==0){
                            ban=false;
            }
        }

    }

    void ListadoDeProductosCompra(MVector &vecPr, int tipoPr){

        int tamVecPr=vecPr.GetTam(sizeof(Producto));
        int SaltDeLin=0, cont=0;

        rlutil::locate(42,9);
        cout << "|------------------------------------------------|" << endl;

        if(tamVecPr==0){
            rlutil::locate(48,10);
            cout << "  Sin Productos que mostrar <SALIR>" << endl;
            return;
        }

        Producto *ArrPrM=vecPr.GetPr();
        for(int i=0; i<tamVecPr; i++){
            if(ArrPrM[i].GetTipoEquipo()==tipoPr){
                if(cont!=0){SaltDeLin+=4;}
                rlutil::locate(48,10+SaltDeLin);
                cout << ArrPrM[i].GetMarca()<< " " <<ArrPrM[i].GetNombreProducto() << endl;
                rlutil::locate(48,11+SaltDeLin);
                cout << std::fixed << std::setprecision(0);
                cout << "Precio: " << ArrPrM[i].GetPrecio() << endl;
                rlutil::locate(48,12+SaltDeLin);
                cout << "Stock: " << ArrPrM[i].GetStock() << endl;
                rlutil::locate(42,13+SaltDeLin);
                cout << "|------------------------------------------------|" << endl;
                cont++;
            }
        }
        SaltDeLin+=4;
        rlutil::locate(48,10+SaltDeLin);
        cout << "<SALIR>" << endl;
    }

    int CalculoPrsXTipo(MVector &vecPrMod, int TpPr){
        int TotalPrs=vecPrMod.GetTam(sizeof(Producto)), cont=0;
        Producto *prM=vecPrMod.GetPr();
        for(int i=0; i<TotalPrs; i++){if(prM[i].GetTipoEquipo()==TpPr){cont++;}}
        return cont;
    }

    int CalculoIndice(MVector &vecPrMod, int TpPr, int PrSelec){
        int TotalPrs=vecPrMod.GetTam(sizeof(Producto)), cont=0;
        Producto *prM=vecPrMod.GetPr();
        for(int i=0; i<TotalPrs; i++){
            if(prM[i].GetTipoEquipo()==TpPr&&cont==PrSelec){
                return i;}else {if(prM[i].GetTipoEquipo()==TpPr){cont++;}}
            }
        return -1;
    }

    void MenuProductosCompra(MVector &vecPrMod, MVector &vecPrSelec){
        MVector vecTPr; TextoTiposDeProducto2(vecTPr);
        int TpPr=SeleccionMenuAnim(vecTPr.GetCd(),54,12,9,1,4,8)+1,CantPrSelec;

        do{
        ListadoDeProductosCompra(vecPrMod,TpPr);
        int TotalPrXTp=CalculoPrsXTipo(vecPrMod,TpPr);
        int indiceMenuPr=SeleccionMenus(47,10,TotalPrXTp,4);
        int IndicePrSelec= CalculoIndice(vecPrMod,TpPr,indiceMenuPr);
        if(indiceMenuPr==TotalPrXTp||IndicePrSelec==-1){return;}
        system("cls");

        Producto *prM=vecPrMod.GetPr();
        Producto *prS=vecPrSelec.GetPr() ;

        int maximo=prM[IndicePrSelec].GetStock();
        rlutil::locate(48,10); cout << "Seleccione Cantidad:";
        CantPrSelec= SeleccionCantidad(48,11,maximo,0);
        if(CantPrSelec==0){return;};

        prM[IndicePrSelec].SetStock(prM[IndicePrSelec].GetStock()-CantPrSelec);

        bool ban=true;
        int tamVecPrSelec=vecPrSelec.GetTam(sizeof(Producto));
        for(int i=0; i<tamVecPrSelec; i++){
            if(prM[IndicePrSelec].GetIdProducto()==prS[i].GetIdProducto()){
                prS[i]=prM[IndicePrSelec];
                ban=false;
            }
        }
        if(ban){vecPrSelec.Agregar(prM[IndicePrSelec]);}
        }while(CantPrSelec);
    }

    void ListadoDeProductosCarrito(MVector &vecPrSelec, MVector &vecPrOrg){

        int tamVecPrSelec=vecPrSelec.GetTam(sizeof(Producto));
        int SaltDeLin=0, cont=0;
        double ImporteTotal=0;

        rlutil::locate(42,9);
        cout << "|------------------------------------------------|" << endl;
        if(tamVecPrSelec==0){
            rlutil::locate(48,10);
            cout << "  |Carrito Vacio| <SALIR>" << endl;
            return;
        }

        int cantPrSelec;
        Producto *arrPrS=vecPrSelec.GetPr();
        for(int i=0; i<tamVecPrSelec; i++){

            cantPrSelec=CalculoCantidadProductosSeleccionados(vecPrSelec,vecPrOrg,i);

            if(arrPrS[i].GetEstado()==true){

                cont++;
                if(i!=0&&cont>1){SaltDeLin+=4;}
                ImporteTotal+=arrPrS[i].GetPrecio()*cantPrSelec;
                rlutil::locate(48,10+SaltDeLin);
                cout << arrPrS[i].GetMarca()<< " " <<arrPrS[i].GetNombreProducto() << endl;
                rlutil::locate(48,11+SaltDeLin);
                cout << std::fixed << std::setprecision(0);
                cout << "Precio: " << arrPrS[i].GetPrecio() << endl;
                rlutil::locate(48,12+SaltDeLin);
                cout << "Cantidad: " << cantPrSelec << endl;
                rlutil::locate(42,13+SaltDeLin);
                cout << "|------------------------------------------------|" << endl;
            }
        }
        if(cont==0){
            rlutil::locate(48,10);
            cout << "|Carrito Vacio| " << "<SALIR>" << endl;
            return;
        }
        SaltDeLin+=1;
        rlutil::locate(48,13+SaltDeLin);
        cout << std::fixed << std::setprecision(0);
        cout << "<SALIR>          |IMPORTE TOTAL: $" << ImporteTotal << "|" << endl;
    }

    void MenuCarrito(MVector &vecPrSelec, MVector &vecPrOrg, MVector &vecPrMod){

        bool ban=true;
        Producto *arrPrSelec=vecPrSelec.GetPr(),*arrPrOrg=vecPrOrg.GetPr(),*arrPrMod=vecPrMod.GetPr();

        do{
            int TamVecPrSelec=vecPrSelec.GetTam(sizeof(Producto)), TotalPr=0;
            for(int i=0; i<TamVecPrSelec; i++){if(arrPrSelec[i].GetEstado()==true){TotalPr++;}}
            ListadoDeProductosCarrito(vecPrSelec,vecPrOrg);
            int IndicePrSelec= SeleccionMenus(47,10,TotalPr,4);
            if(IndicePrSelec==TotalPr){return;}

            system("cls");
            rlutil::locate(48,10); cout << "Eliminar producto?" << endl;
            rlutil::locate(48,11); cout << "No" << endl;
            rlutil::locate(48,12); cout << "Si" << endl;
            int opcion=SeleccionMenus(47,11,1,1);
            switch(opcion){
            case(1):
                arrPrSelec[IndicePrSelec].SetEstado(false);
                int tamVecPrMod=vecPrMod.GetTam(sizeof(Producto));
                for(int i=0; i<tamVecPrMod; i++){
                    if(arrPrMod[i].GetIdProducto()==arrPrSelec[IndicePrSelec].GetIdProducto()){
                        arrPrMod[i]=arrPrOrg[i];
                    }
                }
            break;
            }
        }while(ban);
    }

    void GuardarVentaCarrito(MVector &vecPrSelec, MVector &vecPrOrg, MVector &vecPrMod, bool &salida){

        int tamVecPrselec=vecPrSelec.GetTam(sizeof(Producto)), tamVecPrMod=vecPrMod.GetTam(sizeof(Producto)), contadorParaSalida=0;
        Producto *arrPrSelec=vecPrSelec.GetPr(), *arrPrMod=vecPrMod.GetPr();
        for(int i=0;i<tamVecPrselec;i++){if(arrPrSelec[i].GetEstado()==true){contadorParaSalida++;}}
        if(tamVecPrselec==0||contadorParaSalida==0){ rlutil::locate(48,10); cout << "|CARRITO VACIO|";rlutil::locate(48,11);system("pause");return;}
        rlutil::locate(48,10); cout << "Guardar y finalizar compra? " << endl;
        rlutil::locate(48,11); cout << "No" << endl;
        rlutil::locate(48,12); cout << "Si" << endl;
        int opcion=SeleccionMenus(47,11,1,1);

        Cliente cl;
        Venta v;
        //DetalleVenta dv;
        MVector vecDv;

        if(opcion==0){return;}else{
            double ImporteTotal= CalculoImporteTotal(vecPrSelec,vecPrOrg);

            CargarCliente(cl,0,true);

            CargarVenta(v,cl.GetCuit(),ImporteTotal,true);

            for(int i=0; i<tamVecPrselec; i++){
                if(arrPrSelec[i].GetEstado()==true){
                int cantPrSelec= CalculoCantidadProductosSeleccionados(vecPrSelec,vecPrOrg,i);
                DetalleVenta dv(i+1,v.GetNumeroVenta(),arrPrSelec[i].GetPrecio()*cantPrSelec,arrPrSelec[i].GetIdProducto(),cantPrSelec);
                vecDv.Agregar(dv);
                }
            }
        }

        rlutil::locate(40,10); cout << "Guardar y finalizar compra? " << endl;
        rlutil::locate(48,11); cout << "No" << endl;
        rlutil::locate(48,12); cout << "Si" << endl;
        int opcion1=SeleccionMenus(47,11,1,1);

        int tamVecDv=vecDv.GetTam(sizeof(DetalleVenta));
        DetalleVenta *arrDv=vecDv.GetDtV();
        if(opcion1==0){return;}else{
            GuardarRegistroCliente(cl,false);
            GuardarRegistroVenta(v);
            for(int i=0;i<tamVecDv; i++){GuardarRegistroDetalleVenta(arrDv[i],false);}
            for(int i=0;i<tamVecPrMod; i++){if(arrPrMod[i].GetStock()==0){arrPrMod[i].SetEstado(0);}GuardarRegistroProducto(arrPrMod[i]);}
        }
        salida=false;
    }

    double CalculoImporteTotal(MVector &vecPrSelec, MVector &vecPrOrg){

        int tamVecSelec=vecPrSelec.GetTam(sizeof(Producto));
        Producto *arrPrSelec=vecPrSelec.GetPr();
        double ImporteTotal; int cantPrSelec;

        for(int i=0; i<tamVecSelec; i++){
            cantPrSelec=CalculoCantidadProductosSeleccionados(vecPrSelec,vecPrOrg,i);
            if(arrPrSelec[i].GetEstado()==true){ImporteTotal+=arrPrSelec[i].GetPrecio()*cantPrSelec;}
        }
        return ImporteTotal;
    }

    int CalculoCantidadProductosSeleccionados(MVector &vecPrSelec, MVector &vecPrOrg, int indice){

        int tamVecPrOrg=vecPrOrg.GetTam(sizeof(Producto));
        Producto *arrPrs=vecPrSelec.GetPr(), *arrPrOg=vecPrOrg.GetPr();

            int cantPrSelec;
            for(int a=0; a<tamVecPrOrg; a++){
                if(arrPrOg[a].GetIdProducto()==arrPrs[indice].GetIdProducto()){
                    cantPrSelec=arrPrOg[a].GetStock()-arrPrs[indice].GetStock();
                    return cantPrSelec;
                }
            }
    }

