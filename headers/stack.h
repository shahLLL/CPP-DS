#ifndef STACK_H
#define STACK_H

#include <memory>
#include <climits>
#include <string>
#include "node.h"

const std::string peekEmptyErrorMessage = "PEEK CALLED ON EMPTY  STACK";
const std::string popEmptyErrorMessage = "POP CALLED ON EMPTY STACK";    

template<typename T>
class Stack {
    std::unique_ptr<Node<T>> head;
    unsigned short size;
    const unsigned short capacity = USHRT_MAX;

    public:
        Stack() : head(nullptr), size(0) {}
        bool isEmpty() { return size == 0; }
        unsigned short getSize() { return size; }

        T peek() { 
            if(head == nullptr)
                throw std::out_of_range(peekEmptyErrorMessage);
            return head.get()->getData();
        }

        bool push(T data) { 
            if(size == capacity)
                return false;
            
            auto newNode = std::make_unique<Node<T>>(data);
            newNode->setNext(std::move(head));
            head = std::move(newNode);
            size = size + 1;
            return true;
        }
        
        bool contains(T data) { 
            if(size == 0)
                return false;

            Node<T>* itr = head.get();
            while(itr != nullptr) {
                if(itr->getData() == data)
                    return true;
                itr = itr->getNext().get();
            }

            return false;
        }

        T pop() { 
            if(size == 0)
                throw std::out_of_range(popEmptyErrorMessage);
            
            auto popedNode = std::move(head);
            head = popedNode->releaseNext();
            size = size - 1;
            return popedNode.get()->getData();
        }
};
#endif