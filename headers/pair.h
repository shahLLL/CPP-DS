#ifndef PAIR_H
#define PAIR_H

template <typename T, typename U>
class Pair {
    const T key;
    U value;
    public:
        Pair(T key, U value): key(key), value(value) {}
        T getKey() const { return key; }
        U getValue() const { return value; } 
        void setValue(U value) { this->value = value; }
};

#endif