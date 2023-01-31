
extern "C" {
#include <stdio.h>
#include <string.h>
}

using namespace std;
#include <iostream>

#include "AnsiPrint.h"
#include "Vector.h"

const double test1[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9}; 

/**
 * Print my id 
 */

void
PrintMyID(const char *studId) {

  char *str= new char[sizeof(studId)+5];
  sprintf(str,"ID: %s",studId);
  AnsiPrint(str,yellow,red,true,true);

  cout << endl << endl;
  delete [] str;
  
}

// main testing routine
int
main() {

  // 
  cout << endl << "Testing constructor" << endl;
  // 
  Vector v1;
  cout << "  default constructor - Vector::Vector();" << endl;
  cout << "\tVector v1 = " << v1 << endl;
  cout << "\tlength = " << v1.length() << endl;
  //
  Vector v2(5);
  cout << "  constructor - Vector::Vector(int size);" << endl
       << "\tVector v2(5) = " << v2 << endl;
  cout << "\tlength = " << v2.length() << endl; 
  //
  Vector v3(3, &test1[0]);
  cout << "  constructor - Vector::Vector(int size, double elem[]);" <<endl;
  cout << "\tVector v3(3, {1.1,2.2,3.3}) = " << v3 << endl;
  cout << "\tlength = " << v3.length() << endl;
  //
  Vector v4 = v3;
  cout << "  copy constructor - Vector::Vector(const Vector& v);" << endl;
  cout << " \tVector v4 = v3, v4 = " << v4 << endl;
  cout << endl;
  //
  cout << "Testing get/set Dimension" << endl;
  //
  cout << "  v4.getDimension() = " << v4.getDimension() << endl;
  v4.setDimension(7);
  cout << "  after v4.setDimension(7) , v4.getDimension() = " 
       << v4.getDimension() << endl;
  cout << "\tv4 = " << v4 << endl;
  v4.setDimension(2);
  cout << "  after v4.setDimension(2) , v4.getDimension() = " 
       << v4.getDimension() << endl;
  cout << "\tv4 = " << v4 << endl;
  //
  cout << endl << "Testing Assignment operator" << endl;
  Vector v5(2, &test1[5]);
  cout << "\tVector v5(2, {6.6, 7.7}) = " << v5 << endl; 
  Vector v6;
  v6 = v5;
  cout << "\tVector v6; v6 = v5; v6 = " << v6 << endl;
  //
  cout << endl << "Testing Arithmetic operators" << endl;
  //
  cout << "  -(negate): \t-v3 = " << (-v3) << endl; 
  //
  cout << "  +: \t v4 + v5 = " << v4+v5 << endl;
  //
  cout << "  -:  \tv4 - v5 = " << v4-v5 << endl;
  //
  cout << "  *:  \tv4 * 2.1 = " << v4*2.1 ;
  cout << "\tlength = " << (v4 * 2.1).length() << endl;
  cout << "  *:  \t3.4 * v4 = " << 3.4*v4; 
  cout << "\tlength = " << (3.4 * v4).length() << endl;
  //
  cout << "  +=:  \tv6 += v5; v6 = " << (v6 += v5) << endl;
  //
  cout << "  -=:  \tv5 -= v4; v5 = " << (v5 -= v4) << endl;
  //
  cout << "  *=:  \tv4 *= 7.6; v4 = " << (v4 *= 7.6) << endl;
  //
  cout << endl << "Testing Equality Operators" << endl;
  //
  cout << "  v4 = " << v4 << endl;
  cout << "  v5 = " << v5 << endl;
  cout << " \t==: v4 == v5 :" << (v4 == v5 ? "true" : "false") << endl
       << " \t!=: v4 != v5 :" << (v4 != v5 ? "true" : "false") << endl;
  cout << "  after v4 = v5" << endl;
  v4 = v5;
  cout << " \t==: v4 == v5 :" << (v4 == v5 ? "true" : "false") << endl
       << " \t!=: v4 != v5 :" << (v4 != v5 ? "true" : "false") << endl;
  //
  cout << endl << "General Testing" << endl;

  Vector v7;
  v6 *= (v6 -= (v4 + v6[0] * (v7 = -v5)))[0];
  cout << "  Vector v7; v6 *= (v6 -= (v4 + v6[0] * (v7 = -v5)))[0];" << endl;
  cout << "\tv6 = " << v6 ;
  cout << "\tlength = " << v6.length() << endl;
  //
  PrintMyID("XXX703xxx");
}
