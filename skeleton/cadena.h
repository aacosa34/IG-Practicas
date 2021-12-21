#ifndef _CADENA_H
#define _CADENA_H

#include "eje_ruedas.h"

class _cadena
{
public:
    _cadena();
    _cadena(_eje_ruedas &Eje);
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();

    void draw_flat_shaded_lighting();
    void draw_smooth_shaded_lighting();


protected:
    _eje_ruedas *eje;
};

#endif // _CADENA_H
