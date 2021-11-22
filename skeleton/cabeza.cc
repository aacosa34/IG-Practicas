#include "cabeza.h"

_cabeza::_cabeza()
{

}

void _cabeza::draw_point(){}

void _cabeza::draw_line(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(4,0.5,5);
    Cubo.draw_line();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1,1.75,0);
    glScalef(2,3,5);
    Cubo.draw_line();
    glPopMatrix();
}
void _cabeza::draw_fill(){}

void _cabeza::draw_chess(){}
