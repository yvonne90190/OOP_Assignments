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
	fDimension = size;
	fElements = new double[fDimension];
	for(int i=0; i<fDimension; i++){
		fElements[i] = elements[i];
	}
}

Vector::Vector(const Vector &source){
	allocSize = source.allocSize;
	fDimension = source.fDimension;
	fElements = new double[fDimension];
	for(int i=0; i<fDimension; i++){
		fElements[i] = source.fElements[i];
	}
}

Vector::~Vector(){
	delete [] fElements;
}

void
Vector::initialize(int size){
	fDimension=size;
	allocSize=size;
	for (int i=0; i<size; ++i){
		fElements[i] = 0.0;
	}
}

int 
Vector::getDimension()const{
	return this->fDimension;
}

void 
Vector::setDimension(int dimension){
	if(this->fDimension < dimension){
		int i;
		double tmp[this->fDimension];
		for(i=0; i<this->fDimension; i++){
			tmp[i] = this->fElements[i];
		}
		int orignal_size = i;
		delete [] fElements;
		fElements=new double[dimension];
		for(i=0; i<dimension; i++){
			if ( i < orignal_size ){
				this->fElements[i] = tmp[i];
			}
			else {
				this->fElements[i] = 0.0;
			}
		}
	}
	this->allocSize = dimension;
	this->fDimension = dimension;
}

Vector& 
Vector::operator=(const Vector &v2){
	if (this == &v2){
		return *this;	
	}
	int newSize = v2.fDimension;
	this->fDimension = newSize;
	this->allocSize = newSize;
	this->fElements = new double[newSize];
	for(int i=0; i<newSize; i++){
		fElements[i] = v2.fElements[i];
	}
	return *this;
}

double&
Vector::operator[](int index){
	if (index > this->fDimension || index < 0){
		if (this->fDimension == this->allocSize){
			this->setDimension(fDimension+1);
			this->fDimension -= 1;
		}
		cerr << "out-of-bound ";
		return fElements[allocSize-1];  
	}
	return fElements[index];
}

Vector 
Vector::operator+(const Vector &v2) const{
	int size_ = v2.fDimension;
	Vector temp(size_);
	if (this->fDimension != size_){
		cerr <<  "the dimensions of the two Vectors are not the same ";	
		return temp;
	}
	for(int i=0; i<size_; i++){
		temp.fElements[i] += this->fElements[i];
		if (this->fDimension == size_){
			temp.fElements[i] += v2.fElements[i];
		}
	}
	return temp;
}

Vector 
Vector::operator-(const Vector &v2) const{
	int size_ = this->fDimension;
	Vector temp(size_);
	if (this->fDimension != size_){
		cerr <<  "the dimensions of the two Vectors are not the same ";	
		return temp;
	}
	for(int i=0; i<size_; i++){
		temp.fElements[i] += this->fElements[i];
		if (this->fDimension == size_){
			temp.fElements[i] -= v2.fElements[i];
		}
	}
	return temp;
}

Vector& 
Vector::operator+=(const Vector &v2){
	for(int i=0; i<this->fDimension; i++){
		if (this->fDimension == v2.fDimension){
			this->fElements[i] += v2.fElements[i];
		}
	}
	if (this->fDimension != v2.fDimension){
		cerr <<  "the dimensions of the two Vectors are not the same ";
	}
	return *this;
}

Vector& 
Vector::operator-=(const Vector &v2){
	for(int i=0; i<this->fDimension; i++){
		if (this->fDimension == v2.fDimension){
			this->fElements[i] -= v2.fElements[i];
		}
	}
	if (this->fDimension != v2.fDimension){
		cerr <<  "the dimensions of the two Vectors are not the same ";
	}
	return *this;
}

// negate
Vector
Vector::operator-(){
	for(int i=0; i<this->fDimension; i++){
		this->fElements[i]= -(this->fElements[i]);
	}
	return *this;
}

Vector 
Vector::operator*(double scale){
	Vector temp(this->fDimension);
	for(int i=0; i<fDimension; i++){
		temp.fElements[i] = (this->fElements[i]) * scale;
	}
	return temp;
}

Vector& 
Vector::operator*=(double scale){
	for(int i=0; i<this->fDimension; i++){
		this->fElements[i] = this->fElements[i] * scale;
	}
	return *this;
}

bool 
Vector::operator==(const Vector &v2) const{
	for(int i=0; i<this->fDimension; i++){
		if(this->fElements[i] != v2.fElements[i]){
			return false;
		}
	}
	return true;
}

bool 
Vector::operator!=(const Vector &v2) const{
	for(int i=0;i<this->fDimension;i++){
		if(this->fElements[i] == v2.fElements[i]){
			return false;
		}
	}
	return true;
}

double 
Vector::length()const{
	double len = 0.0;
	for(int i=0;i<fDimension;i++){
		len += (fElements[i])*(fElements[i]);
	}
	return sqrt(len);
}

Vector 
operator*(double scale,Vector v){
	return v*=scale;
}

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
