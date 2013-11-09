#include <iostream>
#include <vector>
using namespace std;
int main(void){
	int T, C, D, N;
	char com[3];
	char opp[2];
	char base[10];
	char end, tmp;
	vector<char> el_list;
	int flag1, flag2;
	int i, j, size;
	cin >> T;
	for(i=1;i<=T;i++){
		cerr << "###case:" << i << "###" << endl;
		el_list.clear();
		tmp='\0';
		end = '$';

		cin >> C;
		if(C){
			cin >> com[0];
			cin >> com[1];
			cin >> com[2];
		}else{
			com[0] = com[1] = com[2] = '\0';
		}
		cin >> D;
		if(D){
			cin >> opp[0];
			cin >> opp[1];
		}else{
			opp[0] = opp[1] = '\0';
		}
		cin >> N;
		for(j=0;j<N;j++){
			flag1 = 0;
			flag2 = 0;
			cin >> tmp;
			cerr << "read:" << tmp << endl;
			if(!el_list.empty()){
				if(end==com[0] && tmp==com[1] || end==com[1] && tmp==com[0]){
					tmp=com[2];
					el_list.pop_back();
					cerr << i << ":combined" << endl;
				}
			}
			end = tmp;
			el_list.push_back(tmp);
			vector<char>::iterator it = el_list.begin();
			while(it != el_list.end()){
				if(*it==opp[0])
					flag1 = 1;
				if(*it==opp[1])
					flag2 = 1;
				it++;
			}
			if(flag1 && flag2){
				el_list.clear();
				end = '$';
				flag1 = 0;
				flag2 = 0;
				cerr << i << ":cleared" << endl;
			}
		}
		cout << "Case #" << i << ": " << "[";
		size = el_list.size();
		if(size==0){
			cout << "]" << endl;
		}
		for(j=0;j<size;j++){
			cout << el_list[j];
			if(j==size-1){
				cout << "]" << endl;
			}else{
				cout << ", ";
			}
		}
	}
	return 0;
}
