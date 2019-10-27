#ifndef 
#define 

#include "proyectAssets.h"
#include "CPunto.h"

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
void generarMapa(entero ancho, entero alto);
void addPunto(CPunto* punto);
CPunto* removerPunto(texto _punto);
CPunto* buscarPunto(texto _punto);
CPunto* modificarPunto(*CPunto _punto);
void updateMap();
void imprimirMap();
void imprimirPuntos();
entero getAncho();
entero getAlto();
entero getCantPuntos();
void calcularRuta(CPunto* a, CPunto* b); //falta implementar
~CMap ();

};

#include "CMap.cpp"

#endif