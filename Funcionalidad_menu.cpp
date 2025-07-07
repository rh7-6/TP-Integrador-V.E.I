#include <iostream>
#include "menu.h"
using namespace std;

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

        cout<<"Ingrese el estado del producto(1-activo, 0-inactivo): ";
        cin>>estado;
        p.SetEstado(estado);
        cout<<endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return 1;
    }

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

//------------------------------------------------------------------------//
    int CargarClientes(Cliente &cl){

        ArchivoClientes archCl("Clientes.dat");

        int tc;
        char *cuil= new char[31], *nombre= new char[31], *apellido= new char[31], *telefono= new char[31], *mail=new char[31], *direccion=new char[31];
        bool estado;

        cout<<"Ingrese el cuit del cliente: ";
        cin.getline(cuil, 31);
        if(archCl.BuscarCliente(cuil)>=0){

            int opcion;
            cout << "Ya existe un cliente con el cuit:" << cuil << " Desea reingresarlo?" << endl;
            cout << "1=si 0=no: " << endl;
            cin >> opcion;
            if(opcion==0){
                return opcion;
            }
        }
        cl.SetCuil(cuil);
        cout<<endl;

        cout<<"Ingrese el nombre del cliente: ";
        cin.getline(nombre, 31);
        cl.SetNombre(nombre);
        cout<<endl;

        cout<<"Ingrese el apellido del cliente: ";
        cin.getline(apellido, 31);
        cl.SetApellido(apellido);
        cout<<endl;

        cout<<"Ingrese el telefono del cliente: ";
        cin.getline(telefono, 31);
        cl.SetTelefono(telefono);
        cout<<endl;

        cout<<"Ingrese el mail del cliente: ";
        cin.getline(mail, 31);
        cl.SetMail(mail);
        cout<<endl;

        cout<<"Ingrese la direccion del cliente: ";
        cin.getline(direccion, 31);
        cl.SetDireccion(direccion);
        cout<<endl;

        cout<<"Ingrese el tipo de cliente(1-particular o 2-empresa): ";
        cin>>tc;
        cl.SetTipoCliente(tc);
        cout<<endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout <<"Ingrese estado del cliente(1-activo, 0-inactivo): ";
        cin>>estado;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        delete[] cuil; delete[] nombre; delete[] apellido; delete[] telefono; delete[] mail; delete[] direccion;

        return 1;
    }

    void GuardarRegistroCliente(Cliente &cl){

        ArchivoClientes archCl("Clientes.dat");
        bool seguir=true;

        while(seguir){
            archCl.GuardarCliente(cl);
            cout << "Para ingresar otro cliente(1=si,0=no): ";
            cin >> seguir;
            if(seguir){
            seguir=CargarClientes(cl);
            }
        }
    }

    void ListadoDeClientesPorEstado(){

        system("cls");
        bool estado;
        cout << "Ingrese estado de clientes (1: activos, 0: inactivos): " << endl;
        cin >> estado;

        ArchivoClientes archCl("Clientes.dat");
        int cantReg=archCl.CantidadRegistros(sizeof(Cliente));

        Cliente cl;
        for(int i; i<=cantReg; i++){
        if(archCl.LeerCliente(i, cl)){
            if(cl.GetEstado()==estado){
                cl.MostrarCliente();
                }
            }
        }
        system("pause");
        system("cls");
    }

//------------------------------------------------------------------------//
    int CargarVenta(Venta &v, bool opcionFuncion){

        ArchivoVentas archV("Ventas.dat");

        int numeroV,dia,mes,siglo;
        double importe;
        Fecha fech;
        char cuit[20];
        bool estado;

        int cantReg= archV.CantidadRegistros(sizeof(Venta));

        if(opcionFuncion){                                  //
                                                            // Carrito
            numeroV=cantReg+1;                              //
        }else{

            bool opcion;                                                                       //
            cout << "Desea igresar una venta nueva o editar una existente?" << endl;           //
            cout << "(1=nueva, 0=existente): ";                                                //
            cin >> opcion;                                                                     //
                                                                                               //
            if(opcion){                                                                        //
                                                                                               //
                numeroV=cantReg+1;                                                             //
            }else{                                                                             // Carga simple o edicion de una venta
                                                                                               //
                cout << "Ingrese numero de venta a editar: ";                                  //
                cin >> numeroV;                                                                //
                                                                                               //
                while(archV.BuscarVenta(numeroV-1)<0){                                         //
                                                                                               //
                    cout << "Numero de venta inexistente" << endl;                             //
                    cout << "Reingrese numero de venta: " << endl;                             //
                    cin >> numeroV;                                                            //
                }
            }
        }
        v.SetNumeroVenta(numeroV);
        cout<<endl;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ingrese el cuit del comprador: ";
        cin.getline(cuit,20);
        v.SetCuit(cuit);
        cout << endl;

        cout << "Ingrese dia de la venta: ";
        cin >> dia;
        cout << endl;

        cout << "Ingrese mes de la venta:  ";
        cin >> mes;
        cout << endl;

        cout << "Ingrese anio de la venta: ";
        cin >> siglo;
        v.SetFechaVenta(dia,mes,siglo);
        cout << endl;

        cout << "Ingrese importe de la venta: ";
        cin >> importe;
        v.SetImporteVenta(importe);
        cout << endl;

        cout << "Ingrese estado de la venta(1-activo, 0-inactivo): ";
        cin >> estado;
        v.SetEstado(estado);
        cout << endl;

        return 1;
    }

    void GuardarRegistroVenta(Venta &v){

        ArchivoVentas archV("Ventas.dat");
        bool seguir=true;

        while(seguir){
            archV.GuardarVenta(v);
            cout << "Para ingresar otra venta(1=si,0=no): ";
            cin >> seguir;
            if(seguir){
            seguir=CargarVenta(v, 0);
            }
        }
    }

    void ListadoDeVentasPorEstado(){

        system("cls");
        bool estado;
        cout << "Ingrese estado de ventas (1: activas, 0: inactivas): " << endl;
        cin >> estado;

        ArchivoVentas archV("Ventas.dat");
        int cantReg=archV.CantidadRegistros(sizeof(Venta));

        Venta v;
        for(int i; i<=cantReg; i++){
        if(archV.LeerVenta(i, v)){
            if(v.GetEstado()==estado){
                v.MostrarVenta();
                }
            }
        }
        system("pause");
        system("cls");
    }

//------------------------------------------------------------------------//
    int CargarDetalleVenta(int numVenta, DetalleVenta &dv){

        ArchivoDetalleVentas archDV("DetalleVentas.dat");

        ArchivoVentas archV("Ventas.dat");
        int cantRegV= archV.CantidadRegistros(sizeof(Venta));

        int numeroventa, idproducto, cantidad;
        float precio;

        if(numVenta==0){                                                                        //
                                                                                                //
            do{                                                                                 //
            cout << "Ingrese un numero de venta existente (entre 1 y " << cantRegV << "): ";    //  Carga simple o edicion de un detalle de venta
            cin >> numeroventa;                                                                 //
            cout << endl;                                                                       //
            }while(numeroventa<0||numeroventa>cantRegV);                                        //
            dv.SetNumeroVentaDT(numeroventa);                                                   //
        }else{
                                                                         //
            dv.SetNumeroVentaDT(numVenta);                               //  Carrito
        }                                                                //

        cout << "ingrese un precio mayor o igual a 1000 : $";
        cin >> precio;
        dv.SetPrecioProductoDT(precio);
        cout << endl;

        cout << "ingrese el nuemro de id del producto: ";
        cin >> idproducto;
        dv.SetIdProductoDT(idproducto);
        cout << endl;

        cout << "ingrese la cantidad de productos vendidos: ";
        cin >> cantidad;
        dv.SetCantidad(cantidad);
        cout << endl;

        return 1;
    }

    void GuardarRegistroDetalleVenta(DetalleVenta &dv){

        ArchivoDetalleVentas archDV("DetalleVentas.dat");
        bool seguir=true;

        while(seguir){
            archDV.GuardarDetalleVenta(dv);
            cout << "Para ingresar otro detalle de venta(1=si,0=no): ";
            cin >> seguir;
            if(seguir){
            seguir=CargarDetalleVenta(0, dv);
            }
        }
    }

    void ListadoDetalleVentasPorNumeroDeVenta(int numVenta){


    }
