#include <iostream>
#include <vector>

using namespace std;

int main(void){
	int T, N, PD, PG;
	int D, G, winD, winG,isPossible;
	int i, j, k;
	vector<int> possibleD;
	cin >> T;
	for(i=1;i<=T;i++){
		cin >> N;
		cin >> PD;
		cin >> PG;

		isPossible = 1;
		possibleD.clear();
		if((PD != 100 && PG == 100)||(PD > 0 && PG == 0)){
			isPossible= 0;
		}else{
			for(j=1;j<=N;j++){
				if(!((PD * j) % 100)) possibleD.push_back(j);
			}
			if(possibleD.empty()){
				isPossible = 0;
			}
		}
		if(isPossible){
			cout << "Case #" << i << ": " << "Possible" << endl;
		}else{
			cout << "Case #" << i << ": " << "Broken" << endl;
		}
		
	}
	return 0;
}
