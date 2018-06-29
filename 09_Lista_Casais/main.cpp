#include <iostream>
#include <list>

using namespace std;

void print_list(list<int*> lista){
    for(auto elem : lista){
        cout << *elem << " ";
    }
    cout << endl;
}

/*int main(){
    // EXEMPLOS
    //positivos homens e negativos mulheres
    //saída: [1, 4, 3, 2]

    list<int*> lista;
    list<int*> lista_casais_het;

    for(auto elem : {1, 2, -1, 1, -1, 1, 4, 3, -3, 3, -2, 2}){
        lista.push_back(new int (elem));
    }

    for(auto it = lista.begin(); it != --lista.end();){
        bool achei = false;
        for(auto itd = ++it; itd != lista.end(); itd++){
            if(((**it)+(**itd)) == 0 ){
                delete *it;
                delete *itd;

                it = lista.erase(it);
                itd = lista.erase(itd);

                achei = true;
                break;
            }
        }
        if(!achei){
            it++;
        }
        print_list(lista);
   }
}*/

/* CORREÇÃO FEITA EM AULA */
int main(){
    list<int*> lista;
    list<int*> lista_casais_het;

    for(auto elem : {1, 2, -1, 1, -1, 1, 4, 3, -3, 3, -2, 2}){
        lista.push_back(new int (elem));
    }

    for(auto it = lista.begin(); it != --lista.end();){

        for(auto itd = ++it; itd != lista.end(); itd++){
            if(((**it)+(**itd)) == 0 ){
                lista_casais_het.push_back(*it);
                lista_casais_het.push_back(*itd);
            }
        }
    }

    print_list(lista);
    print_list(lista_casais_het);

}
