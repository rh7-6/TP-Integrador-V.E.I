#include <iostream>
#include "menu.h"
using namespace std;


                                ///PRODUCTO///
//------------------------------------------------------------------------//
    int CargarProducto(Producto &p, int switchEdit, bool opcCarga){

        ArchivoProductos archP("Productos.dat");
        int id,tipo=0,stock;
        float precio;
        char nombre[50]{},descripcion[500]{}, marca[20]{};

        if(opcCarga==1){
            rlutil::locate(30,5);
            cout<<"Ingrese id del producto: ";
            cin>>id; LimpiarBuffer();

            while(p.SetIdProducto(id)==0){
                rlutil::locate(20,5);
                cout<<"Ingrese un numero mayor a 0: ";
                cin>>id; LimpiarBuffer();
                system("cls");
            }
        }
        do{
            switch(switchEdit){
                case(0):{
                    rlutil::locate(35,5);
                    cout << "Ingrese nombre del producto: ";
                    cin.getline(nombre, 50);
                    p.SetNombreProducto(nombre);
                    system("cls");
                }break;

                case(1):{
                    rlutil::locate(20,5);
                    cout<<"Ingrese el precio del producto tienen que ser igual o mayor a 100: $";
                    cin>>precio;
                    while(p.SetPrecio(precio)==0){
                        system("cls");
                        rlutil::locate(20,5);
                        cout<<"el precio debe ser mayor a 100 por favor vuelva a ingresar el precio: $";
                        cin>>precio; LimpiarBuffer();
                    }
                    system("cls");
                }break;

                case(2):{
                    rlutil::locate(2,5);
                    cout<<"Ingrese la descripcion del producto(terminada en el caracter #): "<<endl;
                    cin.getline(descripcion,500, '#'); LimpiarBuffer();
                    p.SetDescripcion(descripcion);
                    system("cls");
                }break;

                case(3):{
                    rlutil::locate(20,5);
                    cout<<"Ingrese la marca a la que pertenece el producto: ";
                    cin.getline(marca,20);
                    p.SetMarca(marca);
                    system("cls");
                }break;

                case(4):{
                    rlutil::locate(50,7);
                    cout<<"Selecione el tipo de producto";
                    TextoTiposDeProducto();
                    tipo=SeleccionMenus(56,8,9,1);
                    tipo++;
                    p.SetTipoEquipo(tipo);
                    system("cls");
                }break;

                case(5):{
                    rlutil::locate(35,5);
                    cout<<"Ingrese el stock del producto: ";
                    cin>>stock; LimpiarBuffer();
                    while(p.SetStock(stock)==0){
                        rlutil::locate(20,5);
                        cout<<"El stock no puede ser menor a 0 por favor vuelva a ingresar el stock: ";
                        cin>>stock; LimpiarBuffer();
                    }
                    system("cls");
                }break;

                case(6):{
                    rlutil::locate(45,5);
                    cout<<"Selecione el estado del producto";
                    rlutil::locate(56,7);
                    cout<<"inactivo";
                    rlutil::locate(56,8);
                    cout<<"activo";
                    switch(SeleccionMenus(54,7,1,1)){
                    case(0):{p.SetEstado(0);}break;

                    case(1):{p.SetEstado(1);}break;
                    }
                    cout<<endl;
                    }break;
            }
            switchEdit++;
        }while(opcCarga);
        return 1;
    }

    void MostrarProducto(Producto &p){
    cout<<"Id: "<<p.GetIdProducto()<<endl<< endl;
    cout<<"Nombre y Marca: "<<p.GetMarca()<<endl<< endl;
    cout<<"Precio: $"<<fixed << setprecision(0)<<p.GetPrecio()<<endl<< endl;
    cout<< p.GetDescripcion();
    cout<< endl << endl;

 switch(p.GetTipoEquipo()){
case 1:
    cout << "Tipo de producto: Equipo" << endl;
    break;
case 2:
    cout << "Tipo de producto: Notebook" << endl;
    break;
case 3:
    cout << "Tipo de producto: Procesador" << endl;
    break;
case 4:
    cout << "Tipo de producto: Mother" << endl;
    break;
case 5:
    cout << "Tipo de producto: Placa de video" << endl;
    break;
case 6:
    cout << "Tipo de producto: Memoria Ram" << endl;
    break;
case 7:
    cout << "Tipo de producto: Gabinete" << endl;
    break;
case 8:
    cout << "Tipo de producto: Fuente" << endl;
    break;
case 9:
    cout << "Tipo de producto: Monitor" << endl;
    break;
case 10:
    cout << "Tipo de producto: Periferico" << endl;
    break;
default:{}
    }
    cout << endl;
    cout << "Stock: " << p.GetStock() << endl;

    cout<<"//////////////////////////////////////////////"<<endl;

    }

    void BuscarProducto(bool opcion){

        ArchivoProductos archP("Productos.dat");
        Producto p;

        if(opcion){

            int pos, id;
            rlutil::locate(40,5);
            cout << "Ingrese el Id del producto a buscar: ";
            cin >> id; LimpiarBuffer();
            cout << endl;

            if((pos=archP.BuscarProducto(id))<0){

                system("cls");
                rlutil::locate(40,5);
                cout << "Producto inexistente reingrese id: ";
                cin >> id;
            }else{
                p=archP.LeerProducto(pos);
                MostrarProducto(p);
                system("pause");
            }
        }else{

            float precioMax, precioMin;

            system("cls");
            rlutil::locate(35,5);
            cout << "Ingrese valor maximo en rango de precio a buscar: ";
            cin >> precioMax; LimpiarBuffer();
            cout << endl;

            rlutil::locate(35,8);
            cout << "Ingrese valor minimo en rango de precio a buscar: ";
            cin >> precioMin; LimpiarBuffer();
            cout << endl;
            system("cls");

            MVector PrEnRango;
            for(int i=0; i<archP.CantidadRegistros(sizeof(Producto)); i++){

                p= archP.LeerProducto(i);
                if(p.GetPrecio()<=precioMax&&p.GetPrecio()>=precioMin){

                    PrEnRango.Agregar(p);
                }
            }
            int tamVecProd=PrEnRango.GetTam(sizeof(Producto));
            Producto *p=PrEnRango.GetPr();
            for(int i=0; i<tamVecProd; i++){
                MostrarProducto(p[i]);
            cout<<"///////////////////////////////////////////////"<<endl;
            }
            system("pause");
            system("cls");
        }
    }

    void GuardarRegistroProducto(Producto &p){

        ArchivoProductos archP("Productos.dat");

        archP.GuardarProducto(p);
    }

    void ListadoDeProductos(bool opcion){

        system("cls");
        int TipoDeProducto;
        bool estado;

        rlutil::locate(50,7);
        cout<<"Selecione el tipo de producto";
        TextoTiposDeProducto();
        TipoDeProducto=SeleccionMenus(56,8,9,1);
        TipoDeProducto++;
        system("cls");

        while(TipoDeProducto>10||TipoDeProducto<0){
            system("cls");
            cout<<"como saliste del menu? ingrese por favor un numero entre el 1 y 10 ";
            cin>>TipoDeProducto; LimpiarBuffer();
        }
        system("cls");
        rlutil::locate(45,5);
        cout << "Ingrese estado en inventario" << endl;
        rlutil::locate(55,8);
        cout<<"Inactivo";
        rlutil::locate(55,9);
        cout<<"Activo";
        estado=SeleccionMenus(53,8,1,1);

        ArchivoProductos archPr("Productos.dat");
        int cantReg=archPr.CantidadRegistros(sizeof(Producto));

        MVector PrOrdenados;

        system("cls");

        Producto pr;
        for(int i=0; i<cantReg; i++){
            archPr.LeerProducto(i, pr);
            if(pr.GetTipoEquipo()==TipoDeProducto&&pr.GetEstado()==estado){
                //MostrarProducto(pr);
                PrOrdenados.Agregar(pr);
                }
            }

        if(opcion){

                bool ban=true;
                int tamVecProd=PrOrdenados.GetTam(sizeof(Producto));
                Producto *PrOr=PrOrdenados.GetPr();
                while(ban){

                        int contPrOrdenados=0;
                    for(int i=0; i<tamVecProd; i++){

                        if(i!=tamVecProd-1){
                            if(PrOr[i].GetPrecio()<PrOr[i+1].GetPrecio()){
                                Producto p;
                                p= PrOr[i+1];
                                PrOr[i+1]=PrOr[i];
                                PrOr[i]=p;
                                contPrOrdenados++;
                            }
                        }
                    }
                        if(contPrOrdenados==0){
                            ban=false;
                        }
                }
            }else{
                bool ban=true;
                int tamVecProd=PrOrdenados.GetTam(sizeof(Producto));
                Producto *PrOr= PrOrdenados.GetPr();
                while(ban){

                        int contPrOrdenados=0;
                    for(int i=0; i<tamVecProd; i++){

                        if(i!=tamVecProd-1){
                            if(PrOr[i].GetStock()<PrOr[i+1].GetStock()){
                                Producto p;
                                p= PrOr[i+1];
                                PrOr[i+1]=PrOr[i];
                                PrOr[i]=p;
                                contPrOrdenados++;
                            }
                        }
                    }
                        if(contPrOrdenados==0){
                            ban=false;
                        }
                }
            }
            int tamVecProd=PrOrdenados.GetTam(sizeof(Producto));
            Producto *PrOr=PrOrdenados.GetPr();
            for(int i=0; i<tamVecProd; i++){
                MostrarProducto(PrOr[i]);
            }
            system("pause");
            system("cls");
    }

    void MenuRegistroProducto(){

        system("cls");
        ArchivoProductos archP("Productos.dat");
        Cadena txt;
        MVector vecOp;
        txt.setTexto("Guardar/Editar registro");vecOp.Agregar(txt);
        txt.setTexto("Eliminar/Restaurar Registro");vecOp.Agregar(txt);
        int opcion=SeleccionMenuAnim(vecOp.GetCd(),54,12,1,1,4,8);

        Producto p;
        if(opcion==0){
                Cadena txt1;
                MVector vecOp1;
                txt1.setTexto("Ingresar nuevo");vecOp1.Agregar(txt1);
                txt1.setTexto("Editar existente");vecOp1.Agregar(txt1);

                if(SeleccionMenuAnim(vecOp1.GetCd(),54,12,1,1,4,8)==0){
                    CargarProducto(p,0,1);
                    }else{
                        MVector VecPr;
                        MVector vecTxTpPr;
                        TextoTiposDeProducto2(vecTxTpPr);
                        int TpPr=SeleccionMenuAnim(vecTxTpPr.GetCd(),54,12,9,1,4,8)+1;
                        CopiarYOrdenarProductos(VecPr,TpPr,1);
                        CopiarYOrdenarProductos(VecPr,TpPr,0);

                        int tamVecPr=VecPr.GetTam(sizeof(Producto));
                        Producto *ArrPr=VecPr.GetPr();
                        MVector OpcPrTxt;
                        for(int i=0;i<tamVecPr;i++){
                            string estado;
                            if(ArrPr[i].GetEstado()==0){estado="Borrado";}else{estado="listado";}
                            string s="ID:"+to_string(ArrPr[i].GetIdProducto())+"|"+ArrPr[i].GetMarca()+" "+ArrPr[i].GetNombreProducto()+"|"+estado;
                            OpcPrTxt.Agregar(s.c_str());
                        }
                        int PrSelec=SeleccionMenuAnim(OpcPrTxt.GetCd(),54,12,tamVecPr-1,2,4,8);
                        p=ArrPr[PrSelec];
                        MVector vecEdt;
                        TxtEditProducto(vecEdt);
                        int SwitchEdit=SeleccionMenuAnim(vecEdt.GetCd(),54,12,6,2,4,8);
                        CargarProducto(p,SwitchEdit,0);
                    }
                archP.GuardarProducto(p);
                system("cls");
                rlutil::hidecursor();
        }else{
            int idPr;
            ArchivoProductos archP("Productos.dat");
            rlutil::locate(40, 5);
            cout<<"Ingrese el id del producto: ";
            cin>>idPr; LimpiarBuffer();

            int posP=archP.BuscarProducto(idPr);
            while(posP<0){
                rlutil::locate(40, 5);
                cout<<"Producto inexistente reingrese id de producto: ";
                cin>>idPr; LimpiarBuffer();
                posP =archP.BuscarProducto(idPr);
                system("cls");
            }

            p=archP.LeerProducto(posP);
            if(p.GetEstado()==false){
                system("cls");
                rlutil::locate(40,5); cout<<"El registro ya se elimino desea restauralo?";
                rlutil::locate(55,7); cout<<"Si";
                rlutil::locate(55,8); cout<<"No";
                if(SeleccionMenus(53,7,1,1)==0){
                p.SetEstado(true);
                archP.GuardarProducto(p);
                }
            }else{p.SetEstado(false);archP.GuardarProducto(p);}
        }
    }

    void CargaDirecta(){
     ArchivoProductos archP("Productos.dat");
     Producto p;

      p.CargarProducto();
      if(archP.GuardarProducto(p))
        {
         cout<<"producto guardado correctamente";
        }
      else
        {
         cout<<"fallo al guradardar el producto";
        }

}
