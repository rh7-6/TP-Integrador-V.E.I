#include <iostream>
#include "menu.h"
using namespace std;

                                ///INFORMES///
//------------------------------------------------------------------------//

    void RecaudacionAnual(){
     int anio=0,i=0;
     float importe=0,meses[12]={0};
     Fecha fech;
     Venta ven;
     ArchivoVentas archV("Ventas.dat");
    int cantReg= archV.CantidadRegistros(sizeof(Venta));
        rlutil::locate(45,5);
        cout<<"Ingrese el anio que desea consultar: ";
        cin>>anio; LimpiarBuffer();
        for(i=0;i<cantReg;i++)
        {
        archV.LeerVenta(i,ven);
        fech=ven.GetFecha();
        if(fech.getAnio()==anio&&ven.GetEstado()==true)
        {
        switch(fech.getMes())
        {
    case(1):
        {
        meses[0]=meses[0]+ven.GetImporteVenta();
        }
    break;
    case(2):
        {
        meses[1]=meses[1]+ven.GetImporteVenta();
        }
    break;
    case(3):
        {
        meses[2]=meses[2]+ven.GetImporteVenta();
        }
    break;
    case(4):
        {
        meses[3]=meses[3]+ven.GetImporteVenta();
        }
    break;
    case(5):
        {
        meses[4]=meses[4]+ven.GetImporteVenta();
        }
    break;
    case(6):
        {
        meses[5]=meses[5]+ven.GetImporteVenta();
        }
    break;
    case(7):
        {
        meses[6]=meses[6]+ven.GetImporteVenta();
        }
    break;
    case(8):
        {
        meses[7]=meses[7]+ven.GetImporteVenta();
        }
    break;
    case(9):
        {
        meses[8]=meses[8]+ven.GetImporteVenta();
        }
    break;
    case(10):
        {
        meses[9]=meses[9]+ven.GetImporteVenta();
        }
    break;
    case(11):
        {
        meses[10]=meses[10]+ven.GetImporteVenta();
        }
    break;
    case(12):
        {
        meses[11]=meses[11]+ven.GetImporteVenta();
        }
    break;
        }
        importe=importe+ven.GetImporteVenta();
        }
        }
        if(importe==0)
        {
        system("cls");
        rlutil::locate(47,5);
        cout<<"No se recaudo nada el anio "<<anio;
        rlutil::getkey();
        }
        else
        {
        system("cls");
        cout << std::fixed << std::setprecision(0);
        rlutil::locate(52,5);
        cout<<"Enero= $"<<meses[0];
        rlutil::locate(52,6);
        cout<<"Febrero= $"<<meses[1];
        rlutil::locate(52,7);
        cout<<"Marzo= $"<<meses[2];
        rlutil::locate(52,8);
        cout<<"Abril= $"<<meses[3];
        rlutil::locate(52,9);
        cout<<"Mayo= $"<<meses[4];
        rlutil::locate(52,10);
        cout<<"Junio= $"<<meses[5];
        rlutil::locate(52,11);
        cout<<"Julio= $"<<meses[6];
        rlutil::locate(52,12);
        cout<<"Agosto= $"<<meses[7];
        rlutil::locate(52,13);
        cout<<"Septiembre= $"<<meses[8];
        rlutil::locate(52,14);
        cout<<"Octubre= $"<<meses[9];
        rlutil::locate(52,15);
        cout<<"Noviembre= $"<<meses[10];
        rlutil::locate(52,16);
        cout<<"Diciembre= $"<<meses[11];
        rlutil::locate(35,18);
        cout<<"Lo que se recaudo en total del "<<anio<<" es de: $"<<importe;
        rlutil::getkey();
        }
    }

    void RecaudacionCliente(){
    int i=0,anio=0;
    char cuit[50];
     float total=0, importe=0;
     Cliente clie;
     Venta ven;
     Fecha fech;
     ArchivoClientes archCl("Clientes.dat");
     ArchivoVentas archV("Ventas.dat");
    int cantReg= archV.CantidadRegistros(sizeof(Venta));
        rlutil::locate(45,5);
        cout<<"Ingrese el cuil del cliente: ";
        cin>>cuit; LimpiarBuffer();
        rlutil::locate(35,5);
        cout<<"Ingrese el anio que desea ver de la recaudacion del cliente: ";
        cin>>anio; LimpiarBuffer();
        archCl.LeerCliente(archCl.BuscarCliente(cuit),clie);
        if(clie.GetEstado()==false||archCl.BuscarCliente(cuit)<0)
        {
        system("cls");
        rlutil::locate(45,5);
        cout<<"cliente borrado o inexistente";
        rlutil::getkey();
        return;
        }

        for(i=0;i<cantReg;i++)
        {
        ven=archV.LeerVenta(i);
        fech=ven.GetFecha();
        if(clie.GetEstado()==true&&fech.getAnio()==anio){
        if(strcmp(ven.GetCuit(),cuit)==0)
        {
        importe=ven.GetImporteVenta();
        total=total+importe;
        }
        }
        }
        if(total==0)
        {
        system("cls");
        rlutil::locate(47,5);
        cout<<"No se recaudo nada con el cliente "<<cuit;
        rlutil::getkey();
        }
        else
        {
        system("cls");
        rlutil::locate(35,5);
        cout << std::fixed << std::setprecision(0);
        cout<<"Lo que se recaudo en total del cliente "<<cuit<<" es de: $"<<total<<endl;
        rlutil::getkey();
        }

    }

    void RecaudacionEquipo(){

    int i=0,f=0,equipo=0;
    float total=0, importe=0;
    DetalleVenta deven;
    Producto prod;

    ArchivoDetalleVentas archD("DetalleVentas.dat");
    ArchivoProductos archprod("Productos.dat");
    int cantRegDv= archD.CantidadRegistros(sizeof(DetalleVenta));
    int cantRegPr= archprod.CantidadRegistros(sizeof(Producto));


        rlutil::locate(45,5);
        cout<<"seleccione el tipo de producto";
        TextoTiposDeProducto();
        equipo=SeleccionMenus(55,8,9,1);
        for(i=0;i<cantRegDv;i++)
        {
        for(f=0;f<cantRegPr;f++){
        deven=archD.LeerDetalleDeVenta(i);
        prod=archprod.LeerProducto(f);
        if(deven.GetIdProductoDT()==prod.GetIdProducto()){
        if(prod.GetTipoEquipo()==equipo+1&&prod.GetEstado()==true)
        {
        importe=deven.GetPrecioProducto()*deven.GetCantidad();
        total=total+importe;
        }
        }
        }
        }
        if(total==0)
        {
        system("cls");
        rlutil::locate(47,5);
        cout<<"No se recaudo nada con el producto";
        rlutil::getkey();
        }
        else
        {
        system("cls");
        rlutil::locate(35,5);
        cout << std::fixed << std::setprecision(0);
        cout<<"Lo que se recaudo en total del producto es de: $"<<total<<endl;
        rlutil::getkey();
        }

    }

    void informetipocliente(){
    int tipocliente=0,acumulador=0,contador=0;
    DetalleVenta deven;
    Cliente cli;
    Venta ven;
    ArchivoVentas arch1("Ventas.dat");
    ArchivoClientes arch2("Clientes.dat");
    ArchivoDetalleVentas arch3("DetalleVentas.dat");
    int cantReg1= arch3.CantidadRegistros(sizeof(DetalleVenta));
    int cantReg2= arch2.CantidadRegistros(sizeof(Cliente));
    int cantReg3= arch1.CantidadRegistros(sizeof(Venta));
    rlutil::locate(45,5);
    cout<<"selecione el tipo de cliente";
    rlutil::locate(40,7);
    cout<<"Particular";
    rlutil::locate(40,8);
    cout<<"Empresa";
    tipocliente=SeleccionMenus(38,7,1,1);
    tipocliente++;

    for(int i=0;i<cantReg2;i++)
    {
    cli=arch2.LeerCliente(i);
    if(cli.GetTipoCliente()==tipocliente)
    {
    for(int f=0;f<cantReg3;f++)
        {
            ven=arch1.LeerVenta(f);
            if(strcmp(ven.GetCuit(),cli.GetCuit())==0)
            {
                for(int a=0;a<cantReg1;a++)
                    {
                    deven=arch3.LeerDetalleDeVenta(a);
                        if(ven.GetNumeroVenta()==deven.GetNumeroVentaDT())
                        {
                        contador=deven.GetCantidad();
                        acumulador=acumulador+contador;
                        }
                    }
            }
        }

    }

    }
    cout << std::fixed << std::setprecision(0);
    if(tipocliente==1){cout<<"La cantidad de equipos vendidos por Particulares es: "<<acumulador;}
    else {cout<<"La cantidad de equipos vendidos por Empresas es: "<<acumulador;}
   rlutil::getkey();

    }





    void LimpiarBuffer(){
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
