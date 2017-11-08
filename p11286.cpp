#include <bits/stdc++.h>
using namespace std;

int main(){
	while (1){
	    int n;
	    scanf("%d", &n);
	    if (n == 0) break;

	    vector <int> v[10007];
	    int i, j, a;
	    for (i = 0; i < n; i++){
	        for (j = 0; j < 5; j++){
	            scanf("%d", &a);
	            v[i].push_back(a);
	        }
	    }
	    
	    for (i = 0; i < n; i++){
	        sort(v[i].begin(), v[i].end());
	    }
	    
	    int contagem[n];
	    for (i = 0; i < n; i++)
	        contagem[i] = 0;
	    
	    map <vector <int>, int> mp;
	    for (i = 0; i < n; i++){
	        mp[v[i]]++;
	    }
	    
	    int maj = 0;
	    for (auto it : mp){
	        if(it.second > maj)
	            maj = it.second;
	    }
	    int resp = 0;
	    for(auto it : mp){
	        if(it.second == maj)
	            resp += it.second;
	    }
	    printf("%d\n", resp);
	}
}