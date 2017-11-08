#include <bits/stdc++.h>
using namespace std;

int dom[32];
int n;
int m;

void backtracking(int resp[], int adjacente, int cont, int *flag){
	int i;
	int aux;

	if (cont < n){
		/*for(i = 0; i < 2*m+4; i++){
			printf("%d ", resp[i]);
			if (i == 2*m+3) printf("\n");
		}
		for(i = 0; i < 2*m+4; i++){
			printf("%d ", dom[i]);
		}
		printf("  adj = %d\n\n", adjacente);*/

		for (i = 2; i < 2*m+2 && *flag == 0; i++){
			if(resp[i] == 0 && dom[i] == adjacente){
				if(i%2 == 1){
					resp[i] = 1;
					resp[i-1] = 1;
					aux = adjacente;
					adjacente = dom[i-1];

					backtracking(resp, adjacente, cont+1, flag);
					
					adjacente = aux;
					resp[i] = 0;
					resp[i-1] = 0;
				}
				else{
					resp[i] = 1;
					resp[i+1] = 1;
					aux = adjacente;
					adjacente = dom[i+1];

					backtracking(resp, adjacente, cont+1, flag);

					adjacente = aux;
					resp[i] = 0;
					resp[i+1] = 0;
				}
			}
		}
	}
	else if(adjacente == dom[2*m+2]){
		printf("YES\n");
		*flag = 1;
		return;
	}
}


int main(){
	int i;
	int aux;
	int resp[32];
	int flag;

	while (1){
		cin >> n;
		if(n == 0) break;
		cin >> m;
		//printf("n = %d m = %d\n", n, m);
		
		scanf("%d %d", &dom[0], &dom[1]);
		scanf("%d %d", &dom[2*m+2], &dom[2*m+3]);

		//printf("dom[0] = %d, dom[1] = %d,\ndom[%d] = %d, dom[%d] = %d\n", dom[0], dom[1], 2*m+2, dom[2*m+2], 2*m+3, dom[2*m+3]);

		resp[0] = 1;
		resp[1] = 1;
		resp[2*m+2] = 1;
		resp[2*m+3] = 1;

		for (i = 2; i < 2*m+2; i++){
			scanf("%d", &dom[i]);
			//printf("dom[%d] = %d\n", i, dom[i]);
			resp[i] = 0;
		}

		aux = dom[1];
		flag = 0;
		backtracking(resp, aux, 0, &flag);
		if (flag == 0){
			printf("NO\n");
		}

	}
	return 0;
}
