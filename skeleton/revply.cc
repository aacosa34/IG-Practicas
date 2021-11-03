#include "revply.h"

_revply::_revply(const string &File_name)
{
    int abierto=archivo.open(File_name);

    if(abierto!=0){
        vector<float> Profile;
        vector<_vertex3f> Perfil;
        vector<unsigned int> Figuras;

        archivo.read(Profile, Figuras); // Adquirimos los puntos sueltos del perfil (Figuras se quedara vacio)

        Perfil.resize(Profile.size()/3);
        int n_vertice=0;
        for(unsigned int i = 0; i<Vertices.size(); i++){
            Perfil[i] = _vertex3f(Profile[n_vertice], Profile[n_vertice+1], Profile[n_vertice+2]);
            n_vertice+=3;
        }

        crearRevolucion(Perfil, 36); // Generacion de todos los puntos y triangulos

        archivo.close();
    }
    else
    {
        cerr << "ERROR: No se ha podido leer el archivo\n";
    }
}
