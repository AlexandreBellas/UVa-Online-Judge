#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

int desloc[][2] = {{ 0, 1}, { 1, 0}, {-1, 0}, { 0,-1},
                   { 1, 1}, { 1,-1}, {-1, 1}, {-1,-1}};

int main (){
    int n;
    int r, c;
    int i, j, k;
    int vesepula = 0;
    char ch;

    while(1){
        if (vesepula == 0)
            vesepula = 1;
        else
            cout << endl;

        n = 0;
        cin >> r >> c;
        if(r == 0 && c == 0)
            break;

        char sky[r][c];

        vector<int> v[2];

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                scanf("%c", &ch);
                if(ch == '\n')
                    scanf("%c", &ch);

                sky[i][j] = ch;

                if(sky[i][j] == '*'){
                    n++;
                    v[0].push_back(i);
                    v[1].push_back(j);
                }
            }
        }

        int confere;
        int resp = 0;
        for(i = 0; i < n; i++){
            confere = 0;
            for(k = 0; k < 8; k++){
                int aux1 = desloc[k][0]; int aux2 = desloc[k][1];
                //cout << "aux1 = " << aux1;
                //cout << " aux2 = " << aux2 << endl;
                if(v[0][i] + aux1 >= 0 && v[0][i] + aux1 < r && v[1][i] + aux2 >= 0 && v[1][i] + aux2 < c){
                    //cout << "passou" << endl;
                    for(j = 0; j < n; j++){
                        if(j == i) continue;

                        if(v[0][i]+aux1 == v[0][j] && v[1][i]+aux2 == v[1][j])
                            confere = 1;

                        //cout << "confere = " << confere << endl;
                    }
                }
            }
            if(confere != 1)
                resp++;
        }


        cout << resp;      
    }

    return 0;
}