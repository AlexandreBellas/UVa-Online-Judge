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

bool isPrimeSieve(ll N){
	if (N <= _sieve_size) return bs[N];
	for(int i = 0; i < (int)primes.size() && (ll) primes[i]*primes[i] <= N; i++)
		if (N % primes[i] == 0) return false;
	return true;
}

int main (){
	int n;
	int flag;
	int aux1, aux2;
	int i;
	sieve(1000100);
	while(cin >> n && n >= 6 && n <= 1000000 && n != 0){
		//cout << n << endl;
		for(i = 2; i < n; i++){
			flag = 0;
			aux1 = n - i;
			//cout << "aux1 = " << aux1 << endl;
			//cout << "i = " << i << endl;
			if(isPrimeSieve((ll) aux1)){
				if(isPrimeSieve((ll) i)){
					aux2 = i;
					flag = 1;
					//cout << "entro" << endl;
					break;
				}
			}
		}

		if(flag == 1)
			printf("%d = %d + %d\n", n, aux2, aux1);
		else
			cout << "Goldbach's conjecture is wrong." << endl;

	}

	return 0;
}