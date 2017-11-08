#include <bits/stdc++.h>
using namespace std;

int main(){
	map<string,double> m;
	string s;
	int n;
	int i;
	cin >> n;
	string aux;
	getline(cin, aux);
	//cout << "Essa porra eh '" << aux << "'" << endl;
	getline(cin, aux);
	//cout << "Essa porra eh '" << aux << "'" << endl;
	while(n--){
		i = 0;
		
		while(getline(cin, s) && s.size() != 0){
			m[s]++;
			i++;
		}

		for (auto& x: m) {
		    cout << x.first << ' ' << fixed << setprecision(4) << (x.second/i)*100 << '\n';
		}
		m.clear();
		if (n != 0) cout << endl;
	}

	return 0;
}