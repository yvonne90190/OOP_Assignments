#include <map>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	map<char, vector<int>> azmap;
	char c;
	for (c='a'; c<='z'; c++){
		int now = (int)c - 96;
		vector<int> vect;
		for(int i = 0; i < now; i++){
			//cout << i << " ";
			vect.push_back(i);
		}
		//cout << endl;
		azmap[c] = vect;
	}
	int num, cnt, ans, action;
	while (cin >> c >> action >> num){
		cnt = -1;
		ans = 0;
		// 宣告 iterator
		vector<int>::iterator itr_1 = azmap[c].begin();
		vector<int>::iterator itr_2 = azmap[c].end(); // [begin, end)
		vector<int>::iterator itr;
		switch(action){
			case 0:	
				for(itr=itr_1; itr!=itr_2; itr++){
					cnt++;
					//cout << *itr << " ";
					if (*itr == num){
						ans = cnt;
					}
				}
				cout << ans << " ";
				break;
			case 1:	
				reverse(itr_1, itr_2);
				for(itr=itr_1; itr!=itr_2; itr++){
					cnt++;
					//cout << *itr << " ";
					if (*itr == num){
						ans = cnt;
					}
				}
				cout << ans << " ";
				reverse(itr_1, itr_2);
				break;
			case 2:
				vector<int> evenVect;
				for(itr=azmap[c].begin(); itr!=azmap[c].end(); itr++){
					cnt++;
					if (*itr%2 == 0){
						evenVect.push_back(*itr);
					}
				}
				itr_1 = evenVect.begin();
				itr_2 = evenVect.end(); // [begin, end)
				cnt = 0;
				for(itr=itr_1; itr!=itr_2; itr++){
					cnt++; 
					//cout << cnt << " " << *itr << " " << endl;
					if(cnt == num){
						ans = *itr;
					}	
				}
				cout << ans << " ";
				break;
		}	
	}
}
