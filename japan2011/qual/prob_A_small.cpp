#include <iostream>
#include <vector>

using namespace std;

int main() {
	int T;
	int i,j,k;

	cin >> T;

	for (i=1;i<=T;i++) {
		int M, C, W;
		vector<int> A, B; 
		vector<int> cards; 
		cin >> M;
		cin >> C;
		cin >> W;
		//cout << M << " " << C << " " << W << endl;
		for (j=0;j<C;j++) {
			int a, b;
			cin >> a;
			cin >> b;
			//cout << a << " " << b << endl;
			A.push_back(a);
			B.push_back(b);
		}
		for (j=0;j<M;j++) {
			cards.push_back(j+1);
		}

		//shuffle
		for (j=0;j<C;j++) {
			int start = A[j] - 1;
			int end = A[j] + B[j] - 1;
			vector<int> temp_cards;
			for (k=start; k<end; k++) {
				temp_cards.push_back(cards[k]);				
			}
			for (k=0;k<start;k++) {
				temp_cards.push_back(cards[k]);
			}
			for (k=end;k<M;k++) {
				temp_cards.push_back(cards[k]);
			}
			for (k=0;k<M;k++) {
				cards[k] = temp_cards[k];
			}
			temp_cards.clear();
		}
		//output
		cout << "Case #" << i << ": ";
		cout << cards[W-1] << endl;
		cards.clear();
	}

}
