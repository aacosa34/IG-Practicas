#ifndef _DASHBOARD_H
#define _DASHBOARD_H

#include "object3d.h"
#include "cube.h"

class _dashboard:public _object3D
{
public:
    _dashboard(float Size=1.0, unsigned int divisiones=16);

    void draw_texture();
    void draw_texture_flat_shading_lighting();
    void draw_texture_smooth_shading_lighting();

protected:
    unsigned int Divisiones;
};

#endif // _DASHBOARD_H
