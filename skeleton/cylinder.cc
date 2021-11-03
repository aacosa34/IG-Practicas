#include "cylinder.h"

_cylinder::_cylinder(float Size, int Faces)
{
    // GENERACION DE LOS VERTICES

    vector<_vertex3f> perfil;

    perfil.push_back(_vertex3f(0.0, Size, 0.0));
    perfil.push_back(_vertex3f(Size/2, Size, 0.0));
    perfil.push_back(_vertex3f(Size/2, 0.0, 0.0));
    perfil.push_back(_vertex3f(0.0, 0.0, 0.0));

    crearRevolucion(perfil, Faces);
}
