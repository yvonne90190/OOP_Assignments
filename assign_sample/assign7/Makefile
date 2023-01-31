#
#  Sample Makefile for C++ programs 
#  Designed for the OOP class
#  by Tsai-Yen Li (li@cs.nccu.edu.tw) 08/08/96
#

# the name of this package. 
# The library and tar file, if any, will be named after it.
PACKAGE  = Queue
# The executable program
TARGET   = Queue
# The C++ source programs (.cc) [multiple files]
SOURCES  = AnsiPrint Except
# The C++ source program for testing your implementation
TEST     = QueueTest

O_DIR    = O_$(HOSTTYPE)
SYSDIR   = /usr/local
CLASSDIR = $(SYSDIR)/class/oop
BASEDIR  = .
INCDIR   = $(BASEDIR)/include #-I$(SYSDIR)/lib/g++-include  
LIBDIR   = -L$(BASEDIR)/lib #-L/usr/openwin/lib -L/usr/ucblib
LIBS     = $(LIBDIR) -lm -lc
HOSTTYPE = $(shell arch)
# You may not need to modify anything below

CXX      = g++
CXXFLAGS = -Wno-deprecated -Wall -I$(INCDIR) #-D__STDC__ 
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

clean: 
	rm -f $(OBJS) $(TESTOBJ) $(TARG) core* *~ Makefile.bak 
	rmdir $(O_DIR)

tags: 
	etags $(SRCS) $(HEADERS)

ztar:
	/usr/local/bin/tar zcvf $(PACKAGE).tgz Makefile $(SRCS) $(HEADERS) $(TESTSRC) 

ci:
	ci -l Makefile $(SRCS) $(HEADERS) $(TESTSRC) 

depend : 
	$(MAKEDEP) -p$(O_DIR)/ -I$(INCDIR) $(SRCS) $(TESTSRC)

# DO NOT DELETE THIS LINE -- make depend depends on it.

O_sun4/AnsiPrint.o: /usr/include/stdlib.h /usr/include/iso/stdlib_iso.h
O_sun4/AnsiPrint.o: /usr/include/sys/feature_tests.h
O_sun4/AnsiPrint.o: /usr/include/sys/isa_defs.h AnsiPrint.h
O_sun4/Except.o: /usr/include/string.h /usr/include/iso/string_iso.h
O_sun4/Except.o: /usr/include/sys/feature_tests.h /usr/include/sys/isa_defs.h
O_sun4/Except.o: Except.h
O_sun4/QueueTest.o: /usr/include/stdio.h /usr/include/iso/stdio_iso.h
O_sun4/QueueTest.o: /usr/include/sys/feature_tests.h
O_sun4/QueueTest.o: /usr/include/sys/isa_defs.h /usr/include/sys/va_list.h
O_sun4/QueueTest.o: /usr/include/stdio_tag.h /usr/include/stdio_impl.h
O_sun4/QueueTest.o: /usr/include/stdlib.h /usr/include/iso/stdlib_iso.h
O_sun4/QueueTest.o: /usr/include/assert.h AnsiPrint.h Queue.cc Queue.h
