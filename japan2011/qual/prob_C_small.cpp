#include <iostream>
#include <vector>

using namespace std;

int func(int x);

int main() {
	int T;
	int i, j, k;

	cin >> T;
	for (i=1;i<=T;i++) {
		int N;
		vector<int> nums;
		cin >> N;
		
		for (j=0; j<=N/2; j++) {
			int a = j;
			int b = N - j;
			nums.push_back(func(a) + func(b));
		}
		vector<int>::iterator max_it = max_element(nums.begin(), nums.end());

		cout << "Case #" << i << ": " << *max_it << endl;
	}
}


int func(int x) {
	int i;
	int result = 0;
	int bit = 1;
	while (x > 0) {
		if(x & bit) {
			result++;
		}
		x = x >> 1;
	}

	return result;
}
