#include <iostream>
#include <string>
#include <vector>

using namespace std;

int check_type(int t, int p) {
	int sup_max, unsup_max;
	int type = 0;

	if (t == 0) {
		if (p == 0) {
			type = 3;
		} 
	} else if (t == 1) {
		if (p <= 1) {
			type = 3;
		}	
	} else {
		switch (t % 3) {
			case 0:
				sup_max = t/3 + 1;
				unsup_max = t/3;
				break;
			case 1:
				sup_max = unsup_max = t/3 + 1;
				break;
			case 2:
				sup_max = t/3 + 2;
				unsup_max = t/3 + 1;
				break;
		}
		
		if (sup_max >= p || unsup_max >= p) {
			if (unsup_max < p) {
				type = 1;
			} else {
				type = 2;
			}
		}
	}

	return type;
}

int main () {
	int T;
	cin >> T;

	for (int i=1; i<=T; i++) {
		int N, S, p, t;

		cin >> N;
		cin >> S;
		cin >> p;

		int rest_sup = S;
		int n_sup = 0;
		int can_sup = 0;
		int result = 0;
		for (int j=0; j<N; j++) {
			cin >> t;
			int type = check_type(t, p);
			if (type == 1) {
				if (rest_sup > 0) {
					result += 1;
					rest_sup -= 1;
				}
			} else if (type >= 2) {
				result += 1;
				if (type == 2) can_sup += 1;
			}
		}

		cout << "Case #" << i << ": ";
		cout << result << endl;
	}	

	return 0;
}
