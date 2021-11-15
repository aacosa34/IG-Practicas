#include "cabeza.h"

void _cabeza::crear()
{

}

void _cabeza::draw_point(){}

void _cabeza::draw_line(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1.5,0.4,1);
    Cubo.draw_line();
    glPopMatrix();
}

void _cabeza::draw_fill(){}

void _cabeza::draw_chess(){}
