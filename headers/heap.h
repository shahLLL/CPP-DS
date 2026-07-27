#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <stdexcept>
#include <string>

const std::string heapPeekErrorMessage = "PEEK CALLED ON EMPTY HEAP";

template <typename T>
class Heap {
    protected:
    std::vector<T> heapTable;
    public:
        Heap(): heapTable() {};
        boolean isEmpty() const noexcept { return heapTable.size() == 0; }
        unsigned int getSize() const noexcept { return heapTable.size(); }
        T peek() const {
            if(heapTable.size() == 0)
                throw std::out_of_range(heapPeekErrorMessage);
            return heapTable[0];
        }
        virtual void add(T val) = 0;
        virtual T pop() = 0;
};

#endif