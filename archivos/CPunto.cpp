#include "CPunto.h"

CPunto::CPunto(texto _name, simbolo _mark, entero _x, entero _y) {
    name = _name; 
    if (mark!='0' || mark !='1' || mark!='.')
        mark = _mark;
    else
        mark = 'x';
    x = _x;
    y = _y;
}

CPunto::CPunto (const CPunto &otroPunto) {
    name = otroPunto.name;
    mark = otroPunto.mark;
    x = otroPunto.x;
    y = otroPunto.y;
}

entero CPunto::getX() {
    return x;
}

entero CPunto::getY() {
    return y;
}

texto CPunto::getName() {
    return name;
}

simbolo CPunto::getMark() {
    return mark;
}

CPunto:: ~CPunto () {

}

void CPunto::setX(entero _x) {
    x = _x;
}

void CPunto::setY(entero _y) {
    y = _y;
}

void CPunto::setName(texto _name) {
    name = _name;
}

void CPunto::setMark(simbolo _mark) {
    mark = _mark;
}

void CPunto::imprimirXY() {
    cout<<"\nEl punto "<<getName()<<"se encuentra en ("<<getX()<<", "<<getY()<<")";
}
