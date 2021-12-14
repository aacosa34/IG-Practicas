#ifndef _SPHERE_H
#define _SPHERE_H

#include "objectrev.h"

class _sphere:public _objectrev
{
public:
    _sphere(float Size=1.0, int Faces=36, int Profile=36);
    void calculo_normales_vertices();
    void calculo_normales_caras();
    void draw_flat_shaded_lighting();
    void draw_smooth_shaded_lighting();

private:
    _vertex2f centro = _vertex2f(0.0,0.0);
};

#endif // _SPHERE_H
