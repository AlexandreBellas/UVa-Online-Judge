#include <bits/stdc++.h>
using namespace std;

int main(){
	int s, d, soma_anual, max_deficit;

	while (cin >> s >> d){
		soma_anual = -12*d;

		if (4*s < d)
			soma_anual = 10*s - 2*d;

		else if (3*s < 2*d)
			soma_anual = 8*s - 4*d;
		
		else if (2*s < 3*d)
			soma_anual = 6*s - 6*d;
		
		else if (s < 4*d)
			soma_anual = 3*s - 9*d;
		

		if (soma_anual > 0)
			printf("%d\n", soma_anual);
		else
			printf("Deficit\n");
	}
	return 0;
}