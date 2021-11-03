#include "objectrev.h"

void _objectrev::crearRevolucion(vector<_vertex3f> perfil, int Faces)
{
    float radianes = 2*M_PI/Faces;
    int n_tapas=0;

    _vertex3f t_inferior = perfil.front();
    _vertex3f t_superior = perfil.back();

    if(t_superior._0 == 0.0 && t_superior._2 == 0.0){
        n_tapas++;
        perfil.erase(perfil.begin());
    }

    if(t_inferior._0 == 0.0 && t_inferior._2 == 0.0){
        n_tapas++;
        perfil.erase(perfil.end()-1);
    }

    int Profile = perfil.size(); // Puntos que realmente se generan (sin las tapas)

    // El numero de vertices es igual que el numero de caras por el numero de puntos que
    // tiene el perfil mas los puntos de las tapas
    Vertices.resize(Faces*Profile+n_tapas);

    for(int n=0; n<Faces; n++){
        for(int i = 0; i<Profile; i++){
            float x = perfil[i]._0*cos(radianes*n);
            float y = perfil[i]._1;
            float z = -perfil[i]._0*sin(radianes*n);

            Vertices[n*Profile+i] = _vertex3f(x, y, z);
        }
    }

    Vertices[Vertices.size()-2] = t_inferior;
    Vertices[Vertices.size()-1] = t_superior;

    _vertex3ui triangulo;

    // En cada cara hay dos triangulos por el numero de puntos que se revolucionan del perfil
    Triangles.resize(Faces*2*Profile);

    int n=0;
    for(int row=0; row<Profile-1; row++){
        for(int col=0; col<Faces; col++){
            // Crear el triangulo par
            triangulo._0 = (col%Faces)*(Profile)+(row+1);
            triangulo._1 = (col%Faces)*(Profile)+row;
            triangulo._2 = ((col+1)%Faces)*(Profile)+row;

            Triangles[n++] = triangulo;

            // Crear el triangulo impar
            triangulo._0 = (col%Faces)*(Profile)+(row+1);
            triangulo._1 = ((col+1)%Faces)*(Profile)+row;
            triangulo._2 = ((col+1)%Faces)*(Profile)+(row+1);

            Triangles[n++] = triangulo;
        }
    }

    for(int i = 0; i<Faces; i++){
        triangulo._0 = Profile*i;
        triangulo._1 = Vertices.size()-2;
        triangulo._2 = (Profile*(i+1))%(Vertices.size()-2);

        Triangles[n++] = triangulo;

    }

    for(int i = 1; i<=Faces; i++){
        triangulo._0 = Vertices.size()-1;
        triangulo._1 = (Profile)*i-1;
        triangulo._2 = ((Profile)*(i+1)-1)%(Vertices.size()-2);

        Triangles[n++] = triangulo;
    }
//
}



