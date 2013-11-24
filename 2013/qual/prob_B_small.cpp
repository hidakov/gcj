#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for(int i=1;i<=T;i++){
		int N, M;

		cin >> N;
		cin >> M;

		int pattern[N][M];
		for (int j=0; j<N; j++) {
			for (int k=0; k<M; k++) {
				cin >> pattern[j][k];
			}
		}

		string result = "YES";
		for (int j=0; j<N; j++) {
			for (int k=0; k<M; k++) {
				if (pattern[j][k] == 1) {
					//vertical
					bool vPossible = true;
					for (int n=0; n<N; n++) {
						if (pattern[n][k] == 2) vPossible = false;
					}
					//horizontal
					bool hPossible = true;
					for (int m=0; m<M; m++) {
						if (pattern[j][m] == 2) hPossible = false;
					}
					if (!vPossible && !hPossible) {
						result = "NO";
					}
				}
			}
		}



		cout << "Case #" << i << ": " << result << endl;
	}
}
