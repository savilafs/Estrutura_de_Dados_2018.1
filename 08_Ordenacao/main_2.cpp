#include <iostream>
#include <ctime>
#include <cstdlib> //rand
#include "libs/ed_sort.h"

using namespace std;

//cores rgbcymkw
//red, green, blue, cyan, yellow, magenta, black, white

/*void minimum_sort(vector<int>& vet){
    for(int i = 0; i < (int) vet.size() - 1; i++){
        int imenor = i;
        for(int j = i + 1; j < (int) vet.size(); j++){
            view_show(vet, {i, j, imenor}, "gy");
            if(vet[j] < vet[imenor]){
                //std::swap(vet[i], vet[j]);
                imenor = j;
                view_show(vet, {i, j}, "yg");
            }
        }
        std::swap(vet[imenor], vet[i]);
    }
}*/
/*void minimum_sort(vector<int>& vet){
    int ultimo = vet.size()-1;
    for(int i = 0; i <= ultimo; i++; ultimo--){
        int imenor = i;
        int imaior = ultimo;
        for(int j = i + 1; j < ultimo; j++){
            view_show(vet, {i, j, imenor, imaior, ultimo}, "rgyyr");
            if(vet[j] < vet[imenor]){
                //std::swap(vet[i], vet[j]);
                imenor = j;
                view_show(vet, {i, j, imenor, imaior, ultimo}, "rgyyr");
            }
            if(vet[j] > vet[imaior]){
                //std::swap(vet[i], vet[j]);
                imaior = j;
                view_show(vet, {i, j, imenor, imaior, ultimo}, "rgyyr");
            }
        }
        std::swap(vet[imenor], vet[i]);
        if(imaior == imenor || imaior == imenor)
            std::swap(i, imenor);
        std::swap(ve[imaior], vet[ultimo]);
        view_show(vet, {i, j, imenor, imaior, ultimo}, "rgyyr");
    }
}*/



/*int main(){
    srand(time(NULL));
    const int qtd = 70;
    vector<int> vet(qtd, 0);

    int min = 10;
    int max = 400;

    for(int i = 0; i < qtd; i++)
        vet[i] = (rand() % (max - min + 1) + min);

    view_set_bar();
    view_set_faixa(0, qtd - 1);

    minimum_sort(vet);

    view_lock();
    return 0;
}*/
