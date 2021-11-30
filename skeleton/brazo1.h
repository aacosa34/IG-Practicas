#ifndef _BRAZO1_H
#define _BRAZO1_H

#include "cylinder.h"

class _brazo1
{
public:
    _brazo1();
    _brazo1(_cylinder &cilindro);
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();

protected:
    _cylinder *Cilindro;
};

#endif // _BRAZO1_H
