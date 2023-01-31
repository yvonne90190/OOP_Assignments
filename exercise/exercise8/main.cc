#include <iostream>
#include <string.h>
#include <cmath>
//#include <iomanip>
//#include <cstdio>
using namespace std;

template <typename T1, typename T2>
float Add(T1 a, T2 b) {
	float A = stof(a);
	float B = stof(b);
	return A+B;
}

int main() {
	string type1, value1, type2, value2;
	while (1){
		cin >> type1;
	   	if (type1.compare("-1")==0){
			break;
		}
		cin >> value1 >> type2;
	   	if (type2.compare("-1")==0){
			break;
		}	
		cin >> value2;
		float ans = Add(value1, value2);
		if (ans==0){
			cout << "Sum: 0" << endl;
		}
		else{
			cout << "Sum: ";
			 cout << std::ceil(ans*10)/10.0 << endl;
			//cout << setprecision(2) << ans << endl;
			//			printf("%.1lf", ans);
		}
	}
	return 0;
}

