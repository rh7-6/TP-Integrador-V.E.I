#include <iostream>
#include "menu.h"
using namespace std;

                                ///DETALLE VENTA///
//------------------------------------------------------------------------//
    bool CargarDetalleVenta(DetalleVenta &dv, int NUMVENTA, int IDPRODUCTO, int CANTIDAD, bool opcionCarga){

        rlutil::showcursor(); system("cls");
        ArchivoDetalleVentas archDV("DetalleVentas.dat");
        ArchivoVentas archV("Ventas.dat");
        ArchivoProductos archP("Productos.dat");

        int cantRegV= archV.CantidadRegistros(sizeof(Venta)), cantRegDv= archDV.CantidadRegistros(sizeof(DetalleVenta));
        int numeroventa, idproducto, cantidad;
        Producto p;
        int posP;

        dv.SetIdDetalle(30);
        if(opcionCarga){
            posP=archP.BuscarProducto(IDPRODUCTO);
            p=archP.LeerProducto(posP);
            dv.SetNumeroVentaDT(NUMVENTA);  //  Carrito
            dv.SetIdProductoDT(IDPRODUCTO); //
            dv.SetCantidad(CANTIDAD);
            dv.SetPrecioProductoDT(p.GetPrecio());
        }else{
            do{
                rlutil::locate(30, 5);
                cout<<"Ingrese un numero de venta existente (entre 1 y " << cantRegV << "): ";
                cin>>numeroventa; LimpiarBuffer(); cout<<endl;
                system("cls");
            }while(numeroventa<0||numeroventa>cantRegV);
            dv.SetNumeroVentaDT(numeroventa);

            rlutil::locate(30,5);
            cout<<"Ingrese el numero de id del producto: ";
            cin>>idproducto; LimpiarBuffer();
            do{
                posP=archP.BuscarProducto(idproducto);
                while(posP<0){
                    system("cls");
                    rlutil::locate(35,5); cout<<"Producto inexistente reingrese id: ";
                    cin>>idproducto; LimpiarBuffer();
                }
                p=archP.LeerProducto(posP);
                if(p.GetEstado()==false){
                    system("cls");
                    rlutil::locate(35,5); cout<<"Producto inactivo reingrese id o 0 para salir: ";
                    cin>>idproducto; LimpiarBuffer();
                    if(idproducto==0){return false;}
                }
                if(p.GetStock()==0){
                    system("cls");
                    rlutil::locate(35,5); cout<<"Producto sin stock, reingrese id o 0 para salir: ";
                    cin>>idproducto; LimpiarBuffer();
                    if(idproducto==0){return false;}
                }
            }while(p.GetEstado()==false||p.GetStock()==0);
            dv.SetIdProductoDT(idproducto);
            cout << endl;

            int stock= p.GetStock();
            system("cls");
            rlutil::locate(30,5);
            cout << "Ingrese la cantidad requerida(minimo 1, maximo " << stock << "): ";
            cin >> cantidad; LimpiarBuffer();
            while(dv.SetCantidad(cantidad)==0||cantidad>stock)
                {
                system("cls");
                rlutil::locate(30,5);
                cout << "Reingrese la cantidad (minimo 1, maximo " << stock << "): ";
                cin >> cantidad; LimpiarBuffer();
                }
            cout << endl;
            dv.SetPrecioProductoDT(p.GetPrecio());
        }
        p.SetStock(p.GetStock()-dv.GetCantidad());
        archP.GuardarProducto(p);
        if(!opcionCarga){
            Venta v;
            for(int i=0; i<cantRegV; i++){
                v=archV.LeerVenta(i);
                if(v.GetNumeroVenta()==dv.GetNumeroVentaDT()){
                    double importeActulizado;
                    importeActulizado=v.GetImporteVenta()+dv.GetPrecioProducto()*dv.GetCantidad();
                    v.SetImporteVenta(importeActulizado);
                    archV.GuardarVenta(v);
                    return true;
                }
            }
        }
        rlutil::hidecursor(); system("cls");
        return true;
    }

    void MostrarDetalleVenta(DetalleVenta &dv){

       cout<<"El ID de Detalle es: "<<dv.GetIdDetalle()<<endl;
       cout<<"El numero de venta es: "<<dv.GetNumeroVentaDT()<<endl;
       cout << std::fixed << std::setprecision(0);
       cout<<"El precio de productos: $"<<dv.GetPrecioProducto()<<endl;
       cout<<"El numero de id del producto es: "<<dv.GetIdProductoDT()<<endl;
       cout<<"La cantidad de productos comprados: "<<dv.GetCantidad()<<endl;
       cout<<"//////////////////////////////////////////////"<<endl;
       }

    void GuardarRegistroDetalleVenta(DetalleVenta &dv, bool opcionSeguir){

        ArchivoDetalleVentas archDV("DetalleVentas.dat");
        bool seguir=true;
        system("cls");
        while(seguir){
            archDV.GuardarDetalleVenta(dv);
            if(!opcionSeguir){return;}
            rlutil::locate(40,5);
            cout << "Desea ingresar otro detalle de venta?";
            rlutil::locate(56,7);
            cout<<"si";
            rlutil::locate(56,8);
            cout<<"no";
                    switch(SeleccionMenus(55, 7, 1, 1))
                    {
                    case(0):{
                    seguir=1;
                    }
                    break;
                    case(1):{
                    seguir=0;
                    }
                    break;
                    }
            system("cls");
            if(seguir){
            CargarDetalleVenta(dv,0,0,0,false);
            system("cls");
            rlutil::locate(53,5);
            cout << "Que desea hacer";
            rlutil::locate(56,7);
            cout<<"Guardar";
            rlutil::locate(56,8);
            cout<<"Descartar";
                    switch(SeleccionMenus(53, 7, 1, 1))
                    {
                    case(0):{
                    seguir=1;
                    }
                    break;
                    case(1):{
                    seguir=0;
                    }
                    break;
                    }

                system("cls");
                if(!seguir){
                    return;
                }
            }
        }
    }

    void ListadoDetalleVentasPorNumeroDeVenta(){

        rlutil::showcursor();
        system("cls");
        int numeroventa;

        ArchivoVentas archV("Ventas.dat");
        int cantRegV= archV.CantidadRegistros(sizeof(Venta));

        ArchivoDetalleVentas archDV("DetalleVentas.dat");
        int cantRegDv=archDV.CantidadRegistros(sizeof(DetalleVenta));

        rlutil::locate(35,5);
        cout << "Ingrese un numero de venta existente (entre 1 y " << cantRegV << "): ";
        cin >> numeroventa; LimpiarBuffer();

        system("cls");
        while(numeroventa<0||numeroventa>cantRegV){
            rlutil::locate(35,6);
            cout << "Reingrese un numero de venta entre 1 y " << cantRegV << ": ";
            cin >> numeroventa; LimpiarBuffer();
            int pos=archV.BuscarVenta(numeroventa);
            Venta v=archV.LeerVenta(pos);
            if(v.GetEstado()==false){rlutil::locate(35,7); cout<<"Venta inactiva"; rlutil::getkey(); system("cls");}
        }

        DetalleVenta dv;
        for(int i=0; i<cantRegDv; i++){
            archDV.LeerDetalleDeVenta(i, dv);
            if(dv.GetNumeroVentaDT()==numeroventa){
                MostrarDetalleVenta(dv);
                }
        }
        system("pause");
        system("cls");
        rlutil::hidecursor();
    }
