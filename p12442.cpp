#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define UNVISITED 0

vi vertices;
int p;

vector<vii> AdjList(50007);

int dfsresp(int i){
	int cont = 0;
	vertices[i] = p;
	for(int j = 0; j < AdjList[i].size(); j++){
		int adj = AdjList[i][j].first;
		if(vertices[adj] != p){
			cont++;
			cont += dfsresp(adj);
			vertices[adj] = 1;
		}
	}
	return cont;
}

int dfs(){
	int resp = 0;
	int n_max = 0;
	for(int i = 0; i < vertices.size(); i++){
		if(vertices[i] == UNVISITED){
			p++;
			int t = dfsresp(i);
			if(t > n_max){
				resp = i;
				n_max = t;
			}
		}
	}
	return resp;
}

int main(){
	int T;
	int N;
	int u, v;
	int num = 1;

	cin >> T;
	while(T--){
		cin >> N;
		for(int i = 0; i < N; i++){
			cin >> u >> v;
			AdjList[u-1].push_back(make_pair(v-1, 0));
		}

		for(int i = 0; i < N; i++){
			vertices.push_back(UNVISITED);
		}

		p = 0;
		cout << "Case " << num << ": " << dfs()+1 << endl;

		for(int j = 0; j < N; j++){
			while(!AdjList[j].empty()){
				AdjList[j].pop_back();
			}
		}

		while(!vertices.empty()){
			vertices.pop_back();
		}

		num++;
	}
    return 0;
}