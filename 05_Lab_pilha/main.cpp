#include "libs/ed_base.h"
#include "libs/ed_mat.h"

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <algorithm> //random_shuffle
#include <cstdlib>
#include <ctime>

using namespace std;

const char PAREDE = 'k';
const char ABERTO = 'w';
const char EMBUSCA = 'y';
const char CAMINHO = 'b';
const char ABATIDO = 'm';

void showMat(matchar& mat, vector<Par> pilha, Par inicio, Par fim){
    mat_draw(mat);
    for(Par par : pilha)
        mat_focus(par, 'c');
    if(pilha.size() > 0)
        mat_focus(pilha.back(), 'k');
    mat_focus(inicio, 'g');
    mat_focus(fim, 'r');
}

vector<Par> getNeib(Par par){
    vector<Par> vizinhos;
    vizinhos.push_back(Par(par.l + 1, par.c));
    vizinhos.push_back(Par(par.l - 1, par.c));
    vizinhos.push_back(Par(par.l, par.c + 1));
    vizinhos.push_back(Par(par.l, par.c - 1));
    return vizinhos;
}

int countOpen(matchar &mat, Par par){
    int cont = 0;
    for(auto vizinho : getNeib(par))
        if(!mat.is_inside(vizinho) || mat.get(vizinho) != PAREDE)
            cont++;
    return cont;
}

vector<Par> shuffle(vector<Par> vet){
    std::random_shuffle(vet.begin(), vet.end());
    return vet;
}

bool findPath(matchar& mat, Par inicio, Par final){
    vector<Par> a;
    a.push_back(inicio);
    mat.get(inicio) = EMBUSCA;

    while(a.size() != 0){
        Par topo = a.back();
        if(topo == final){
            showMat(mat, a, inicio, final);
            ed_show();
            return true;
        }
        vector<Par> vizinhos_disponiveis;
        showMat(mat, a, inicio, final);
        for(Par par : getNeib(topo)){
            if(mat.get(par) == ABERTO){
                vizinhos_disponiveis.push_back(par);
                mat_focus(par, 'r');
            }
        }
        ed_show();
        if(vizinhos_disponiveis.size() == 0){
            a.pop_back();
            showMat(mat, a, inicio, final);
            ed_show();
        }else{
            Par selecionado = vizinhos_disponiveis[rand() % vizinhos_disponiveis.size()];
            mat.get(selecionado) = EMBUSCA;
            a.push_back(selecionado);
            showMat(mat, a, inicio, final);
            ed_show();
        }
    }
    showMat(mat, a, inicio, final);
    ed_show();
    return false;
}

 void furar(matriz<char>& mat,Par inicio){
    vector<Par> pilha;
    pilha.push_back(inicio);
    mat.get(inicio)=ABERTO;

    while(pilha.size()!=0){
        vector<Par> caminhosLivres;
        Par topo = pilha.back();
        for(auto vizinhos:getNeib(topo))
            if(countOpen(mat,vizinhos)<=1 && mat.equals(vizinhos,PAREDE))
               caminhosLivres.push_back(vizinhos);

        if(caminhosLivres.size()!=0){
            int vizinho = rand() % caminhosLivres.size();
            mat.get(caminhosLivres[vizinho])=ABERTO;
            pilha.push_back(caminhosLivres[vizinho]);
            mat_draw(mat);
            ed_show();
        }else{
            pilha.pop_back();
        }
    }
 }

int main(){
    srand(time(NULL));
    matchar mat(10, 15, PAREDE);
    furar(mat, Par(1,1));//chama a pilha
    Par inicio = mat_get_click(mat, "digite o local de inicio");
    Par final = mat_get_click(mat, "digite o local de fim");
    mat_draw(mat);
    ed_show();
    findPath(mat, inicio, final);
    ed_lock();//impede que termine abruptamente
    return 0;
}
