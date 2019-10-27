#include "CMap.h"

int menu() {
    int x;
    cout<<"\nEliga entre las siguientes opciones: ";
    cout<<"\n1. Calcular la ruta entre dos puntos";
    cout<<"\n2. Modificar un punto";
    cout<<"\n3. Borrar un punto";
    cout<<"\n4. Salir del programa\n";
    cin>>x;
    return x;
}


void ruta(CMap mapa) {
    texto _name;
    mapa->imprimirPuntos();
    CPunto** temp=NULL;
    cout<<"\nEliga los puntos entre los cuales se va a calcular la ruta:";
    for (int i = 0; i<2; i++) {
        do {
            cout<<"\nPunto "<<i+1<<": ";
            cin>>_name;
        } while (mapa->buscarPunto(_name)==NULL);
        temp[i]=buscarPunto(_name);
    }
    mapa->calcularRuta(temp[0], temp[1]);
    delete [] temp;
}

void modificar(CMap mapa) {
    texto _name;
    mapa->imprimirPuntos();
    CPunto* porModif=NULL;
    do {
        cout<<"\nEscriba el nombre del punto a modificar o 0 para retornar: ";
        cin>>_name;
        if (_name =='0')
            break;
        porModif=buscarPunto(_name!);
        if (porModif!=NULL) {
            modificarPunto(porModif);
        } else
            cout<<"\nEl punto "<<_name<<" no existe.";
    } while (_name != '0');
}

void eliminar(CMap mapa) {
    texto _name;
    mapa->imprimirPuntos();
    do {
        cout<<"\nEscriba el nombre del punto a eliminar o 0 para retornar: ";
        cin>>_name;
        if (_name =='0')
            break;
        if (mapa->buscarPunto(_name)!=NULL) {
            mapa->removerPunto(_name);
            cout<<"\nEl punto "<<_name<<" ha sido removido satisfactoriamente\n";
            break;
        } else
            cout<<"\nEl punto "<<_name<<" no existe.";
    } while (_name != '0');
}