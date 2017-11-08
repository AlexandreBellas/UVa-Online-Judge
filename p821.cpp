#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int N = 100;
int INF = 1000;

int main(){
    int Case = 1;   
    int a, b;
    while (1){
        cin >> a >> b;

        if(a == 0 && b == 0)
            break;

        vector<vector<int> > adj(N + 1, vector<int>(N + 1, INF));

        adj[a][b] = 1;
        while(1){
            cin >> a >> b;

            if (a == 0 && b == 0)
                break;

            adj[a][b] = 1;
        }

        for (int k = 1; k <= N; k++)
            for (int i = 1; i <= N; i++)
                for (int j = 1; j <= N; j++)
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

        int soma = 0;
        int cont = 0;
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                if (i != j && adj[i][j] != INF){
                    soma += adj[i][j];
                    cont++;
                }
            
        cout << "Case " << Case++ << ": average length between pages = " << setprecision(3) << fixed << (double)soma / cont << " clicks" << endl;
    }
    return 0;
}