#ifndef _BRAZO1_H
#define _BRAZO1_H

#include "cylinder.h"

class _brazo1
{
public:
    _brazo1();
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();

protected:
    _cylinder Cilindro = _cylinder(1.0, 36);
};

#endif // _BRAZO1_H
