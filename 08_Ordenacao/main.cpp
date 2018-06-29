#include <iostream>
#include <ctime>
#include <cstdlib> //rand
#include "libs/ed_sort.h"

using namespace std;

//cores rgbcymkw
//red, green, blue, cyan, yellow, magenta, black, white

void swap_sort(vector<int>& vet){
    for(int i = 0; i < (int) vet.size() - 1; i++){
        view_set_faixa(i, vet.size() - 1);
        for(int j = i + 1; j < (int) vet.size(); j++){
            view_show(vet, {i, j}, "yg");
            if(vet[j] < vet[i]){
                std::swap(vet[i], vet[j]);
                view_show(vet, {i, j}, "yg");
            }
        }
    }
}

void selection_sort(vector<int>& vet){
    for(int i = 0; i < (int) vet.size() - 1; i++){
        int imenor = i;
        view_set_faixa(i, vet.size() - 1);
        for(int j = i + 1; j < (int) vet.size(); j++){
            view_show(vet, {i, j, imenor}, "ygr");
            if(vet[j] < vet[imenor]){
                imenor = j;
                view_show(vet, {i, j, imenor}, "ygr");
            }
        }
        std::swap(vet[imenor], vet[i]);
    }
}

void reverse_minimum_sort(vector<int>& vet){
    int ultimo = vet.size() - 1;
    for(int i = 0; i <= ultimo; ultimo--){
        int imaior = ultimo;
        for(int j = 0; j < ultimo; j++){
            view_show(vet, {j, imaior, ultimo}, "ygr");
            if(vet[j] > vet[imaior]){
                imaior = j;
                view_show(vet, {j, imaior, ultimo}, "ygr");
            }
        }
        std::swap(vet[imaior], vet[ultimo]);
    }
}

void palma_sort(vector<int>& vet){
    int ultimo = vet.size() - 1;
    for(int i = 0; i <= ultimo; i++, ultimo--){
        int imaior = i;
        int imenor = i;
        view_set_faixa(i, ultimo);
        for(int j = i; j <= ultimo; j++){
            view_show(vet, {i, j, imenor, imaior, ultimo}, "rgyyr");
            if(vet[j] < vet[imenor]){
                imenor = j;
                view_show(vet, {i, j, imenor, imaior, ultimo}, "rgyyr");
            }
            else if(vet[j] > vet[imaior]){
                imaior = j;
                view_show(vet, {i, j, imenor, imaior, ultimo}, "rgyyr");
            }
        }
        std::swap(vet[imenor], vet[i]);
        if(imaior == i)
            imaior = imenor;
        std::swap(vet[imaior], vet[ultimo]);
        view_show(vet, {i, imenor, imaior, ultimo}, "ryyr");
    }
}

void bubble_sort(vector<int>& vet){
    int ultimo = vet.size()-1;
    for(int i = ultimo; i > 0; i--){
        for(int j = 0; j < i; j++){
            if(vet[j] > vet[j+1]){
                swap(vet[j], vet[j+1]);
                view_show(vet, {i, j}, "rgy");
            }
            view_show(vet, {i, j}, "rgy");
        }
    }

}

void insertion_sort(vector<int>& vet){
    int ultimo = vet.size();
    for(int i = 0; i < ultimo; i++){
        for(int j = i; j > 0; j--){
            if(vet[j]<vet[j-1]){
                swap(vet[j], vet[j-1]);
                view_show(vet, {i, j}, "rgy");
            }else{
                break;
            }
            view_show(vet, {i, j}, "rgy");
        }
    }

}

//intervalos fechados [c, f]
#define qshow view_show(vet,{C,F,i,j}, "rgby");

void quick_sort(vector<int>& vet, int c, int f){
    if(c >= f){
        return;
    }
    int pivo = vet[c];
    int i = c;
    int j = f;

    view_set_faixa(c, f);

    while(i <= j){
        while(vet[i]< pivo){
            i++;
        }
        while((vet[j] > pivo) && (i<c)){
            j--;
        }
        if(i<=j){
           std::swap(vet[i], vet[j]);
           i++;
           j--;
        }
    }
    quick_sort(vet, c, j);
    quick_sort(vet, i, f);
}

void marge(vector<int>& vet, int a, int b, int c){
    int i = a;
    int j = b;
    vector<int> vaux;
    vaux.reserve(c-a);
    while((i< b) && (j<c)){//testando se há elementos nas particoes particao
        if(vet[i]< vet[j]){
            vaux.push_back(vet[i++]);//salvando i atual e após isso andando para frente
        }else{
            vaux.push_back(vet[j++]);
            view_show(vet, {a,b,c,i,j},"rgbyc");

        }
    }
    while(i < b){//testando se ainda há algo na primeira particao
        vaux.push_back(vet[i++]);//salvando i atual e após isso andando para frente
        view_show(vet, {a,b,c,i,j},"rgbyc");

    }
    while(j < c){//testando se ainda há algo na ultima particao
        vaux.push_back(vet[j++]);
        view_show(vet, {a,b,c,i,j},"rgbyc");
    }
    for(int i = 0; i < (int) vaux.size(); i++){
        vet[i+a] = vaux[i];
        view_show(vet, {a + i},"rgbyc");

    }
 }

//   vector<int>& aux para guardar    ordenaçao e cola no vetor original
//   compara o menor e ele anda
void margesort(vector<int>& vet, int a, int b, int c){
    if(c == a+1){
        return;
    }
    b = (a+c) / 2;
    margesort(vet, a, b, c);//posicionam os elementos
    margesort(vet, a, b, c);//posicionam os elementos
    margesort(vet, a, b, c);//trocam os elementos de fato // na volta
    view_show(vet);
}

void test_sort(vector<int>& vet){
    for(int i = 0; i < (int) vet.size() - 1; i++){
        if(vet[i] <= vet[i + 1])
            view_show(vet, {i, i + 1}, "gg");
        else{
            view_show(vet, {i, i + 1}, "rr");
            view_lock();
        }
    }
}

int main(){
    srand(time(NULL));

    const int qtd = 70;
    vector<int> vet(qtd, 0);

    int min = 10;
    int max = 400;

    for(int i = 0; i < qtd; i++)
        vet[i] = (rand() % (max - min + 1) + min);

    view_set_bar();
    view_set_faixa(0, qtd - 1);

    //swap_sort(vet);
    //selection_sort(vet);
    // insertion_sort(vet);
    //reverse_minimum_sort(vet);
    //margesort(vet, 0 , 0, vet.size());
    test_sort(vet);
    view_lock();
    return 0;
}
