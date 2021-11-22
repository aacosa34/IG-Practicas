#ifndef _RUEDA_H
#define _RUEDA_H

#include "cylinder.h"

class _rueda
{
public:
    _rueda();
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();

protected:
    _cylinder Rueda = _cylinder(1.0, 20);
};

#endif // _RUEDA_H
