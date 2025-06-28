#include <iostream>
#include "menu.h"
using namespace std;


    void GuardarRegistroProducto(Producto &p){

        ArchivoProductos archp("Productos.dat");
        bool seguir=true;

        while(seguir){

        CargarProducto(p, archp);
        archp.GuardarProducto(p);
        cout << "continuar?(1=si,0=no): ";
        cin >> seguir;
        }
    }

    int CargarProducto(Producto &p, ArchivoProductos &archP){

        int id,tipo,stock;
        float precio;
        char nombre[50]{},descripcion[500]{}, marca[20]{};

        cout<<"Ingrese el id del producto o equipo igual o mayor a 0: ";
        cin>>id;
        if(archP.BuscarProducto(id)>=0){

            int opcion;
            cout << "Ya existe un producto con el Id:" << id << " Desea reingresarlo?" << endl;
            cout << "1=si 0=no: " << endl;
            cin >> opcion;
            if(opcion==0){
                return opcion;
            }
        }
        p.SetIdProducto(id);
        cout<<endl;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');///limpiador del buffer///
        cout << "Ingrese nombre del producto: ";
        cin.getline(nombre, 50);
        p.SetNombreProducto(nombre);
        cout << endl;

        cout<<"Ingrese el precio del producto tienen que ser igual o mayor a 100: ";
        cin>>precio;
        p.SetPrecio(precio);
        cout<<endl;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');///limpiador del buffer///
        cout<<"Ingrese la descripcion del producto(terminada en el caracter #): ";
        cin.getline(descripcion,500, '#');
        p.SetDescripcion(descripcion);
        cout<<endl;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');///limpiador del buffer///
        cout<<"Ingrese la marca a la que pertenece el producto: ";
        cin.getline(marca,20);
        p.SetMarca(marca);
        cout<<endl;

        cout<<"Ingrese el tipo de producto: ";
        cin>>tipo;
        p.SetTipoEquipo(tipo);
        cout<<endl;

        cout<<"Ingrese el stock del producto: ";
        cin>>stock;
        p.SetStock(stock);
        cout<<endl;
        return 1;
    }

    void ListadoDeProductosPorTipo(){

        int TipoDeProducto;
        bool estado, ban=false;
        cout << "Ingrese un tipo de producto(1 a 10)" << endl;
        MuestraTextoTiposDeProducto();
        cin >> TipoDeProducto;
        cout << "Ingrese estado en inventario(1: listado, 0: no listado)" << endl;
        cin >> estado;

        ArchivoProductos archPr("Productos.dat");
        int cantReg=archPr.CantidadRegistros(sizeof(Producto));

        do{
        ban=false;
        switch(TipoDeProducto){
        case 1:{
            Producto pr;
            for(int i; i<=cantReg; i++){
                pr= archPr.LeerProducto(i);
                if(pr.GetTipoEquipo()==1&& pr.GetEstado()==estado){
                        pr.MostrarProducto();
                }
            }
        }
            break;
        case 2:{
            Producto pr;
            for(int i; i<=cantReg; i++){
                pr= archPr.LeerProducto(i);
                if(pr.GetTipoEquipo()==2&& pr.GetEstado()==estado){
                        pr.MostrarProducto();
                }
            }
        }
            break;
        case 3:{
            Producto pr;
            for(int i; i<=cantReg; i++){
                pr= archPr.LeerProducto(i);
                if(pr.GetTipoEquipo()==3&& pr.GetEstado()==estado){
                        pr.MostrarProducto();
                }
            }
        }
            break;
        case 4:{
            Producto pr;
            for(int i; i<=cantReg; i++){
                pr= archPr.LeerProducto(i);
                if(pr.GetTipoEquipo()==4&& pr.GetEstado()==estado){
                        pr.MostrarProducto();
                }
            }
        }
            break;
        case 5:{
            Producto pr;
            for(int i; i<=cantReg; i++){
                pr= archPr.LeerProducto(i);
                if(pr.GetTipoEquipo()==5&& pr.GetEstado()==estado){
                        pr.MostrarProducto();
                }
            }
        }
            break;
        case 6:{
            Producto pr;
            for(int i; i<=cantReg; i++){
                pr= archPr.LeerProducto(i);
                if(pr.GetTipoEquipo()==6&& pr.GetEstado()==estado){
                        pr.MostrarProducto();
                }
            }
        }
            break;
        case 7:{
            Producto pr;
            for(int i; i<=cantReg; i++){
                pr= archPr.LeerProducto(i);
                if(pr.GetTipoEquipo()==7&& pr.GetEstado()==estado){
                        pr.MostrarProducto();
                }
            }
        }
            break;
        case 8:{
            Producto pr;
            for(int i; i<=cantReg; i++){
                pr= archPr.LeerProducto(i);
                if(pr.GetTipoEquipo()==8&& pr.GetEstado()==estado){
                        pr.MostrarProducto();
                }
            }
        }
            break;
        case 9:{
            Producto pr;
            for(int i; i<=cantReg; i++){
                pr= archPr.LeerProducto(i);
                if(pr.GetTipoEquipo()==9&& pr.GetEstado()==estado){
                        pr.MostrarProducto();
                }
            }
        }
            break;
        case 10:{
            Producto pr;
            for(int i; i<=cantReg; i++){
                pr= archPr.LeerProducto(i);
                if(pr.GetTipoEquipo()==10&& pr.GetEstado()==estado){
                        pr.MostrarProducto();
                }
            }
        }
            break;
        default:{
            cout << "Reingrese el tipo de producto(1 a 10)" << endl;
            MuestraTextoTiposDeProducto();
            cin >> TipoDeProducto;
            ban=true;
            break;
            }
        }
        } while(ban);
    }
