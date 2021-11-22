#ifndef _PALA_H
#define _PALA_H

#include "cube.h"

class _pala
{
public:
    _pala();
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();
protected:
    _cube Cubo;
};

#endif // _PALA_H
