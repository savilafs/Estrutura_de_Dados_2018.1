#include <iostream>

using namespace std;

struct  Node{
    int value;
    Node* next;

    Node(int value = 0, Node * next = nullptr){
        this->value = value;
        this->next = next;
    }
};

struct SList{
    Node* head;

    SList(){
        this->head = nullptr;
    }

    ~SList(){
        deletarTudo(head);
    }

    Node * deletarTudo(Node * node){
        if(node == nullptr){
            return nullptr;
        }
        deletarTudo(node->next);
        delete node;
        return nullptr;
    }

    void push_front(int value){
        Node * node = new Node(value);
        node->next = head;
        this->head = node;
    }

    void pop_front(){
        if(head == nullptr)
            return;
        Node * aux = head;
        head = head->next;
        delete aux;
    }

    /*
     * PUSH_BACK INTERATIVO
     */
    void push_back(int value){
        if(head == nullptr){
            head = new Node(value);
            return;
        }
        auto node = head;
        while(node->next != nullptr)
            node = node->next;
        node->next = new Node(value);
    }

    /*
     * PUSH_BACK RECURSIVO
     */
    Node * _rpush_back(Node * node, int value){
        if(node == nullptr)
            return new Node(value);
        node->next = _rpush_back(node->next, value);
        return node;
    }

    void rpush_back(int value){
        head = _rpush_back(head, value);
    }

    /*
     * POP_BACK INTERATIVO
     */
    void pop_back(){
        if(head == nullptr)
            return;
        if(head->next == nullptr){
            delete head;
            head = nullptr;
            return;
        }
        auto node = head;
        while(node->next->next != nullptr)
            node = node->next;
        delete node->next;
        node->next = nullptr;
    }

    /*
     * POP_BACK RECURSIVO
     */
    Node * _rpop_back(Node * node){
        if(node->next == nullptr){
            delete node;
            return nullptr;
        }
        node->next = _rpop_back(node->next);
    }

    void rpop_back(){
        this->head = _rpop_back(head);
    }

    /*
     * SHOW INTERATIVO
     */
    void ishow(){
        auto node = head;
        while(node != nullptr){
            cout << node->value << " ";
            node = node->next;
        }
        cout << endl;
    }

private:
    /*
     * SHOW RECURSIVO PRIVADO
     */
    void _rshow(Node * node){
        if(node == nullptr)
            return;
        _rshow(node->next);
        cout << node->value << " ";
    }

public:
    /*
     * SHOW RECURSIVO PÚBLICO
     */
    void rshow(){
        _rshow(head);
        cout << "" << endl;
    }

    /*
     * REMOVER INTERATIVO
     */
    /*
    Node * _iremove(Node * node, int value){
       // auto n = node;
        while(node != nullptr){
            auto aux = node->next;
            if(node->value == value){
                delete node;
                return aux;
            }
            node = aux;
        }
        return nullptr;
    }

    void iremove(int value){
        head = _iremove(head, value);
    }
    */


    /*
     * REMOVER RECURSIVO
     */
    Node * _rremove(Node * node, int value){
        if(node == nullptr)
            return nullptr;
        if(node->value == value){
            auto aux = node->next;
            delete node;
            return aux;
        }
        node->next = _rremove(node->next, value);
    }

    void rremove(int value){
        head = _rremove(head, value);
    }

    /*
     * ARRANCA RABO
     *
     * Exemplo:
     * 5 9 1 2
     * arrancaRabo(1);
     * 5 9 1
     */
    Node * arrancaRabo(Node * node, int value){
        if(node == nullptr)
            return nullptr;
        if(node->next->value == value){
            return node;
        }
        delete node;
        node->next = arrancaRabo(node->next, value);
    }

    /*
     * ARRANCA VENTA
     *
     * Exemplo:
     * 5 9 1 2
     * arrancaVenta(9);
     * 9 1 2
     */
    Node * arrancaVenta(Node * node, int value){
        if(node == nullptr)
            return nullptr;
        node->next = arrancaVenta(node->next, value);
        if(node->next == nullptr){
            if(node->value != value){
                delete node;
                return nullptr;
            }else{
                return node;
            }
        }
        return node;
    }

    /*
        head = 900;
        900:{1 500};
        500:{2 700};
   node 700:{4 250};
        300:{6 0};
        250:{5 300};

        5
        2 > 4 X 6
    */

    /*
     * INSERIR ORDENADA ITERATIVO
     */
    void inserir_ordenado(int value){
        auto node = head;
        if(head == nullptr || head->value > value){
            this->head = new Node(value, head);
            return;
        }
        while(node->next != nullptr && node->next->value < value){
            node = node->next;
        }
        node->next = new Node(value, node->next);
    }

    /*
     * INSERIR ORDENADA RECURSIVO
     */
    Node * _rinserir_ordenado(Node * node, int value){
        if(node == nullptr || (node->value >= value))
           return new Node(value, node);
        node->next = _rinserirOrdenado(node->next, value);
        return node;
    }

    void rinserir_ordenado(int value){
        head = _rinserir_ordenado(head, value);
    }

    int size(){
        int size = 0;
        auto node = head;        
        while(node != nullptr){
            node = node->next;
            size++;
        }
        return size;
    }

    int rsomar(Node * node){
        if(node->next == nullptr)
            return node->value;
        return rsomar(node->next)+node->value;
    }

    int rmin(Node * node){
        if(node->next == nullptr)
            return node->value;
        return std::min(node->value, rmin(node->next));
    }

};

int main(){
    SList lista;
    lista.push_back(5);
    lista.push_back(6);
    lista.push_back(7);
    lista.push_back(10);
    lista.rshow();
    cout << lista.rsomar(lista.head) << endl;
    //lista.iremove(10);
    //lista.arrancaRabo(lista.head, 6);
    lista.rshow();
    lista.arrancaRabo(lista.head, 7);
    lista.rshow();
    return 0;
}
