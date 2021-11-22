#include "brazo1.h"

_brazo1::_brazo1()
{

}

void _brazo1::draw_point(){}

void _brazo1::draw_line(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(90,0,0,1);
    glScalef(1,2,1);
    Cilindro.draw_line();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,2,0);
    glScalef(1,4,1);
    Cilindro.draw_line();
    glPopMatrix();

}
void _brazo1::draw_fill(){}

void _brazo1::draw_chess(){}
