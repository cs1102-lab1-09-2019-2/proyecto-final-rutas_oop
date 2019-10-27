#include "CMap.h"
#include "functions.h"

int main() {

srand (time(NULL));
entero largo, altura;

cout<<"Ingrese alto del mapa: ";
cin>>altura;
cout<<"\nIngrese ancho del mapa: ";
cin>>largo;
cout<<"\n";

CMap* laberinto = new CMap(altura,largo);
laberinto.imprimirMap();

entero numPuntos, cx, cy;
texto nombre;
simbolo marca;

do {
cout<<"Ingrese cantidad de puntos (al menos dos): ";
cin>>numPuntos;
} while (numPuntos < 2);

for (int i = 0; i < numPuntos; i++) {
    cout<<"\nPunto "<<i+1<<" :";
    cout<<"\nIngrese nombre del punto: ";
    cin>>nombre;
    do {
        cout<<"\nIngrese un símbolo que represente el punto: ";
        cin>>marca;
    } while (marca=='1' || '0');
    do {
        cout<<"\nIngrese coordenadas en x: ";
        cin>>cx;
    } while (cx<0 || cx>laberinto->getAncho()-1);
    do {
        cout<<"\nIngrese coordenadas en y: ";
        cin>>cy;
    } while (cy<0 || cy>laberinto->getAlto()-1);

    laberinto->addPunto(new CPunto(nombre, marca, cx, cy));
    laberinto->updateMap();

}

entero answer;

do {
    answer=menu();
    switch (answer) {
        case 1:
            ruta(laberinto);
        case 2:
            modificar(laberinto);
        case 3:
            eliminar(laberinto);
        case 4:
            cout<<"\nSaliendo del programa...";
            break;
        default:
            cout<<"\nNo es una opcion valida";
    }
} while (answer!=4);

return 0;
}