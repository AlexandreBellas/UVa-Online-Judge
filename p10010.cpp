#include <bits/stdc++.h>
using namespace std;
 
#define PI acos(-1.0)
#define EPS 1e-6

int n, m;

//se é maiúsculo, deixa minúsculo
char deixaMinusculo(char c){
    return ( (c >= 'A' && c <= 'Z') ? (c - 'A' + 'a') : (c) );
}

//encontrar posição da primeira letra
void encontraPalavra(char s[], char grid[][60]){
    int desloc[][2] = {{ 0, 1}, { 1, 0}, {-1, 0}, { 0,-1},
                       { 1, 1}, { 1,-1}, {-1, 1}, {-1,-1}};

    int i, j, k;
    int aux1, aux2;
    int cont;
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            for(k = 0; k < 8; k++){
                aux1 = i;
                aux2 = j;
                cont = 0;
                while(grid[aux1][aux2] == s[cont]){
                    aux1 += desloc[k][0];
                    aux2 += desloc[k][1];
                    cont++;

                    //chegou no fim da palavra que quer achar
                    if(s[cont] == '\0'){
                        cout << i+1 << " " << j+1 << endl;
                        return;
                    }

                    //se extrapolar a matriz, ou seja, nao achou
                    if(aux1 < 0 || aux2 < 0 || aux1 >= m || aux2 >= n)
                        break;
                }
            }
        }
    }
}

int main(){
    int t;
    int i, j;
    int k;
    char grid[60][60];
    char s[60];

    cin >> t;
    
    while (t--){
        scanf("%d %d", &m, &n);
        for(i = 0; i < m; i++){
            scanf("%s", &grid[i]);
            for(j = 0; j < n; j++)
                grid[i][j] = deixaMinusculo(grid[i][j]);
        }

        cin >> k;
        while(k--){
            scanf("%s", s);

            for(i = 0; s[i]; i++){
                s[i] = deixaMinusculo(s[i]);
            }

            encontraPalavra(s, grid);
        }
        if(t)
            cout << endl;
    }
    return 0;
}