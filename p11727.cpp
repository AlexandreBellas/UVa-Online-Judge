#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int k = n;
	int m[3];
	int i;
	
	while (n--){
        for (i = 0; i < 3; i++)
            m[i] = 0;
	
    	for (i = 0; i < 3; i++){
    	    scanf("%d", &m[i]);
    	}
    	sort(m, m+3);
        printf("Case %d: %d\n", k-n, m[1]);
    }
}