#include <iostream>
#include "menu.h"
using namespace std;


                                ///VENTA///
//------------------------------------------------------------------------//
    void CargarVenta(Venta &v, const char *cuit, double IMPORTE, bool opcionCarga){

        system("cls");
        ArchivoVentas archV("Ventas.dat");

        int numeroV,dia,mes,siglo;
        Fecha fech;
        bool estado;
        int cantReg= archV.CantidadRegistros(sizeof(Venta));

        if(opcionCarga){                                    //
                                                            // Carrito
            numeroV=cantReg+1;                              //
            v.SetNumeroVenta(numeroV);
        }else{
            bool opcion;
            rlutil::locate(35,5); cout << "Desea ingresar una venta nueva o editar una existente?" << endl;
            rlutil::locate(57,8); cout << "Nueva Venta";
            rlutil::locate(57,9); cout << "Editar Existente";
                    switch(SeleccionMenus(55, 8, 1, 1)){
                    case(0):{opcion=1;}
                    break;

                    case(1):{opcion=0;}
                    break;
                    }
            if(opcion){

                numeroV=cantReg+1;
                v.SetNumeroVenta(numeroV);
                v.SetImporteVenta(0);
            }else{
                rlutil::locate(35,5); cout << "Ingrese numero de venta a editar: ";
                cin >> numeroV; LimpiarBuffer();

                while(archV.BuscarVenta(numeroV-1)<0){

                    system("cls");
                    rlutil::locate(43,5); cout << "Numero de venta inexistente" << endl;
                    rlutil::locate(43,6); cout << "Reingrese numero de venta: ";
                    cin >> numeroV; LimpiarBuffer();
                }
                v.SetNumeroVenta(numeroV);
            }
        }

        system("cls");
        v.SetCuit(cuit);
        cout << endl;

        rlutil::locate(40,5); cout<<"Seleccione la fecha de la venta: "<<endl;
        rlutil::locate(40,6); cout<<"Dia: ";
        dia=SeleccionCantidad(45,6,31,1);

        rlutil::locate(40,6); cout<<"Mes: ";
        mes=SeleccionCantidad(45,6,12,1);

        rlutil::locate(40,6); cout<<"Anio: ";
        siglo=SeleccionCantidad(45,6,2025,2022);

        v.SetFechaVenta(dia,mes,siglo);
        cout << endl;

        if(opcionCarga){
            v.SetImporteVenta(IMPORTE);
        }

        system("cls");
            rlutil::locate(47,5); cout << "Seleccione el estado de venta";
            rlutil::locate(57,8); cout << "Activo";
            rlutil::locate(57,9); cout << "Inactivo";
                    switch(SeleccionMenus(55,8,1,1)){
                    case(0):{estado=1;v.SetEstado(estado);}
                    break;
                    case(1):{estado=0;v.SetEstado(estado);}
                    break;
                    }
        cout << endl;
        rlutil::hidecursor();
        system("cls");
    }

    void MostrarVenta(Venta &Venta){
    cout<<"El numero de venta es: "<<Venta.GetNumeroVenta()<<endl;
    cout<<"El cuil de la venta es: "<<Venta.GetCuit()<<endl;
    Venta.MostrarVentafecha();
    cout << std::fixed << std::setprecision(0);
    cout<<"El importe de la venta es: "<<Venta.GetImporteVenta()<<endl;
    cout<<"//////////////////////////////////////////////"<<endl;
    }

    void BuscarVenta(int opcion){

        ArchivoVentas archV("Ventas.dat");
        int cantReg= archV.CantidadRegistros(sizeof(Venta));
        Venta v;

        switch(opcion){
    case 0:{
        int numVenta;
        system("cls");
        rlutil::locate(35,5);
        cout << "Ingrese numero de venta(entre 1 y " << cantReg << ") :";
        cin >> numVenta; LimpiarBuffer(); cout << endl;
        while(numVenta<1||numVenta>cantReg){
            system("cls");
            rlutil::locate(35,5);
            cout << "Ingrese un numero de venta valido(entre 1 y " << cantReg << ") :";
            cin >> numVenta; LimpiarBuffer();
        }
        for(int i=0; i<cantReg; i++){
            v= archV.LeerVenta(i);
            if(v.GetNumeroVenta()==numVenta){MostrarVenta(v);}
        }
    }
    system("pause");
    system("cls");
    break;

    case 1:{
        ArchivoClientes archCl("Clientes.dat");
        char CUIT[30]{};

        system("cls");
        rlutil::locate(50,5); cout << "Ingrese CUIT: ";
        cin >> CUIT; LimpiarBuffer();
        cout << endl;

        int pos;
        while((pos=archCl.BuscarCliente(CUIT))<0){
            system("cls");
            rlutil::locate(40,5); cout << "Cliente inexistente reingrese CUIT: ";
            cin >> CUIT; LimpiarBuffer();
        }

        for(int i=0; i<cantReg; i++){
            v=archV.LeerVenta(i);
            if(strcmp(v.GetCuit(),CUIT)==0){MostrarVenta(v);}
        }
        system("pause");
        system("cls");
    }
    break;

    case 2:{
        system("cls");
        MVector vecVtOrdenadas;
        int Dia1, Mes1, Anio1, Dia2, Mes2, Anio2;

        rlutil::locate(40,5); cout<<"Seleccione la fecha inicial del rango: "<<endl;
        rlutil::locate(40,6); cout<<"Dia: ";
        Dia1=SeleccionCantidad(45,6,31,1);

        rlutil::locate(40,6); cout<<"Mes: ";
        Mes1=SeleccionCantidad(45,6,12,1);

        rlutil::locate(40,6); cout<<"Anio: ";
        Anio1=SeleccionCantidad(45,6,2025,2022);

        cout << endl;
        Fecha fMin(Dia1,Mes1,Anio1);
        system("cls");
        //----------------------------------------------------//

        rlutil::locate(40,5); cout<<"Seleccione la fecha final del rango: "<<endl;
        rlutil::locate(40,6); cout<<"Dia: ";
        Dia2=SeleccionCantidad(45,6,31,1);

        rlutil::locate(40,6); cout<<"Mes: ";
        Mes2=SeleccionCantidad(45,6,12,1);

        rlutil::locate(40,6); cout<<"Anio: ";
        Anio2=SeleccionCantidad(45,6,2025,2022);
        cout << endl;

        Fecha fMax(Dia2,Mes2,Anio2);

        Fecha fAct;
        int dia, mes, anio;
        for(int i=0; i<cantReg; i++){

            v= archV.LeerVenta(i);
            fAct= v.GetFecha();
            dia=fAct.getDia(); mes=fAct.getMes(); anio=fAct.getAnio();
            if((dia>=fMin.getDia()&&mes>=fMin.getMes()&&anio>=fMin.getAnio())&&(dia<=fMax.getDia()&&mes<=fMax.getMes()&&anio<=fMax.getAnio())){

                MostrarVenta(v);
            }
        }
        system("pause");
    }
        }
    }

    void GuardarRegistroVenta(Venta &v){

        ArchivoVentas archV("Ventas.dat");
        archV.GuardarVenta(v);
    }

    void ListadoDeVentas(){

        system("cls");
        bool estado;
        rlutil::locate(35,5);
        cout << "Selecione el estado de ventas que desea listar" << endl;

        rlutil::locate(50,8);
        cout<<"Borradas";
        rlutil::locate(50,9);
        cout<<"Listadas";

        estado=SeleccionMenus(48,8,1,1);

        ArchivoVentas archV("Ventas.dat");
        int cantReg=archV.CantidadRegistros(sizeof(Venta));

        MVector VtOrdenadas;

        Venta v;
        for(int i=0; i<cantReg; i++){
            archV.LeerVenta(i, v);
            if(v.GetEstado()==estado){
                //MostrarVenta(v);
                VtOrdenadas.Agregar(v);
                }
            }

        bool ban=true;
        int tamVecV=VtOrdenadas.GetTam();
        Venta *VtOr=VtOrdenadas.GetVt();
        while(ban){

            int contVtOrdenadas=0;
            for(int i=0; i<tamVecV; i++){

                if(i!=tamVecV-1){

                    if(VtOr[i].GetImporteVenta()<VtOr[i+1].GetImporteVenta()){

                        Venta v;
                        v= VtOr[i+1];
                        VtOr[i+1]=VtOr[i];
                        VtOr[i]=v;
                        contVtOrdenadas++;
                    }
                }
            }
                if(contVtOrdenadas==0){
                    ban=false;
                }
        }

            for(int i=0; i<tamVecV; i++){
                MostrarVenta(VtOr[i]);
            }

        system("pause");
        system("cls");
    }

    void MenuRegistroVentas(){

        system("cls");
        rlutil::locate(50,6);cout<<"<Guardar/Editar registro>"<<endl;
        rlutil::locate(50,7);cout<<"<Eliminar Registro>"<<endl;
        int opcion=SeleccionMenus(49,6,1,1);

        Venta v;
        Cliente cl;
        if(opcion==0){
                if(CargarCliente(cl,0,1)==1){GuardarRegistroCliente(cl, 0);}
                CargarVenta(v, cl.GetCuit(), 0, 0);
                GuardarRegistroVenta(v);
        }else{
            int numVent;
            ArchivoVentas archV("Ventas.dat");
            rlutil::locate(40, 5);
            cout<<"Ingrese el numero de venta: ";
            cin>>numVent; LimpiarBuffer();

            int posV=archV.BuscarVenta(numVent);
            while(posV<0){
                cout<<"Venta inexistente reingrese numero de venta: ";
                cin>>numVent; LimpiarBuffer();
                posV =archV.BuscarVenta(numVent);
                system("cls");
            }

            v=archV.LeerVenta(posV);
            v.SetEstado(false);
            archV.GuardarVenta(v);
        }
    }
