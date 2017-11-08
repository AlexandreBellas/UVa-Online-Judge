#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef map<int, int> mii;
 
ll _sieve_size;
bitset<20000010> bs;
vi primes;
 
void sieve(ll upperbound){
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= _sieve_size; i++) if (bs[i]){
        for (ll j = i*i; j <= _sieve_size; j += i) bs[j] = 0;
        primes.push_back((int)i);
    }
}
 
bool isPrimeSieve(ll N){
    if (N <= _sieve_size) return bs[N];
    for(int i = 0; i < (int)primes.size() && (ll) primes[i]*primes[i] <= N; i++)
        if (N % primes[i] == 0) return false;
    return true;
}
 
void backtracking(int n, int j, int usado[], int circulo[]){
    int i;
    if(j == n && isPrimeSieve(circulo[n-1]+circulo[0])){
        for(i = 0; i < n; i++){
            cout << circulo[i];
            if (i != n-1)
                cout << " ";
        }
        cout << endl;
        return;
    }
    else{
        for(i = 2; i <= n; i++){
            if(usado[i-1] == 0 && isPrimeSieve(i+circulo[j-1])){
                circulo[j] = i;
                usado[i-1] = 1;
                backtracking(n, j+1, usado, circulo);
                circulo[j] = 0;
                usado[i-1] = 0;
            }
        }
    }
}
 
int main(){
    sieve(100);
    int n;
    int i;
    int cont = 1;
    bool flag = 0;
    while(cin >> n){
        if(flag) cout << endl;
        flag = 1;
        int usado[n];
        int circulo[n];
       
        usado[0] = 1;
        circulo[0] = 1;
        for(i = 1; i < n; i++){
            usado[i] = 0;
            circulo[n] = 0;
        }
       
        cout << "Case " << cont << ":" << endl;
        backtracking(n, 1, usado, circulo);
        // cout << endl;
        cont++;
    }
 
 
    return 0;
}