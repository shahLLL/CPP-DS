#ifndef DOUBLE_NODE_H
#define DOUBLE_NODE_H

#include <memory>

template <typename T>
class DoubleNode {
    T data;
    std::weak_ptr<DoubleNode<T>> prev;
    std::shared_ptr<DoubleNode<T>> next;

    public:
        DoubleNode(T data): data(data), prev(), next(nullptr) {}
        T getData() const { return data; }
        std::weak_ptr<DoubleNode<T>> getPrev() const { return prev.lock(); }
        std::shared_ptr<DoubleNode<T>> getNext() const { return next; }
        bool hasPrev() const { return !prev.expired(); }
        bool hasNext() const { return next != nullptr; }
        void setPrev(std::shared_ptr<DoubleNode<T>> newPrev) { prev = newPrev; }
        void setNext(T data) { next = std::make_shared<DoubleNode<T>>(data); }
        void setNext(std::shared_ptr<DoubleNode<T>> newNext) { next = newNext; }
};
#endif