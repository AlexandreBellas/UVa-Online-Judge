#include <bits/stdc++.h>
using namespace std;

int ve_se_nao_ta_vazio(queue<int> v[], int tam){
    int i;
    for (i = 0; i < tam; i++){
        if (!(v[i].empty()))
            return 1;
    }
    return 0;
}

int main(){
    int set;
    scanf("%d", &set);

    int N, S, Q, i;
    for (i = 0; i < set; i++){
        cin >> N >> S >> Q;
        queue<int> plat[N];
        stack<int> aviao;
        int j, k;
        int aux, aux2;
        for (j = 0; j < N; j++){
            scanf("%d", &aux);
            for (k = 0; k < aux; k++){
                scanf("%d", &aux2);
                plat[j].push(aux2);
            }
        }
        int tempo = 0;
        int station = 0;
        while (ve_se_nao_ta_vazio(plat, N)){
            while (!(aviao.empty()) && plat[station].size() < Q){
                if (aviao.top() != station+1)
                    plat[station].push(aviao.top());

                aviao.pop();
                tempo++;
            }

            while (!(aviao.empty()) && aviao.top() == station+1){
                aviao.pop();
                tempo++;
            }

            while (aviao.size() < S && !(plat[station].empty())){
                aviao.push(plat[station].front());
                plat[station].pop();
                tempo++;
            }

            tempo += 2;
            station++;
            if (station == N)
                station = 0;
        }
        printf("%d\n", tempo);
    }
}
