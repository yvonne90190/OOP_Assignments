#include <iostream>
#include <string>
using namespace std;

void
Repeat(int *arr, bool &valid) {
	for (int i=0; i<9; ++i) {
		if (arr[i]!=1) {
			valid = false;
			break;
		}
	}
}

int
main(){

	int num_arr;
	cin >> num_arr;

	for (int n=0; n<num_arr; ++n) {       // The nth arr
		bool valid = true;
		int sudoku[9][9];
		for (int i=0; i<9; ++i) {
			for (int j=0; j<9; ++j) {
				cin >> sudoku[i][j];
				if (sudoku[i][j]<1 || sudoku[i][j]>9){
					valid = false;
				}
			}
		}
		char separate;
		cin >> separate;

		// Test Row
		if (valid) {
			for (int r=0; r<9; ++r) {         // The arr's rth row
				int exist[9]={};
				for (int c=0; c<9; ++c) {     // The arr's cth column
					exist[sudoku[r][c]-1]+=1;
				}
				Repeat(exist, valid);
				if (!valid) {
					break;
				}
			}
		}
		// Test Col
		if (valid){
			for (int c=0; c<9; ++c) {         // The arr's rth row
				int exist[9]={};
				for (int r=0; r<9; ++r) {     // The arr's cth column
					exist[sudoku[r][c]-1]+=1;
				}
				Repeat(exist, valid);
				if (!valid) {
					break;
				}
			}
		}
		// Test Bolck
		if (valid){
			for (int i=0; i<3; ++i) { 
				for (int j=0; j<3; ++j) {
					int exist[9]={};
					for (int c=0; c<3; ++c) {
						for (int r=0; r<3; ++r) {
							exist[sudoku[3*i+c][3*j+r]-1]+=1;
						}
					}
					Repeat(exist, valid);
					if (!valid) {
						break;
					}
				}
				if (!valid) {
					break;
				}
			}
		}
		//Print Result
		if (valid) {
			cout << "Valid" << endl;
		} else {
			cout << "Invalid" << endl;
		}
	}
	return 0;
}
