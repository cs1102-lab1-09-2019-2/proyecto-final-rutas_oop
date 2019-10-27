#include "CMap.h"

CMap::CMap() {
    ancho=defAncho;
    alto=defAlto;
    cantPuntos=defPunto;
    generarMapa(ancho, alto);
}

CMap::CMap(entero _ancho, entero _alto) {
    cantPuntos=0;
    if (x>defAncho) {
        ancho = _ancho;
    } if (y>defAlto)
        alto = _alto;
    } else {
        ancho = defAncho;
        alto = defAlto;
    }
    generarMapa(ancho, alto);
}

void CMap::generarMapa(entero ancho, entero alto) {

    M=new simbolo*[alto];
    for (int i=0;i<alto;i++)
    M[i]=new simbolo[ancho];

    for(int i=0;i<alto;i++){
      for(int j=0;j<ancho;j++){
        if(i==0)
            M[i][j]=(simbolo)rand()%2;
        else
            if (i<alto-1){
                if(M[i-1][j+1]==1)
                    M[i][j]=(simbolo)0;
                else
                    M[i][j] =(simbolo)rand()%2;  
            } else {
               if (M[i-1][j]==1)
                   M[i][j]=(simbolo)0;
               else
                   M[i][j] =(simbolo)rand()%2;
            }
    }
}

void CMap::addPunto(CPunto* _punto) {
     CPunto** temp = new CPunto*[cantPuntos + 1];
     for (int i = 0; i < cantPuntos; ++i)
         temp[i] = puntos[i];
     temp[cantPuntos]= punto;
     cantPuntos++;
}

CPunto* CMap::buscarPunto(texto _nombre) {
    for (int i = 0; i < cantPuntos; ++i) {
        if (_nombre == puntos[i]->getName())
            return puntos[i];
    }
    return NULL;
}

CPunto* CMap::removerPunto(texto _nombre) {
    auto punto = buscarPunto(_nombre);

    if (punto == NULL)
       return NULL;

    CPunto** temp = new CPunto*[cantPuntos-1];
    int j=0;
    for (int = 0; i < cantPuntos; i++) {
        if (puntos[i] ! = punto) {
            temp[j]=puntos[i];
            j++
        } else {
            M[puntos[i]->getX()][puntos[i]->getY()]='0';
        }
    }
    puntos = temp;
    cantPuntos--;
    return punto;
}

void CMap::modificarPunto(*CPunto _punto) {
            entero newX, newY;
            simbolo newMark;
            texto newName;
            do {
                cout<<"\nIngrese nuevo valor para la coordenada x: ";
                cin>>newX;
            } while (newX > mapa->getAncho() || newX<0);
            do {
            cout<<"\nIngrese nuevo valor para la coordenada y: ";
            cin>>newY;
            } while (newY > mapa->getAlto() || newY<0);
            do {
            cout<<"\nIngrese nuevo marcador para el punto: ";
            cin>>newMark;
            } while (newMark=='1' || newMark=='0');
            cout<<"\Ingrese nuevo nombre para el punto: ";
            cin>>newName;
            M[_punto->getX()][_punto->getY()]='0';
            _punto->setX(newX);
            _punto->setY(newY);
            _punto->setMark(newMark);
            _punto->setName(newName);
            mapa->updateMap();
}

void CMap::updateMap() {
    for (int i =0; i < cantPuntos; i++)
        M[puntos[i]->getX()][puntos[i]->getY()]=puntos[i]->getMark();
}

void CMap::imprimirMap() {
    for (int i=0; i<alto; i++){
      for (int j=0; j<ancho; j++) {
        cout<<M[i][j]<<setw(2)<<" ";
      }
      cout<<"\n";
    }
}

void CMap::imprimirPuntos() {
    for (int i = 0; i < cantPuntos; i++) {
        cout<<"\n"<<puntos[i]->getName()<<" | "<<puntos[i]->getMark()
        <<"en ("<<puntos[i]->getX()<<", "<<puntos[i]->getY()<<")";
    }
}

entero CMap::getAncho() {
    return ancho;
}

entero CMap::getAlto() {
    return alto;
}

entero CMap::getCantPuntos() {
    return cantPuntos;
}

CMap::~CMap() {
    for (int i= 0; i<alto; i++) {
        delete [] M[i];
    }

    delete [] M;
    M = NULL;
}