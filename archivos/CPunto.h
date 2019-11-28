#include "proyectAssets.h"

class CPunto {

private:
    entero x;
    entero y;
    simbolo mark;
    texto name;

public:
    CPunto (texto _name, simbolo _mark, entero _x, entero _y);
    CPunto (const CPunto &otroPunto);
    entero getX();
    entero getY();
    entero getG();
    entero getF();
    entero getH();
    entero getTempG();
    texto getName();
    simbolo getMark();
    ~CPunto ();
    void setG(entero _g);
    void setF(entero _f);
    void setH(entero _h);
    void setTempG(entero _tg);
    void setX(entero _x);
    void setY(entero _y);
    void setName(texto _name);
    void setMark(simbolo _mark);
    void imprimirXY();
};
