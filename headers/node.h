#ifndef NODE_H
#define NODE_H

#include <memory>

template<typename T>

class Node {
    const T data;
    std::unique_ptr<Node<T>> next;
    public:
        Node(T data): data(data), next(nullptr) {}
        T getData() const { return data; }
        Node<T>* getNext() const { return next.get(); }
        void setNext(T data) { next = std::make_unique<Node<T>>(data); }
        bool hasNext() const { return next != nullptr; }; 
};
#endif