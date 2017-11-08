#include <bits/stdc++.h>
using namespace std;

int main(){
    string s1, s2;
    string saux;
    set<string> fuba;
    int vesepula = 0;
    int i;

    while(cin >> s1 >> s2){
        if(vesepula == 0)
            vesepula = 1;
        else
            cout << endl;

        set<string> sufixosInput1;
        set<string> sufixosInput2;
        
        for(i = 0; i < s1.size(); i++){
            sufixosInput1.insert(s1.substr(i));
        }
        for(i = 0; i < s2.size(); i++){
            sufixosInput2.insert(s2.substr(i));
        }

        string resp;
        int flag = 0;

        for(set<string>::iterator it1 = sufixosInput1.begin(); it1 != sufixosInput1.end(); it1++){
            for(set<string>::iterator it2 = sufixosInput2.begin(); it2 != sufixosInput2.end(); it2++){
                string atual1 = *it1;
                string atual2 = *it2;

                for(i = 0; i < min(atual1.size(), atual2.size()) && atual1[i] == atual2[i]; i++) {}

                string repeticao = atual2.substr(0, i);

                //Se não teve repetição, faz dnovo
                if(repeticao.size() < 2)
                    continue;


                //Se é o maior, é a resposta
                fuba.insert(repeticao);
                flag = 1;

            }
            
        }

        if(flag == 1){
            for(set<string>::iterator it = fuba.begin(); it != fuba.end(); it++){
                cout << *it << endl;
            }
        }
        else{
            cout << "No common sequence." << endl;
        }
        fuba.clear();
    }

    return 0;
}