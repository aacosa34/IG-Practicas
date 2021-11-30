#ifndef _BRAZO2_H
#define _BRAZO2_H

#include "cylinder.h"

class _brazo2
{
public:
    _brazo2();
    _brazo2(_cylinder &cilindro);
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();
protected:
    _cylinder *Cilindro;
};

#endif // _BRAZO2_H
