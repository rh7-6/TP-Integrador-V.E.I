#include <iostream>
#include "menu.h"
using namespace std;


    void GuardarRegistroProducto(Producto &p){

        ArchivoProductos archP("Productos.dat");
        bool seguir=true;

        while(seguir){
            archP.GuardarProducto(p);
            cout << "Para ingresar otro producto(1=si,0=no): ";
            cin >> seguir;
            if(seguir){
            CargarProducto(p);
            }
        }
    }

    int CargarProducto(Producto &p){

        ArchivoProductos archP("Productos.dat");
        int id,tipo,stock;
        float precio;
        char nombre[50]{},descripcion[500]{}, marca[20]{};
        bool estado;

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

        cout<<"Ingrese el estado del producto(1=activo, 0=inactivo): ";
        cin>>estado;
        p.SetEstado(estado);
        cout<<endl;
        return 1;
    }

    void ListadoDeProductosPorTipo(){
        system("cls");
        int TipoDeProducto;
        bool ban=true;
        bool estado;
        cout << "Ingrese un tipo de producto(1 a 10)" << endl;
        MuestraTextoTiposDeProducto();
        cout << "==> :";
        cin >> TipoDeProducto;
        cout << "Ingrese estado en inventario(1: Activo, 0: inactivo)" << endl;
        cin >> estado;

        ArchivoProductos archPr("Productos.dat");
        int cantReg=archPr.CantidadRegistros(sizeof(Producto));

        system("cls");
        while(ban==true){
            if(TipoDeProducto<=10&&TipoDeProducto>0){
                Producto pr;
                for(int i=0; i<=cantReg; i++){
                if(archPr.LeerProducto(i, pr)){
                    if(pr.GetTipoEquipo()==TipoDeProducto&& pr.GetEstado()==estado){
                        pr.MostrarProducto();
                        }
                    }
                }
                system("pause");
                system("cls");
                ban=false;
            } else{
                cout<<"Ingrese porfavor un tipo valido(1 a 10): ";
                cin>>TipoDeProducto;
            }
        }
    }

    void GuardarRegistroCliente(Cliente &cl){

        ArchivoClientes archCl("Productos.dat");
        bool seguir=true;

        while(seguir){
            archCl.GuardarCliente(cl);
            cout << "Para ingresar otro cliente(1=si,0=no): ";
            cin >> seguir;
            if(seguir){
            CargarClientes(cl);
            }
        }
    }

    int CargarClientes(Cliente &cl){


    }

    void ListadoDeClientesPorEstado(){

        system("cls");
        bool estado, ban=true;
        cout << "Ingrese estado del cliente (1: activo, 0: inactivo): " << endl;
        cin >> estado;

        ArchivoClientes archCl("clientes.dat");
        int cantReg=archCl.CantidadRegistros(sizeof(Producto));

        Cliente cl;
        for(int i; i<=cantReg; i++){
        if(archCl.LeerCliente(i, cl)){
            if(cl.GetEstado()==estado){
                cl.MostrarCliente();
                }
            }
        }

    }
