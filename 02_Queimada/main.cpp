#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

const int num_col = 10;
const int num_lin = 2;

struct Par{
    int l, c;
    Par(int l = 0, int c = 0){
        this->l = l;
        this->c = c;
    }
};

vector<Par> getNeib(Par p){
    vector<Par> v;
    v.push_back(Par(p.l, p.c + 1));
    v.push_back(Par(p.l, p.c - 1));
    v.push_back(Par(p.l + 1, p.c));
    v.push_back(Par(p.l - 1, p.c));
    return v;
}

void mostrar(vector<string>& mat){
    cout << string(50, '\n');
    for(string s : mat)
        cout << s << endl;
    getchar();
}

vector<Par> embaralhar(vector<Par> vet){
    for(int i = 0; i < (int) vet.size(); i++){
        int aleat = rand() % vet.size();
        std::swap(vet[i], vet[aleat]);
    }
    return vet;
}

int queimar(vector<string> &mat, int l, int c, int nivel){
    int contador = 0;
    if(l < 0 || l >= num_lin)
        return 0;
    if(c < 0 || c >= num_col)
        return 0;
    if((mat[l][c] != '#'))
        return 0;
    if(nivel > 9)
        nivel = 0;

    mat[l][c] = '0' + nivel;
    contador++;
    mostrar(mat);

    for(Par p : embaralhar(getNeib(Par(l, c)))){
            contador +=  queimar(mat, p.l, p.c, nivel+1);
    }

    return contador;
}


int main(){
    srand(time(NULL));
    vector<string> mat(num_lin, string(num_col, '#'));
    int narvores = num_lin * num_col * 1.5;

    for(int i = 0; i < narvores; i++){
        mat[rand() % num_lin][rand() % num_col] = '#';
    }
    mostrar(mat);

    int total = queimar(mat, 0, 0, 0);
    cout << "Foram " << total << " arvores queimadas\n"  << endl;

    return 0;
}
