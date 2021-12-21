#ifndef _PALA_H
#define _PALA_H

#include "cube.h"
#include "cylinder.h"
#include "tetrahedron.h"

class _pala
{
public:
    _pala();
    _pala(_cylinder &cilindro, _cube &cubo, _tetrahedron &tetraedro);
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();

    void draw_flat_shaded_lighting();
    void draw_smooth_shaded_lighting();

protected:
    _cube *Cubo;
    _cylinder *Cilindro;
    _tetrahedron *Tetraedro;
};

#endif // _PALA_H
