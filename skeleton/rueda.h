#ifndef _RUEDA_H
#define _RUEDA_H

#include "cylinder.h"

class _rueda
{
public:
    _rueda();
    _rueda(_cylinder &cilindro);
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();

    void draw_flat_shaded_lighting();
    void draw_smooth_shaded_lighting();


protected:
    _cylinder *Rueda;
};

#endif // _RUEDA_H
