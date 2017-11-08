#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef map<int, int> mii;

ll _sieve_size;
bitset<20000010> bs;
vi primes;

void sieve(ll upperbound){
	_sieve_size = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i <= _sieve_size; i++) if (bs[i]){
		for (ll j = i*i; j <= _sieve_size; j += i) bs[j] = 0;
		primes.push_back((int)i);
	}
}

int main(){
	int S;
	int i;
	vector<int> v[2];
	//printf("passou0\n");
	sieve(20000000);
	//printf("passou1\n");

	for(i = 0; i < primes.size()-1; i++){
		if(primes[i]+2 == primes[i+1]){
			v[0].push_back(primes[i]);
			v[1].push_back(primes[i+1]);
		}
	}

	while(cin >> S){
		S--;
		printf("(%d, %d)\n", v[0][S], v[1][S]);
	}
	return 0;
}