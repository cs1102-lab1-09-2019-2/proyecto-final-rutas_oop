#include "CMap.h"


void rEspacio(simbolo* s)
{
    simbolo* cpy = s;
    simbolo* temp = s;
    while (*cpy)
    {
        if (*cpy != ' ')
            *temp++ = *cpy;
        cpy++;
    }
    *temp = 0;
    cout << s << endl;
}

void displayMaps() {
  texto mapaListado;
  ifstream mapaMostrado;
  texto lineTemp;
	for (int i=1; i<11; i++) {
		mapaListado = to_string(i)+".txt";
		cout<<mapaListado<<"\n";
    mapaMostrado.open(mapaListado.c_str());
    while (getline (mapaMostrado, lineTemp)) {
      cout<<lineTemp<<"\n";
    } cout<<"\n";
    mapaMostrado.close();
	  }
  }

void loadBoot() {
  displayMaps();
  texto nombreMapa;
  ifstream mapaElegido;
  texto line;
  entero row=0;
  cout<<"Ingrese el número del mapa que quiere usar: ";

  do {
    cin>>nombreMapa;
  } while(stoi(nombreMapa)<0 || stoi(nombreMapa)>10);

  CMap* laberinto = new CMap();
  nombreMapa = nombreMapa + ".txt";
  mapaElegido.open(nombreMapa.c_str());
/*
      simbolo cstr[line.size()+1];
      strcpy(cstr, line.c_str());
      entero j=0+(i*line.size());
      while (j<line.size()){
        if(cstr[j]=='1')
        laberinto->getMap()[i][j]='1';
        if(cstr[j]=='0')
        laberinto->getMap()[i][j]='0';
        j++;
      }
      i++;
*/
  while(getline(mapaElegido,line)) {
    if(cstr[col]=='1')
    laberinto->getMap()[row][col]='1';
    if(cstr[row]=='0')
    laberinto->getMap()[row][col]='0';
    row++;
    }
  
  mapaElegido.close();
 
  laberinto->imprimirMap();
  
  entero numPuntos, cx, cy;
  texto nombre;
  simbolo marca;
 
  do {
  cout<<"\nIngrese cantidad de puntos (al menos dos): ";
  cin>>numPuntos;
  } while (numPuntos < 2);
  laberinto->setCantPuntos(numPuntos);
  laberinto->updateList();

  for (int i = 0; i < numPuntos; i++) {
      cout<<"\nPunto "<<i+1<<" :";
      cout<<"\nIngrese nombre del punto: ";
      cin>>nombre;
      do {
          cout<<"\nIngrese un símbolo que represente el punto: ";
          cin>>marca;
      } while (marca== '1' || marca == '0');
      do {
        do {
            cout<<"\nIngrese coordenadas en x de 0 a 19: ";
            cin>>cx;
        } while (cx<0 || cx>laberinto->getAncho()-1);
        do {
            cout<<"\nIngrese coordenadas en y de 0 a 19: ";
            cin>>cy;
        } while (cy<0 || cy>laberinto->getAlto()-1);
      } while(laberinto->getMap()[cx][cy]=='1');
      laberinto->addPunto(new CPunto(nombre, marca, cx, cy), i);
  }
  cout<<"\n";
  laberinto->imprimirMap();
  laberinto->imprimirPuntos();
  cout<<"\nElegir los dos puntos entre los que se va a calcular la ruta:";
  string a, b;
  do {
    cout<<"\nPunto de inicio: ";
    cin>>a;
  } while(!(laberinto->verificarNombre(a)));
  do {
    cout<<"\nPunto de llegada: ";
    cin>>b;
  } while(!(laberinto->verificarNombre(b)));
  laberinto->BFS(laberinto->buscarPunto(a)->getX(),
  laberinto->buscarPunto(a)->getY(),
  laberinto->buscarPunto(b)->getX(),
  laberinto->buscarPunto(b)->getY());
}

void randomBoot() {
  entero largo=20, altura=20;

  CMap* laberinto = new CMap(altura,largo);
  laberinto->generarMapa();
  laberinto->imprimirMap();

  entero numPuntos, cx, cy;
  texto nombre;
  simbolo marca;

  do {
  cout<<"\nIngrese cantidad de puntos (al menos dos): ";
  cin>>numPuntos;
  } while (numPuntos < 2);
  laberinto->setCantPuntos(numPuntos);
  laberinto->updateList();

  for (int i = 0; i < numPuntos; i++) {
      cout<<"\nPunto "<<i+1<<" :";
      cout<<"\nIngrese nombre del punto: ";
      cin>>nombre;
      do {
          cout<<"\nIngrese un símbolo que represente el punto: ";
          cin>>marca;
      } while (marca== '1' || marca == '0');
      do {
        do {
            cout<<"\nIngrese coordenadas en x de 0 a 19: ";
            cin>>cx;
        } while (cx<-1 || cx>laberinto->getAncho()-1);
        do {
            cout<<"\nIngrese coordenadas en y de 0 a 19: ";
            cin>>cy;
        } while (cy<-1 || cy>laberinto->getAlto()-1);
      } while(laberinto->getMap()[cx][cy]=='1');
      laberinto->addPunto(new CPunto(nombre, marca, cx, cy), i);
  }
  cout<<"\n";
  laberinto->imprimirMap();
  laberinto->imprimirPuntos();
  cout<<"\nElegir los dos puntos entre los que se va a calcular la ruta:";
  string a, b;
  do {
    cout<<"\nPunto de inicio: ";
    cin>>a;
  } while(!(laberinto->verificarNombre(a)));
  do {
    cout<<"\nPunto de llegada: ";
    cin>>b;
  } while(!(laberinto->verificarNombre(b)));
  laberinto->BFS(laberinto->buscarPunto(a)->getX(),
  laberinto->buscarPunto(a)->getY(),
  laberinto->buscarPunto(b)->getX(),
  laberinto->buscarPunto(b)->getY());
}

void menu() {
    int x;
    cout<<"\nEliga entre las siguientes opciones: ";
    cout<<"\n1. Elegir mapa existente";
    cout<<"\n2. Crear mapa aleatorio";
    do{
    cout<<"\nIngrese su opción: ";
    cin>>x;} while(x>2 || x<1);
    switch(x){
      case 1:
      loadBoot();
      break;
      case 2:
      randomBoot();
      break;
      default:
      cout<<"\nNo es una opción válida\n";
    }
}

int main() {
srand (time(NULL));
menu();
return 0;
}
