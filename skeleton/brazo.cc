#include "brazo.h"

_brazo::_brazo(_cylinder &cilindro, _cube &cubo, _tetrahedron &tetraedro)
{
    _brazo1 Brazo1 = _brazo1(cilindro);
    _brazo2 Brazo2 = _brazo2(cilindro);
    _pala Pala = _pala(cilindro, cubo, tetraedro);
    brazo1 = &Brazo1;
    brazo2 = &Brazo2;
    pala = &Pala;
}

void _brazo::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    brazo1->draw_point();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,4.75,0);
    //glRotatef(angulo_brazo2,1,0,0);
    brazo2->draw_point();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,3,5.5);
    //glRotatef(angulo_brazo2,1,0,0);
    pala->draw_point();
    glPopMatrix();
}

void _brazo::draw_line(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    brazo1->draw_line();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,4.75,0);
    //glRotatef(angulo_brazo2,1,0,0);
    brazo2->draw_line();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,3,5.5);
    //glRotatef(angulo_brazo2,1,0,0);
    pala->draw_line();
    glPopMatrix();

}

void _brazo::draw_fill(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    brazo1->draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,4.75,0);
    //glRotatef(angulo_brazo2,1,0,0);
    brazo2->draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,3,5.5);
    //glRotatef(angulo_brazo2,1,0,0);
    pala->draw_fill();
    glPopMatrix();
}

void _brazo::draw_chess(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    brazo1->draw_chess();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,4.75,0);
    //glRotatef(angulo_brazo2,1,0,0);
    brazo2->draw_chess();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,3,5.5);
    //glRotatef(angulo_brazo2,1,0,0);
    pala->draw_chess();
    glPopMatrix();
}


