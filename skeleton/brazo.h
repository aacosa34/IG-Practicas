#ifndef _BRAZO_H
#define _BRAZO_H

#include "brazo1.h"
#include "brazo2.h"
#include "pala.h"

class _brazo
{
public:
    _brazo();
    _brazo(_brazo1 &brazo1, _brazo2 &brazo2, _pala &pala);
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();

    void draw_flat_shaded_lighting();
    void draw_smooth_shaded_lighting();

protected:
    _brazo1 *Brazo1;
    _brazo2 *Brazo2;
    _pala *Pala;
};

#endif // _BRAZO_H
