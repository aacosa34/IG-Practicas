#include "ply_matrix.h"

_ply_matrix::_ply_matrix(int Lado)
{
    int tamanio=Lado*Lado;
    lado = Lado;

    MatrizPly.resize(tamanio);
    for(int i=0; i<tamanio; i++){
        MatrizPly[i].init("../ply_models/big_porsche.ply");
    }
}

void _ply_matrix::draw(int tipo){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    float R, G, B;
    for(int i = 0; i<lado; i++){
        for(int j = 0; j<lado; j++){
            glPushMatrix();
            glTranslatef(i*15,0,j*15);

            if(objeto_seleccionado==(j+(i*lado))){
                glColor3f(0.0f,0.0f,1.0f);
            }

            if(tipo==2){
                R = ((j + (i * lado)) & 0x00FF0000) >> 16;
                G = ((j + (i * lado)) & 0x0000FF00) >> 8;
                B = ((j + (i * lado)) & 0x000000FF);
                glColor3f(R/255.0f, G/255.0f, B/255.0f);
            }

            MatrizPly[j+(i*lado)].draw_fill();

            if(objeto_seleccionado==(j+(i*lado))){
                glColor3f(0.0f,1.0f,1.0f);
            }

            glPopMatrix();
        }
    }
    glPopMatrix();
}

void _ply_matrix::selected_object(int objeto){
    objeto_seleccionado=objeto;
}
