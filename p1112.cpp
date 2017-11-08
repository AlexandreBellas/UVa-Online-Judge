stdlib.h>
#include <iostream>

using namespace std;

#define INF 1000000

// estruturas uteis para representacao de grafos...
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main(){
	vector<vii> adjList(105);    // uma lista de adjacencia: para cada vertice v, tem-se um conjunto de tuplas (u,w)
	int A;  // nro de Arestas
	int V; // nro de Vertices
	int u,v,w;
 	int cases;
 	int E; //vertice de chegada
 	int T; //tempo countdown
 	int vesepula = 0;

 	cin >> cases;
 	while(cases--){
 		if (vesepula == 0)
 			vesepula = 1;
 		else
 			cout << endl;

 		cin >> V >> E >> T >> A;

		// lembre-se, o grafo eh direcionado!
		for (int i=0; i<A; i++) {
			cin >> u >> v >> w;
			//adjList[u].push_back(make_pair(v,w));
			adjList[v].push_back(make_pair(u,w));
		}

		// o vetor de distancia a partir de um vertice quqlquer tem inicialmente distancia INFINITA
		vi dist(105, INF); 
		vi parent(105);   // grava a trilha, guardando o pai  de cada vertice..

		dist[E] = 0;  // a distancia de s para s eh zero !!!

		// a fila comecao com o elemento source s e a distancia claro eh zero...
		// armazenaremos (distancia d, vertice u) nesta ordem...
		priority_queue<ii, vector<ii>, greater<ii> > pq;
		pq.push(ii(0,E)); 


		while(!pq.empty()){  // enquanto houver elementos na fila...

			ii front = pq.top(); pq.pop();
			int d = front.first;  u = front.second;

			// atencao.. faca um teste no papel...este algoritmo permite que valore distintos
			// de distancias para um mesmo mesmo vertice u seja armazenada nela.. essa
			// verificacao abaixo faz com que uma distancia maior seja ignorada...
			if (d > dist[u]) continue;

			// para todos os adjacentes de u
			for(int j=0; j<adjList[u].size(); j++){
				ii v = adjList[u][j];
				if (dist[u] + v.second < dist[v.first]){
					dist[v.first] = dist[u]+ v.second; //vai acumulando a distancia..
					parent[v.first] = u;
					pq.push(ii(dist[v.first], v.first));
				}
			}
		}

		int resp = 0;
		for (int i=1; i<=V; i++){
			if(dist[i] <= T){
				resp++;
			}
		}

		cout << resp << endl;

		for(int i = 0; i < 105; i++){
			adjList[i].clear();
		}

	}
	return 0;
}