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
        Node<T>* getNext() const noexcept { return next.get(); }
        void setNext(T data) { next = std::make_unique<Node<T>>(data); }
        void setNext(std::unique_ptr<Node<T>> newNext) noexcept { next = std::move(newNext); }
        bool hasNext() const noexcept { return next != nullptr; };
        std::unique_ptr<Node<T>> releaseNext() noexcept { return std::move(next); }
};
#endif