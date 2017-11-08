#include <bits/stdc++.h>
using namespace std;

#define numMax 105

struct Elevador{
    int id;
    int partida;
    int chegada;
    int custo;
    bool operator>(const Elevador &e) const{
        return this->custo > e.custo;
    }
};

int main(){    
    int n, k;
    while (cin >> n >> k){
        vector<vector<Elevador> > elevadores(numMax);
        vector<int> tempo(n + 1);

        for (int i = 1; i <= n; i++){
            cin >> tempo[i];
        }

        cin.ignore();

        for (int i = 1; i <= n; i++){
            string s;
            vector<int> andares;
            int andar;

            getline(cin, s);
            stringstream ss(s);

            while (ss >> andar){
                andares.push_back(andar);
            }

            for (int j = 0; j < andares.size(); j++){
                for (int k = j + 1; k < andares.size(); ++k){
                    Elevador e;
                    e.id = i;
                    e.custo = 0;
                    // andares[j] para andares[k]
                    e.partida = andares[j];
                    e.chegada = andares[k];      
                    elevadores[andares[j]].push_back(e);
                    // andares[k] para andares[j]
                    e.partida = andares[k];
                    e.chegada = andares[j];
                    elevadores[andares[k]].push_back(e);
                }
            }
        }

        // Dijkstra
        priority_queue<Elevador, vector<Elevador>, greater<Elevador> > pq;
        vector<int> caminhoMaisCurto(numMax, - 1);
        vector<int> id(numMax, -1);
   
        Elevador e;
        e.partida = 0;
        e.chegada = 0;
        e.custo = 0;
        caminhoMaisCurto[0] = 0;
        pq.push(e);
        while (!pq.empty()){
            Elevador u = pq.top();
            pq.pop();

            if (caminhoMaisCurto[u.chegada] != u.custo)
                continue;

            for (int i = 0; i < elevadores[u.chegada].size(); i++){
                Elevador v = elevadores[u.chegada][i];
                int tempoAtual = caminhoMaisCurto[v.partida] + abs(v.chegada - v.partida) * tempo[v.id];

                if (id[v.partida] != -1 && id[v.partida] != v.id){
                    tempoAtual += 60;
                }

                if (caminhoMaisCurto[v.chegada] == -1 || tempoAtual < caminhoMaisCurto[v.chegada]){
                    caminhoMaisCurto[v.chegada] = tempoAtual;
                    v.custo = tempoAtual;
                    id[v.chegada] = v.id;
                    pq.push(v);
                }
            }
        }
        if (caminhoMaisCurto[k] == -1)
            cout << "IMPOSSIBLE" << endl;
        else
            cout << caminhoMaisCurto[k] << endl;
    }
    return 0;
}