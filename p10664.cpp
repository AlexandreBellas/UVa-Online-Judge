#include <bits/stdc++.h>
using namespace std;

int pd[207][207];
int somatotal;
int pesos[207];
string s;
int u;

void PD(){
	int peso = somatotal/2;

	for(int j = 0; j <= peso; j++){
		pd[0][j] = 0;
	}

	for(int i = 1; i <= u; i++){
		for(int j = 0; j <= peso; j++){
			if(j < pesos[i]){
				pd[i][j] = pd[i-1][j];
			}
			else{
				pd[i][j] = max(pd[i-1][j], pesos[i] + pd[i-1][j - pesos[i]]);
			}
		}
	}
	/*
	for(int i = 0; i <= u; i++){
		for(int j = 0; j <= peso; j++){
			cout << pd[i][j] << " ";
			if (j == peso)
				cout << endl;
		}
	}*/
}

int resposta(){
	int i = u;
	int j = somatotal/2;
	int respint = 0;
	while(pd[i][j] != 0){
		if(pd[i-1][j] == pd[i][j]){
			i--;
			continue;
		}
		if (j - pesos[i] < 0){
			break;
		}
		
		i--;
		j -= pesos[i];
		respint++;
	}

	return respint;
}

int main(){
	int m;
	int aux;
	cin >> m;
	getchar();
	for(int w = 0; w < m; w++){
		getline(cin, s);
		istringstream in(s);
		somatotal = 0;
		u = 1;
		while(in >> aux){
			pesos[u] = aux;
			somatotal += aux;
			u++;
		}
		
		sort(pesos, pesos+u);

		u--;

		if(somatotal%2 == 0){
			PD();
			if(pd[u][somatotal/2] >= somatotal/2)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
		else{
			cout << "NO" << endl;
		}

	}
	return 0;
}