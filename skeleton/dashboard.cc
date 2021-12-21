#include "dashboard.h"

_dashboard::_dashboard(float Size, unsigned int divisiones)
{
    int k = 0, t=0;
    unsigned int fils_cols = sqrt(divisiones);
    Vertices.resize(4*divisiones);
    Triangles.resize(2*divisiones);
    Coordenadas_textura.resize(4*divisiones);
    for(unsigned int i=0; i<fils_cols; i++){ // filas
        for(unsigned int j=0; j<fils_cols; j++){ // columnas
            Coordenadas_textura[k] = _vertex2f(j*Size/fils_cols, Size-i*Size/fils_cols);
            Coordenadas_textura[k+1] = _vertex2f(Coordenadas_textura[k]._0 + Size/fils_cols, Coordenadas_textura[k]._1);
            Coordenadas_textura[k+2] = _vertex2f(Coordenadas_textura[k+1]._0, Coordenadas_textura[k]._1 - Size/fils_cols);
            Coordenadas_textura[k+3] = _vertex2f(Coordenadas_textura[k]._0, Coordenadas_textura[k+2]._1);

            Vertices[k] = _vertex2f(j*Size/fils_cols-Size/2, Size/2-i*Size/fils_cols);
            Vertices[k+1] = _vertex2f(Vertices[k]._0 + Size/fils_cols, Vertices[k]._1);
            Vertices[k+2] = _vertex2f(Vertices[k+1]._0, Vertices[k]._1 - Size/fils_cols) ;
            Vertices[k+3] = _vertex2f(Vertices[k]._0, Vertices[k+2]._1);

            Triangles[t] = _vertex3ui(k, k+3, k+2);
            Triangles[t+1] = _vertex3ui(k, k+2, k+1);
            k+=4;
            t+=2;
        }
    }
}

void _dashboard::draw_texture(){

    glEnable(GL_TEXTURE_2D);

    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    for(unsigned int i=0; i<Triangles.size(); i++){
        glTexCoord2f(Coordenadas_textura[Triangles[i]._0]._0,Coordenadas_textura[Triangles[i]._0]._1);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
        glTexCoord2f(Coordenadas_textura[Triangles[i]._1]._0,Coordenadas_textura[Triangles[i]._1]._1);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
        glTexCoord2f(Coordenadas_textura[Triangles[i]._2]._0,Coordenadas_textura[Triangles[i]._2]._1);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }
    glEnd();
    glDisable(GL_TEXTURE_2D);

}

void _dashboard::draw_texture_flat_shading_lighting(){
    calculo_normales_caras();
    calculo_normales_vertices();

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);
    glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
    glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
    draw_flat_shaded_lighting();
    glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
    glDisable(GL_TEXTURE_2D);
}

void _dashboard::draw_texture_smooth_shading_lighting(){
    calculo_normales_caras();
    calculo_normales_vertices();

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);
    glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
    glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
    glShadeModel(GL_SMOOTH);
    draw_smooth_shaded_lighting();
    glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
    glDisable(GL_TEXTURE_2D);
}
