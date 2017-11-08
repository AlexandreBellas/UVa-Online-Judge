#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll maximo = (ll) 1e18;
vector<pair<pair<int, int>, ll> > lados;
int custo[203];
ll distancia[203];
int N, M;

void bellman(){
    for(int i = 0; i <= N; i++)
        distancia[i] = maximo;
    
    distancia[1] = 0;
    for(int k = 0; k < M+1; k++){
        bool relaxado = false;
        for(int i = 0; i < M; i++){
            int u = lados[i].first.first;
            int v = lados[i].first.second;
            ll w = lados[i].second;

            if(distancia[u] == maximo)
                continue;

            if(distancia[v] > distancia[u] + w){
                distancia[v] = distancia[u] + w;
                relaxado = true;
            }
        }
        if(!relaxado)
            break;
    }
    for(int i = 0; i< M;++i){
        int u = lados[i].first.first;
        int v = lados[i].first.second;
        ll w = lados[i].second;

        if(distancia[u] == maximo)
            continue;

        if(distancia[v] > distancia[u] + w){
            distancia[u] = -maximo;
            distancia[v] = -maximo;
        }
    }
}

int main(){
    int u, v, w, Q, q;
    int T = 1;
    while(cin >> N){
        cout << "Set #" << T << endl;
        T++;

        for(int i = 1; i <= N; i++)
            cin >> custo[i];

        lados.clear();
        cin >> M;
        for(int i = 0; i < M; i++){
            cin >> u >> v;
            w = custo[v] - custo[u];
            w = w*w*w;
            lados.push_back(make_pair(make_pair(u,v), w));
        }
        bellman();
        cin >> Q;
        while(Q--){
            cin >> q;
            if(N == 0 || q > N || distancia[q] < 3 || distancia[q] == maximo)
                cout << "?" << endl;
            else 
                cout << distancia[q] << endl;
        }
    }
    return 0;
}