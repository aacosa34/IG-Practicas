/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "object3d.h"

using namespace _colors_ne;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_line()
{
    glLineWidth(1.0);
    glColor3f(0.0f,0.0f,0.0f);
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE); // Pintamos lineas en ambas caras del poligono
    glBegin(GL_TRIANGLES); // Pintamos con triangulos
    for (unsigned int i=0;i<Triangles.size();i++){
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]); // Primera componente del triangulo
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]); // Segunda componente del triangulo
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]); // Tercera componente del triangulo
    }
    glEnd();
}


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_fill()
{
    glColor3f(1.0f, 0.5f, 0.0f); // Naranja

    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL); // Rellenamos ambas caras del poligono
    glBegin(GL_TRIANGLES); // Pintamos con triangulos
    for (unsigned int i=0;i<Triangles.size();i++){
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]); // Primera componente del triangulo
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]); // Segunda componente del triangulo
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]); // Tercera componente del triangulo
    }
    glEnd();
}


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_chess()
{
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL); // Rellenamos ambas caras del poligono
    glBegin(GL_TRIANGLES); // Pintamos con triangulos
    for (unsigned int i=0;i<Triangles.size();i++){
        if(i%2==0){
           glColor3f(0.0f, 0.0f, 0.0f);// Negro
        }

        else
           glColor3f(1.0f, 1.0f, 0.0f);// Amarillo

        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]); // Primera componente del triangulo
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]); // Segunda componente del triangulo
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]); // Tercera componente del triangulo
    }
    glEnd();
}

void _object3D::draw_flat_shaded_lighting(){
    if(!Triangles.empty()){
        calculo_normales_caras();
        calculo_normales_vertices();

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

        glShadeModel(GL_FLAT);

        glBegin(GL_TRIANGLES); // Pintamos con triangulos
        for (unsigned int i=0;i<Triangles.size();i++){
            glNormal3f(normales[i].x, normales[i].y, normales[i].z);

            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]); // Primera componente del triangulo
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]); // Segunda componente del triangulo
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]); // Tercera componente del triangulo
        }
        glEnd();
    }
}

void _object3D::draw_smooth_shaded_lighting(){
    if (!Triangles.empty()){
         calculo_normales_caras();
         calculo_normales_vertices();

         glPolygonMode(GL_FRONT, GL_FILL);
         glShadeModel(GL_SMOOTH);

         glBegin(GL_TRIANGLES);
         for (unsigned int i = 0; i<Triangles.size(); i++){
             glNormal3fv((GLfloat *) &Vertices_normales[Triangles[i]._0]);
             glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
             glNormal3fv((GLfloat *) &Vertices_normales[Triangles[i]._1]);
             glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
             glNormal3fv((GLfloat *) &Vertices_normales[Triangles[i]._2]);
             glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);

         }
         glEnd();
     }
}

// Funcion que calcula las normales de todas las caras
// y las almacena en otro vector de normales.
void _object3D::calculo_normales_caras(){
    _vertex3f a, b, n;
    float modulo;

    for(unsigned int i=0; i < Triangles.size(); i++){

        // Vector a
        a(Vertices[Triangles[i]._1]._0 - Vertices[Triangles[i]._0]._0,
          Vertices[Triangles[i]._1]._1 - Vertices[Triangles[i]._0]._1,
          Vertices[Triangles[i]._1]._2 - Vertices[Triangles[i]._0]._2);

        // Vector b
        b(Vertices[Triangles[i]._2]._0 - Vertices[Triangles[i]._0]._0,
          Vertices[Triangles[i]._2]._1 - Vertices[Triangles[i]._0]._1,
          Vertices[Triangles[i]._2]._2 - Vertices[Triangles[i]._0]._2);

        // Vector Producto vectorial entre a y b
        n((a.y * b.z) - (a.z * b.y),
          -((a.x * b.z) - (a.z * b.x)),
          (a.x * b.y) - (a.y * b.x));

        modulo = sqrt(pow(n.x, 2) + pow(n.y, 2) + pow(n.z, 2));

        n.x /= modulo;
        n.y /= modulo;
        n.z /= modulo;

        normales.push_back(n);

    }
}

void _object3D::calculo_normales_vertices(){
    float modulo;

    if(!Vertices.empty()){
        Vertices_normales.resize(Vertices.size()); // Cada vertice tiene una normal
        n_normales.resize(Vertices.size());

        for(unsigned int i = 0; i < Triangles.size(); i++){
            Vertices_normales[Triangles[i]._0] += normales[i];
            Vertices_normales[Triangles[i]._1] += normales[i];
            Vertices_normales[Triangles[i]._2] += normales[i];
        }

        for(unsigned int i = 0; i < Vertices_normales.size(); i++){
            modulo = sqrt(pow(Vertices_normales[i].x,2) + pow(Vertices_normales[i].y,2) + pow(Vertices_normales[i].z,2));

            Vertices_normales[i].x /= modulo;
            Vertices_normales[i].y /= modulo;
            Vertices_normales[i].z /= modulo;
        }
    }
}

void _object3D::draw_texture(){
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);
    glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
    glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
    draw_fill();
    glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
    glDisable(GL_TEXTURE_2D);
}

void _object3D::draw_texture_flat_shading_lighting(){
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

void _object3D::draw_texture_smooth_shading_lighting(){
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
