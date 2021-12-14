/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef OBJECT3D_H
#define OBJECT3D_H

#include <cmath>
#include "basic_object3d.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _object3D:public _basic_object3D
{
  public:
  vector<_vertex3ui> Triangles;
  vector<_vertex3f> Triangles_normales;
  vector<_vertex3f> Vertices_normales;

  void draw_line();
  void draw_fill();
  void draw_chess();

  void draw_flat_shaded_lighting();
  void draw_smooth_shaded_lighting();
  void draw_texture();
  void draw_texture_flat_shading_lighting();
  void draw_texture_smooth_shading_lighting();

  void calculo_normales_caras();
  void calculo_normales_vertices();

  protected:
  vector<int> n_normales;
};

#endif // OBJECT3D_H
