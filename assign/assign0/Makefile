#
#  Sample Makefile for C++ programs 
#  Designed for the OOP class
#  by Tsai-Yen Li (li@cs.nccu.edu.tw) 08/08/96
#

# the name of this package. 
# The library and tar file, if any, will be named after it.
PACKAGE  = Sample
# The executable program
TARGET   = STest
# The C++ source programs (.cc) [multiple files]
SOURCES  = Hello
# The C++ source program for testing your implementation
TEST     = STest

O_DIR    = O_$(HOSTTYPE)
SYSDIR   = /usr/local
CLASSDIR = $(SYSDIR)/class
BASEDIR  = .
INCDIR   = $(BASEDIR)/include #-I$(SYSDIR)/lib/g++-include 
# LIBDIR   = -L$(BASEDIR)/lib -L/usr/openwin/lib
# LIBS     = $(LIBDIR) -lX11 -lcurses -ltermcap -lm -lc

# You may not need to modify anything below

CXX      = g++
CXXFLAGS = -g -Wall -Wno-deprecated -I$(INCDIR) 
TARG     = $(TARGET)_$(HOSTTYPE)
LIB      = lib$(PACKAGE)_$(HOSTTYPE).a

SRCS     = ${SOURCES:%=%.cc}
OBJS     = ${SRCS:%.cc=$(O_DIR)/%.o}
HEADERS  = ${SRCS:%.cc=%.h}
TESTSRC  = ${TEST:%=%.cc}
TESTOBJ  = ${TESTSRC:%.cc=$(O_DIR)/%.o}
#MAKEDEP  = $(CLASSDIR)/bin/makedepend
MAKEDEP  = makedepend

$(TARG) : $(O_DIR) $(OBJS) $(TESTOBJ)
	$(CXX) -o $@ $(CXXFLAGS) $(OBJS) $(TESTOBJ) $(LIBS) 

$(O_DIR) :
	mkdir $@

lib : $(O_DIR) $(LIB)
	@echo $@ Built

$(LIB) : $(OBJS)
	rm -f $(LIB)
	ar cr $@ $(OBJS)
	ranlib $@

$(O_DIR)/%.o: %.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean : 
	rm -f $(OBJS) $(TESTOBJ) $(TARG) core* *~ 

TAGS : 
	etags $(SRCS) $(HEADERS)

ztar:
	tar zcvf $(PACKAGE).tgz Makefile $(SRCS) $(HEADERS) $(TESTSRC) 

ci:
	ci -l Makefile $(SRCS) $(HEADERS) $(TESTSRC) 

depend : 
	$(MAKEDEP) -p$(O_DIR)/ -I$(INCDIR) $(SRCS) $(TESTSRC)

# DO NOT DELETE THIS LINE -- make depend depends on it.

O_sun4/Hello.o: /usr/local/lib/g++-include/iostream.h
O_sun4/Hello.o: /usr/local/lib/g++-include/streambuf.h
O_sun4/Hello.o: /usr/local/lib/g++-include/libio.h
O_sun4/Hello.o: /usr/local/lib/g++-include/_G_config.h Hello.h
O_sun4/STest.o: /usr/local/lib/g++-include/iostream.h
O_sun4/STest.o: /usr/local/lib/g++-include/streambuf.h
O_sun4/STest.o: /usr/local/lib/g++-include/libio.h
O_sun4/STest.o: /usr/local/lib/g++-include/_G_config.h Hello.h
