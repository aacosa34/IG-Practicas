#include "brazo.h"

_brazo::_brazo(_brazo1 &brazo1, _brazo2 &brazo2, _pala &pala)
{
    Brazo1 = &brazo1;
    Brazo2 = &brazo2;
    Pala = &pala;
}

void _brazo::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    Brazo1->draw_point();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,4.75,0);
    Brazo2->draw_point();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,3,5.5);
    Pala->draw_point();
    glPopMatrix();
}

void _brazo::draw_line(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    Brazo1->draw_line();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,4.75,0);
    Brazo2->draw_line();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,3,5.5);
    Pala->draw_line();
    glPopMatrix();

}

void _brazo::draw_fill(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    Brazo1->draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,4.75,0);
    Brazo2->draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,3,5.5);
    Pala->draw_fill();
    glPopMatrix();
}

void _brazo::draw_chess(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    Brazo1->draw_chess();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,4.75,0);
    Brazo2->draw_chess();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,3,5.5);
    Pala->draw_chess();
    glPopMatrix();
}

void _brazo::draw_flat_shaded_lighting(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    Brazo1->draw_flat_shaded_lighting();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,4.75,0);
    Brazo2->draw_flat_shaded_lighting();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,3,5.5);
    Pala->draw_flat_shaded_lighting();
    glPopMatrix();
}

void _brazo::draw_smooth_shaded_lighting(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    Brazo1->draw_smooth_shaded_lighting();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,4.75,0);
    Brazo2->draw_smooth_shaded_lighting();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,3,5.5);
    Pala->draw_smooth_shaded_lighting();
    glPopMatrix();
}


