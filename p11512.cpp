#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, i;
    cin >> n;

    while(n--){
        string input;
        cin >> input;
        set<string> sufixosInput;
        
        //Aqui pega a string de entrada de 0 até s.size, dps 1 ate s.size e assim sucessivamente
        for(i = 0; i < input.size(); i++){
            sufixosInput.insert(input.substr(i));
        }

        string resp;
        int cont = -1;

        //Percorre tudo no set, e verifica as repetições
        for(set<string>::iterator it = sufixosInput.begin(); it != --sufixosInput.end(); ){
            string atual = *it;
            it++;
            string prox = *it;

            //Pega a ultima posição de repetiçao entre atual e prox
            for(i = 0; i < min(prox.size(), atual.size()) && prox[i] == atual[i]; i++) {}

            //Pega a string de repetição entre atual e prox
            string repeticao = prox.substr(0, i);

            //Se não teve repetição, faz dnovo
            if(repeticao.size() == 0)
                continue;

            //Se é o maior, é a resposta
            if(repeticao.size() > resp.size()){
                resp = repeticao;
                cont = 2;
            }
            //Senão, vê lexicograficamente
            else if(repeticao.size() == resp.size()){
                int aux = resp.compare(repeticao);

                if(aux > 0){
                    resp = repeticao;
                    cont = 2;
                }
                else if(aux == 0){
                    cont++;
                }
            }
        }

        if(cont != -1){
            cout << resp << " " << cont << endl;
        }
        else{
            cout << "No repetitions found!" << endl;
        }
    }

  return 0;
}