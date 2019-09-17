/*
This problem was asked by Google.
A unival root (which stands for "universal value")
is a root where all nodes under it have the same value.
Given the root to a binary root, 
count the number of unival subtrees.

For example, the following root has 5 unival subtrees:

          0
         / \
        1   0
           / \
          1   0
         / \
        1   1
*/

#include <memory>
#include <cassert>
#include <optional>
#include <iostream>

// Just my simple implementation of a binary root
class node{
private:
    int label;
    std::shared_ptr<node> left;
    std::shared_ptr<node> right;
public:
    node(const int& name,
            const std::optional<node>& leftChild = {},
            const std::optional<node>& rightChild = {}) : 
        label(name), 
        left(leftChild ? std::make_shared<node>(*leftChild) : nullptr), 
        right(rightChild ? std::make_shared<node>(*rightChild) : nullptr) {}
    inline auto getLabel() const -> int {return (this->label);}
    inline auto getLeft() const -> std::shared_ptr<node> {return this->left;}
    inline auto getRight() const -> std::shared_ptr<node> {return this->right;}
    inline auto setLeft(std::shared_ptr<node> leftChild)  {this->left = leftChild;}
    inline auto setRight(std::shared_ptr<node> rightChild)  {this->right = rightChild;}
    static int univalSubtrees(const std::shared_ptr<node>& root){
        if (!root) return 0;
        if (!root->getLeft() && !root->getRight()) return 1;
        if (!root->getLeft() && (root->getLabel() == root->getRight()->getLabel()))
            return 1 + node::univalSubtrees(root->getRight());
        if (!root->getRight() && (root->getLabel() == root->getLeft()->getLabel()))
            return 1 + node::univalSubtrees(root->getLeft());
        if (root->getLabel() == root->getLeft()->getLabel() && root->getLabel() == root->getRight()->getLabel())
            return 1 + node::univalSubtrees(root->getLeft()) + node::univalSubtrees(root->getRight());
        else return node::univalSubtrees(root->getLeft()) + node::univalSubtrees(root->getRight());
    }
};

int main(){
    auto exampleTree = std::make_shared<node>(0, node(1), node(0, node(1, node(1), node(1)), node(0)));
    assert(node::univalSubtrees(exampleTree) == 5);
    return 0;
}