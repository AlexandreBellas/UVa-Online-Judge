#include <bits/stdc++.h>
using namespace std;

double distancia(double x1, double y1, double x2, double y2){
	double dx;
	double dy;
	dx = x1 - x2;
	dy = y1 - y2;
	return sqrt(dx*dx + dy*dy);
}

int certo(double x, double y, double a){
	if(distancia(x, y, 0, 0) <= a && distancia(x, y, a, 0) <= a && distancia(x, y, 0, a) <= a && distancia(x, y, a, a) <= a)
		return 1;
	else return 0;
}

int main(){
	int N;
	double a;
	int M;
	while(1){
		cin >> N;
		if (N == 0)
			exit(0);

		cin >> a;
		M = 0;

		int i;
		for(i = 0; i < N; i++){
			double x, y;
			cin >> x >> y;
			if(certo(x, y, a)){
				M++;
			}
		}

		double resp = M*a*a/(double)N;
		cout << fixed << setprecision(5) << resp << endl;
	}

	return 0;
}