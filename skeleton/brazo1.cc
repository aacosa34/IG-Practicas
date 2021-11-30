#include "brazo1.h"

_brazo1::_brazo1(_cylinder &cilindro)
{
    Cilindro=&cilindro;
}

void _brazo1::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(90,0,0,1);
    glScalef(1,2,1);
    (*Cilindro).draw_point();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,2,0);
    glScalef(1,4,1);
    (*Cilindro).draw_point();
    glPopMatrix();

}

void _brazo1::draw_line(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(90,0,0,1);
    glScalef(1,2,1);
    (*Cilindro).draw_line();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,2,0);
    glScalef(1,4,1);
    (*Cilindro).draw_line();
    glPopMatrix();

}

void _brazo1::draw_fill(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(90,0,0,1);
    glScalef(1,2,1);
    (*Cilindro).draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,2,0);
    glScalef(1,4,1);
    (*Cilindro).draw_fill();
    glPopMatrix();

}

void _brazo1::draw_chess(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(90,0,0,1);
    glScalef(1,2,1);
    (*Cilindro).draw_chess();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,2,0);
    glScalef(1,4,1);
    (*Cilindro).draw_chess();
    glPopMatrix();

}
