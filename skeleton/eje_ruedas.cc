#include "eje_ruedas.h"

_eje_ruedas::_eje_ruedas(_rueda &rueda, _cylinder &cilindro)
{
    Rueda = &rueda;
    Eje = &cilindro;
}

void _eje_ruedas::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1.5,0.375,0);
    Rueda->draw_point();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.375,0);
    glRotatef(90,0,0,1);
    glScalef(0.1,2,0.1);
    (*Eje).draw_point();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-1.5,0.375,0);
    Rueda->draw_point();
    glPopMatrix();
}

void _eje_ruedas::draw_line(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1.5,0.375,0);
    Rueda->draw_line();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.375,0);
    glRotatef(90,0,0,1);
    glScalef(0.1,2,0.1);
    (*Eje).draw_line();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-1.5,0.375,0);
    Rueda->draw_line();
    glPopMatrix();
}

void _eje_ruedas::draw_fill(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1.5,0.375,0);
    Rueda->draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.375,0);
    glRotatef(90,0,0,1);
    glScalef(0.1,2,0.1);
    (*Eje).draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-1.5,0.375,0);
    Rueda->draw_fill();
    glPopMatrix();
}

void _eje_ruedas::draw_chess(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1.5,0.375,0);
    Rueda->draw_chess();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.375,0);
    glRotatef(90,0,0,1);
    glScalef(0.1,2,0.1);
    (*Eje).draw_chess();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-1.5,0.375,0);
    Rueda->draw_chess();
    glPopMatrix();
}
