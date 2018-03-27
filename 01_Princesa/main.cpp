#include <iostream>
//using namespace std;

int matar_passar(int espada, int fila_Cavaleiros[], int tam){
    espada = (espada + 1) % tam;

    while(fila_Cavaleiros[espada] == 0){

        espada = (espada + 1) % tam;
    }

    fila_Cavaleiros[espada] = 0;

    while(fila_Cavaleiros[espada] == 0)
    {
        espada = (espada + 1) % tam;
    }

    return espada;

}

void imprimir(int v[], int jogador){
    int i = 0;

    for(i=0; i<jogador; i++){
        std::cout << "[" << v[i] << "] ";
    }
    std::cout << "\n";
}

int main(int argc, char *argv[]){
    int tam, escolha, contVivos;

    std::cout << "Digite o numero de guerreiros: ";
    std::cin >> tam;
    std::cout << "Escolha um soldado para comecar: ";
    std::cin >> escolha;

    escolha--;
    contVivos = tam;
    int soldados[tam];
    for(int i = 0; i < tam; i++){
        soldados[i] = i + 1;
    }

    while(contVivos > 1){
        escolha = matar_passar(escolha, soldados, tam);
        imprimir(soldados, tam);
        contVivos--;
    }

    return 0;
}

