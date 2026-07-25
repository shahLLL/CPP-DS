#ifndef QUEUE_H
#define QUEUE_H

#include <memory>
#include <climits>
#include <string>
#include <stdexcept>
#include "double_node.h"

const std::string peekEmptyErrorMessage = "PEEK CALLED ON EMPTY QUEUE";
const std::string dequeEmptyErrorMessage = "DEQUE CALLED ON EMPTY QUEUE";

template <typename T>
class Queue {
    std::shared_ptr<DoubleNode<T>> head;
    std::weak_ptr<DoubleNode<T>> tail;

    unsigned short size;
    const unsigned short capacity = USHRT_MAX;

    public:
        Queue(): head(nullptr), tail(), size(0) {}
        unsigned short getSize() const { return size; }
        bool isEmpty() const { return size == 0; }

        T peek() const {
            if(size == 0)
                throw std::out_of_range(peekEmptyErrorMessage);
            return head->getData();
        }

        bool enque(T data) {
            if(size == capacity)
                return false;
            
            if(size == 0) {
                head = std::make_shared<DoubleNode<T>>(data);
                tail = head;
            } else {
                auto tailShared = tail.lock();
                auto newNode = std::make_shared<DoubleNode<T>>(data);
                newNode->setPrev(tailShared);
                tailShared->setNext(newNode);
                tail = newNode;
            }

            size = size + 1;
            return true;
        }

        bool contains(T data) const {
            std::shared_ptr<DoubleNode<T>> itr = head;
            while(itr) {
                if(itr->getData() == data)
                    return true;
                itr = itr->getNext();
            }
            return false;
        }

        T deque() {
            if (size == 0)
                throw std::out_of_range(dequeEmptyErrorMessage);

            std::shared_ptr<DoubleNode<T>> oldHead = head;
            head = head->getNext();

            if (head) {
                head->setPrev(std::shared_ptr<DoubleNode<T>>(nullptr));
            } else {
                tail.reset();
            }

            oldHead->setNext(nullptr);
            size = size - 1;
            return oldHead->getData();
        }
};
#endif