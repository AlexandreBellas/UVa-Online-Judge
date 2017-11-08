#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	int k = t;
	
	while (t--){
	    int n;
	    int i;
	    scanf("%d", &n);
	    int m[n];
	
    	for (i = 0; i < n; i++){
    	    scanf("%d", &m[i]);
    	}
    	sort(m, m+n);
        printf("Case %d: %d\n", k-t, m[n-1]);
        
        for (i = 0; i < 3; i++)
            m[i] = 0;
    }
}