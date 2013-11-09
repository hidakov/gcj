#include <iostream>
#include <list>

using namespace std;

int func(int a, int b, int idx);

int main() {
	int T;
	int i,j,k;

	cin >> T;
	for (i=1;i<=T;i++) {
		int M, C, W;
		list<int> A, B; 
		cin >> M;
		cin >> C;
		cin >> W;
		for (j=0;j<C;j++) {
			int a, b;
			cin >> a;
			cin >> b;
			A.push_back(a);
			B.push_back(b);
		}
		
		int idx = W;
		for (j=0;j<C;j++) {
			int a = A.back();
			A.pop_back();
			int b = B.back();
			B.pop_back();
			idx = func(a,b,idx);
		}

		//output
		cout << "Case #" << i << ": " << idx << endl;
	}

}

int func(int a, int b, int idx) {
	int result = 0;
	if (a + b -1 < idx) {
		result = idx;
	} else {
		if (b < idx) {
			result = idx - b;
		} else {
			result = a + idx - 1;
		}
	}
}
