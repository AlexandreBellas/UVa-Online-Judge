#include <bits/stdc++.h>
using namespace std;

#define AGUA -1
#define POSSIVEL -2
#define PASSADO -3

typedef pair<int, int> ii;

int R, C, M, N, W;
int mapa[107][107];

void marca(queue<pair<int,int> > &q, int &estado, int i, int j){
	if(mapa[i][j] != AGUA) 
		estado++;

	if(mapa[i][j] == POSSIVEL){
		q.push(make_pair(i, j));
		mapa[i][j] = PASSADO;
	}
}

void bfs(){
	queue<ii> q;
	q.push(make_pair(0,0));

	while(!q.empty()){
		ii v = q.front(); q.pop();
		int x = v.first;
		int y = v.second;
		int estado = 0;
		if(M == 0 || N == 0){
			int maior = max(M, N);
			if(x - maior >= 0){
				marca(q, estado, x - maior, y);
			}

			if(x + maior < R){
				marca(q, estado, x + maior, y);
			}

			if(y - maior >= 0){
				marca(q, estado, x, y - maior);
			}

			if(y + maior < C){
				marca(q, estado, x, y + maior);
			}

		}
		else {
			if(x + M < R && y + N < C){
				marca(q, estado, x + M, y + N);
			}

			if((M != N) && x + N < R && y + M < C){
				marca(q, estado, x + N, y + M);
			}

			if(x - N >= 0 && y + M < C){
				marca(q, estado, x - N, y + M);
			}

			if((M != N) && x - M >= 0 && y + N < C){
				marca(q, estado, x - M, y + N);
			}

			if(x + M < R && y - N >= 0){
				marca(q, estado, x + M, y - N);
			}

			if((M != N) && x + N < R && y - M >= 0){
				marca(q, estado, x + N, y - M);
			}

			if(x - N >= 0 && y - M >= 0){
				marca(q, estado, x - N, y - M);
			}

			if((M != N) && x - M >= 0 && y - N >= 0){
				marca(q, estado, x - M, y - N);
			}
		}
		mapa[x][y] = estado;
	}
}

int main(){
	int T;
	cin >> T;
	for(int caso = 1; caso <= T; caso++){
		cout << "Case " << caso << ": ";

		cin >> R >> C >> M >> N;
		for(int i = 0; i < R; i++){
			for(int j = 0; j < C; j++){
				mapa[i][j] = POSSIVEL;
			}
		}

		mapa[0][0] = PASSADO;

		cin >> W;
		for(int i = 0; i < W; i++){
			int x, y;
			cin >> x >> y;
			mapa[x][y] = AGUA;
		}

		if(M == 0 && N == 0){
			cout << "0 1" << endl;
			continue;
		}

		bfs();

		int odd = 0;
		int even = 0;
		for(int i = 0; i < R; i++){
			for(int j = 0; j < C; j++){
				if(mapa[i][j] != AGUA && mapa[i][j] != POSSIVEL){
					if(mapa[i][j]%2 == 0){
						even++;
					}
					else{
						odd++;
					}
				}
			}
		}

		cout << even << " " << odd << endl;
	}
    return 0;
}