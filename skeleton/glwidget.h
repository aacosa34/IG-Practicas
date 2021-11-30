/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <GL/gl.h>
#include <QOpenGLWidget>
#include <QKeyEvent>
#include <QTimer>
#include <iostream>
#include "vertex.h"
#include "colors.h"
#include "axis.h"
#include "tetrahedron.h"
#include "cube.h"
#include "cylinder.h"
#include "cone.h"
#include "sphere.h"
#include "ply.h"
#include "modelo.h"


namespace _gl_widget_ne {

  const float X_MIN=-.1;
  const float X_MAX=.1;
  const float Y_MIN=-.1;
  const float Y_MAX=.1;
  const float FRONT_PLANE_PERSPECTIVE=(X_MAX-X_MIN)/2;
  const float BACK_PLANE_PERSPECTIVE=1000;
  const float DEFAULT_DISTANCE=2;
  const float ANGLE_STEP=1;

  typedef enum {MODE_DRAW_POINT,MODE_DRAW_LINE,MODE_DRAW_FILL,MODE_DRAW_CHESS} _mode_draw;
  typedef enum {OBJECT_TETRAHEDRON,OBJECT_CUBE,OBJECT_CONE,OBJECT_CYLINDER,OBJECT_SPHERE,OBJECT_PLY, OBJECT_HIERARCHICAL} _object;
}

class _window;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _gl_widget : public QOpenGLWidget
{
Q_OBJECT
public:
  _gl_widget(_window *Window1);

  void clear_window();
  void change_projection();
  void change_observer();

  void draw_axis();
  void draw_objects();

  void animacion();


protected:
  void resizeGL(int Width1, int Height1) Q_DECL_OVERRIDE;
  void paintGL() Q_DECL_OVERRIDE;
  void initializeGL() Q_DECL_OVERRIDE;
  void keyPressEvent(QKeyEvent *Keyevent) Q_DECL_OVERRIDE;

protected slots:
  void tick();


private:
  _window *Window;

  _axis Axis;
  _tetrahedron Tetrahedron;
  _cube Cube;
  _cylinder Cylinder;
  _cone Cone;
  _sphere Sphere;
  _ply Ply;

  _brazo1 Brazo1 = _brazo1();
  _brazo2 Brazo2 = _brazo2();
  _pala Pala = _pala();
  _brazo Brazo = _brazo();
  _rueda Rueda = _rueda();
  _eje_ruedas Ejes = _eje_ruedas();
  _cadena Cadena = _cadena();
  _cabeza Cabeza = _cabeza();
  _modelo Modelo = _modelo();


  _gl_widget_ne::_object Object;

  bool Draw_point;
  bool Draw_line;
  bool Draw_fill;
  bool Draw_chess;

  enum class estados {QUIETO, GIRAR_CUERPO_DERECHA, GIRAR_CUERPO_IZQUIERDA, AVANZAR_BRAZO,
               INCLINAR_ADELANTE_BRAZO,RETROCEDER_BRAZO,INCLINAR_ATRAS_BRAZO, INICIO};

  estados estado=estados::QUIETO;
  estados ultimo=estados::QUIETO;

  bool Animacion;
  QTimer * Timer;

  float Observer_angle_x;
  float Observer_angle_y;
  float Observer_distance;
};

#endif
