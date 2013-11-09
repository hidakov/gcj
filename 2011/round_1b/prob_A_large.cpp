#include <iostream>
#
#define NMAX 100

using namespace std;

int main(void){
	int T,N;
	int schedule[NMAX][NMAX];
	double WP[NMAX],OWP[NMAX],OOWP[NMAX];
	char ch;
	int i,j,k;

	cin >> T;

	for(i=1;i<=T;i++){
		cin >> N;
		for(j=0;j<N;j++){
			for(k=0;k<N;k++){
				cin >> ch;
				if(ch == '.'){
					schedule[j][k] = -1;
				}else{
					schedule[j][k] = atoi(&ch);
				}
				cerr << schedule[j][k];
			}
			cerr << endl;
		}
		// calc WP
		for(j=0;j<N;j++){
			int sum=0;
			int count=0;
			for(k=0;k<N;k++){
				int num = schedule[j][k];
				if(num != -1){
					sum += num;
					count++;
				}
			}
			WP[j] = (double)sum/(double)count;
		}
		//calc OWP
		for(j=0;j<N;j++){
			double sum=0.0;
			int count=0;
			for(k=0;k<N;k++){
				int num = schedule[j][k];
				if(num != -1){
					int sum2 = 0;
					int count2 = 0;
					for(int kk=0;kk<N;kk++){
						int num2 = schedule[k][kk];
						if((num2!=-1) && j!=kk){
							sum2 += num2;
							count2++;
						}
					}
					sum += (double)sum2/(double)count2;
					count++;
				}
			}
			OWP[j] = sum/(double)count;
		}
		//calc OOWP
		for(j=0;j<N;j++){
			double sum=0.0;
			int count=0;
			for(k=0;k<N;k++){
				int num = schedule[j][k];
				if(num != -1){
					sum += OWP[k];
					count++;
				}
			}
			OOWP[j] = sum/(double)count;
		}
		//output
		cout << "Case #" << i << ":" << endl;
		for(j=0;j<N;j++){
			double RPI = 0.25*WP[j] + 0.50*OWP[j] + 0.25*OOWP[j];
			printf("%1.10f\n",RPI);
		}
		
	}

	return 0;
}
