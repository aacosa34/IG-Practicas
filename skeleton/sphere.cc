    #include "sphere.h"

_sphere::_sphere(float Size, int Faces, int Profile)
{
    float radianes=M_PI/Profile;
    float radio=Size;

    vector<_vertex3f> perfil;

    // GENERACION DEL PERFIL
    for(int i=0; i<Profile; i++){
        float x=radio*sin(radianes*i);
        float y=radio*cos(radianes*i);

        perfil.push_back(_vertex3f(x, y, 0.0));
    }

    perfil.push_back(_vertex3f(0.0, -Size, 0.0)); // Para que salga bien al crear revolucion

    crearRevolucion(perfil, Faces);
}

void _sphere::calculo_normales_vertices(){
    float modulo;

    if(!Vertices.empty()){
        Vertices_normales.resize(Vertices.size()); // Cada vertice tiene su normal que va del centro a cada uno de los vertices
        n_normales.resize(Vertices.size());

        for(unsigned int i=0; i<Vertices.size(); i++){
            Vertices_normales[i] = _vertex3f(Vertices[i]._0-centro._0, Vertices[i]._1-centro._1, Vertices[i]._2);

            modulo = sqrt(pow(Vertices_normales[i]._0,2) + pow(Vertices_normales[i]._1,2) + pow(Vertices_normales[i]._2,2));

            Vertices_normales[i] /= modulo;
        }

    }
}

// Funcion que calcula las normales de todas las caras
// y las almacena en otro vector de normales.
void _sphere::calculo_normales_caras(){
    _vertex3f a, b, n;
    float modulo;

    for(unsigned int i=0; i < Triangles.size(); i++){

        // Vector a
        b(Vertices[Triangles[i]._1]._0 - Vertices[Triangles[i]._0]._0,
          Vertices[Triangles[i]._1]._1 - Vertices[Triangles[i]._0]._1,
          Vertices[Triangles[i]._1]._2 - Vertices[Triangles[i]._0]._2);

        // Vector b
        a(Vertices[Triangles[i]._2]._0 - Vertices[Triangles[i]._0]._0,
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

void _sphere::draw_flat_shaded_lighting(){
    if(!Triangles.empty()){
        this->calculo_normales_caras();
        this->calculo_normales_vertices();

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glPushMatrix();
//        GLfloat color[] = {0.0, 1.0, 0.0, 1.0};
        //glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
//        GLfloat ambient[] = {1.0, 1.0, 1.0, 1.0};
        //glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
//        GLfloat white[] = { 1.0f, 1.0f, 1.0f, 1.0f };
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

void _sphere::draw_smooth_shaded_lighting(){
    if (!Triangles.empty()){
         this->calculo_normales_caras();
         this->calculo_normales_vertices();

         glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
         glPushMatrix();
//         GLfloat color[] = {1.0, 1.0, 0.0, 1.0};
        // glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
//         GLfloat ambient[] = {1.0, 1.0, 1.0, 1.0};
        // glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
//         GLfloat white[] = { 1.0f, 1.0f, 1.0f, 1.0f };
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
