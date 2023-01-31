#include<iostream>
#include<math.h>
#include"Vector.h"

using namespace std;

Vector::Vector(){
	fElements = new double[2];
	initialize(2);
}

Vector::Vector(int dimension){
	fElements = new double[dimension];
	initialize(dimension);
}

Vector::Vector(int size, const double elements[]){
	allocSize = size;
	fElements = new double[allocSize];
	for(int i=0; i<allocSize; i++){
		fElements[i] = elements[i];
	}
}

Vector::Vector(const Vector &source){
	allocSize = source.allocSize;
	fElements = new double[allocSize];
	for(int i=0; i<allocSize; i++){
		fElements[i] = source.fElements[i];
	}
}

Vector::~Vector(){
	delete [] fElements;
}

void
Vector::initialize(int size){
	allocSize=size;
	for (int i=0; i<size; ++i){
		fElements[i] = 0.0;
	}
}

int 
Vector::getDimension()const{
	return this->allocSize;
}

void 
Vector::setDimension(int dimension){
	if(this->allocSize>dimension){
		int i;
		double a[this->allocSize];
		for(i=0;i<this->allocSize;i++)a[i]=this->fElements[i];
		delete [] fElements;
		fElements=new double[dimension];
		for(i=0;i<dimension;i++)this->fElements[i]=a[i];
	}
	else if(this->allocSize<dimension){
		int i;
		double a[this->allocSize];
		for(i=0;i<this->allocSize;i++)a[i]=this->fElements[i];
		delete [] fElements;
		fElements=new double[dimension];
		for(i=0;i<this->allocSize;i++)this->fElements[i]=a[i];
		for(;i<dimension;i++)this->fElements[i]=0;
	}
	this->allocSize=dimension;
}

Vector& 
Vector::operator=(const Vector &v2){
	if (this == &v2){
		return *this;	
	}
	int newSize = v2.allocSize;
	this->allocSize = newSize;
	this->fElements = new double[newSize];
	for(int i=0; i<newSize; i++){
		fElements[i] = v2.fElements[i];
	}
	return *this;
}

double&
Vector::operator[](int index){
	return fElements[index];
}

Vector 
Vector::operator+(const Vector &v2) const{
	Vector temp(this->allocSize);
	for(int i=0;i<temp.allocSize;i++)temp.fElements[i]=this->fElements[i]+v2.fElements[i];
	return temp;
}
Vector Vector::operator-(const Vector &v2) const{
	Vector temp(this->allocSize);
	for(int i=0;i<temp.allocSize;i++)temp.fElements[i]=this->fElements[i]-v2.fElements[i];
	return temp;
}
Vector& Vector::operator+=(const Vector &v2){
	for(int i=0;i<this->allocSize;i++)this->fElements[i]=this->fElements[i]+v2.fElements[i];
	return *this;
}
Vector& Vector::operator-=(const Vector &v2){
	for(int i=0;i<this->allocSize;i++)this->fElements[i]-=v2.fElements[i];
	return *this;
}
Vector Vector::operator-(){
	for(int i=0;i<this->allocSize;i++)this->fElements[i]=-(this->fElements[i]);
	return *this;
}
Vector Vector::operator*(double scale){
	Vector temp(this->allocSize);
	for(int i=0;i<temp.allocSize;i++)temp.fElements[i]=(this->fElements[i])*scale;
	return temp;
}
Vector& Vector::operator*=(double scale){
	for(int i=0;i<this->allocSize;i++)this->fElements[i]*=scale;
	return *this;
}
bool Vector::operator==(const Vector &v2)const{
	for(int i=0;i<this->allocSize;i++)if(this->fElements[i]!=v2.fElements[i])return false;
	return true;
}
bool Vector::operator!=(const Vector &v2)const{
	for(int i=0;i<this->allocSize;i++)if(this->fElements[i]==v2.fElements[i])return false;
	return true;
}
double Vector::length()const{
	double len = 0.0;
	for(int i=0;i<allocSize;i++)len+=(fElements[i])*(fElements[i]);
	len=sqrt(len);
	return len;
}
Vector operator*(double scale,Vector v){
	return v*scale;
}
/*ostream &operator<<(ostream &os, const Vector &v){
  int i=1;
  for(os<<'('<<v.fElements[0];i<v.allocSize;i++)os<<','<<v.fElements[i];
  os<<')';
  return os;
  }*/


// display the vector
ostream &
operator << (ostream &os, const Vector &v) {
        os << "(";
        for( int i = 0 ; i < v.getDimension() - 1; i++ ){
                os << v.fElements[i] << ", ";
        }
        os << v.fElements[ v.getDimension() - 1 ] << ")";
        return os;
}
