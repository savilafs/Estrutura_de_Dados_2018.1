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

    void reserve(int value){
        int capacidade = this->_capacidade;
        int * data = new int[capacidade];
        for(int i=0; i<capacidade; i++){
            data[i] = this->_data[i];
        }
        this->_capacidade = value;
        this->_data = new int[this->_capacidade];
        for(int i=0; i<capacidade; i++)
            this->_data[i] = data[i];
    }
};

int main(){
    Vetor v(5);
    v.push_back(4);
    v.push_back(1);
    v.reserve(8);
    std:: cout << v.capacity() << endl;
    std:: cout << v.size() << endl;
    std:: cout << v.front() << endl;
    std:: cout << v.back() << endl;
    std:: cout << v.begin() << endl;
    std:: cout << v.end() << endl;

    return 0;
}
