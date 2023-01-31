#
#  Sample Makefile for C++ programs 
#  Designed for the OOP class
#  by Tsai-Yen Li (li@cs.nccu.edu.tw) 08/08/96
#

# the name of this package. 
# The library and tar file, if any, will be named after it.
PACKAGE  = Vector
# The executable program
TARGET   = vector
# The C++ source programs (.cc) [multiple files]
SOURCES  = Vector AnsiPrint
# The C++ source program for testing your implementation
TEST     = Main

O_DIR    = O_$(HOSTTYPE)
SYSDIR   = /usr/local
CLASSDIR = $(SYSDIR)/class/oop
BASEDIR  = .
INCDIR   = ../Canvas -I$(BASEDIR)/include -I$(CLASSDIR)/include -I/usr/openwin/include -I/usr/lib/g++-include
LIBDIR   =  -L../Canvas -L/usr/openwin/lib -L$(CLASSDIR)/lib
#LIBS     = $(LIBDIR) -lcurses -ltermcap -lX11 -lm -lc 
HOSTTYPE = $(shell arch)

# You may not need to modify anything below

CXX      = g++
CXXFLAGS = -g -Wno-deprecated -Wall -I$(INCDIR) #-D__STDC__ 
TARG     = $(TARGET)_$(HOSTTYPE)
LIB      = lib$(PACKAGE)_$(HOSTTYPE).a

SRCS     = ${SOURCES:%=%.cc}
OBJS     = ${SRCS:%.cc=$(O_DIR)/%.o}
HEADERS  = ${SRCS:%.cc=%.h} #Canvas.h keys.h
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

clean: 
	rm -f $(OBJS) $(TESTOBJ) $(TARG) core* *~ Makefile.bak 
	rmdir $(O_DIR)

tags: 
	etags $(SRCS) $(HEADERS)

ztar:
	/usr/local/bin/tar zcvf $(PACKAGE).tgz Makefile $(SRCS) $(HEADERS) $(TESTSRC) input.dat assign6.txt

ci:
	ci -l Makefile $(SRCS) $(HEADERS) $(TESTSRC) 

depend : 
	$(MAKEDEP) -p$(O_DIR)/ -I$(INCDIR) $(SRCS) $(TESTSRC)

# DO NOT DELETE THIS LINE -- make depend depends on it.

O_i86pc/Vector.o: /usr/include/math.h /usr/include/iso/math_iso.h
O_i86pc/Vector.o: /usr/include/sys/feature_tests.h
O_i86pc/Vector.o: /usr/include/sys/ccompile.h /usr/include/sys/isa_defs.h
O_i86pc/Vector.o: /usr/include/iso/math_c99.h /usr/include/stdlib.h
O_i86pc/Vector.o: /usr/include/iso/stdlib_iso.h /usr/include/iso/stdlib_c99.h
O_i86pc/Vector.o: /usr/include/assert.h Vector.h
O_i86pc/AnsiPrint.o: AnsiPrint.h
O_i86pc/Main.o: /usr/include/stdio.h /usr/include/sys/feature_tests.h
O_i86pc/Main.o: /usr/include/sys/ccompile.h /usr/include/sys/isa_defs.h
O_i86pc/Main.o: /usr/include/iso/stdio_iso.h /usr/include/sys/va_list.h
O_i86pc/Main.o: /usr/include/stdio_tag.h /usr/include/stdio_impl.h
O_i86pc/Main.o: /usr/include/iso/stdio_c99.h /usr/include/string.h
O_i86pc/Main.o: /usr/include/iso/string_iso.h AnsiPrint.h Vector.h
