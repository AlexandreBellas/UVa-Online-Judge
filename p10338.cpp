#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ul;

ul fac(int n) {
  ul ret = 1;
  for(int i = 2; i <= n; ++i)
    ret *= i;
  return ret;
}

int main() {
	int N;
	cin >> N;
	string s;
	for(int cas = 1; cas <= N; ++cas) {
		cin >> s;
		sort(s.begin(), s.end());
		ul out = fac((int)s.size());
		int rep = 1;
		char prev = '_';
		for(unsigned int i = 0; i < s.size(); ++i) {
  			if(s[i] == prev)
				++rep;
  			else {
				out /= fac(rep);
				rep = 1;
				prev = s[i];
  			}
		}
		out /= fac(rep);
		cout << "Data set " << cas << ": " << out << std::endl;
  	}
}