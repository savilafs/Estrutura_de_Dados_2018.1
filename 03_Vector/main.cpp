#include <iostream>
#include <vector>

using namespace std;

struct Vetor{
    int * _data;
    int _capacidade;
    int _size;

    Vetor(int capacidade){
        this->_capacidade = capacidade;
        this->_size = 0;
        this->_data = new int[capacidade];
    }

    void push_back(int value){
        if(this->_size == this->_capacidade)
            return;
        this->_data[this->_size] = value;
        this->_size += 1;
    }

    void pop_back(){
        if(this->_size == 0)
            return;
        this->_data[_size] = 0;
        this->_size -= 1;
    }

    int& at(int indice){
        return this->_data[indice];
    }

    int& front(){
        return this->_data[0];
    }

    int& back(){
        return this->_data[this->_size - 1];
    }

    int * begin(){
        return &this->_data[0];
    }

    int * end(){
        return &this->_data[this->_size];
    }

    int size(){
        return this->_size;
    }

    int capacity(){
        return this->_capacidade;
    }

    void reserve(int capacity){
        Vetor aux(capacity);

        if(this->_size <= capacity)
            for (int i = 0; i < this->_size; i++)
                aux.push_back(this->_data[i]);
        else
            for (int i = 0; i < capacity; i++)
                aux.push_back(this->_data[i]);

        this->_data = new int[capacity];
        this->_size = 0;

        for (int i = 0; i < aux.size(); ++i) {
            this->push_back(aux.at(i));
        }
    }
};

int main(){
    Vetor pivet(5);
    pivet.push_back(4);
    pivet.reserve(3);
    std:: cout << pivet.capacity() << endl;
    std:: cout << pivet.size() << endl;

    return 0;
}
