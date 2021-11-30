#ifndef _EJE_RUEDAS_H
#define _EJE_RUEDAS_H

#include "rueda.h"
#include "cylinder.h"

class _eje_ruedas
{
public:
    _eje_ruedas();
    _eje_ruedas(_cylinder &cilindro);
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();
protected:
    _rueda Rueda;
    _cylinder *Eje;
};

#endif // _EJE_RUEDAS_H
