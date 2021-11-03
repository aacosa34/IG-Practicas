#ifndef _REVPLY_H
#define _REVPLY_H

#include "object3d.h"
#include "file_ply_stl.h"

class _revply
{
private:
    _file_ply archivo;
public:
    _revply(const string &File_name);
};

#endif // _REVPLY_H
