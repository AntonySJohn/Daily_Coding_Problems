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

#include "include/binaryTree.hpp"
#include <memory>
#include <cassert>

int main(){
    using iNode = node<int>;
    auto exampleTree = std::make_shared<iNode>(0, iNode(1), iNode(0, iNode(1, iNode(1), iNode(1)), iNode(0)));
    assert(iNode::univalSubtrees(exampleTree) == 5);
    return 0;
}