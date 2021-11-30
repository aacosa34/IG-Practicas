#ifndef _MODELO_H
#define _MODELO_H

#include "object3d.h"
#include "cabeza.h"
#include "cadena.h"
#include "cube.h"
#include "tetrahedron.h"

class _modelo
{
public:
    _modelo();
    _modelo(_cylinder &cilindro, _cube &cubo, _tetrahedron &tetraedro);
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();

    void girar_cuerpo_derecha();
    void girar_cuerpo_izquierda();
    void aumentar_grados_cuerpo();
    void disminuir_grados_cuerpo();

    void inclinar_brazo_adelante();
    void inclinar_brazo_atras();
    void aumentar_grados_brazo();
    void disminuir_grados_brazo();

    void adelantar_brazo();
    void atrasar_brazo();
    void aumentar_velocidad_brazo();
    void disminuir_velocidad_brazo();

    float getDesplazamientoBrazo();
    float getAnguloBrazo();

    float angulo_cuerpo=0;
    float velocidad_cuerpo=1;

protected:
    _cube *Cubo;
    _cabeza Cabeza;
    _cadena Cadena;
};

#endif // _MODELO_H
