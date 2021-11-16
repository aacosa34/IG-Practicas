#include "brazo1.h"

_brazo1::_brazo1()
{

}

void _brazo1::draw_point(){}

void _brazo1::draw_line(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-1,1.5,0);
    glRotatef(90, 0, 0, 1);
    glScalef(2, 1, 2);
    Cilindro.draw_line();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-1,3.5,2);
    glRotatef(45,1,0,0);
    glScalef(1,3,1);
    Cilindro.draw_line();
    glPopMatrix();
}

void _brazo1::draw_fill(){}

void _brazo1::draw_chess(){}
