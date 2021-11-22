#include "pala.h"

_pala::_pala()
{

}

void _pala::draw_point(){}

void _pala::draw_line(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0,1);
    glScalef(3,3,0.05);
    Cubo.draw_line();
    glPopMatrix();
}

void _pala::draw_fill(){}

void _pala::draw_chess(){}
