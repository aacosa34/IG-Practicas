#include "cadena.h"

_cadena::_cadena(_eje_ruedas &Eje)
{
    eje = &Eje;
}

void _cadena::draw_point(){
    // EJE1
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0,2);
    eje->draw_point();
    glPopMatrix();

    // EJE2
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0,1);
    eje->draw_point();
    glPopMatrix();

    // EJE3
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    eje->draw_point();
    glPopMatrix();

    // EJE4
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0,-1);
    eje->draw_point();
    glPopMatrix();

    // EJE5
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0,-2);
    eje->draw_point();
    glPopMatrix();
}

void _cadena::draw_line(){
    // EJE1
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0,2);
    eje->draw_line();
    glPopMatrix();

    // EJE2
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0,1);
    eje->draw_line();
    glPopMatrix();

    // EJE3
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    eje->draw_line();
    glPopMatrix();

    // EJE4
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0,-1);
    eje->draw_line();
    glPopMatrix();

    // EJE5
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0,-2);
    eje->draw_line();
    glPopMatrix();
}

void _cadena::draw_fill(){
    // EJE1
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0,2);
    eje->draw_fill();
    glPopMatrix();

    // EJE2
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0,1);
    eje->draw_fill();
    glPopMatrix();

    // EJE3
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    eje->draw_fill();
    glPopMatrix();

    // EJE4
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0,-1);
    eje->draw_fill();
    glPopMatrix();

    // EJE5
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0,-2);
    eje->draw_fill();
    glPopMatrix();
}

void _cadena::draw_chess(){
    // EJE1
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0,2);
    eje->draw_chess();
    glPopMatrix();

    // EJE2
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0,1);
    eje->draw_chess();
    glPopMatrix();

    // EJE3
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    eje->draw_chess();
    glPopMatrix();

    // EJE4
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0,-1);
    eje->draw_chess();
    glPopMatrix();

    // EJE5
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0,-2);
    eje->draw_chess();
    glPopMatrix();
}

void _cadena::draw_flat_shaded_lighting(){
    // EJE1
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0,2);
    eje->draw_flat_shaded_lighting();
    glPopMatrix();

    // EJE2
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0,1);
    eje->draw_flat_shaded_lighting();
    glPopMatrix();

    // EJE3
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    eje->draw_flat_shaded_lighting();
    glPopMatrix();

    // EJE4
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0,-1);
    eje->draw_flat_shaded_lighting();
    glPopMatrix();

    // EJE5
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0,-2);
    eje->draw_flat_shaded_lighting();
    glPopMatrix();
}

void _cadena::draw_smooth_shaded_lighting(){
    // EJE1
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0,2);
    eje->draw_smooth_shaded_lighting();
    glPopMatrix();

    // EJE2
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0,1);
    eje->draw_smooth_shaded_lighting();
    glPopMatrix();

    // EJE3
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    eje->draw_smooth_shaded_lighting();
    glPopMatrix();

    // EJE4
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0,-1);
    eje->draw_smooth_shaded_lighting();
    glPopMatrix();

    // EJE5
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0,-2);
    eje->draw_smooth_shaded_lighting();
    glPopMatrix();
}
