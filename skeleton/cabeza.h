#ifndef _CABEZA_H
#define _CABEZA_H

#include "cube.h"


class _cabeza
{
public:
    void crear();
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();

protected:
    _cube Cubo;
};

#endif // _CABEZA_H
