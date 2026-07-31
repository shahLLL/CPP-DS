#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <string>
#include <climits>
#include <stdexcept>
#include "pair.h"
#include "node.h"

constexpr unsigned int hashTableDefaultCapacity = 10;
const std::string hashTableGetErrorMessage = "PROVIDED KEY NOT PRESENT IN HASH TABLE";
const std::string hashTableExceedCapacityErrorMessage = "HASH TABLE HAS EXCEEDED CAPACITY";

template <typename T, typename U>
class HashTable {
    const unsigned short maxCapacity = USHRT_MAX;
    const std::hash<T> hasher;
    unsigned short size;
    unsigned int currentCapacity;
    std::unique_ptr<std::unique_ptr<Node<Pair<T, U>>>[]> table;

    void resize(unsigned int newCapacity) {
        if(newCapacity >= maxCapacity)
            throw std::out_of_range(hashTableExceedCapacityErrorMessage);
        if(newCapacity < hashTableDefaultCapacity)
            return;

        std::unique_ptr<std::unique_ptr<Node<Pair<T, U>>>[]> newTable = std::make_unique<std::unique_ptr<Node<Pair<T,U>>>[]>(newCapacity);
        for(unsigned int i = 0; i < currentCapacity; i++) {
            Node<Pair<T, U>>* itr = table[i].get();
            while(itr) {
                T key = itr->getData().getKey();
                U value = itr->getData().getValue();
                unsigned short index = (hasher(key)) % newCapacity;
                Node<Pair<T, U>>* newItr = newTable[index].get();
                if(newItr) {
                    while(newItr->hasNext()) newItr = newItr->getNext();
                    newItr->setNext(std::make_unique<Node<Pair<T, U>>>(Pair<T, U>(key, value)));
                } else {
                    newTable[index] = std::make_unique<Node<Pair<T, U>>>(Pair<T, U>(key, value));
                }
                itr = itr->getNext();
            }
        }

        currentCapacity = newCapacity;
        table = std::move(newTable);
    }

    public:
        HashTable(): hasher(), size(0), currentCapacity(hashTableDefaultCapacity), table(std::make_unique<std::unique_ptr<Node<Pair<T,U>>>[]>(hashTableDefaultCapacity)){}
        unsigned short getSize () const noexcept { return size; }
        unsigned int getCapacity () const noexcept { return currentCapacity; }
        bool isEmpty() const noexcept { return size == 0; }

        U get(T key) const {
            if(size == 0)
                throw std::invalid_argument(hashTableGetErrorMessage);
            
            unsigned short index = (hasher(key)) % currentCapacity;
            Node<Pair<T, U>>* itr = table[index].get();
            while(itr) {
                if(itr->getData().getKey() == key)
                    return itr->getData().getValue();
                itr = itr->getNext();
            }
            throw std::invalid_argument(hashTableGetErrorMessage);
        }

        bool add(T key, U value) {
            if(size == maxCapacity)
                return false;
            
            unsigned short index = (hasher(key)) % currentCapacity;
            if(table[index].get()) {
                Node<Pair<T, U>>* itr = table[index].get();
                while(itr->hasNext())
                    itr = itr->getNext();
                itr->setNext(std::make_unique<Node<Pair<T, U>>>(Pair<T,U>(key, value)));
            } else {
                table[index] = std::make_unique<Node<Pair<T, U>>>(Pair<T, U>(key, value));
            }

            size = size + 1;
            if(static_cast<double>(size)/static_cast<double>(currentCapacity) >= 0.8) resize(currentCapacity * 2);
            return true;
        }

        bool put(T key, U value) {
            if(size == 0)
                return false;

            unsigned int index = hasher(key) % currentCapacity;
            Node<Pair<T, U>>* itr = table[index].get();
            Node<Pair<T, U>>* follower = nullptr;

            while(itr) {
                if(itr->getData().getKey() == key) {
                    auto newNode = std::make_unique<Node<Pair<T, U>>>(Pair<T, U>(key, value));
                    newNode->setNext(itr->releaseNext());

                    if(follower)
                        follower->setNext(std::move(newNode));
                    else
                        table[index] = std::move(newNode);

                    return true;
                }
                follower = itr;
                itr = itr->getNext();
            }

            return false;
        }

        bool contains(T key) const noexcept {
            if(size == 0)
                return false;

            unsigned short index = (hasher(key)) % currentCapacity;
            Node<Pair<T, U>>* itr = table[index].get();
            while(itr) {
                if(itr->getData().getKey() == key)
                    return true;
                itr = itr->getNext();
            }
            return false;
        }

        bool remove(T key) noexcept {
            if(size == 0)
                return false;
            
            unsigned short index = (hasher(key)) % currentCapacity;
            Node<Pair<T, U>>* itr = table[index].get();
            Node<Pair<T, U>>* follower = nullptr;

            while(itr) {
                if(itr->getData().getKey() == key) {
                    if(follower) {
                        follower->setNext(itr->releaseNext());

                    } else {
                        table[index] = itr->releaseNext();
                    }
                    size = size - 1;
                    if(static_cast<double>(size)/static_cast<double>(currentCapacity) <= 0.2) resize(currentCapacity / 2);
                    return true;
                }
                follower = itr;
                itr = itr->getNext();
            }
            return false;
        }
};
#endif