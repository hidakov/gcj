#include <iostream>
#include <stdlib.h>
#define NMAX 100
using namespace std;
int main(void){
	int T, N;
	int o_list[NMAX][2], b_list[NMAX][2];
	int pos_o, pos_b, time;
	int i, j, io, ib, tmp;
	char color;
	cin >> T;
	for(i=1;i<=T;i++){
		pos_o = 1;
		pos_b = 1;
		time = 0;
		
		cin >> N;
		io = ib = 0;
		for(j=0;j<N;j++){
			cin >> color;
			if(color == 'O'){
				o_list[io][0] = j;
				cin >> o_list[io][1];
				io++;
			}else{
				b_list[ib][0] = j;
				cin >> b_list[ib][1];
				ib++;
			}
		}
		o_list[io][0] = NMAX;
		b_list[ib][0] = NMAX;

		io = ib = 0;
		for(j=0;j<N;j++){
			if(o_list[io][0] < b_list[ib][0]){
				tmp = abs(o_list[io][1] - pos_o) + 1;
				pos_o = o_list[io][1];
				if(abs(b_list[ib][1] - pos_b) <= tmp){
					pos_b = b_list[ib][1];
				}else if(pos_b < b_list[ib][1]){
					pos_b = pos_b + tmp;
				}else{
					pos_b = pos_b - tmp;
				}
				time = time + tmp;
				io++;
			}else{
				tmp = abs(b_list[ib][1] - pos_b) + 1;
				pos_b = b_list[ib][1];
				if(abs(o_list[io][1] - pos_o) <= tmp){
					pos_o = o_list[io][1];
				}else if(pos_o < o_list[io][1]){
					pos_o = pos_o + tmp;
				}else{
					pos_o = pos_o - tmp;
				}
				time = time + tmp;
				ib++;
			}
		}
		cout << "Case #" << i << ": " << time << endl;
	}
	return 0;
}
