#include "rueda.h"

_rueda::_rueda()
{

}

void _rueda::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(90,0,0,1);
    glScalef(0.75,1,0.75);
    Rueda.draw_point();
    glPopMatrix();
}

void _rueda::draw_line(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(90,0,0,1);
    glScalef(0.75,1,0.75);
    Rueda.draw_line();
    glPopMatrix();
}

void _rueda::draw_fill(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(90,0,0,1);
    glScalef(0.75,1,0.75);
    Rueda.draw_fill();
    glPopMatrix();
}

void _rueda::draw_chess(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(90,0,0,1);
    glScalef(0.75,1,0.75);
    Rueda.draw_chess();
    glPopMatrix();
}
