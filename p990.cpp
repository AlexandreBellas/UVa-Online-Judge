#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
#define NUMTES 35
#define NUMTEMPO 1007

typedef struct {
	int d1;
	int v1;
} tesouro;

int t, w;
int numtesouros;
tesouro tes[NUMTES];
tesouro resp[NUMTES];
int tempo[NUMTES];
int valor[NUMTES];
int M[NUMTES][NUMTEMPO];

int tempodescida(int di){
	return w*di;
}

int temposubida(int di){
	return 2*w*di;
}

int tempototal(int di){
	return tempodescida(di)+temposubida(di);
}

void ordenaPorProfundidade(){
	for(int i = 1; i <= numtesouros; i++){
		for(int j = 2; j <= numtesouros; j++){
			if(tes[j].d1 < tes[j-1].d1){
				tesouro aux = tes[j];
				tes[j] = tes[j-1];
				tes[j-1] = aux;
			}
		}
	}
	/*for(int i = 1; i <= numtesouros; i++){
		cout << tes[i].d1 << " " << tes[i].v1 << endl;
	}
	cout << "cabo ordenacao prof" << endl;*/
}

void ordenaPorValor(){
	for(int i = 1; i <= numtesouros; i++){
		for(int j = 2; j <= numtesouros; j++){
			if(tes[j].d1 == tes[j-1].d1 && tes[j].v1 < tes[j-1].v1){
				tesouro aux = tes[j];
				tes[j] = tes[j-1];
				tes[j-1] = aux; 
			}
		}
	}
	/*for(int i = 1; i <= numtesouros; i++){
		cout << tes[i].d1 << " " << tes[i].v1 << endl;
	}
	cout << "cabo ordenacao valor" << endl;*/
}

void completapd(){
	for(int i = 1; i <= numtesouros; i++){
		tempo[i] = tempototal(tes[i].d1);
		valor[i] = tes[i].v1;
	}
}

int PD(){
	for(int i = 0; i <= t; i++){
		M[0][i] = 0;
	}

	for(int i = 1; i <= numtesouros; i++){
		for(int j = 0; j <= t; j++){
			if(j < tempo[i]){
				M[i][j] = M[i-1][j];
			}
			else{
				M[i][j] = max(M[i-1][j], valor[i] + M[i-1][j - tempo[i]]);
			}
		}
	}
}

int resposta(){
	int i = numtesouros;
	int j = t;
	int respint = 0;
	while(M[i][j] != 0){
		if(M[i-1][j] == M[i][j]){
			i--;
			continue;
		}
		if (j - tempo[i] < 0){
			break;
		}
		
		resp[respint] = tes[i];
		i--;
		j -= tempo[i];
		respint++;
	}

	return respint;
}

int main(){
	int vesepula = 0;
	while(cin >> t >> w >> numtesouros){
		if(vesepula == 0)
			vesepula = 1;
		else
			cout << endl;

		for(int i = 1; i <= numtesouros; i++){
			cin >> tes[i].d1 >> tes[i].v1;
		}

		ordenaPorProfundidade();
		ordenaPorValor();
		completapd();
		PD();

		int lol = resposta();

		cout << M[numtesouros][t] << endl << lol << endl;
		for(int i = 0; i < lol; i++){
			cout << resp[i].d1 << " " << resp[i].v1 << endl;
		}
		//se W < wi, entao OPT(i, W) = OPT(i-1, W)
		//senão OPT(i, W) = max(OPT(i-1, W), wi + OPT(i-1, W-wi))
	}
	return 0;
}