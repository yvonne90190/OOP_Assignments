#
#  Sample Makefile for C++ programs 
#  Designed for the OOP class
#  by Tsai-Yen Li (li@cs.nccu.edu.tw) 08/08/96
#

# the name of this package. 
# The library and tar file, if any, will be named after it.
PACKAGE  = Cards
# The executable program
TARGET   = CardTest
# The C++ source programs (.cc) [multiple files]
SOURCES  = AnsiPrint Cards 
# The C++ source program for testing your implementation
TEST     = CardTest

O_DIR    = O_$(HOSTTYPE)
SYSDIR   = /usr/local
CLASSDIR = $(SYSDIR)/class/oop
BASEDIR  = .
INCDIR   = $(BASEDIR)/include #-I$(SYSDIR)/lib/g++-include 
LIBDIR   = -L$(BASEDIR)/lib -L/usr/openwin/lib -L/usr/ucblib
LIBS     = $(LIBDIR) -lm -lc #-lucb  -liostream

# You may not need to modify anything below

CXX      = g++
CXXFLAGS = -g -Wall -I$(INCDIR) #-D__STDC__ 
TARG     = $(TARGET)_$(HOSTTYPE)
LIB      = lib$(PACKAGE)_$(HOSTTYPE).a

SRCS     = ${SOURCES:%=%.cc}
OBJS     = ${SRCS:%.cc=$(O_DIR)/%.o}
HEADERS  = ${SRCS:%.cc=%.h} Cards.h
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
	tar zcvf $(PACKAGE).tgz Makefile $(SRCS) $(HEADERS) $(TESTSRC) 

ci:
	ci -l Makefile $(SRCS) $(HEADERS) $(TESTSRC) 

depend : 
	$(MAKEDEP) -p$(O_DIR)/ -I$(INCDIR) $(SRCS) $(TESTSRC)

# DO NOT DELETE THIS LINE -- make depend depends on it.

O_i86pc/AnsiPrint.o: AnsiPrint.h
O_i86pc/CardTest.o: /usr/include/stdio.h /usr/include/sys/feature_tests.h
O_i86pc/CardTest.o: /usr/include/sys/ccompile.h /usr/include/sys/isa_defs.h
O_i86pc/CardTest.o: /usr/include/iso/stdio_iso.h /usr/include/sys/va_list.h
O_i86pc/CardTest.o: /usr/include/stdio_tag.h /usr/include/stdio_impl.h
O_i86pc/CardTest.o: /usr/include/iso/stdio_c99.h /usr/include/stdlib.h
O_i86pc/CardTest.o: /usr/include/iso/stdlib_iso.h
O_i86pc/CardTest.o: /usr/include/iso/stdlib_c99.h /usr/include/strings.h
O_i86pc/CardTest.o: /usr/include/sys/types.h /usr/include/sys/machtypes.h
O_i86pc/CardTest.o: /usr/include/ia32/sys/machtypes.h
O_i86pc/CardTest.o: /usr/include/sys/int_types.h /usr/include/sys/select.h
O_i86pc/CardTest.o: /usr/include/sys/time_impl.h /usr/include/sys/time.h
O_i86pc/CardTest.o: /usr/include/sys/time.h /usr/include/string.h
O_i86pc/CardTest.o: /usr/include/iso/string_iso.h /usr/include/assert.h
O_i86pc/CardTest.o: AnsiPrint.h Cards.h
