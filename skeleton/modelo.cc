#include "modelo.h"


_modelo::_modelo(_cube &cubo, _cadena &cadena, _cabeza &cabeza)
{
    Cubo = &cubo;
    Cadena = &cadena;
    Cabeza = &cabeza;
}

void _modelo::draw_point(){
    // Ruedas
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    Cadena->draw_point();
    glPopMatrix();

    // Base de la excavadora
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,1,0);
    glScalef(4,0.5,5);
    (*Cubo).draw_point();
    glPopMatrix();

    // Cabeza o cabina de la excavadora
    // Esta parte va a girar en el eje y sobre la base
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,1.5,0);
    glRotatef(angulo_cuerpo,0,1,0);
    Cabeza->draw_point();
    glPopMatrix();
}

void _modelo::draw_line(){
    // Ruedas
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    Cadena->draw_line();
    glPopMatrix();

    // Base de la excavadora
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,1,0);
    glScalef(4,0.5,5);
    (*Cubo).draw_line();
    glPopMatrix();

    // Cabeza o cabina de la excavadora
    // Esta parte va a girar en el eje y sobre la base
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,1.5,0);
    glRotatef(angulo_cuerpo,0,1,0);
    Cabeza->draw_line();
    glPopMatrix();

}

void _modelo::draw_fill(){
    // Ruedas
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    Cadena->draw_fill();
    glPopMatrix();

    // Base de la excavadora
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,1,0);
    glScalef(4,0.5,5);
    (*Cubo).draw_fill();
    glPopMatrix();

    // Cabeza o cabina de la excavadora
    // Esta parte va a girar en el eje y sobre la base
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,1.5,0);
    glRotatef(angulo_cuerpo,0,1,0);
    Cabeza->draw_fill();
    glPopMatrix();
}

void _modelo::draw_chess(){
    // Ruedas
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    Cadena->draw_chess();
    glPopMatrix();

    // Base de la excavadora
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,1,0);
    glScalef(4,0.5,5);
    (*Cubo).draw_chess();
    glPopMatrix();

    // Cabeza o cabina de la excavadora
    // Esta parte va a girar en el eje y sobre la base
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,1.5,0);
    glRotatef(angulo_cuerpo,0,1,0);
    Cabeza->draw_chess();
    glPopMatrix();
}

void _modelo::draw_flat_shaded_lighting(){
    // Ruedas
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    Cadena->draw_flat_shaded_lighting();
    glPopMatrix();

    glEnable(GL_NORMALIZE);
    // Base de la excavadora
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,1,0);
    glScalef(4,0.5,5);
    (*Cubo).draw_flat_shaded_lighting();
    glPopMatrix();
    glDisable(GL_NORMALIZE);

    // Cabeza o cabina de la excavadora
    // Esta parte va a girar en el eje y sobre la base
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,1.5,0);
    glRotatef(angulo_cuerpo,0,1,0);
    Cabeza->draw_flat_shaded_lighting();
    glPopMatrix();
}

void _modelo::draw_smooth_shaded_lighting(){
    // Ruedas
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    Cadena->draw_smooth_shaded_lighting();
    glPopMatrix();

    glEnable(GL_NORMALIZE);
    // Base de la excavadora
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,1,0);
    glScalef(4,0.5,5);
    (*Cubo).draw_smooth_shaded_lighting();
    glPopMatrix();
    glDisable(GL_NORMALIZE);

    // Cabeza o cabina de la excavadora
    // Esta parte va a girar en el eje y sobre la base
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,1.5,0);
    glRotatef(angulo_cuerpo,0,1,0);
    Cabeza->draw_smooth_shaded_lighting();
    glPopMatrix();
}


void _modelo::girar_cuerpo_derecha(){
    angulo_cuerpo+=velocidad_cuerpo;
}

void _modelo::girar_cuerpo_izquierda(){
    angulo_cuerpo-=velocidad_cuerpo;
}

void _modelo::aumentar_grados_cuerpo(){
    if(velocidad_cuerpo<20)
        velocidad_cuerpo++;
}

void _modelo::disminuir_grados_cuerpo(){
    if(velocidad_cuerpo>2)
        velocidad_cuerpo--;
}

void _modelo::inclinar_brazo_adelante(){
    Cabeza->inclinar_adelante_brazo();
}

void _modelo::inclinar_brazo_atras(){
    Cabeza->inclinar_atras_brazo();
}

void _modelo::aumentar_grados_brazo(){
    Cabeza->aumentar_grados_brazo();
}

void _modelo::disminuir_grados_brazo(){
    Cabeza->disminuir_grados_brazo();
}

void _modelo::adelantar_brazo(){
    Cabeza->adelantar_brazo();
}

void _modelo::atrasar_brazo(){
    Cabeza->atrasar_brazo();
}

void _modelo::aumentar_velocidad_brazo(){
    Cabeza->aumentar_velocidad_brazo();
}

void _modelo::disminuir_velocidad_brazo(){
    Cabeza->disminuir_velocidad_brazo();
}

float _modelo::getDesplazamientoBrazo(){
    return Cabeza->desplazamiento_brazo;
}

float _modelo::getAnguloBrazo(){
    return Cabeza->angulo_brazo;
}

