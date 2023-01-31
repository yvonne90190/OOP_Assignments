#include <iostream>
using namespace std;

class Complex{
        public:
                Complex(double=0.0, double=0.0);
                double getReal() const {return real;};
                double getImaginary() const {return imag;};
                Complex operator- (const Complex &) const;
                Complex operator* (const Complex &) const;
                void print() const;
                //....................................
                Complex &operator= (const Complex &);
                //Complex operator= (const Complex &);
                //........................................
                Complex operator+ (const Complex &) const;
                Complex operator+ (double A);

        private:
                double real;
                double imag;
};

//......................................................................
Complex operator+ (double A, Complex B) {
        Complex tmp(A+B.getReal(), B.getImaginary());
        return tmp;
}

Complex Complex::operator+ (double A) {
        Complex tmp(real+A, imag);
        return tmp;
}

Complex Complex::operator+ (const Complex &A) const {
        Complex tmp(real+A.getReal(), imag+A.getImaginary());
        return tmp;
}
//......................................................................


Complex &Complex::operator= (const Complex &origin) {
        if (this == &origin){
                return *this;
        }
        real = origin.getReal();
        imag = origin.getImaginary();
        return *this;
}

/*
Complex Complex::operator= (const Complex &origin) {
        Complex tmp(origin.getReal(), origin.getImaginary());
        //cout << endl << tmp.getReal() << " " << tmp.getImaginary() << endl;
        return tmp;
}
*/
//......................................................................
Complex::Complex(double real_, double imag_){
        real = real_;
        imag = imag_;
}


Complex Complex::operator- (const Complex &A) const {
        Complex tmp(real-A.getReal(), imag-A.getImaginary());
        return tmp;
}

Complex Complex::operator* (const Complex &A) const {
        Complex tmp(real*A.getReal(), imag*A.getImaginary());
        return tmp;
}

void Complex::print() const {
        cout << "(" << real << "," << imag << ") ";
}

int main(){
        Complex n1;
        Complex n2(1,2);
        Complex n3(3,4);
        cout << "n1,  n2,  n3  ";
        n1.print();
        n2.print();
        n3.print();
        
        cout << "\nn1 = (n2 = n3)";
        n1 = (n2 = n3);
        n1.print();
        n2.print();
        n3.print();
        
        cout << "\nn1 = n2 + n3  ";
        n1 = n2 + n3;
        n1.print();
        cout << " = ";
        n2.print();
        cout << " + ";
        n3.print();
        cout << "\nn1 = n2 - n3  ";
        n1 = n2 - n3;
        n1.print();
        cout << " = ";
        n2.print();
        cout << " - ";
        n3.print();
        cout << "\nn1 = n2 * n3  ";
        n1 = n2 * n3;
        n1.print();
        cout << " = ";
        n2.print();
        cout << " * ";
        n3.print();

        cout << endl;

        double a=5;
        Complex b(1,3);
        Complex c;
        cout << "\nc     b    a" << endl;
        c.print();
        b.print();
        cout << a;
        cout << endl << endl;

        cout << "\n   c   = 1.0  +  b  +  a" << endl;
        c = 1.0 + b + a;
        c.print();
        cout << " = 1.0 + ";
        b.print();
        cout << " + ";
        cout << a;
        cout << endl;

        //Complex c = 1.0+b+a;
        return 0;
}
