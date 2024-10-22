#ifndef NODE_H
#define NODE_H

#include <iostream>

template <typename T>
class Node {
public:
    // Atributos
    T data;            // El valor almacenado en el nodo
    Node<T>* next;     // Puntero al siguiente nodo (o nullptr si es el último)

    // Constructor
    Node(T data, Node<T>* next = nullptr) : data(data), next(next) {}

    // Sobrecarga del operador << para imprimir el nodo
    friend std::ostream& operator<<(std::ostream& out, const Node<T>& node) {
        out << node.data;  // Solo imprimimos el valor del nodo
        return out;
    }
};

#endif // NODE_H

