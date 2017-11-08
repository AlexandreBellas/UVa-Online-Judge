#include <bits/stdc++.h>
using namespace std;
 
#define PI acos(-1.0)
#define EPS 1e-6
 
int b[100010];
string P, T;

void kmpPreprocess() {
    int i = 0;
    int j = -1;
    b[0] = -1;
    while (i < P.length()){
        while (j >= 0 && P[i] != P[j])
            j = b[j];
    
        i++;
        j++;
        b[i] = j;
    }
}

int kmpSearch(){
    int i = 0, j = 0;
    while (i < T.length()){
        while (j >= 0 && T[i] != P[j])
            j = b[j];
        
        i++;
        j++;
        if (j == P.length()){
            return j;
        
        j = b[j];
        }
    }

    return j;
}

int main(){
    int n;
    int k, w;
    int i;

    cin >> n;

    while (n--){
        cin >> k >> w;
        T = "";
        cin >> P;
        T = P;
        w--;
        while (w--){
            cin >> P;
            kmpPreprocess();
            i = kmpSearch();
            T += P.substr(i);
        }

        cout << T.size() << endl;
    }

    return 0;
}