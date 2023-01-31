#include<iostream>
#include<math.h>
#include"Vector.h"
using namespace std;
Vector::Vector(){
        allocSize=2;
        fElements=new double[allocSize];
        fElements[0]=0;
        fElements[1]=0;
}
Vector::Vector(int dimension){
        allocSize=dimension;
        fElements=new double[allocSize];
        for(int i=0;i<allocSize;i++)fElements[i]=0;
}
Vector::Vector(int size, const double elements[]){
        allocSize=size;
        fElements=new double[allocSize];
        for(int i=0;i<allocSize;i++)fElements[i]=elements[i];
}
Vector::Vector(const Vector &source){
        allocSize=source.allocSize;
        fElements=new double[allocSize];
        for(int i=0;i<allocSize;i++){
                fElements[i]=source.fElements[i];
        }
}
Vector::~Vector(){
        delete [] fElements;
}
int Vector::getDimension()const{
        return this->allocSize;
}
void Vector::setDimension(int dimension){
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
Vector& Vector::operator=(const Vector &v2){
        this->allocSize=v2.allocSize;
        this->fElements=new double[allocSize];
        for(int i=0;i<this->allocSize;i++){
                fElements[i]=v2.fElements[i];
        }
        return *this;
}
double &Vector::operator[](int index){
        return this->fElements[index];
}
Vector Vector::operator+(const Vector &v2) const{
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
