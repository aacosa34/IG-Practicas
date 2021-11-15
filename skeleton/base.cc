#include "base.h"

void _base::crear()
{
    _cabeza::crear();
}

void _base::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(3,0.75,2);
    glTranslatef(0,1.1,0);
    Cubo.draw_point();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,1.4,0);
    _cabeza::draw_point();
    glPopMatrix();
}

void _base::draw_line(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(3,0.75,2);
    glTranslatef(0,1.1,0);
    Cubo.draw_line();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,1.4,0);
    _cabeza::draw_line();
    glPopMatrix();
}

void _base::draw_fill(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(3,0.75,2);
    glTranslatef(0,1.1,0);
    Cubo.draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,1.4,0);
    _cabeza::draw_fill();
    glPopMatrix();
}

void _base::draw_chess(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(3,0.75,2);
    glTranslatef(0,1.1,0);
    Cubo.draw_chess();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,1.4,0);
    _cabeza::draw_chess();
    glPopMatrix();
}
