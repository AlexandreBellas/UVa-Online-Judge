#include <bits/stdc++.h>
using namespace std;

typedef struct {
	string name;
	int starttime;
	int duration;
	int endtime;
	int price;
} order;

int n;
order input[3007];
int p[3007];

void sorta(){
	for(int i = 1; i <= n; i++){
		for(int j = 2; j <= n; j++){
			if(input[j].endtime < input[j-1].endtime){
				order aux = input[j];
				input[j] = input[j-1];
				input[j-1] = aux;
			}
		}
	}
}

int arruma_p(int u){
	int resp = 0;
	for(int i = 1; i <= n; i++){
		if(input[i].endtime < input[u].starttime)
			resp = i;
		else
			break;
	}

	return resp;
}

int PD(){
	int opt[n+1];
	opt[0] = 0;

	for(int i = 1; i <= n; i++){
		opt[i] = max(opt[i-1], opt[p[i]] + input[i].price);
	}

	return opt[n];
}

int main(){
	int vesepula = 0;
	while(cin >> n){
		if(vesepula == 0)
			vesepula = 1;
		else
			cout << endl;

		input[0].starttime = input[0].duration = input[0].endtime = input[0].price = 0;
		for(int i = 1; i <= n; i++){
			cin >> input[i].name >> input[i].starttime;
			cin >> input[i].duration >> input[i].price;
			input[i].endtime = input[i].starttime + input[i].duration-1;
		}

		sorta();
		p[0] = 0;
		for(int i = 1; i <= n; i++){
			p[i] = arruma_p(i);
			//cout << p[i] << endl;
		}

		cout << PD() << endl;
	}
	return 0;
}