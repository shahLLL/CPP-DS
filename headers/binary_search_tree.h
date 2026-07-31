#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <memory>
#include <climits>
#include "binary_tree_node.h"

template <typename T>
class BinarySearchTree {
    std::unique_ptr<BinaryTreeNode<T>> root;
    unsigned short size;
    const unsigned short maxCapacity = USHRT_MAX;

    public:
        BinarySearchTree(): root(nullptr), size(0) {}
        unsigned short getSize() const noexcept { return size; }
        bool isEmpty() const noexcept { return size == 0; }

        bool contains(T val) const noexcept {
            BinaryTreeNode<T> *itr = root.get();
            while(itr) {
                if(itr->getVal() == val) return true;

                if(itr->getVal() < val) {
                    itr = itr->getRight();
                } else {
                    itr = itr->getLeft();
                }
            }
            return false;
        }

        bool add(T val) {
            if(size == maxCapacity) return false;
            
            if(!root) { 
                root = std::make_unique<BinaryTreeNode<T>>(val);
                size = size + 1;
                return true;
            }

            BinaryTreeNode<T> *itr = root.get();
            while(true) {
                if(val > itr->getVal()) {
                    if(itr->hasRight()) {
                        itr = itr->getRight();
                    } else {
                        itr->setRight(val);
                        break;
                    }
                } else {
                    if(itr->hasLeft()) {
                        itr = itr->getLeft();
                    } else {
                        itr->setLeft(val);
                        break;
                    }
                }
            }

            size = size + 1;
            return true;
        }

        bool remove(T val) {
            
        }
};

#endif