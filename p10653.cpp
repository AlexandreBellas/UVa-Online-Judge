#include <bits/stdc++.h>
using namespace std;

int R, C;
int m[1007][1007];
int desloc[4][2] = { { 0,  1}, { 0, -1},
					 { 1,  0}, {-1,  0} };

#define UNVISITED 0
#define VISITED 1

// busca em profundidade a partir de um vertice u
void bfs(int istart, int jstart, int iend, int jend){
	m[istart][jstart] = 1;
	queue< pair<int, int> > q;
	pair<int,int> inicio = make_pair(istart,jstart);
	q.push(inicio);

	while (!q.empty()){
		//  retira da fila e marca como visitado..
		pair<int,int> k = q.front(); q.pop();

		// para todo adjacente, nao visitado poe na fila...
		for(int j = 0; j < 4; j++){
			
			int x = k.first + desloc[j][0];
			int y = k.second + desloc[j][1];

			if((x >= 0 && x < R) && (y >= 0 && y < C) ){
				pair<int,int> v = make_pair(x, y);
				if(m[v.first][v.second] == UNVISITED){
					m[v.first][v.second] = m[k.first][k.second] + 1;
					q.push(v);
				}
			}
		}
	}

	cout << m[iend][jend]-1 << endl;
}

int main (){
	int rows;
	int i, j;
	int nbombs;
	int iinclude, jinclude;
	int istart, jstart;
	int iend, jend;

	while(1){
		cin >> R >> C;
		if(R == 0 && C == 0)
			break;

		for(i = 0; i < R; i++){
			for(j = 0; j < C; j++){
				m[i][j] = 0;
			}
		}

		cin >> rows;

		for(i = 0; i < rows; i++){
			cin >> iinclude;
			cin >> nbombs;
			for(j = 0; j < nbombs; j++){
				cin >> jinclude;
				m[iinclude][jinclude] = -1;
			}
		}

		cin >> istart >> jstart;
		cin >> iend >> jend;

		bfs(istart, jstart, iend, jend);

	}
	return 0;
}