#include <iostream>
using namespace std;

class Complex{
	public:
		Complex operator+ (Complex n);
		Complex operator- (Complex n);
		Complex operator* (Complex n);
		Complex operator/ (Complex n);
		//...
		bool operator== (const Complex &n) const;
		bool operator> (const Complex &n) const;
		bool operator< (const Complex &n) const;
		Complex operator++ (int);
		Complex &operator++ ();
		Complex operator-- (int);
		Complex &operator-- ();
		Complex &operator+= (Complex n);
		// ++C C++ - +=
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
Complex &Complex::operator+= (Complex n){
	this->real += n.real;
	this->imaginary += n.imaginary;
	return *this;
}
Complex Complex::operator-- (int){
	Complex tmp = *this;
	real--;
	imaginary--;
	return tmp;
}
Complex &Complex::operator-- (){
	real--;
	imaginary--;
	return *this;
}
Complex Complex::operator++ (int){
	Complex tmp = *this;
	real++;
	imaginary++;
	return tmp;
}
Complex &Complex::operator++ (){
	real++;
	imaginary++;
	return *this;
}
bool Complex::operator== (const Complex &n) const{
	if (this->real == n.real && this->imaginary == n.imaginary)
		return true;
	return false;
}
bool Complex::operator> (const Complex &n) const{
	if (this->real > n.real)
		return true;
	else if(this->real == n.real && this->imaginary > n.imaginary)
		return true;
	return false;
}
bool Complex::operator< (const Complex &n) const{
	if (this->real < n.real)
		return true;
	else if(this->real == n.real && this->imaginary < n.imaginary)
		return true;
	return false;
}

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
int main(){

	Complex n1;
	Complex n2;
	Complex n3;
	while (cin >> n1 && cin >> n2){
		//cin >> n1;
		//cin >> n2;
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
