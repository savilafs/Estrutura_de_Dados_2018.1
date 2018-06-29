#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

struct Elemento{
    int key;
    string value;

    Elemento(int key = 0, string value = ""){
        this->key = key;
        this->value = value;
    }

    bool operator ==(Elemento other){
        return key == other.key;
    }

    friend ostream& operator << (ostream& os, Elemento e){
        os << e.key;
        return os;
    }
};

struct HashLista{
    vector<list<Elemento>> * vet;
    int qtdElem = 0;
    HashLista(int size){
        vet = new vector<list<Elemento>>(size);
    }

    bool insercao(Elemento elem) {
        int base = elem.key % ((int)vet->size());
        auto& lista = vet[base];
        //se fator de carga > maximo
        /*if(vet->size()<qtdElem)
            resize(elem);*/
        auto it = std::find(lista.begin(), lista.end(), elem);
        if(it != lista.end())
            return false;
        lista.push_back(elem);
        return true;
    }



    void resize(int new_vet_size){
        auto vet_old = this->vet;
        this->vet = new vector<list<Elemento>>(new_vet_size);
        for(auto& lista : *vet_old)
            for(auto& elem : lista)
                this->insercao(elem);
        delete vet_old;

    }

    bool busca(Elemento elem) {
        int base = elem.key % vet->size();
        auto& lista = vet->at(base);
        auto it = std::find(lista.begin(), lista.end(), elem);
        return (it == lista.end());
    }

    bool remocao(Elemento elem) {
        int base = elem.key % vet->size();
        auto& lista = vet->at(base);
        auto it = std::find(lista.begin(), lista.end(), elem);
        if(it == lista.end())
            return false;
        lista.erase(it);
        return true;
    }
};

/*void print_HashList(HashLista hashlist){

}*/

int main(){
    HashLista hl;
    hl.insercao(new Elemento(0, 2));

    printf(hl);
    return 0;
}






