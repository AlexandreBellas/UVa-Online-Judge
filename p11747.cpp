#include <bits/stdc++.h>
using namespace std;

// estruturas uteis para representacao de grafos...
typedef pair<int, int> ii;
typedef vector<int> vi;

vector< pair<int,ii> > EdgeList;    // uma tripla: w, <u,v>

class UnionFind {
    private: 
        typedef vector<int> vi;
        vi p; 
        vi rank;

    public: 

        UnionFind(int N){
            rank.assign (N, 0);  p.assign(N,0);
            for(int i =0; i<N; i++)
                p[i] = i;
        }

        int findSet(int i){
            if (p[i] == i)
                return i;
            return (findSet(p[i]));
        }

        bool isSameSet(int i, int j){
            return (findSet(i) == findSet(j));
        }

        void unionSet(int i, int j){
            if (!isSameSet(i,j)){
                int x = findSet(i);
                int y = findSet(j);

                if (rank[x] > rank[y])
                    p[y] = x;
                else {
                    p[x] = y;
                    if (rank[x] == rank[y])
                        rank[y] = rank[y]+1;
                }
            }

        }
};

int main(){
    while(1){
        int A;  // nro de Arestas
        int V; // nro de Vertices
        cin >> V >> A;

        if(V == 0 && A == 0)
            break;

        int u,v,w;
     
        //scanf("%d", &A);
        //scanf("%d", &V);

        for (int i=0; i<A; i++) {
            scanf("%d %d %d", &u, &v, &w);
            EdgeList.push_back(make_pair(w, ii(u,v)));
        }
        sort(EdgeList.begin(), EdgeList.end());

        int mst_cost = 0;

        UnionFind uf(V); // inicialmente todas as arestas sao conjuntos disjuntos...
        vector< pair<int, ii> > ciclo;

        // percorra todas as arestas...
        for(int i=0; i<A; i++){
            pair<int, ii> front = EdgeList[i]; // pega a aresta de menor peso!
            // se os vertices que compoem a aresta estao em conjuntos separados
            // nao ha ciclo, junta os dois !
            if (!uf.isSameSet(front.second.first, front.second.second)) {
                mst_cost += front.first;  // atualiza o custo
                // coloca ambos no mesmo set...
                uf.unionSet(front.second.first, front.second.second);
            }
            else{
                ciclo.push_back(front);
            }
        }

        if(!ciclo.empty()){
            int flag = 0;
            for(vector< pair<int, ii> >::iterator it = ciclo.begin(); it < ciclo.end(); it++){
                if(flag == 1)
                    cout << " ";
                else
                    flag = 1;
                cout << it->first;
            }
        }            
        else
            cout << "forest";
        
        cout << endl;

        EdgeList.clear();
    }

    return 0;
}