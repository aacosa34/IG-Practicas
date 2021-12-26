#ifndef _PLY_H
#define _PLY_H

#include <vector>
#include "object3d.h"
#include "file_ply_stl.h"

class _ply:public _object3D
{
private:
    _file_ply archivo;
public:
    _ply(){};
    void init(const string &File_name="../ply_models/beethoven.ply");
};

#endif // _PLY_H
