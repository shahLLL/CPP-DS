#ifndef DYNAMIC_ARRAY
#define DYNAMIC_ARRAY

#include <memory>
#include <climits>

unsigned int defaultCapacity = 10;

template <typename T>
class DynamicArray {
    unsigned short size;
    unsigned int currentCapacity;
    const unsigned short maxCapacity = USHRT_MAX;
    std::unique_ptr<T[]> array;

    void resize() {
        unsigned int newCapacity = currentCapacity * 2; 
        auto newArray = std::make_unique<T[]>(newCapacity);

        for (unsigned int i = 0; i < size; ++i)
            newArray[i] = std::move(array[i]);
    
        array = std::move(newArray);
        currentCapacity = newCapacity;
    }

    public:
        DynamicArray(): size(0),  currentCapacity(defaultCapacity), array(std::make_unique<T[]>(currentCapacity)){}
        unsigned short getSize() const { return size; }
        unsigned int getCapacity() const { return currentCapacity; }
        bool isEmpty() const { return size == 0; }

        bool contains(T data) const {
            for(int i = 0; i < size; i++)
                if(array[i] == data)
                    return true;
            return false;
        }

        bool append(T data) {
            if(size == maxCapacity)
                return false;
            if(size == currentCapacity)
                resize();

            array[size] = data;
            size = size + 1;
            return true;
        }

        bool remove(T data) {
            bool found = false;
            unsigned short index = 0;

            for(unsigned short i = 0; i < size; i++)
                if(array[i] == data) {
                    found = true;
                    index = i;
                    break;
                }
            
            if(found) {
                size = size - 1;
                for(unsigned short i = index; i < size; i++)
                    array[i] = array[i + 1];
            }
            return found;
        }
};
#endif