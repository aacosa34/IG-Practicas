#ifndef _CADENA_H
#define _CADENA_H

#include "eje_ruedas.h"

class _cadena
{
public:
    _cadena();
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();

protected:
    _eje_ruedas eje;
};

#endif // _CADENA_H
