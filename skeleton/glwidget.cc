/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "glwidget.h"
#include "window.h"

using namespace std;
using namespace _gl_widget_ne;
using namespace _colors_ne;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_gl_widget::_gl_widget(_window *Window1):Window(Window1)
{
  setMinimumSize(300, 300);
  setFocusPolicy(Qt::StrongFocus);
}


/*****************************************************************************//**
 * Evento tecla pulsada
 *
 *
 *
 *****************************************************************************/

void _gl_widget::keyPressEvent(QKeyEvent *Keyevent)
{
  switch(Keyevent->key()){
  case Qt::Key_1:Object=OBJECT_TETRAHEDRON;break;
  case Qt::Key_2:Object=OBJECT_CUBE;break;
  case Qt::Key_3:Object=OBJECT_CONE;break;
  case Qt::Key_4:Object=OBJECT_CYLINDER;break;
  case Qt::Key_5:Object=OBJECT_SPHERE;break;
  case Qt::Key_6:Object=OBJECT_PLY;break;
  case Qt::Key_7:Object=OBJECT_HIERARCHICAL;break;

  case Qt::Key_P:Draw_point=!Draw_point;break;
  case Qt::Key_L:Draw_line=!Draw_line;break;
  case Qt::Key_F:Draw_fill=!Draw_fill;break;
  case Qt::Key_C:Draw_chess=!Draw_chess;break;

  // Activar o desactivar la animacion
  case Qt::Key_A:Animacion=!Animacion;animacion();break;

  // Grados de libertad
  case Qt::Key_Q:Modelo.inclinar_brazo_adelante();break;
  case Qt::Key_W:Modelo.inclinar_brazo_atras();break;
  case Qt::Key_S:Modelo.girar_cuerpo_derecha();break;
  case Qt::Key_D:Modelo.girar_cuerpo_izquierda();break;
  case Qt::Key_Z:Modelo.adelantar_brazo();break;
  case Qt::Key_X:Modelo.atrasar_brazo();break;

  // Modificacion de los grados de libertad
  case Qt::Key_E:Modelo.aumentar_grados_brazo();break;
  case Qt::Key_R:Modelo.disminuir_grados_brazo();break;
  case Qt::Key_T:Modelo.aumentar_grados_cuerpo();break;
  case Qt::Key_Y:Modelo.disminuir_grados_cuerpo();break;
  case Qt::Key_U:Modelo.aumentar_velocidad_brazo();break;
  case Qt::Key_I:Modelo.disminuir_velocidad_brazo();break;

  case Qt::Key_Left:Observer_angle_y-=ANGLE_STEP;break;
  case Qt::Key_Right:Observer_angle_y+=ANGLE_STEP;break;
  case Qt::Key_Up:Observer_angle_x-=ANGLE_STEP;break;
  case Qt::Key_Down:Observer_angle_x+=ANGLE_STEP;break;
  case Qt::Key_PageUp:Observer_distance*=1.2;break;
  case Qt::Key_PageDown:Observer_distance/=1.2;break;
  }

  update();
}


/*****************************************************************************//**
 * Limpiar ventana
 *
 *
 *
 *****************************************************************************/

void _gl_widget::clear_window()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}



/*****************************************************************************//**
 * Funcion para definir la transformación de proyeccion
 *
 *
 *
 *****************************************************************************/

void _gl_widget::change_projection()
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  // formato(x_minimo,x_maximo, y_minimo, y_maximo,Front_plane, plano_traser)
  // Front_plane>0  Back_plane>PlanoDelantero)
  glFrustum(X_MIN,X_MAX,Y_MIN,Y_MAX,FRONT_PLANE_PERSPECTIVE,BACK_PLANE_PERSPECTIVE);
}



/*****************************************************************************//**
 * Funcion para definir la transformación de vista (posicionar la camara)
 *
 *
 *
 *****************************************************************************/

void _gl_widget::change_observer()
{
  // posicion del observador
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0,0,-Observer_distance);
  glRotatef(Observer_angle_x,1,0,0);
  glRotatef(Observer_angle_y,0,1,0);
}


/*****************************************************************************//**
 * Funcion que dibuja los objetos
 *
 *
 *
 *****************************************************************************/

void _gl_widget::draw_objects()
{
  Axis.draw_line();

  if (Draw_point){
    glPointSize(5);
    glColor3fv((GLfloat *) &BLACK);
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_point();break;
    case OBJECT_CUBE:Cube.draw_point();break;
    case OBJECT_CONE:Cone.draw_point();break;
    case OBJECT_CYLINDER:Cylinder.draw_point();break;
    case OBJECT_SPHERE:Sphere.draw_point();break;
    case OBJECT_PLY:Ply.draw_point();break;
    case OBJECT_HIERARCHICAL:Modelo.draw_point();break;
    default:break;
    }
  }

  if (Draw_line){
    glLineWidth(3);
    glColor3fv((GLfloat *) &MAGENTA);
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_line();break;
    case OBJECT_CUBE:Cube.draw_line();break;
    case OBJECT_CONE:Cone.draw_line();break;
    case OBJECT_CYLINDER:Cylinder.draw_line();break;
    case OBJECT_SPHERE:Sphere.draw_line();break;
    case OBJECT_PLY:Ply.draw_line();break;
    case OBJECT_HIERARCHICAL:Modelo.draw_line();break;
    default:break;
    }
  }

  if (Draw_fill){
    glColor3fv((GLfloat *) &BLUE);
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_fill();break;
    case OBJECT_CUBE:Cube.draw_fill();break;
    case OBJECT_CONE:Cone.draw_fill();break;
    case OBJECT_CYLINDER:Cylinder.draw_fill();break;
    case OBJECT_SPHERE:Sphere.draw_fill();break;
    case OBJECT_PLY:Ply.draw_fill();break;
    case OBJECT_HIERARCHICAL:Modelo.draw_fill();break;
    default:break;
    }
  }

  if (Draw_chess){
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_chess();break;
    case OBJECT_CUBE:Cube.draw_chess();break;
    case OBJECT_CONE:Cone.draw_chess();break;
    case OBJECT_CYLINDER:Cylinder.draw_chess();break;
    case OBJECT_SPHERE:Sphere.draw_chess();break;
    case OBJECT_PLY:Ply.draw_chess();break;
    case OBJECT_HIERARCHICAL:Modelo.draw_chess();break;
    default:break;
    }
  }
}



/*****************************************************************************//**
 * Evento de dibujado
 *
 *
 *
 *****************************************************************************/

void _gl_widget::paintGL()
{
  clear_window();
  change_projection();
  change_observer();
  draw_objects();
}


/*****************************************************************************//**
 * Evento de cambio de tamaño de la ventana
 *
 *
 *
 *****************************************************************************/

void _gl_widget::resizeGL(int Width1, int Height1)
{
  glViewport(0,0,Width1,Height1);
}


/*****************************************************************************//**
 * Inicialización de OpenGL
 *
 *
 *
 *****************************************************************************/

void _gl_widget::initializeGL()
{
  const GLubyte* strm;

  strm = glGetString(GL_VENDOR);
  std::cerr << "Vendor: " << strm << "\n";
  strm = glGetString(GL_RENDERER);
  std::cerr << "Renderer: " << strm << "\n";
  strm = glGetString(GL_VERSION);
  std::cerr << "OpenGL Version: " << strm << "\n";

  if (strm[0] == '1'){
    std::cerr << "Only OpenGL 1.X supported!\n";
    exit(-1);
  }

  strm = glGetString(GL_SHADING_LANGUAGE_VERSION);
  std::cerr << "GLSL Version: " << strm << "\n";

  int Max_texture_size=0;
  glGetIntegerv(GL_MAX_TEXTURE_SIZE, &Max_texture_size);
  std::cerr << "Max texture size: " << Max_texture_size << "\n";

  glClearColor(1.0,1.0,1.0,1.0);
  glEnable(GL_DEPTH_TEST);;

  Observer_angle_x=0;
  Observer_angle_y=0;
  Observer_distance=DEFAULT_DISTANCE;

  Draw_point=false;
  Draw_line=true;
  Draw_fill=false;
  Draw_chess=false;

  Animacion=false;

  Timer = new QTimer(this);
  connect(Timer, SIGNAL(timeout()), this, SLOT(tick()));
}

void _gl_widget::animacion(){
    if(Animacion)
        Timer->start(100);
    else{
        Timer->stop();
        delete Timer;
        Timer = new QTimer(this);
    }
}

void _gl_widget::tick(){
    switch(estado){
        case QUIETO:
            estado = (estado==QUIETO && ultimo==QUIETO) ? GIRAR_CUERPO_DERECHA : QUIETO;
        break;
        case GIRAR_CUERPO_DERECHA:
            if(Modelo.angulo_cuerpo<60)
                Modelo.girar_cuerpo_derecha();
            else{estado=AVANZAR_BRAZO; ultimo=GIRAR_CUERPO_DERECHA;}
        break;
        case AVANZAR_BRAZO:
            if(Modelo.getDesplazamientoBrazo()<1)
                Modelo.adelantar_brazo();
            else{estado=INCLINAR_ADELANTE_BRAZO; ultimo=AVANZAR_BRAZO;}
        break;
        case INCLINAR_ADELANTE_BRAZO:
            if(Modelo.getAnguloBrazo()<45)
                Modelo.inclinar_brazo_adelante();
            else{estado=GIRAR_CUERPO_IZQUIERDA; ultimo=INCLINAR_ADELANTE_BRAZO;}
        break;
        case GIRAR_CUERPO_IZQUIERDA:
            if(Modelo.angulo_cuerpo>-60)
                Modelo.girar_cuerpo_izquierda();
            else{estado=RETROCEDER_BRAZO; ultimo=GIRAR_CUERPO_IZQUIERDA;}
        break;
        case RETROCEDER_BRAZO:
            if(Modelo.getDesplazamientoBrazo()>-1)
                Modelo.atrasar_brazo();
            else{estado=INCLINAR_ATRAS_BRAZO; ultimo=RETROCEDER_BRAZO;}
        break;
        case INCLINAR_ATRAS_BRAZO:
            if(Modelo.getAnguloBrazo()>-45)
                Modelo.inclinar_brazo_atras();
            else estado=INICIO;
        break;
        case INICIO:
            if(Modelo.angulo_cuerpo<0)
                Modelo.girar_cuerpo_derecha();
            if(Modelo.getAnguloBrazo()<0)
                Modelo.inclinar_brazo_adelante();
            if(Modelo.getDesplazamientoBrazo()<0)
                Modelo.adelantar_brazo();
            else{estado=QUIETO; ultimo=QUIETO;}
        break;
    }
    update();
}
