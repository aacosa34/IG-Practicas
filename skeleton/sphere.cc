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
