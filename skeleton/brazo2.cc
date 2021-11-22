#include "brazo2.h"

_brazo2::_brazo2()
{

}

void _brazo2::draw_point(){}

void _brazo2::draw_line(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(90,0,0,1);
    glScalef(1.5,1,1.5);
    Cilindro.draw_line();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0,2.75);
    glRotatef(90,1,0,0);
    glScalef(1,4,1);
    Cilindro.draw_line();
    glPopMatrix();

}
void _brazo2::draw_fill(){}

void _brazo2::draw_chess(){}
