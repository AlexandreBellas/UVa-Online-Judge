#include <bits/stdc++.h>
using namespace std;

map<char, int> m;

int main(){
    int T;
    int i;
    int caso = 1;
    cin >> T;

    while(T--){
        stack<char> s;
        string caminho;
        cin >> caminho;

        s.push(caminho[0]);

        for(i = 1; i < caminho.size()-1; i++){
            if(caminho[i] == s.top()){
                m[s.top()]++;
                
                s.pop();
                if(!s.empty())
                    m[s.top()]++;
            }

            else{
                s.push(caminho[i]);
            }

        }

        cout << "Case " << caso << endl;

        for(auto x: m){
            cout << x.first << " = " << x.second << endl;
        }

        caso++;
        m.clear();
    }

    return 0;
}