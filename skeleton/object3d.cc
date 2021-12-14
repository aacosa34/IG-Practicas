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
        glPushMatrix();
        GLfloat color[] = {0.0, 1.0, 0.0, 1.0};
        //glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
        GLfloat ambient[] = {1.0, 1.0, 1.0, 1.0};
        //glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
        GLfloat white[] = { 1.0f, 1.0f, 1.0f, 1.0f };
        //glMaterialfv(GL_FRONT, GL_SPECULAR, white);
        //glColor3fv((GLfloat *) &GREEN);
        glPopMatrix();
        glShadeModel(GL_FLAT);

        glBegin(GL_TRIANGLES); // Pintamos con triangulos
        for (unsigned int i=0;i<Triangles.size();i++){
            glNormal3f(Triangles_normales[i].x, Triangles_normales[i].y, Triangles_normales[i].z);

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
         glPushMatrix();
         GLfloat color[] = {1.0, 1.0, 0.0, 1.0};
        // glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
         GLfloat ambient[] = {1.0, 1.0, 1.0, 1.0};
        // glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
         GLfloat white[] = { 1.0f, 1.0f, 1.0f, 1.0f };
        // glMaterialfv(GL_FRONT, GL_SPECULAR, white);
         //glColor3fv((GLfloat *) &YEllOW);
         glPopMatrix();
         glShadeModel(GL_SMOOTH);

         glBegin(GL_TRIANGLES);
         for (unsigned int i = 0; i<Triangles.size(); i++){
             glNormal3f(Vertices_normales[Triangles[i]._0].x, Vertices_normales[Triangles[i]._0].y, Vertices_normales[Triangles[i]._0].z);
             glVertex3f(Vertices[Triangles[i]._0].x, Vertices[Triangles[i]._0].y, Vertices[Triangles[i]._0].z);
             //glNormal3fv((GLfloat *) &Vertices_normals[Triangles[i]._0]);
            // glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);

             glNormal3f(Vertices_normales[Triangles[i]._1].x, Vertices_normales[Triangles[i]._1].y, Vertices_normales[Triangles[i]._1].z);
             glVertex3f(Vertices[Triangles[i]._1].x, Vertices[Triangles[i]._1].y, Vertices[Triangles[i]._1].z);
             //glNormal3fv((GLfloat *) &Vertices_normals[Triangles[i]._1]);
             //glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);

             glNormal3f(Vertices_normales[Triangles[i]._2].x, Vertices_normales[Triangles[i]._2].y, Vertices_normales[Triangles[i]._2].z);
             glVertex3f(Vertices[Triangles[i]._2].x, Vertices[Triangles[i]._2].y, Vertices[Triangles[i]._2].z);
           //  glNormal3fv((GLfloat *) &Vertices_normals[Triangles[i]._2]);
           //  glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);

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

        n /= modulo;

        Triangles_normales.push_back(n);

    }
}

void _object3D::calculo_normales_vertices(){
    float modulo;

    if(!Vertices.empty()){
        Vertices_normales.resize(Vertices.size()); // Cada vertice tiene una normal
        n_normales.resize(Vertices.size());

        for(unsigned int i = 0; i < Triangles.size(); i++){
            Vertices_normales[Triangles[i]._0] += Triangles_normales[i];
            n_normales[Triangles[i]._0]++;
            Vertices_normales[Triangles[i]._1] += Triangles_normales[i];
            n_normales[Triangles[i]._1]++;
            Vertices_normales[Triangles[i]._2] += Triangles_normales[i];
            n_normales[Triangles[i]._2]++;
        }

        for(unsigned int i = 0; i < Vertices_normales.size(); i++){
            modulo = sqrt(pow(Vertices_normales[i].x,2) + pow(Vertices_normales[i].y,2) + pow(Vertices_normales[i].z,2));

            Vertices_normales[i] /= n_normales[i];
            Vertices_normales[i] /= modulo;
        }
    }
}
