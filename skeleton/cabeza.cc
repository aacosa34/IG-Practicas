#include "cabeza.h"

_cabeza::_cabeza()
{
    _brazo1();
}

void _cabeza::draw_point(){}

void _cabeza::draw_line(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(2,3,4);
    Cubo.draw_line();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-1,-3,0);  // Movemos la figura al origen de coordenadas
    _brazo1::draw_line();
    glPopMatrix();

}

void _cabeza::draw_fill(){}

void _cabeza::draw_chess(){}
