#include "ply.h"

_ply::_ply(const string &File_name)
{
    int abierto=archivo.open(File_name);

    if(abierto!=0){
        vector<float> Vertex;
        vector<unsigned int> Figuras;

        archivo.read(Vertex, Figuras); // Leemos en forma de vector todos los vertices y triangulos

        Vertices.resize(Vertex.size()/3);
        int n_vertice = 0;
        for(unsigned int i=0; i<Vertices.size(); i++){
            Vertices[i] = _vertex3f(Vertex[n_vertice], Vertex[n_vertice+1], Vertex[n_vertice+2] );
            n_vertice+=3;
        }

        Triangles.resize(Figuras.size()/3);
        int n_figura = 0;
        for(unsigned int i=0; i<Triangles.size(); i++){
            Triangles[i] = _vertex3ui(Figuras[n_figura], Figuras[n_figura+1], Figuras[n_figura+2]);
            n_figura+=3;
        }

        archivo.close();

    }
    else
    {
        cerr << "ERROR: No se ha podido leer el archivo\n";
    }

}
