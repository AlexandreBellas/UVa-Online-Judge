#include <bits/stdc++.h>
using namespace std;

struct point{
	double x;
	double y;
};

bool comp(point a, point b){
	return (a.x < b.x);
}

void sorta(point p[], int n){
	int i, j;
	for(i = 1; i < n; i++){
		for(j = i; j < n; j++){
			if(comp(p[j], p[j-1])){
				point aux = p[j];
				p[j] = p[j-1];
				p[j-1] = aux;
			}
		}
	}
}

int main(){
	int C;
	int N;
	int i, j;
	double angulo;
	cin >> C;
	while(C--){
		cin >> N;
		point p[N];
		for(i = 0; i < N; i++){
			cin >> p[i].x;
			cin >> p[i].y;
		}

		sorta(p, N);

		double soma = 0;
		i = N-1;
		int j;
		while(1){
			j = i-1;
			
			while(j != -1 && p[j].y <= p[i].y){
				j--;
			}

			if(j == -1)
				break;

			angulo = atan2(p[j+1].x-p[j].x, p[j].y-p[j+1].y);
			soma += (p[j].y-p[i].y)/cos(angulo);

			i = j;
		}
		cout << fixed << setprecision(2) << soma << endl;
	}

	return 0;
}