#include <iostream>
using namespace std;

struct Nodo {
    int data;
    Nodo* siguiente;
};

class fila {
private:
    Nodo* inicio;
    Nodo* final;
public:
    fila() {
        inicio = nullptr;
        final = nullptr;
    }
    void enqueue(int data) {
        Nodo* temp = new Nodo;
        temp->data = data;
        temp->siguiente = nullptr;
        if (inicio == nullptr) {
            inicio = temp;
            final = temp;
        }
        else {
            final->siguiente = temp;
            final = temp;
        }
    }
    void dequeue() {
        if (inicio == nullptr) {
            cout << "fila esta vacia" << endl;
            return;
        }
        Nodo* temp = inicio;
        inicio = inicio->siguiente;
        delete temp;
    }
    int front() {
        if (inicio == nullptr) {
            cout << "fila esta vacia" << endl;
            return -1;
        }
        return inicio->data;
    }
    void mostrar()
    {
        if (inicio  == nullptr)
        {
            std::cout << "La lista esta vacia\n";
            return;
        }

        Nodo* apunta = inicio;
        while (apunta != nullptr)
        {
            std::cout << "[ " << apunta->data << " ]-> ";
            apunta = apunta->siguiente;
        }
        std::cout << "[NULL] ";
    }
};

int main() {
    fila Fila;
    Fila.enqueue(1);
    Fila.enqueue(2);
    Fila.enqueue(3);
    cout << Fila.front() << endl; // 1
    Fila.dequeue();
    cout << Fila.front() << endl; // 2
    return 0;
}