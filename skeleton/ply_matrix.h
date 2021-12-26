#ifndef _PLY_MATRIX_H
#define _PLY_MATRIX_H

#include "object3d.h"
#include "ply.h"

class _ply_matrix
{
private:
    int objeto_seleccionado = -1;
    vector<_ply> MatrizPly;
    int lado;
public:
    _ply_matrix(int Lado=4);
    void selected_object(int objeto);
    void draw(int tipo=1);

};

#endif // _PLY_MATRIX_H
