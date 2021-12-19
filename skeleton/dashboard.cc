#include "dashboard.h"

_dashboard::_dashboard(float Size, unsigned int divisiones)
{
    unsigned int filas = sqrt(divisiones);
    unsigned int columnas=filas;
    unsigned int triangulos=0;
    unsigned int k=0;

    float fila, tam_textura=1.0, fila_textura;

    Vertices.resize(4*divisiones);
    Triangles.resize(2*divisiones);
    Coordenadas_textura.resize(4*divisiones);

    for(unsigned int i=0; i<filas; i++){
        fila = Size/2-i*Size/columnas;
        fila_textura = tam_textura-i*tam_textura/columnas;
        for(unsigned int j=0; j<columnas; j++){
            Coordenadas_textura[k] = _vertex2f(j*tam_textura/columnas,fila_textura);
            Vertices[k]=_vertex3f(j*Size/columnas - Size/2, fila,0.0);

            Coordenadas_textura[k+1] = _vertex2f(Coordenadas_textura[k].x + tam_textura/columnas,fila_textura);
            Vertices[k+1]=_vertex3f(Vertices[k].x + Size/columnas, Vertices[k].y, 0.0);

            Coordenadas_textura[k+2] = _vertex2f(Coordenadas_textura[k+1].x,fila_textura - tam_textura/columnas);
            Vertices[k+2]=_vertex3f(Vertices[k+1].x, Vertices[k].y - Size/columnas, 0.0);

            Coordenadas_textura[k+3] = _vertex2f(Coordenadas_textura[k].x, Coordenadas_textura[k+2].y);
            Vertices[k+3]=_vertex3f(Vertices[k].x, Vertices[k+2].y, 0.0);


            Triangles[triangulos] = _vertex3ui(k,k+3,k+2);
            Triangles[triangulos+1] = _vertex3ui(k,k+2,k+1);
            k+=4;
            triangulos += 2;
        }
    }
}

void _dashboard::draw_texture(){
    glEnable(GL_TEXTURE_2D);

    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
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
