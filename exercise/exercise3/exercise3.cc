#include <iostream>
using namespace std;

void
Repeat(int *arr, bool &valid) {
	for (int i=0; i<9; ++i) {
		if (arr[i]!=1) {
			valid = false;
		}
	}
}

int
main(){

	int num_arr;
	cin >> num_arr;

	for (int n=0; n<num_arr; ++n) {       // The nth arr
		int sudoku[9][9];
		for (int i=0; i<9; ++i) {
			for (int j=0; j<9; ++j) {
				cin >> sudoku[i][j];
			}
		}

		bool valid = true;

		// Test Row
		int exist_row[9]={};
		for (int r=0; r<9; ++r) {         // The arr's rth row
			for (int c=0; c<9; ++c) {     // The arr's cth column
				exist_row[sudoku[r][c]]+=1;
				Repeat(exist_row, valid);
				if (valid == false) {
					break;
				}
			}
		}
		// Test Column
		int exist_col[9]={};
		for (int c=0; c<9; ++c) {         // The arr's rth row
			for (int r=0; r<9; ++r) {     // The arr's cth column
				exist_col[sudoku[c][r]]+=1;
				Repeat(exist_col, valid);
				if (valid == false) {
					break;
				}
			}
		}
		// Test Bolck


	}
}
