#ifndef _SPHERE_H
#define _SPHERE_H

#include "objectrev.h"

class _sphere:public _objectrev
{
public:
    _sphere(float Size=1.0, int Faces=100, int Profile=100);
};

#endif // _SPHERE_H
