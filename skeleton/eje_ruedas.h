#ifndef _EJE_RUEDAS_H
#define _EJE_RUEDAS_H

#include "rueda.h"
#include "cylinder.h"

class _eje_ruedas
{
public:
    _eje_ruedas();
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();
protected:
    _rueda Rueda;
    _cylinder Eje = _cylinder(1.0, 20);
};

#endif // _EJE_RUEDAS_H
