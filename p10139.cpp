#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll m, n;
int pr[99];
int cnt[99];

char notprime[70000];
int primes[70000];
int nprime = 0;

void init(){
    int i, j;
    for (i = 2; i < sizeof(notprime); i++){
        if (notprime[i])
            continue;

        primes[nprime++] = i;

        for (j = i*2; j < sizeof(notprime); j += i){
            notprime[j] = 1;
        }
    }
}

int main(){
    init();
    while (1){
        int lal = scanf("%d %d", &n, &m);

        if (lal != 2)
            break;

        bool aux = true;

        if (m == 1 || (n >= m && m == 1))
            aux = true;
        else if (n == 0 || m == 0)
            aux = false;
        else {
            ll m2 = m;
            int prc = 0;
            int i;

            for (i = 0; i < nprime; i++){
                int p = primes[i];
                if (m < p) break;
                if (m % p) continue;
                cnt[prc] = 0;
                pr[prc] = p;
                while (m % p == 0){ 
                    cnt[prc]++;
                    m /= p;
                }
                prc++;
            }

            if (m > n)
                aux = false;
            else{
                for (i = 0; i < prc; i++){
                    int p = pr[i];
                    int c = cnt[i];
                    ll j;
                    for (j = p; j <= n; j += p){
                        ll j2 = j;
                        while (j2 % p == 0){
                            j2 /= p;
                            c--;
                            if (c == 0){
                                j = n+1;
                                break;
                            }
                        }
                    }
                    if (c != 0){
                        aux = false;
                        break;
                    }
                    
                }
            }
            m = m2;
        }
        if(aux)
            printf("%lld divides %lld!\n", m, n);
        else
            printf("%lld does not divide %lld!\n", m, n);
    }
}