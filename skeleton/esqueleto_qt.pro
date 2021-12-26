HEADERS += \
  brazo.h \
  brazo1.h \
  brazo2.h \
  cabeza.h \
  cadena.h \
  colors.h \
  basic_object3d.h \
  cone.h \
  cube.h \
  cylinder.h \
  dashboard.h \
  eje_ruedas.h \
  file_ply_stl.h \
  modelo.h \
  object3d.h \
  axis.h \
  objectrev.h \
  pala.h \
  ply.h \
  ply_matrix.h \
  revply.h \
  rueda.h \
  sphere.h \
  tetrahedron.h \
  glwidget.h \
  window.h \
  GL/*.h

SOURCES += \
  basic_object3d.cc \
  brazo.cc \
  brazo1.cc \
  brazo2.cc \
  cabeza.cc \
  cadena.cc \
  cone.cc \
  cube.cc \
  cylinder.cc \
  dashboard.cc \
  eje_ruedas.cc \
  file_ply_stl.cc \
  modelo.cc \
  object3d.cc \
  axis.cc \
  objectrev.cc \
  pala.cc \
  ply.cc \
  ply_matrix.cc \
  revply.cc \
  rueda.cc \
  sphere.cc \
  tetrahedron.cc \
  main.cc \
  glwidget.cc \
  window.cc


LIBS += -L/usr/X11R6/lib64 -lGL -lGLEW


CONFIG += c++11
QT += widgets
