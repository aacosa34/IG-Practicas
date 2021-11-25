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
