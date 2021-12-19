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
  case Qt::Key_8:Object=OBJECT_DASHBOARD;break;

  case Qt::Key_P:Draw_point=!Draw_point;break;
  case Qt::Key_L:Draw_line=!Draw_line;break;
  case Qt::Key_F:Draw_fill=!Draw_fill;break;

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

  // Display mode
  case Qt::Key_F1:Modo_render=SOLID_MODE;break;
  case Qt::Key_F2:Modo_render=CHESS_MODE;break;
  case Qt::Key_F3:Modo_render=FLAT_SHADED_LIGHTING;break;
  case Qt::Key_F4:Modo_render=SMOOTH_SHADED_LIGHTING;break;
  case Qt::Key_F5:Modo_render=TEXTURE;break;
  case Qt::Key_F6:Modo_render=TEXTURE_FLAT_SHADING;break;
  case Qt::Key_F7:Modo_render=SMOOTH_TEXTURE_SHADED_LIGHTING;break;

  case Qt::Key_J:luz0_activa=!luz0_activa;break;
  case Qt::Key_K:luz1_activa=!luz1_activa;break;

  case Qt::Key_M:siguiente_material();break;

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
    case OBJECT_DASHBOARD:Dashboard.draw_point();break;
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
    case OBJECT_DASHBOARD:Dashboard.draw_line();break;
    default:break;
    }
  }

  if (Draw_fill){
    switch(Modo_render){
        case SOLID_MODE:
                glColor3fv((GLfloat *) &BLUE);
                switch (Object){
                case OBJECT_TETRAHEDRON:Tetrahedron.draw_fill();break;
                case OBJECT_CUBE:Cube.draw_fill();break;
                case OBJECT_CONE:Cone.draw_fill();break;
                case OBJECT_CYLINDER:Cylinder.draw_fill();break;
                case OBJECT_SPHERE:Sphere.draw_fill();break;
                case OBJECT_PLY:Ply.draw_fill();break;
                case OBJECT_HIERARCHICAL:Modelo.draw_fill();break;
                case OBJECT_DASHBOARD:Dashboard.draw_fill();break;
                default:break;
                }
        break;

        case CHESS_MODE:
            switch (Object){
            case OBJECT_TETRAHEDRON:Tetrahedron.draw_chess();break;
            case OBJECT_CUBE:Cube.draw_chess();break;
            case OBJECT_CONE:Cone.draw_chess();break;
            case OBJECT_CYLINDER:Cylinder.draw_chess();break;
            case OBJECT_SPHERE:Sphere.draw_chess();break;
            case OBJECT_PLY:Ply.draw_chess();break;
            case OBJECT_HIERARCHICAL:Modelo.draw_chess();break;
            case OBJECT_DASHBOARD:Dashboard.draw_chess();break;
            default:break;
            }
        break;

        case FLAT_SHADED_LIGHTING:
        {
        _vertex4f Ambient(0.5,0.5,0.5,1);

        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, (GLfloat *)&Ambient);

        set_luces();
        set_materiales();

        glEnable(GL_LIGHTING);
        switch (Object){
            case OBJECT_TETRAHEDRON:Tetrahedron.draw_flat_shaded_lighting();break;
            case OBJECT_CUBE:Cube.draw_flat_shaded_lighting();break;
            case OBJECT_CONE:Cone.draw_flat_shaded_lighting();break;
            case OBJECT_CYLINDER:Cylinder.draw_flat_shaded_lighting();break;
            case OBJECT_SPHERE:Sphere.draw_flat_shaded_lighting();break;
            case OBJECT_PLY:Ply.draw_flat_shaded_lighting();break;
            default:break;
            }
        glDisable(GL_LIGHTING);
        }
        break;


        case SMOOTH_SHADED_LIGHTING:
        {
        _vertex4f Ambient(0.1,0.1,0.1,1);

        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, (GLfloat *)&Ambient);

        set_luces();
        set_materiales();

        glEnable(GL_LIGHTING);
        switch (Object){
            case OBJECT_TETRAHEDRON:Tetrahedron.draw_smooth_shaded_lighting();break;
            case OBJECT_CUBE:Cube.draw_smooth_shaded_lighting();break;
            case OBJECT_CONE:Cone.draw_smooth_shaded_lighting();break;
            case OBJECT_CYLINDER:Cylinder.draw_smooth_shaded_lighting();break;
            case OBJECT_SPHERE:Sphere.draw_smooth_shaded_lighting();break;
            case OBJECT_PLY:Ply.draw_smooth_shaded_lighting();break;
            default:break;
        glDisable(GL_LIGHTING);
        }
        break;
        }

        case TEXTURE:
        switch (Object){
            case OBJECT_TETRAHEDRON:Tetrahedron.draw_texture();break;
            case OBJECT_CUBE:Cube.draw_texture();break;
            case OBJECT_CONE:Cone.draw_texture();break;
            case OBJECT_CYLINDER:Cylinder.draw_texture();break;
            case OBJECT_SPHERE:Sphere.draw_texture();break;
            case OBJECT_PLY:Ply.draw_texture();break;
            case OBJECT_DASHBOARD:Dashboard.draw_texture();break;
            default:break;
        }
        break;

        case TEXTURE_FLAT_SHADING:
        break;

        case SMOOTH_TEXTURE_SHADED_LIGHTING:
        break;

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

  luz0_activa=true;
  luz1_activa=false;

  // Code for reading an image
  QString File_name("/home/adrian/Documents/IG-Practicas/skeleton/texturas/dia_8192.jpg");
  QImage Image;
  QImageReader Reader(File_name);
  Reader.setAutoTransform(true);
  Image = Reader.read();
  if (Image.isNull()) {
    QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
                             tr("Cannot load %1.").arg(QDir::toNativeSeparators(File_name)));
    exit(-1);
  }
  Image=Image.mirrored();
  Image=Image.convertToFormat(QImage::Format_RGB888);

  // Code to control the application of the texture
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

  // Code to pass the image to OpenGL to form a texture 2D
  glTexImage2D(GL_TEXTURE_2D,0,3,Image.width(),Image.height(),0,GL_RGB,GL_UNSIGNED_BYTE,Image.bits());
}

void _gl_widget::animacion(){
    if(Animacion){
        connect(Timer, SIGNAL(timeout()), this, SLOT(tick()));
        Timer->start(30);
    }
    else{
        Timer->stop();
        disconnect(Timer, SIGNAL(timeout()), 0, 0);
        delete Timer;
        Timer = new QTimer(this);
    }
}

void _gl_widget::tick(){
    if(luz1_activa){
        angulo_luz_magenta = (angulo_luz_magenta < 360) ? angulo_luz_magenta += 5 : angulo_luz_magenta = 0;
    }

    switch(estado){
        case estados::QUIETO:
            estado = (estado==estados::QUIETO && ultimo==estados::QUIETO) ? estados::GIRAR_CUERPO_DERECHA : estados::QUIETO;
        break;
        case estados::GIRAR_CUERPO_DERECHA:
            if(Modelo.angulo_cuerpo<60)
                Modelo.girar_cuerpo_derecha();
            else{estado=estados::AVANZAR_BRAZO; ultimo=estados::GIRAR_CUERPO_DERECHA;}
        break;
        case estados::AVANZAR_BRAZO:
            if(Modelo.getDesplazamientoBrazo()<1)
                Modelo.adelantar_brazo();
            else{estado=estados::INCLINAR_ADELANTE_BRAZO; ultimo=estados::AVANZAR_BRAZO;}
        break;
        case estados::INCLINAR_ADELANTE_BRAZO:
            if(Modelo.getAnguloBrazo()<45)
                Modelo.inclinar_brazo_adelante();
            else{estado=estados::GIRAR_CUERPO_IZQUIERDA; ultimo=estados::INCLINAR_ADELANTE_BRAZO;}
        break;
        case estados::GIRAR_CUERPO_IZQUIERDA:
            if(Modelo.angulo_cuerpo>-60)
                Modelo.girar_cuerpo_izquierda();
            else{estado=estados::RETROCEDER_BRAZO; ultimo=estados::GIRAR_CUERPO_IZQUIERDA;}
        break;
        case estados::RETROCEDER_BRAZO:
            if(Modelo.getDesplazamientoBrazo()>-1)
                Modelo.atrasar_brazo();
            else{estado=estados::INCLINAR_ATRAS_BRAZO; ultimo=estados::RETROCEDER_BRAZO;}
        break;
        case estados::INCLINAR_ATRAS_BRAZO:
            if(Modelo.getAnguloBrazo()>-45)
                Modelo.inclinar_brazo_atras();
            else estado=estados::INICIO;
        break;
        case estados::INICIO:
            if(Modelo.angulo_cuerpo<0)
                Modelo.girar_cuerpo_derecha();
            else if(Modelo.getDesplazamientoBrazo()<0)
                Modelo.adelantar_brazo();
            else if(Modelo.getAnguloBrazo()<0)
                Modelo.inclinar_brazo_adelante();
            else{estado=estados::QUIETO; ultimo=estados::QUIETO;}
        break;
    }
    update();
}

void _gl_widget::set_luces(){
    if(luz0_activa){
        _vertex4f posicion(0,0,1,0);

        glEnable(GL_LIGHT0);
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glLoadIdentity();
        glLightfv(GL_LIGHT0, GL_POSITION, (GLfloat *)&posicion);
        glPopMatrix();
    }
    else
        glDisable(GL_LIGHT0);

    if(luz1_activa){
        GLfloat luz_ambiente[] = {1.0f,1.0f,1.0f,1.0f};
        GLfloat luz_magenta[] = {1.0f,0.0f,1.0f,1.0f};

        _vertex4f posicion_luz1(12.0, 10.0, 20.0, 1.0);
        glLightfv(GL_LIGHT1, GL_AMBIENT, luz_ambiente);
        glLightfv(GL_LIGHT1, GL_DIFFUSE, luz_magenta);
        glLightfv(GL_LIGHT1, GL_SPECULAR, luz_magenta);
        glEnable(GL_LIGHT1);
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glRotatef(angulo_luz_magenta,0,1,0);
        glLightfv(GL_LIGHT1, GL_POSITION, (GLfloat *)&posicion_luz1);
        glPopMatrix();
    }

    else
        glDisable(GL_LIGHT1);

}

void _gl_widget::set_materiales(){
    switch (material_activo){
        case materiales::EMERALD:
        {
            _vertex3f diffuse = {0.07568, 0.61424, 0.07568};
            _vertex3f ambient = {0.0215, 0.1745, 0.0215};
            _vertex3f specular = {0.633, 0.727811, 0.633};
            float shininess = 0.6;

            glMaterialfv(GL_FRONT, GL_DIFFUSE, (GLfloat *) &diffuse);
            glMaterialfv(GL_FRONT, GL_AMBIENT, (GLfloat *) &ambient);
            glMaterialfv(GL_FRONT, GL_SPECULAR, (GLfloat *) &specular);
            glMaterialf(GL_FRONT, GL_SHININESS, shininess*128.0);
        }
        break;
        case materiales::OBSIDIAN:
        {
            _vertex3f diffuse = {0.18275, 0.17, 0.22525};
            _vertex3f ambient = {0.05375, 0.05, 0.06625};
            _vertex3f specular = {0.332741, 0.328634, 0.346435};
            float shininess = 0.3;

            glMaterialfv(GL_FRONT, GL_DIFFUSE, (GLfloat *) &diffuse);
            glMaterialfv(GL_FRONT, GL_AMBIENT, (GLfloat *) &ambient);
            glMaterialfv(GL_FRONT, GL_SPECULAR, (GLfloat *) &specular);
            glMaterialf(GL_FRONT, GL_SHININESS, shininess*128.0);
        }
        break;
        case materiales::CHROME:
        {
            _vertex3f diffuse = {0.4, 0.4, 0.4};
            _vertex3f ambient = {0.25, 0.25, 0.25};
            _vertex3f specular = {0.774597, 0.774597, 0.774597};
            float shininess = 0.6;

            glMaterialfv(GL_FRONT, GL_DIFFUSE, (GLfloat *) &diffuse);
            glMaterialfv(GL_FRONT, GL_AMBIENT, (GLfloat *) &ambient);
            glMaterialfv(GL_FRONT, GL_SPECULAR, (GLfloat *) &specular);
            glMaterialf(GL_FRONT, GL_SHININESS, shininess*128.0);
        }
        break;
    }
}

void _gl_widget::siguiente_material(){
    switch(material_activo){
    case materiales::EMERALD:material_activo=materiales::OBSIDIAN;
    case materiales::OBSIDIAN:material_activo=materiales::CHROME;
    case materiales::CHROME:material_activo=materiales::EMERALD;
    }
}
