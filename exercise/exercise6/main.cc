#include <iostream>
using namespace std;
class Complex;
class Complex2{
	public:
		Complex2();
		Complex2(int real_, int imaginary_);
		bool operator== (const Complex2 &n) const;
		bool operator> (const Complex2 &n) const;
		bool operator< (const Complex2 &n) const;
		Complex2 operator++ (int);
		Complex2 &operator++ ();
		Complex2 operator-- (int);
		Complex2 &operator-- ();
        Complex2 operator+ (Complex2 n);
        Complex2 operator- (Complex2 n);
        Complex2 operator* (Complex2 n);
		Complex2 &operator+= (Complex2 n);
        friend ostream &operator<<( ostream& out, const Complex2 &n);
        friend istream &operator>>( istream& in, Complex2 &n);
	
		Complex* m;
};
class Complex{
	friend Complex2;
    public:
        Complex operator+ (Complex n);
        Complex operator- (Complex n);
        Complex operator* (Complex n);
        Complex operator/ (Complex n);
        friend ostream &operator<<( ostream& out, const Complex &n);
        friend istream &operator>>( istream& in, Complex &n);
        Complex(){
            this->real = 0;
            this->imaginary = 0;
        }
        Complex(int r, int i){
            this->real = r;
            this->imaginary = i;
        }
    private:
        int real;
        int imaginary;
};
//.........................................
Complex2 Complex2::operator+ (Complex2 n){
	Complex2 tmp;
	*tmp.m = *this->m + *n.m;
	return tmp;
}
Complex2 Complex2::operator- (Complex2 n){
	Complex2 tmp;
	*tmp.m = *this->m - *n.m;
	return tmp;
}
Complex2 Complex2::operator* (Complex2 n){
	Complex2 tmp;
	*tmp.m = *this->m * *n.m;
	return tmp;
}
ostream &operator<<( ostream& out, const Complex2 &n){
	out << *n.m;
	return out;
}
istream &operator>>( istream& in, Complex2 &n){
	in >> *n.m;
	return in;
}
Complex2::Complex2(){
	m = new Complex();
}
Complex2::Complex2(int real_, int imaginary_){
	m = new Complex(real_, imaginary_);
}
Complex2 Complex2::operator-- (int){
	Complex2 tmp;
    *tmp.m	= *m;
	m->real--;
	m->imaginary--;
	return tmp;
}
Complex2 &Complex2::operator-- (){
	m->real--;
	m->imaginary--;
	return *this;
}
Complex2 Complex2::operator++ (int){
	Complex2 tmp;
    *tmp.m	= *m;
	m->real++;
	m->imaginary++;
	return tmp;
}
Complex2 &Complex2::operator++ (){
	m->real++;
	m->imaginary++;
	return *this;
}
Complex2 &Complex2::operator+= (Complex2 n){
	*m = *m + *n.m;
	return *this;
}
bool Complex2::operator== (const Complex2 &n) const{
	if (m->real == n.m->real && m->imaginary == n.m->imaginary)
		return true;
	return false;
}
bool Complex2::operator> (const Complex2 &n) const{
	if (m->real > n.m->real)
		return true;
	else if(m->real == n.m->real && m->imaginary > n.m->imaginary)
		return true;
	return false;
}
bool Complex2::operator< (const Complex2 &n) const{
	if (m->real < n.m->real)
		return true;
	else if(m->real == n.m->real && m->imaginary < n.m->imaginary)
		return true;
	return false;
}
//.............................................
Complex Complex::operator+ (Complex n){
    Complex temp;
    temp.real = this->real + n.real;
    temp.imaginary = this->imaginary + n.imaginary;
    return temp;
}
Complex Complex::operator- (Complex n){
    Complex temp;
    temp.real = this->real - n.real;
    temp.imaginary = this->imaginary - n.imaginary;
    return temp;
}
Complex Complex::operator* (Complex n){
    Complex temp;
    temp.real = this->real * n.real - this->imaginary * n.imaginary; //I^2 = -1
    temp.imaginary = this->real * n.imaginary + this->imaginary * n.real;
    return temp;
}
Complex Complex::operator/ (Complex n){
    Complex temp;
    temp.real = (this->real*n.real+this->imaginary*n.imaginary) / (n.real*n.real + n.imaginary*n.imaginary);
    temp.imaginary = (this->imaginary*n.real - this->real*n.imaginary) / (n.real*n.real + n.imaginary*n.imaginary);
    return temp;
}

ostream &operator<<( ostream& out, const Complex &n){
    if(n.imaginary<0){
        out << n.real << n.imaginary << "i";
        return out;
    }else{
        out << n.real << "+" << n.imaginary << "i";
        return out;
    }
}
istream &operator>>( istream& in, Complex &n){
    in >> n.real >> n.imaginary;
    return in;
}
//.............................................
int main(){
	Complex2 n1;
	Complex2 n2;
	Complex2 n3;
	
	while (cin >> n1 && cin >> n2){
		cout<<"C1 = "<<n1<<endl;
		cout<<"C2 = "<<n2<<endl;
		cout<<"C1==C2? "<< (n1==n2 ? "true" : "false") <<endl;
		cout<<"C1<C2?  "<< (n1<n2 ? "true" : "false") <<endl;
		cout<<"C1>C2?  "<< (n1>n2 ? "true" : "false") <<endl;
		n3 = n1+n2;
		cout<<"C1+C2 = "<<n3<<endl;
		n3 = n1-n2;
		cout<<"C1-C2 = "<<n3<<endl;
		n3 = n1*n2;
		cout<<"C1*C2 = "<<n3<<endl;
		n3 = n1++;
		cout << "C1++  = "<<n3<<endl;
		n3 = n1++;
		cout << "C1++  = "<<n3<<endl;
		n3 = ++n1;
		cout << "++C1  = "<<n3<<endl;
		n3 = ++n1;
		cout << "++C1  = "<<n3<<endl;
		n3 = n2--;
		cout << "C2--  = "<<n3<<endl;
		n3 = n2--;
		cout << "C2--  = "<<n3<<endl;
		n3 = --n2;
		cout << "--C2  = "<<n3<<endl;
		n3 = --n2;
		cout << "--C2  = "<<n3<<endl;
		n1+=n2;
		cout << "C1+=C2  "<<n1<<endl;
		cout <<"=============="<<endl;
	}
    return 0;
}
