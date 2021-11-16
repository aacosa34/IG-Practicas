#ifndef _BASE_H
#define _BASE_H

#include "object3d.h"
#include "cube.h"
#include "cabeza.h"

class _base:public _cabeza
{
public:
    _base();
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();

protected:
    _cube Cubo;
};

#endif // _BASE_H
