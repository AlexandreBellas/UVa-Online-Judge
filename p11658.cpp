#include <bits/stdc++.h>
using namespace std;

int n, x;
int stockholder[107];
int pd[107][10007];

int PD(int i, int soma){
	if(i == x){
		return PD(i+1, soma);
	}
	else{
		if(soma > 5000)
			return soma;
		if (i == n)
			return 1000000;
		if (pd[i][soma] != -1)
			return pd[i][soma];
		
		return pd[i][soma] = min(PD(i+1, soma), PD(i+1, soma+stockholder[i]));
	}
}

int main(){
	while(1){
		cin >> n >> x;

		if(n == 0 && x == 0)
			break;

		string lo;

		for(int i = 0; i < n; i++){
			cin >> lo;
			lo.erase(find(lo.begin(), lo.end(), '.'));
			//cout << lo << endl;
			stockholder[i] = stoi(lo);
		}

		x--;
		if(stockholder[x] >= 5000){
			cout << "100.00" << endl;
			continue;
		}

		memset(pd, -1, sizeof pd);

		int resp = PD(0, stockholder[x]);		

		cout << fixed << setprecision(2) << (double)100*stockholder[x]/(double)resp << endl;
	}


	return 0;
}