#ifndef _BRAZO_H
#define _BRAZO_H

#include "brazo1.h"
#include "brazo2.h"
#include "pala.h"

class _brazo
{
public:
    _brazo();
    _brazo(_cylinder &cilindro, _cube &cubo, _tetrahedron &tetraedro);
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();

protected:
    _brazo1 brazo1;
    _brazo2 brazo2;
    _pala Pala;
};

#endif // _BRAZO_H
