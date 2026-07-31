#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <memory>
#include <algorithm>
#include <stdexcept>
#include <string>
#include "graph_node.h"

const std::string graphGetNodeErrorMessage = "NODE NOT FOUND IN GRAPH FOR GET NODE CALL";
const std::string graphAddEdgeErrorMessage = "NODE NOT FOUND IN GRAPH FOR ADD EDGE CALL";
const std::string graphContainsEdgeErrorMessage = "NODE NOT FOUND IN GRAPH FOR ADD EDGE CALL";
const std::string graphRemoveEdgeErrorMessage = "NODE NOT FOUND IN GRAPH FOR REMOVE EDGE CALL";

template <typename T>
class Graph {
    std::vector<std::unique_ptr<GraphNode<T>>> nodes;

    GraphNode<T>* findNode(const T& val) const noexcept {
        auto it = std::find_if(nodes.begin(), nodes.end(),
            [&val](const std::unique_ptr<GraphNode<T>>& n) { return n->getVal() == val; });
        return it != nodes.end() ? it->get() : nullptr;
    }

    public:
        Graph() = default;
        std::size_t getSize() const noexcept { return nodes.size(); }
        bool isEmpty() const noexcept { return nodes.empty(); }

        const GraphNode<T>& getNode(const T& val) const {
            GraphNode<T>* node = findNode(val);
            if (!node)
                throw std::out_of_range(graphGetNodeErrorMessage);
            return *node;
        }

        bool containsNode(const T& val) const noexcept {
            return findNode(val) != nullptr;
        }

        void addNode(const T& val) {
            if (containsNode(val))
                return;
            nodes.push_back(std::make_unique<GraphNode<T>>(val));
        }

        void removeNode(const T& val) {
            GraphNode<T>* target = findNode(val);
            if (!target)
                return;

            for (auto& node : nodes) {
                if (node.get() != target)
                    node->removeNeighbor(target);
            }

            nodes.erase(std::remove_if(nodes.begin(), nodes.end(),
                [target](const std::unique_ptr<GraphNode<T>>& n) { return n.get() == target; }),
                nodes.end());
        }

        bool containsEdge(const T& fromVal, const T& toVal) const {
            GraphNode<T>* from = findNode(fromVal);
            GraphNode<T>* to = findNode(toVal);
            if (!from || !to)
                throw std::out_of_range(graphContainsEdgeErrorMessage);
            return from->isNeighbor(to);
        }

        void addEdge(const T& fromVal, const T& toVal) {
            GraphNode<T>* from = findNode(fromVal);
            GraphNode<T>* to = findNode(toVal);
            if (!from || !to)
                throw std::out_of_range(graphAddEdgeErrorMessage);
            from->addNeighbor(to);
        }

        void removeEdge(const T& fromVal, const T& toVal) {
            GraphNode<T>* from = findNode(fromVal);
            GraphNode<T>* to = findNode(toVal);
            if (!from || !to)
                throw std::out_of_range(graphRemoveEdgeErrorMessage);
            from->removeNeighbor(to);
        }
};

#endif