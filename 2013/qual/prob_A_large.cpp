#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for(int i=1;i<=T;i++){
		string line;
		char board[4][4];

		for (int j=0; j<4; j++) {
			cin >> line;
			for (int k=0; k<4; k++) {
				board[j][k] = line[k];
			}
		}

		bool isDecided = false;
		string result = "";

		for (int j=0; j<4; j++) {
			int numT = 0;
			int numX = 0;
			int numO = 0;
			for (int k=0; k<4; k++) {
				if (board[j][k] == 'T') {
					numT += 1;
				} else if (board[j][k] == 'X') {
					numX += 1;
				} else if (board[j][k] == 'O') {
					numO += 1;
				} 
			}

			if (numT + numX >= 4) {
				result = "X won";
				isDecided = true;
				break;
			} else if (numT + numO >= 4) {
				result = "O won";
				isDecided = true;
				break;
			}
		}

		for (int k=0; k<4; k++) {
			if (isDecided) {
				break;
			}

			int numT = 0;
			int numX = 0;
			int numO = 0;
			for (int j=0; j<4; j++) {
				if (board[j][k] == 'T') {
					numT += 1;
				} else if (board[j][k] == 'X') {
					numX += 1;
				} else if (board[j][k] == 'O') {
					numO += 1;
				}
			}

			if (numT + numX >= 4) {
				result = "X won";
				isDecided = true;
				break;
			} else if (numT + numO >= 4) {
				result = "O won";
				isDecided = true;
				break;
			}
		}

		if (!isDecided) {
			int numT = 0;
			int numX = 0;
			int numO = 0;
			for (int j=0; j<4; j++) {
				if (board[j][j] == 'T') {
					numT += 1;
				} else if (board[j][j] == 'X') {
					numX += 1;
				} else if (board[j][j] == 'O') {
					numO += 1;
				}
			}
			if (numT + numX >= 4) {
				result = "X won";
				isDecided = true;
			} else if (numT + numO >= 4) {
				result = "O won";
				isDecided = true;
			}
		}

		if (!isDecided) {
			int numT = 0;
			int numX = 0;
			int numO = 0;
			for (int j=0; j<4; j++) {
				if (board[j][3-j] == 'T') {
					numT += 1;
				} else if (board[j][3-j] == 'X') {
					numX += 1;
				} else if (board[j][3-j] == 'O') {
					numO += 1;
				}
			}
			if (numT + numX >= 4) {
				result = "X won";
				isDecided = true;
			} else if (numT + numO >= 4) {
				result = "O won";
				isDecided = true;
			}
		}

		if (!isDecided) {
			int numEmpty = 0;

			for(int j=0; j<4; j++) {
				for (int k=0; k<4; k++) {
					if (board[j][k] == '.') {
						numEmpty += 1;
					}
				}
			}

			if (numEmpty > 0) {
				result = "Game has not completed";
			} else {
				result = "Draw";
			}
		}

		cout << "Case #" << i << ": " << result << endl;
	}
}
