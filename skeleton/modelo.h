#ifndef _MODELO_H
#define _MODELO_H

#include "object3d.h"
#include "cabeza.h"
#include "brazo1.h"
#include "brazo2.h"
#include "pala.h"
#include "eje_ruedas.h"
#include "cube.h"

class _modelo
{
public:
    _modelo();
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();

protected:
    _cube Cubo;
    _cabeza Cabeza;
    _brazo1 Brazo1;
    _brazo2 Brazo2;
    _pala Pala;
    _eje_ruedas eje;
};

#endif // _MODELO_H
