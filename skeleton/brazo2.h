#ifndef _BRAZO2_H
#define _BRAZO2_H

#include "cylinder.h"

class _brazo2
{
public:
    _brazo2();
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();
protected:
    _cylinder Cilindro = _cylinder(1.0, 20);
};

#endif // _BRAZO2_H
