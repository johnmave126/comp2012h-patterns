#############################################################################
# Makefile for building: build_bin/patterns
# Generated by qmake (1.07a) (Qt 3.3.6) on: Sun Mar 24 17:38:23 2013
# Rewritten by TAN Shuhao
# Project:  patterns
# Template: app
#############################################################################

####### Compiler, tools and options

CC       = gcc
CXX      = g++
LEX      = flex
YACC     = yacc
CFLAGS   = -pipe -Wall -W -O2 -g -pipe -Wall -Wp,-D_FORTIFY_SOURCE=2 -fexceptions -fstack-protector --param=ssp-buffer-size=4 -m64 -mtune=generic  -DQT_NO_DEBUG -DQT_SHARED -DQT_THREAD_SUPPORT
CXXFLAGS = -pipe -Wall -W -O2 -g -pipe -Wall -Wp,-D_FORTIFY_SOURCE=2 -fexceptions -fstack-protector --param=ssp-buffer-size=4 -m64 -mtune=generic  -DQT_NO_DEBUG -DQT_SHARED -DQT_THREAD_SUPPORT
LEXFLAGS = 
YACCFLAGS= -d
INCPATH  = -I/usr/lib64/qt-3.3/mkspecs/linux-g++-64 -I. -Iinclude -I$(QTDIR)/include -Ibuild_tmp/
LINK     = g++
LFLAGS   = 
LIBS     = $(SUBLIBS) -L$(QTDIR)/lib -lqt-mt -lXext -lX11 -lm
AR       = ar cqs
RANLIB   = 
MOC      = $(QTDIR)/bin/moc
UIC      = $(QTDIR)/bin/uic
QMAKE    = qmake
TAR      = tar -cf
GZIP     = gzip -9f
COPY     = cp -f
COPY_FILE= $(COPY)
COPY_DIR = $(COPY) -r
INSTALL_FILE= $(COPY_FILE)
INSTALL_DIR = $(COPY_DIR)
DEL_FILE = rm -f
SYMLINK  = ln -sf
DEL_DIR  = rmdir
MOVE     = mv -f
CHK_DIR_EXISTS= test -d
MKDIR    = mkdir -p

####### Output directory

OBJECTS_DIR = build_tmp/

####### Files

HEADERS = include/deque.h \
		include/patterns_algorithm.h \
		include/patterns_common.h \
		include/Point.h \
		include/Vector2D.h 
SOURCES = src/Brute.cpp \
		src/Fast.cpp \
		src/patterns_common.cpp 
OBJECTS = build_tmp/patterns_common.o 
BRUTE_O = build_tmp/Brute.o
FAST_O = build_tmp/Fast.o
FORMS = 
UICDECLS = 
UICIMPLS = 
SRCMOC   = 
OBJMOC = 
DESTDIR  = build_bin
TARGET   = $(DESTDIR)/Brute $(DESTDIR)/Fast

first: all
####### Implicit rules

.SUFFIXES: .c .o .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o $@ $<

####### Build rules

all: path $(TARGET) resource

$(DESTDIR)/Brute: $(UICDECLS) $(OBJECTS) $(OBJMOC) $(BRUTE_O)
	test -d build_bin/ || mkdir -p build_bin/
	$(LINK) $(LFLAGS) -o $(DESTDIR)/Brute $(OBJECTS) $(BRUTE_O) $(OBJMOC) $(OBJCOMP) $(LIBS)

$(DESTDIR)/Fast: $(UICDECLS) $(OBJECTS) $(OBJMOC) $(Fast_O)
	test -d build_bin/ || mkdir -p build_bin/
	$(LINK) $(LFLAGS) -o $(DESTDIR)/Fast $(OBJECTS) $(FAST_O) $(OBJMOC) $(OBJCOMP) $(LIBS)

.PHONY: resource
resource:
	(test -d resource/ && cp -r resource/* build_bin/) || true 

mocables: $(SRCMOC)
uicables: $(UICDECLS) $(UICIMPLS)

$(MOC): 
	( cd $(QTDIR)/src/moc && $(MAKE) )

mocclean:
	-$(DEL_FILE) $(OBJMOC)
	-$(DEL_FILE) $(SRCMOC)

uiclean:

yaccclean:
lexclean:
clean: mocclean
	-$(DEL_FILE) $(OBJECTS) $(BRUTE_O) $(BRUTE_O)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET)


FORCE:

####### Compile

.PHONY: path
path:
	test -d build_tmp/ || mkdir -p build_tmp/

build_tmp/Brute.o: src/Brute.cpp include/patterns_algorithm.h include/Point.h \
 include/Vector2D.h include/deque.h include/Point.h include/Vector2D.h \
 include/deque.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build_tmp/Brute.o src/Brute.cpp

build_tmp/Fast.o: src/Fast.cpp include/patterns_algorithm.h include/Point.h \
 include/Vector2D.h include/deque.h include/Point.h include/Vector2D.h \
 include/deque.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build_tmp/Fast.o src/Fast.cpp

build_tmp/patterns_common.o: src/patterns_common.cpp \
 include/patterns_common.h include/Point.h include/Vector2D.h \
 include/deque.h include/Point.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build_tmp/patterns_common.o src/patterns_common.cpp
