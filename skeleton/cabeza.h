#ifndef _CABEZA_H
#define _CABEZA_H

#include "cube.h"
#include "brazo1.h"


class _cabeza:public _brazo1
{
public:
    _cabeza();
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();

protected:
    _cube Cubo;
};

#endif // _CABEZA_H
