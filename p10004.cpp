#include <bits/stdc++.h>
using namespace std;

#define UNVISITED 0
#define VISITED 1
#define SEMCOR 2
#define COR1 3
#define COR2 4

// estruturas uteis para representacao de grafos...
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;


int NumVert;
int NumAres;
// vetor de vertices
vi vertices;   

// a lista de adjacencia e um vetor de vetor de pares.
// cada par contem o vertice adjacente e o peso da aresta
// assumimos que o peco aqui eh inteiro...
vector<vii> AdjList(200);  

int resp;

void dfs(int u, int la){
    if(la == 0){
        vertices[u] = COR1;
        la = 1;
    }
    else{
        vertices[u] = COR2;
        la = 0;
    }
    //printf("%d\n", u+1);

    for(int j = 0; j < AdjList[u].size(); j++){
        ii v = AdjList[u][j];  // v  eh um vertice do tipo (vizinho de u, peso)
        if (vertices[v.first] == UNVISITED)
            dfs(v.first, la);
        else{
            if(vertices[u] == vertices[v.first])
                resp = 1;
        }
    }
}

int main (){
    int u, v;

    while(1){
        cin >> NumVert;
        if(NumVert == 0) break;

        for (int i=0; i<NumVert; i++){
            vertices.push_back(UNVISITED);
            //AdjList.pushback(0);
            //printf("%d ", vertices[i]);
        }
        //printf("\n");
        //cout << "passou 1";

        cin >> NumAres;
        int i = 0;

        // lembre-se, o grafo nao eh direcionado!
        while (i < NumAres) {
            cin >> u >> v;
            //cout << u << " " << v << endl;
            AdjList[u].push_back(make_pair(v,0));
            AdjList[v].push_back(make_pair(u,0));
            i++;
        }
        //cout << "passou 2";
        resp = 0;
        dfs(0, 0);

        //cout << "passou 3";

        if (resp == 1)
            printf("NOT BICOLORABLE.\n");
        else printf("BICOLORABLE.\n");

        vertices.clear();
        for(i = 0; i < NumVert; i++){
            while(!AdjList[i].empty()){
                AdjList[i].pop_back();
            }
        }
    }

    return 0;
}