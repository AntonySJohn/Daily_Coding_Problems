/*
This problem was asked by Google.
Given the root to a binary tree, implement serialize(root), which serializes
the tree into a string, and deserialize(s), which deserializes the string back
into the tree.

For example, given the following Node class
    class Node:
        def __init__(self, val, left=None, right=None):
            self.val = val
            self.left = left
            self.right = right

The following test should pass:
    node = Node('root', Node('left', Node('left.left')), Node('right'))
    assert deserialize(serialize(node)).left.left.val == 'left.left'
*/

#include "include/binaryTree.hpp"
#include <cassert>
#include <string>
#include <memory>

int main()
{
    //          "root"                                                            "root"
    //         /     \                                                           /     \ 
    //    "left"    "right"  -> "root left left.left # # # right # # " ->   "left"    "right"
    //      /                                                                 /
    // "left.left"                                                       "left.left"
    
    using sNode = node<std::string>;
    auto root = std::make_shared<sNode>("root", sNode("left", sNode("left.left")), sNode("right"));
    assert(sNode::deserialize(root->serialize())->getLeft()->getLeft()->getLabel() == "left.left");
    return 0;
}