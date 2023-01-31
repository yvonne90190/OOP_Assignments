/* Copyright (c) 1996 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     Vector.cc
   PURPOSE
     Generic geometric vector
   NOTES
     
   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Aug 27, 1996: Created.
***************************************************************************/

/* $Log:$ */

extern "C" { 
#include <math.h>
#include <stdlib.h>
}
using namespace std;
#include <assert.h>
#include <iostream>
#include "Vector.h"


// default constructor
Vector::Vector() {

  initialize(2);
  for(int i=0;i<2;i++) 
    fElements[i]=0.0;

}

// initialization routine for use in various member functions
void 
Vector::initialize(int size) {

  allocSize = fDimension = size;
  fElements = new double[size];
  if (fElements==NULL) {
    cout << "No more memory\n";
    exit(-1);
  }
}

// construct a vector of the given dimension
Vector::Vector(int size) {

  initialize(size);
  for(int i=0;i<size;i++) 
    fElements[i]=0.0;

}

// constructor for a list of initialization value
// the dimension of elements should be consistent with the size
Vector::Vector(int size, const double elements[]) {

  initialize(size);
  for(int i=0;i<size;i++) 
    fElements[i]=elements[i];
  
}

// copy constructor
Vector::Vector(const Vector &source) {

  int dim=source.getDimension();
  initialize(dim);
  for(int i=0;i<dim;i++) 
    fElements[i] = source[i];

}

// destructor
Vector::~Vector() {

  delete [] fElements;

}


// get the dimension of the vector
int 
Vector::getDimension() const {

  return fDimension;

}

// reset the dimension of the vector
void 
Vector::setDimension(int dimension) {

  if (fDimension >= dimension) {
    // shrinking the vector
    fDimension = dimension;
  } else { 
    int oldDim = fDimension;
    if (allocSize >= dimension) {
      // growing the vector but no memory allocated needed
      fDimension = dimension;
    } else {
      // need to allocate new memory
      double *tmp = fElements;
      initialize(dimension);
      for(int i=0;i<oldDim;i++) 
	fElements[i] = tmp[i];
      delete [] tmp;
    }
    // setting the grown portion to zero
    for(int i=oldDim;i<dimension;i++)
      fElements[i] = 0.0;
  }
  return;
    
}

// assignment operator
Vector & 
Vector::operator=(const Vector &v2) {

  if (this == &v2) 
    return *this;
  setDimension(v2.getDimension());
  for(int i=0;i<fDimension;i++) 
    fElements[i] = v2[i];
  return *this;

}

// element access function
double & 
Vector::operator[](int index) {
  if (index>=fDimension) {
    cout << "Index [" << index << "] out of bound" << endl;
    return *new double(0.0);
  }
  //assert(index<fDimension);
  return fElements[index];
}

// element access function
double 
Vector::operator[](int index) const {
  if (index>=fDimension) {
    cout << "Index [" << index << "] out of bound" << endl;
    return 0.0;
  }
  //assert(index<fDimension);
  return fElements[index];
}

// addition of two vectors
Vector 
Vector::operator+(const Vector &v2) const {
  if (fDimension!=v2.getDimension()) {
    cout << "inconsistent dimension" << endl;
    return *this;
  }
  //assert(fDimension==v2.getDimension());
  Vector v3(fDimension);
  for(int i=0;i<fDimension;i++)
    v3[i] = fElements[i] + v2[i];
  return v3;
}

// substraction of two vectors
Vector 
Vector::operator-(const Vector &v2) const {
  if (fDimension!=v2.getDimension()) {
    cout << "inconsistent dimension in operator-" << endl;
    return *this;
  }
  // assert(fDimension==v2.getDimension());
  Vector v3(fDimension);
  for(int i=0;i<fDimension;i++)
    v3[i] = fElements[i] - v2[i];
  return v3;
}

// add the given vector to the current one
Vector & 
Vector::operator+=(const Vector &v2) {
  if (fDimension!=v2.getDimension()) {
    cout << "inconsistent dimension in operator+=" << endl;
    return *this;
  }
  assert(fDimension==v2.getDimension());
  for(int i=0;i<fDimension;i++)
    fElements[i] += v2[i];
  return *this;
}

// substract the given vector to the current one
Vector & 
Vector::operator-=(const Vector &v2) {
  if (fDimension!=v2.getDimension()) {
    cout << "inconsistent dimension in operator-=" << endl;
    return *this;
  }
  //assert(fDimension==v2.getDimension());
  for(int i=0;i<fDimension;i++)
    fElements[i] -= v2[i];
  return *this;
}

// unary negation operator
Vector 
Vector::operator-() {
  
  Vector v2(fDimension);
  for(int i=0;i<fDimension;i++)
    v2[i] = -fElements[i];
  return v2;
}

// scalar multiplication: Note that this is not a member function
Vector 
operator* (double scale,Vector v) {
  Vector ret(v.getDimension());
  for(int i=0;i<v.getDimension();i++)
    ret[i]=v[i]*scale;
  return ret;
}

// scalar multiplication
Vector 
Vector::operator* (double scale) {
  Vector ret(fDimension);
  for(int i=0;i<fDimension;i++)
    ret[i]=fElements[i]*scale;
  return ret;
}

// scalar multiplication and assignment
Vector & 
Vector::operator*=(double scale) {
  for(int i=0;i<fDimension;i++)
    fElements[i] *= scale;
  return *this;
}

// equality relation
bool 
Vector::operator==(const Vector &v2) const {
  if (fDimension != v2.getDimension())
    return false;
  for(int i=0;i<fDimension;i++)
    if (fElements[i] != v2[i])
      return false;
  return true;
}

// inequality relation
bool 
Vector::operator!=(const Vector &v2) const {
  if (fDimension != v2.getDimension())
    return true;
  for(int i=0;i<fDimension;i++)
    if (fElements[i] != v2[i])
      return true;
  return false;
}

// return the euclidean distance of the vector
double 
Vector::length() const {
  double len=0.0;
  for(int i=0;i<fDimension;i++) 
    len += fElements[i]*fElements[i];
  return sqrt(len);
}

// display the vector 
ostream & 
operator << (ostream &os, const Vector &v) {

  os << "(";
  for(int i=0; i<v.fDimension; i++) {
    if (i!=0) 
      os << ", ";
    os << v.fElements[i];
  }
  os << ")" ;
  return os;

}


//double
//Vector::operator*() {

//  return 1.0;
  
//}
