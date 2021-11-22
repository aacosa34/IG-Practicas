HEADERS += \
  base.h \
  brazo1.h \
  brazo2.h \
  cabeza.h \
  colors.h \
  basic_object3d.h \
  cone.h \
  cube.h \
  cylinder.h \
  eje_ruedas.h \
  file_ply_stl.h \
  object3d.h \
  axis.h \
  objectrev.h \
  ply.h \
  revply.h \
  rueda.h \
  sphere.h \
  tetrahedron.h \
  glwidget.h \
  window.h \
  GL/*.h

SOURCES += \
  base.cc \
  basic_object3d.cc \
  brazo1.cc \
  brazo2.cc \
  cabeza.cc \
  cone.cc \
  cube.cc \
  cylinder.cc \
  eje_ruedas.cc \
  file_ply_stl.cc \
  object3d.cc \
  axis.cc \
  objectrev.cc \
  ply.cc \
  revply.cc \
  rueda.cc \
  sphere.cc \
  tetrahedron.cc \
  main.cc \
  glwidget.cc \
  window.cc


LIBS += -L/usr/X11R6/lib64 -lGL


CONFIG += c++11
QT += widgets
