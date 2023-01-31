#include <iostream>
using namespace std;

class Superman {
	private: 
		string category;
		string name;
		int hp;
		float atk;
		float def;

	public:
		Superman(string inCategory = "", string inName = "", int inHp = 0, float inAtk = 0, float inDef = 0);
		~Superman(){};

		void PrintSuperman() const;
		void Attack();
		void Attacked(int damage);
		void ShowHP();
};

Superman::Superman(string inCategory, string inName, int inHp, float inAtk, float inDef)
	:hp(inHp), atk(inAtk), def(inDef){
		category = inCategory;
		name = inName;
	}

void Superman::PrintSuperman() const{
	cout << category << " " << name << " " << hp << " " << atk  << " " << def;
}

void Superman::Attack(){
	//發出的攻擊值=（atk+hp）/2
	cout << category << " " << name << " caused " << (atk+hp)/2 << " points damage" << endl;
}

void Superman::Attacked(int damage){
	//對超人造成的傷害=2*（be_atk_value）/def
	cout << category << " " << name << " is damaged by " << 2*damage/def << " points " << endl;
}

void Superman::ShowHP(){
	cout << category << " " << name << " currently has " << hp << " points of HP" << endl;
}

int Check(int a){
	if ( a<0 ) {
		return 0;
	}
	return a;
}

float Check(float &a){
	if ( a<0 ) {
		return 0;
	}
	return a;
}

int main() {
	string inCategory;
	string inName;
	int inHp;
	float inAtk, inDef, in_be_atk_value;
	char event;
	while ( cin >> inCategory >> inName >> inHp >> inAtk >> inDef >> event ) {
		if ( inHp<0 ){
			inHp = 0;
		}
		Superman player(inCategory, inName, Check(inHp), Check(inAtk), Check(inDef));
		//player.PrintSuperman();
		//cout << " " << event;
		if ( event == 'B' ){
			cin >> in_be_atk_value;
			in_be_atk_value = Check(in_be_atk_value);
		//	cout << " " << in_be_atk_value;
		}
		//cout << endl;
		
		if ( event == 'A' ){
			player.Attack();
		}
		else if ( event == 'B' ){	
			player.Attacked(in_be_atk_value);
		}
		else if ( event == 'C' ){
			player.ShowHP();
		}	

	}
	return 0;
}

