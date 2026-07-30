#ifndef GRAPH_NODE_H
#define GRAPH_NODE_H

#include <vector>
#include <algorithm>

template <typename T>
class GraphNode {
    T val;
    std::vector<GraphNode<T>*> neighbors;

    public:
        explicit GraphNode(T val): val(std::move(val)) {}

        const T& getVal() const noexcept { return val; }
        const std::vector<GraphNode<T>*>& getNeighbors() const noexcept { return neighbors; }

        void addNeighbor(GraphNode<T>* neighbor) {
            neighbors.push_back(neighbor);
        }

        void removeNeighbor(GraphNode<T>* neighbor) {
            neighbors.erase(
                std::remove(neighbors.begin(), neighbors.end(), neighbor),
                neighbors.end()
            );
        }

        bool isNeighbor(const GraphNode<T>* neighbor) const noexcept { 
            return std::find(neighbors.begin(), neighbors.end(), 
                neighbor) != neighbors.end();
        }
};

#endif