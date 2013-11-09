#include <iostream>
#include <vector>
#include <cmath>

double calc_area(double a, double b, double theta);
double deg2rad(double deg);

using namespace std;

int main() {
	int T;
	int i, j, k;

	cin >> T;

	for (i=1;i<=T;i++) {
		int K;
		vector<int> E;
		double theta, area;

		cin >> K;
		for (j=0;j<K;j++) {
			int tmp;
			cin >> tmp;
			E.push_back(tmp);			
		}
		sort(E.begin(), E.end());

		theta = deg2rad(360/K);
		area = calc_area(E[0], E[1], theta) + calc_area(E[K-1], E[K-2], theta);
		for (j=0;j<K-2;j++) {
			area += calc_area(E[j], E[j+2], theta);
		}
		
		printf("Case #%d: %.6f\n", i, area);

	}
}

double deg2rad(double deg) {
	return deg * M_PI /180;
}

double calc_area(double a, double b, double theta) {
	return a * b * sin(theta) / 2;
}
