#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a%b);
}

//r = n - q*d
int main(){
	int n;
	int i;

	while(scanf("%d", &n), n){
		vector<int> v;
		do{
			v.push_back(n);
		}while (scanf("%d", &n), n);

		int aux = 0;
		for (i = 0; i < v.size(); i++){
			aux = gcd(v[0]-v[i], aux);
		}

		printf("%d\n", abs(aux));
	}

	return 0;
}