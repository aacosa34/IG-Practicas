HEADERS += \
  base.h \
  cabeza.h \
  colors.h \
  basic_object3d.h \
  cone.h \
  cube.h \
  cylinder.h \
  file_ply_stl.h \
  object3d.h \
  axis.h \
  objectrev.h \
  ply.h \
  revply.h \
  sphere.h \
  tetrahedron.h \
  glwidget.h \
  window.h \
  GL/*.h

SOURCES += \
  base.cc \
  basic_object3d.cc \
  cabeza.cc \
  cone.cc \
  cube.cc \
  cylinder.cc \
  file_ply_stl.cc \
  object3d.cc \
  axis.cc \
  objectrev.cc \
  ply.cc \
  revply.cc \
  sphere.cc \
  tetrahedron.cc \
  main.cc \
  glwidget.cc \
  window.cc


LIBS += -L/usr/X11R6/lib64 -lGL


CONFIG += c++11
QT += widgets
