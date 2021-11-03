#ifndef _OBJECTREV_H
#define _OBJECTREV_H

#include "object3d.h"

class _objectrev:public _object3D
{
public:
    void crearRevolucion(vector<_vertex3f> perfil, int Faces); // Funcion que crea una revolucion a partir de un perfil dado
};

#endif // _OBJECTREV_H
