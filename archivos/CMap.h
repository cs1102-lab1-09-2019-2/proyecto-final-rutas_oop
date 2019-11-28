#include "CPunto.h"
#include "CNode.h"

const entero defAncho = 20;
const entero defAlto = 20;
const entero defPunto = 0;

class CMap {

private:
  entero ancho;
  entero alto;
  simbolo** M;
  entero cantPuntos;
  CPunto** puntos = NULL;
public:
  CMap();
  CMap (entero _ancho, entero _alto);
  void generarMapa();
  void addPunto(CPunto* punto, entero i);
  CPunto* buscarPunto(texto _punto);
  void updateList();
  void updateMap();
  booleano verificarNombre(string nombre);
  void imprimirMap();
  void imprimirPuntos();
  void setCantPuntos(entero n) {cantPuntos = n;}
  entero getAncho();
  entero getAlto();
  entero getCantPuntos();
  simbolo** getMap();
  booleano isValid(booleano visited[20][20], entero row, entero col);
  void BFS(entero startX, entero startY, entero finishX, entero finishY);
  ~CMap ();
};
