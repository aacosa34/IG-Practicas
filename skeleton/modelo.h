#ifndef _MODELO_H
#define _MODELO_H

#include "object3d.h"
#include "cabeza.h"
#include "cadena.h"
#include "cube.h"

class _modelo
{
public:
    _modelo();
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();

    void girar_cuerpo_derecha();
    void girar_cuerpo_izquierda();
    void aumentar_grados_cuerpo();
    void disminuir_grados_cuerpo();

    void adelantar_brazo();
    void atrasar_brazo();

    float angulo_cuerpo=0;
    float velocidad_cuerpo=5;

protected:
    _cube Cubo;
    _cabeza Cabeza;
    _cadena Cadena;
};

#endif // _MODELO_H
