#include <iostream>
//#include <conio.h>
#include "menu.h"


using namespace std;

    void MostrYRsaltTxt(const char *txt, int EjeX, int EjeY,bool selec){

        if(selec){
            rlutil::setBackgroundColor(rlutil::DARKGREY);
            rlutil::setColor(rlutil::WHITE);
        }else{rlutil::setBackgroundColor(rlutil::BLACK);rlutil::setColor(rlutil::GREY);}
        rlutil::locate(EjeX,EjeY);
        cout<<txt<<endl;
        rlutil::setBackgroundColor(rlutil::BLACK);
    }

    int SeleccionMenuAnim(Cadena *opciones,int EjeX, int EjeY, int CantOpc, int SaltosDeLinea){

        rlutil::hidecursor();
        int y=0, tecla;
        do{
            for(int i=0; i<=CantOpc; i++){
                MostrYRsaltTxt(opciones[i].getTexto(),EjeX,EjeY+(i*SaltosDeLinea),y/SaltosDeLinea==i);
            }
            while(1){
                if(kbhit()){tecla=getch();break;};
                rlutil::locate(EjeX-2,EjeY+y);cout<<" "<<char(175);
                if(kbhit()){tecla=getch();break;};
                rlutil::msleep(50);
                if(kbhit()){tecla=getch();break;};
                rlutil::msleep(50);
                if(kbhit()){tecla=getch();break;};
                rlutil::msleep(50);
                if(kbhit()){tecla=getch();break;};
                rlutil::msleep(50);
                if(kbhit()){tecla=getch();break;};
                rlutil::msleep(50);
                if(kbhit()){tecla=getch();break;};
                rlutil::msleep(50);
                if(kbhit()){tecla=getch();break;};
                rlutil::locate(EjeX-2,EjeY+y);cout<<char(175)<<" ";
                if(kbhit()){tecla=getch();break;};
                rlutil::msleep(50);
                if(kbhit()){tecla=getch();break;};
                rlutil::msleep(50);
                if(kbhit()){tecla=getch();break;};
                rlutil::msleep(50);
                if(kbhit()){tecla=getch();break;};
                rlutil::msleep(50);
                if(kbhit()){tecla=getch();break;};
                rlutil::msleep(50);
                if(kbhit()){tecla=getch();break;};
                rlutil::msleep(50);
                if(kbhit()){tecla=getch();break;};
            }

            switch(tecla){

                case(72):///arriba///
                    rlutil::locate(EjeX-2,EjeY+y);
                    cout<<"  "<<endl;
                    y=y-SaltosDeLinea;
                    if(y<0){y=CantOpc*SaltosDeLinea;}
                break;

                case(80):///abajo///
                    rlutil::locate(EjeX-2,EjeY+y);
                    cout<<"  "<<endl;
                    y=y+SaltosDeLinea;
                    if(y>CantOpc*SaltosDeLinea){y=0;}
                break;

                case(13):///enter///
                    system("cls");
                    if(y==CantOpc*SaltosDeLinea){return CantOpc;}
                    return y/SaltosDeLinea;
                break;

                case(27):
                    system("cls");
                    return 0;
                break;
            }
        }while(1);
        system("cls");
        rlutil::showcursor();
        return 0;
    }


int main(){

    Menu();

//    // Cuadrado sólido
//    cout << "Cuadrado solido (ASCII 219): " << (char)219 << endl;
//
//    // Cuadrados sombreados
//    cout << "Sombreado oscuro (ASCII 178): " << (char)178 << endl;
//    cout << "Sombreado medio (ASCII 177): " << (char)177 << endl;
//    cout << "Sombreado claro (ASCII 176): " << (char)176 << endl;
//
//    // Caracteres para dibujar una caja
//    cout << "Esquina superior izquierda (ASCII 218): " << (char)218 << endl;
//    cout << "Linea horizontal (ASCII 196): " << (char)196 << endl;
//    cout << "Linea vertical (ASCII 179): " << (char)179 << endl;
//
//    cout << "\n--- Dibujando una caja de ejemplo ---" << endl;
//    cout << (char)218 << (char)196 << (char)196 << (char)191 << endl;
//    cout << (char)179 << "  " << (char)179 << endl;
//    cout << (char)192 << (char)196 << (char)196 << (char)217 << endl;
//    system("pause");
//    system("cls");


    Cadena opciones[3];
    opciones[0].setTexto("Opcion 1");
    opciones[1].setTexto("Opcion 2");
    opciones[2].setTexto("Opcion 3");
    int opcion;
    do{
    opcion=SeleccionMenuAnim(opciones,41,5,2,2);
    rlutil::locate(43,5);
    cout<<opcion+1<<endl;
    system("pause");
    system("cls");
    }while(1);



return 0;
}


