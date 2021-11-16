#include "base.h"

_base::_base()
{
    _cabeza();
}

void _base::draw_point(){
    /*
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.75,0);
    glScalef(4,0.5,4);
    Cubo.draw_point();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,2.5,0);
    _cabeza::draw_point();
    glPopMatrix();
    */
}

void _base::draw_line(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,1,0);
    glScalef(4,1,4);
    Cubo.draw_line();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1,3,0);
    _cabeza::draw_line();
    glPopMatrix();
}

void _base::draw_fill(){
    /*
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.75,0);
    glScalef(4,0.5,4);
    Cubo.draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,2.5,0);
    _cabeza::draw_fill();
    glPopMatrix();
    */
}

void _base::draw_chess(){
    /*
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.75,0);
    glScalef(4,0.5,4);
    Cubo.draw_chess();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,2.5,0);
    _cabeza::draw_chess();
    glPopMatrix();
    */
}
