#include "modelo.h"


_modelo::_modelo()
{

}

void _modelo::draw_point(){
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

void _modelo::draw_line(){
    // Base de la excavadora
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,1,0);
    glScalef(4,0.5,5);
    Cubo.draw_line();
    glPopMatrix();

    // Cabeza o cabina de la excavadora
    // Esta parte va a girar en el eje y sobre la base
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,1.5,0);
    Cabeza.draw_line();
    glPopMatrix();

    // Brazo 1
    // a partir de aqui el brazo por completo se mueve hacia adelante y hacia atras
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-1,1.75,0);
    Brazo1.draw_line();
    glPopMatrix();

    // Brazo 2
    // Esta parte del brazo rota sobre si mismo de la misma manera que el anterior
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-1,6.5,0);
    Brazo2.draw_line();
    glPopMatrix();

    // Pala
    // La pala se mueve hacia adelante o hacia atras
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    Pala.draw_line();
    glPopMatrix();

}

void _modelo::draw_fill(){
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

void _modelo::draw_chess(){
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
