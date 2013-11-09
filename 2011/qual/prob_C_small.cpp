#include <iostream>
#include <vector>
#define NMAX 15

using namespace std;

int my_pow(int n, int m);

int main(void){
	int T, N;
	long C[NMAX];
	vector<long> pile1, pile2, values;
	int num_pile1, num_pile2;
	long sum1, sum2, p_sum1, p_sum2;
	unsigned int i, j, k, l, num;

	cin >> T;
	for(i=1;i<=T;i++){
		values.clear();
		cin >> N;
		for(j=0;j<N;j++)
			cin >> C[j];

		num = my_pow(2, N);
		for(j=1;j<num-1;j++){
			pile1.clear();
			pile2.clear();
			l = 0;
			for(k=num;k=k/2;k>0){
				if(j & k)
					pile1.push_back(C[l]);
				else
					pile2.push_back(C[l]);
				l++;
			}

			num_pile1 = pile1.size();
			num_pile2 = pile2.size();
			p_sum1 = 0;
			for(k=0;k<num_pile1;k++)
				p_sum1 = p_sum1 ^ pile1[k];
			p_sum2 = 0;
			for(k=0;k<num_pile2;k++)
				p_sum2 = p_sum2 ^ pile2[k];
			if(p_sum2 == p_sum1){
				sum1=0;
				sum2=0;
				for(k=0;k<num_pile1;k++)
					sum1 = sum1 + pile1[k];
				for(k=0;k<num_pile2;k++)
					sum2 = sum2 + pile2[k];
				if (sum1 > sum2)
					values.push_back(sum1);
				else
					values.push_back(sum2);
			} 
		}
		cout << "Case #" << i << ": ";
		if(values.empty()){
			cout << "NO" <<endl;
		}else{
			vector<long>::iterator it = max_element(values.begin(),values.end());
			cout << *it << endl;
		}
	}

	return 0;
}

int my_pow(int n, int m){
	if(m < 2)
		return n;
	else
		return n * my_pow(n, m-1);
}
