#include "rueda.h"

_rueda::_rueda()
{

}

void _rueda::draw_point(){}

void _rueda::draw_line(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.5,0.25,0.5);
    Rueda.draw_line();
    glPopMatrix();
}

void _rueda::draw_fill(){}

void _rueda::draw_chess(){}
