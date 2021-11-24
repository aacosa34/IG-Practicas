#include "pala.h"

_pala::_pala()
{

}

void _pala::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,-1,0);
    glScalef(3,0.05,2);
    Cubo.draw_point();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-1.5,0,0);
    glScalef(0.05,2,2);
    Tetraedro.draw_point();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1.5,0,0);
    glScalef(0.05,2,2);
    Tetraedro.draw_point();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0,0.5);
    glRotatef(63,1,0,0);
    glScalef(3,0.05,2.25);
    Cubo.draw_point();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,1.75,0);
    glRotatef(90,0,0,1);
    glScalef(1.5,1,1.5);
    Cilindro.draw_point();
    glPopMatrix();
}

void _pala::draw_line(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,-1,0);
    glScalef(3,0.05,2);
    Cubo.draw_line();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-1.5,0,0);
    glScalef(0.05,2,2);
    Tetraedro.draw_line();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1.5,0,0);
    glScalef(0.05,2,2);
    Tetraedro.draw_line();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0,0.5);
    glRotatef(63,1,0,0);
    glScalef(3,0.05,2.25);
    Cubo.draw_line();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,1.75,0);
    glRotatef(90,0,0,1);
    glScalef(1.5,1,1.5);
    Cilindro.draw_line();
    glPopMatrix();
}

void _pala::draw_fill(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,-1,0);
    glScalef(3,0.05,2);
    Cubo.draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-1.5,0,0);
    glScalef(0.05,2,2);
    Tetraedro.draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1.5,0,0);
    glScalef(0.05,2,2);
    Tetraedro.draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0,0.5);
    glRotatef(63,1,0,0);
    glScalef(3,0.05,2.25);
    Cubo.draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,1.75,0);
    glRotatef(90,0,0,1);
    glScalef(1.5,1,1.5);
    Cilindro.draw_fill();
    glPopMatrix();
}

void _pala::draw_chess(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,-1,0);
    glScalef(3,0.05,2);
    Cubo.draw_chess();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-1.5,0,0);
    glScalef(0.05,2,2);
    Tetraedro.draw_chess();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1.5,0,0);
    glScalef(0.05,2,2);
    Tetraedro.draw_chess();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0,0.5);
    glRotatef(63,1,0,0);
    glScalef(3,0.05,2.25);
    Cubo.draw_chess();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,1.75,0);
    glRotatef(90,0,0,1);
    glScalef(1.5,1,1.5);
    Cilindro.draw_chess();
    glPopMatrix();
}
