#include <bits/stdc++.h>
using namespace std;
 
#define PI acos(-1.0)
#define EPS 1e-6
 
int main(){
    int N, l, i, j, total, pot;
    string ans;
    char input[12][90];
    
    cin >> N;
    getchar();
    
    while(N--){
        ans = "";
        for (i = 0; i < 10; i++)
            scanf("%s", &input[i]);
        
        l = strlen(input[0]);
        for(i = 1; i < l-1; i++){
            total = 0;
            pot = 0;

            for(j = 0; j < 9; j++){
                if(input[j][i] == '\\') 
                    total += (int)pow(2, pot-1);
                
                pot++;
            }

            ans += (char)total;
        }

        cout << ans << endl;
    }
    return 0;
}