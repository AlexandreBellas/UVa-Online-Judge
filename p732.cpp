#include <bits/stdc++.h>
using namespace std;

string a, b;
vector<char> v;
stack<char> s;

void percorrer(int x, int y){
    if (x == a.size() && y == b.size()){
        int i;
        printf("%c", v[0]);
        for (i = 1; i < v.size(); i++){
            printf(" %c", v[i]);
        }
        printf("\n");
    }

    if(x < a.size()){
        v.push_back('i');
        s.push(a[x]);
        percorrer(x+1, y);

        v.pop_back();
        s.pop();
    }

    if(y < b.size() && !s.empty() && s.top() == b[y]){
        v.push_back('o');
        char ch = s.top();
        s.pop();
        percorrer(x, y+1);

        s.push(ch);
        v.pop_back();
    }
}

int main(){
    while (cin >> a >> b){
        printf("[\n");
        percorrer(0, 0);
        printf("]\n");
    }
}
