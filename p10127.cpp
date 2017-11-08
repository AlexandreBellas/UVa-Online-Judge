#include <bits/stdc++.h>
using namespace std;

int main() {
	int a;
	while(cin >> a){
		int b = 1;
		int x = 1;
		while (b % a){
			x++;
			b = (b*10 + 1)%a;
		}
		cout << x << endl;

	}
	return 0;
}