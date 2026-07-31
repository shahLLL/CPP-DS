#ifndef BINARY_TREE_NODE_H
#define BINARY_TREE_NODE_H

#include <memory>

template <typename T>
class BinaryTreeNode {
    const T val;
    std::unique_ptr<BinaryTreeNode<T>> left;
    std::unique_ptr<BinaryTreeNode<T>> right;
    public:
        BinaryTreeNode(T val): val(val), left(nullptr), right(nullptr) {}
        const T& getVal() const noexcept { return val; }
        bool hasLeft() const noexcept { return left != nullptr; }
        bool hasRight() const noexcept { return right != nullptr; }
        BinaryTreeNode<T> *getLeft() const noexcept { return left.get(); }
        BinaryTreeNode<T> *getRight() const noexcept { return right.get(); }
        void setLeft(T val) { left = std::make_unique<BinaryTreeNode<T>>(val); }
        void setLeft(std::unique_ptr<BinaryTreeNode<T>> newLeft) noexcept { left = std::move(newLeft); }
        void setRight(T val) { right = std::make_unique<BinaryTreeNode<T>>(val); }
        void setRight(std::unique_ptr<BinaryTreeNode<T>> newRight) noexcept { right = std::move(newRight); }
};

#endif