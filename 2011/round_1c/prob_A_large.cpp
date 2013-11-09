#include <iostream>
#define RMAX 50
#define CMAX 50

using namespace std;

int main(void){
	int T,R,C;
	char tile[RMAX][CMAX];
	int num;
	int i,j,k;
	
	cin >> T;
	for(i=1;i<=T;i++){
		cin >> R;
		cin >> C;
		num = 0;
		for(j=0;j<R;j++){
			for(k=0;k<C;k++){
				cin >> tile[j][k];
				if(tile[j][k] == '#') num++;
			}
		}
		for(j=0;j<R-1;j++){
			for(k=0;k<C-1;k++){
				if((tile[j][k] == '#')
						&& (tile[j][k+1] == '#')
						&& (tile[j+1][k] == '#')
						&& (tile[j+1][k+1]) == '#'){
					
					tile[j][k] = '/';
					tile[j][k+1] = '\\';
					tile[j+1][k] = '\\';
					tile[j+1][k+1] = '/';
					num -= 4;
				}
			}
		}
		cout << "Case #" << i << ":" << endl;
		if(num == 0){
			for(j=0;j<R;j++){
				for(k=0;k<C;k++){
					cout << tile[j][k];
				}
				cout << endl;
			}
		}else{
			cout << "Impossible" << endl;
		}


	
	}	

	return 0;
}
