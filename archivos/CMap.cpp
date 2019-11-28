#include "CMap.h"

void CMap::generarMapa() {
    M=new simbolo*[alto];
    for (int i=0;i<alto;i++)
      M[i]=new simbolo[ancho];

  entero a;
    for(int i=0;i<alto;i++){
      for(int j=0;j<ancho;j++){ 
        if(i==0){
          a = rand()%2;
          if (a==0) {M[i][j]='0';}
          else {M[i][j]='1';}
        } else
            if (i<alto-1){
                if(M[i-1][j+1]=='1')
                    M[i][j]='0';
                else
                    { a = rand()%2;
                      if (a==0) {M[i][j]='0';}
                      else {M[i][j]='1';}
                    }
            } else {
               if (M[i-1][j]==1)
                   M[i][j]='0';
               else
                   {  a = rand()%2;
                      if (a==0) {M[i][j]='0';}
                      else {M[i][j]='1';}
              }
          }
      }
  }
}
CMap::CMap() {
    ancho=defAncho;
    alto=defAlto;
    cantPuntos=defPunto;
    M=new simbolo*[alto];
    for (int i=0;i<alto;i++)
      M[i]=new simbolo[ancho];
}

CMap::CMap (entero _ancho, entero _alto) {
      cantPuntos=0;
    if (_ancho>defAncho)
        ancho = _ancho;
    if (alto>defAlto)
        alto = _alto;
    else {
        ancho = defAncho;
        alto = defAlto;
    }
}

void CMap::updateMap() {
    for (int i = 0; i < cantPuntos; i++)
        M[puntos[i]->getX()][puntos[i]->getY()]=puntos[i]->getMark();
}

void CMap::updateList() {
  puntos = new CPunto*[cantPuntos];
}

void CMap::addPunto(CPunto* _punto, entero i) {
     M[_punto->getX()][_punto->getY()] = _punto->getMark();
     puntos[i] = _punto;
}
CPunto* CMap::buscarPunto(texto _nombre) {
    for (int i = 0; i < cantPuntos; ++i) {
        if (_nombre == puntos[i]->getName())
            return puntos[i];
    }
    return NULL;
}

bool CMap::verificarNombre(texto nombre) {
  for (int i = 0; i< cantPuntos; i++) {
    if (nombre == puntos[i]->getName()) {
      return true;
      }
    }
    return false;
  }

void CMap::imprimirMap() {
    for (int i=0; i<alto; i++){
      for (int j=0; j<ancho; j++) {
        cout<<M[i][j]<<" ";
      }
      cout<<"\n";
    }
}

void CMap::imprimirPuntos() {
    for (int i = 0; i < cantPuntos; i++) {
        cout<<"\n"<<puntos[i]->getName()<<" | "<<puntos[i]->getMark()
        <<" está en ("<<puntos[i]->getY()<<", "<<puntos[i]->getX()<<")";
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

simbolo** CMap::getMap() {
    return M;
}

CMap::~CMap() {
    for (int i= 0; i<alto; i++) {
        delete [] M[i];
    }
    delete [] M;
    M = NULL;
}

booleano CMap::isValid(booleano visited[20][20], entero row, entero col)
{
 return (row >= 0) && (row < alto) && (col >= 0) && (col < ancho)
  && M[row][col] && !visited[row][col];
}

void CMap::BFS(entero i, entero j, entero x, entero y)
{
 int row[] = { -1, 0, 0, 1 };
 int col[] = { 0, -1, 1, 0 };
 char temp=M[x][y];
 booleano visited[20][20];

 memset(visited, false, sizeof (visited));

 queue<CNode> q;

 visited[i][j] = true;
 q.push({i, j, 0});

 entero min_dist = INT_MAX;
 vector<entero>secuencia;

 while (!q.empty()) 
 {
  CNode node = q.front();
  q.pop();
  entero i = node.x, j = node.y, dist = node.dist;

  if (i == x && j == y) 
  {
   min_dist = dist;
   break;
  }

  for (int k = 0; k < 4; k++) 
  {
   if (isValid(visited, i + row[k], j + col[k]) && M[i+row[k]][j+col[k]] != '1')
   {int n,m;
   
    visited[i + row[k]][j + col[k]] = true;

    q.push({ i + row[k], j + col[k], dist + 1 });
    
    secuencia.emplace_back(i+row[k]);
    secuencia.emplace_back(j+col[k]);
    M[i+row[k]][j+col[k]] = '-';
   }
  }
   M[x][y]=temp;
 }

 if (min_dist != INT_MAX)
  { imprimirMap();
    cout << "La distancia más corta tiene longitud "
     << min_dist-1<<"\n";
    cout<<"Para encontrar la ruta, el BFS pasó por: \n";
    for (int a=0; a<secuencia.size()/2; a++) {
      cout<<"("<<secuencia[a]<<", "<<secuencia[a+1]<<")\n";
      }

     }
}
