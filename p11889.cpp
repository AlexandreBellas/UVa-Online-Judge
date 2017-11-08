#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAX (int)1e7

ll gcd(ll a, ll b){
	if(b > a)
		return gcd(b, a);
	return b == 0 ? a : gcd(b, a%b);
}

ll lcm(ll a, ll b){
	return (a*b)/gcd(a,b);
}

int main() {
	int T;
	cin >> T;
	ll A, C;
	while (T--){
		cin >> A >> C;
		if (C % A){
			printf("NO SOLUTION\n");
		}
		else{
			ll B;
			ll i;
			B = C / A;
			for(i = B; i <= MAX; i += B){
				if(lcm(A, i) == C)
					break;
			}
			cout << i << endl;
		}
	}
	return 0;
}