CFLAGS = -O3 -Wall -Wno-narrowing\
  -I./ \
  -I/usr/include \
  -I/usr/include/GL \
  -I../../libSNL/src \
  -I../../glut-3.5/src \
  -I/usr/X11/include 

LFLAGS = \
  -L/usr/lib64 -lGL -lGLU \
  -L/usr/X11R6/lib64 -lX11 -lXi -lXmu -lXext -lXt -lSM -lICE \
  -lm -lpthread -lrt


# on 32bit systems change lib64 to lib
# -lpthread is needed if mesaGL is using threading, otherwhise it is not needed
# -L/usr/X11/lib64 -lpthread -lX11 -lXext -lXi -lXmu -lXt -lSM -lICE \

include Makefile.inc

ULIB = \
 userFunction.c

SUTIL = \
 ../../glut-3.5/src/layerutil.c \
 ../../glut-3.5/src/glut_dials.c \
 ../../glut-3.5/src/glut_ext.c \
 ../../glut-3.5/src/glut_mesa.c \
 ../../glut-3.5/src/glut_menu.c \
 ../../glut-3.5/src/glut_modifier.c \
 ../../glut-3.5/src/glut_space.c \
 ../../glut-3.5/src/glut_shapes.c \
 ../../glut-3.5/src/glut_tablet.c \
 ../../glut-3.5/src/glut_warp.c \
 ../../glut-3.5/src/glut_8x13.c \
 ../../glut-3.5/src/glut_9x15.c \
 ../../glut-3.5/src/glut_hel10.c \
 ../../glut-3.5/src/glut_hel18.c \
 ../../glut-3.5/src/glut_hel12.c \
 ../../glut-3.5/src/glut_tr10.c \
 ../../glut-3.5/src/glut_tr24.c \
 ../../glut-3.5/src/glut_bitmap.c \
 ../../glut-3.5/src/glut_cursor.c \
 ../../glut-3.5/src/glut_event.c \
 ../../glut-3.5/src/glut_get.c \
 ../../glut-3.5/src/glut_overlay.c \
 ../../glut-3.5/src/glut_input.c \
 ../../glut-3.5/src/glut_stroke.c \
 ../../glut-3.5/src/glut_teapot.c \
 ../../glut-3.5/src/glut_winmisc.c \
 ../../glut-3.5/src/glut_fullscrn.c \
 ../../glut-3.5/src/glut_cindex.c \
 ../../glut-3.5/src/glut_roman.c \
 ../../glut-3.5/src/glut_mroman.c \
 ../../glut-3.5/src/glut_swidth.c \
 ../../glut-3.5/src/glut_bwidth.c \
 ../../glut-3.5/src/glut_win.c \
 ../../glut-3.5/src/glut_init.c \
 ../../glut-3.5/src/glut_util.c \
 uselibSNL.cpp \
 generateTet.cpp \
 ../../libSNL/src/*.cpp

OLIB = $(SLIB:.c=.o)
OULIB = $(ULIB:.c=.o)
OUTIL = $(SUTIL:.c=.o)

cgx: $(OLIB) $(OUTIL) $(OULIB)
	g++  $(OULIB)  $(OLIB) $(OUTIL)  $(CFLAGS) $(LFLAGS) -o  $@

setFunktions.o:	setFunktions.c prool.h prool.c
