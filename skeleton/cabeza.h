#ifndef _CABEZA_H
#define _CABEZA_H

#include "cube.h"
#include "brazo.h"

class _cabeza
{
public:
    _cabeza();
    _cabeza(_cube &cubo, _brazo &brazo);
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();

    void inclinar_adelante_brazo();
    void inclinar_atras_brazo();
    void aumentar_grados_brazo();
    void disminuir_grados_brazo();

    void adelantar_brazo();
    void atrasar_brazo();
    void aumentar_velocidad_brazo();
    void disminuir_velocidad_brazo();

    float desplazamiento_brazo=0;
    float velocidad_desplazamiento=0.1;
    float angulo_brazo=0;
    float velocidad_brazo=2;

protected:
    _cube *Cubo;
    _brazo *Brazo;
};

#endif // _CABEZA_H
