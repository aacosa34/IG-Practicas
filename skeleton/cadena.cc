#include "cadena.h"

_cadena::_cadena()
{

}

void _cadena::draw_point(){}

void _cadena::draw_line(){
    // EJE1
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0,2);
    eje.draw_line();
    glPopMatrix();

    // EJE2
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0,1);
    eje.draw_line();
    glPopMatrix();

    // EJE3
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    eje.draw_line();
    glPopMatrix();

    // EJE4
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0,-1);
    eje.draw_line();
    glPopMatrix();

    // EJE5
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0,-2);
    eje.draw_line();
    glPopMatrix();
}

void _cadena::draw_fill(){}

void _cadena::draw_chess(){}
