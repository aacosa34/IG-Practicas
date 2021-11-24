#include "cabeza.h"

_cabeza::_cabeza()
{

}

void _cabeza::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(4,0.5,5);
    Cubo.draw_point();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1,1.75,0);
    glScalef(2,3,5);
    Cubo.draw_point();
    glPopMatrix();

    // Brazo completo
    // Dentro de Brazo estan por separado cada una de sus partes
    // a partir de aqui el brazo por completo se mueve hacia adelante y hacia atras
    // y rota sobre si mismo
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0,desplazamiento_brazo);
    glTranslatef(-1,0.25,0);
    glRotatef(angulo_brazo,1,0,0);
    Brazo.draw_point();
    glPopMatrix();
}

void _cabeza::draw_line(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(4,0.5,5);
    Cubo.draw_line();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1,1.75,0);
    glScalef(2,3,5);
    Cubo.draw_line();
    glPopMatrix();

    // Brazo completo
    // Dentro de Brazo estan por separado cada una de sus partes
    // a partir de aqui el brazo por completo se mueve hacia adelante y hacia atras
    // y rota sobre si mismo
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0,desplazamiento_brazo);
    glTranslatef(-1,0.25,0);
    glRotatef(angulo_brazo,1,0,0);
    Brazo.draw_line();
    glPopMatrix();
}
void _cabeza::draw_fill(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(4,0.5,5);
    Cubo.draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1,1.75,0);
    glScalef(2,3,5);
    Cubo.draw_fill();
    glPopMatrix();

    // Brazo completo
    // Dentro de Brazo estan por separado cada una de sus partes
    // a partir de aqui el brazo por completo se mueve hacia adelante y hacia atras
    // y rota sobre si mismo
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0,desplazamiento_brazo);
    glTranslatef(-1,0.25,0);
    glRotatef(angulo_brazo,1,0,0);
    Brazo.draw_fill();
    glPopMatrix();
}

void _cabeza::draw_chess(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(4,0.5,5);
    Cubo.draw_chess();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1,1.75,0);
    glScalef(2,3,5);
    Cubo.draw_chess();
    glPopMatrix();

    // Brazo completo
    // Dentro de Brazo estan por separado cada una de sus partes
    // a partir de aqui el brazo por completo se mueve hacia adelante y hacia atras
    // y rota sobre si mismo
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0,desplazamiento_brazo);
    glTranslatef(-1,0.25,0);
    glRotatef(angulo_brazo,1,0,0);
    Brazo.draw_chess();
    glPopMatrix();
}

void _cabeza::adelantar_brazo(){
    if(desplazamiento_brazo<2)
        desplazamiento_brazo+=velocidad_desplazamiento;
}

void _cabeza::atrasar_brazo(){
    if(desplazamiento_brazo>-2){
        desplazamiento_brazo-=velocidad_desplazamiento;
    }
}

void _cabeza::aumentar_velocidad_brazo(){
    if(velocidad_desplazamiento<1)
        velocidad_desplazamiento+=0.1;
}

void _cabeza::disminuir_velocidad_brazo(){
    if(velocidad_desplazamiento>0)
        velocidad_desplazamiento-=0.1;
}

void _cabeza::inclinar_adelante_brazo(){
    if(angulo_brazo<45)
        angulo_brazo+=velocidad_brazo;
}

void _cabeza::inclinar_atras_brazo(){
    if(angulo_brazo>-45)
        angulo_brazo-=velocidad_brazo;
}

void _cabeza::aumentar_grados_brazo(){
    if(velocidad_brazo<20)
        velocidad_brazo++;
}

void _cabeza::disminuir_grados_brazo(){
    if(velocidad_brazo>2)
        velocidad_brazo--;
}

