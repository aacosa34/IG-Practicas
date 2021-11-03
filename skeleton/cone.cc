#include "cone.h"

_cone::_cone(float Size, int Faces)
{
    // GENERACION DE VERTICES
    vector<_vertex3f> perfil;

    perfil.push_back(_vertex3f(0.0, 0.0, 0.0));
    perfil.push_back(_vertex3f(Size/2, 0.0, 0.0));
    perfil.push_back(_vertex3f(0.0, Size, 0.0));

    crearRevolucion(perfil, Faces);
}
