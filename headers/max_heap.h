#ifndef MAX_HEAP
#define MAX_HEAP

#include <vector>
#include <string>
#include <stdexcept>
#include <cstddef>

const std::string maxHeapPeekErrorMessage = "PEEK CALLED ON EMPTY MAX HEAP";
const std::string maxHeapPopErrorMessage = "POP CALLED ON EMPTY MAX HEAP";

template <typename T>
class MaxHeap {
    std::vector<T> vec;

    public:
        MaxHeap() = default;
        bool isEmpty() const noexcept { return vec.empty(); }
        std::size_t getSize() const noexcept { return vec.size(); }

        const T& peek() const {
            if(vec.empty())
                throw std::out_of_range(maxHeapPeekErrorMessage);
            return vec.front();
        }

        T pop() {
            if(vec.empty())
                throw std::out_of_range(maxHeapPopErrorMessage);

            T first = vec.front();
            T last = vec.back();
            vec.pop_back();

            if(vec.empty())
                return first;

            vec[0] = last;
            std::size_t target = 0;
            bool swapped = true;

            while(swapped) {
                std::size_t left = (2 * target) + 1;
                std::size_t right = (2 * target) + 2;
                swapped = ((left < vec.size()) && (vec[left] > vec[target])) || 
                    ((right < vec.size()) && (vec[right] > vec[target]));

                if(swapped) {
                    if((right < vec.size()) && (vec[right] > vec[left])) {
                        T targetVal = vec[target];
                        vec[target] = vec[right];
                        vec[right] = targetVal;
                        target = right;
                    } else {
                        T targetVal = vec[target];
                        vec[target] = vec[left];
                        vec[left] = targetVal;
                        target = left;
                    }
                }
            } 

            return first;
        }

        void push(T val) {
            vec.push_back(val);
            std::size_t i = vec.size() - 1;

            while((i > 0) && (vec[(i - 1)/2] < vec[i])) {
                T self = vec[i];
                vec[i] = vec[(i - 1)/2];
                vec[(i - 1)/2] = self;
                i = (i - 1)/2;
            }
        }
};
#endif