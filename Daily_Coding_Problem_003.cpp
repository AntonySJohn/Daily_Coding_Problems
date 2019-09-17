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

#include <string>
#include <memory>
#include <optional> 
#include <algorithm>
#include <iostream>
#include <queue>
#include <cassert>

class node{
private:
    std::string label;
    std::shared_ptr<node> left;
    std::shared_ptr<node> right;
public:
    node(const std::string& name,
            const std::optional<node>& leftChild = {},
            const std::optional<node>& rightChild = {}) : 
        label(name), 
        left(leftChild ? std::make_shared<node>(*leftChild) : nullptr), 
        right(rightChild ? std::make_shared<node>(*rightChild) : nullptr) {}
    auto serialize() const -> std::string;
    static auto deserialize(std::string) -> std::shared_ptr<node>;
    static auto _deserialize(std::queue<std::string>&) -> std::shared_ptr<node>;
    inline auto getLabel() const -> std::string {return this->label;}
    inline auto getLeft() const -> std::shared_ptr<node> {return this->left;}
    inline auto getRight() const -> std::shared_ptr<node> {return this->right;}
    inline auto setLeft(std::shared_ptr<node> leftChild) {this->left = leftChild;}
    inline auto setRight(std::shared_ptr<node> rightChild) {this->right = rightChild;}
};

// recursively building up the tree again
std::shared_ptr<node> node::_deserialize(std::queue<std::string>& tree){
    std::shared_ptr<node> newNode;
    if (!tree.empty()){
        std::string label(tree.front());
        tree.pop();
        if (label != "#"){
            newNode = std::make_shared<node>(label);
            newNode->setLeft(_deserialize(tree));
            newNode->setRight(_deserialize(tree));
        } else {
            newNode = nullptr;
        }
    }
    return newNode;
}

// for more simplicity when rebuilding the tree, adding all
// the labels and empty leaves into a queue
std::shared_ptr<node> node::deserialize(std::string tree){
    std::string temp;
    std::queue<std::string> list;
    for (char& ch : tree){
        if (ch == ' '){
            list.push(temp);
            temp.clear();
        } else {
            temp += ch;
        }
    }
    list.push(temp);
    return _deserialize(list);
}

// storing the tree in preordered way
// string encodings:
//      ' ' - seperates leaves
//      '#' - represent an empty leave
std::string node::serialize() const {
    // case the current node has no children
    if (!this->left && !this->right){
        return this->label + " # #";
    }
    // case the current node only has a left children
    if (this->left && !this->right){
        return this->label + ' ' + this->left->serialize() + " #";
    }
    // case the current node only has a right children
    if (!this->left && this->right){
        return this->label + " # " + this->right->serialize();
    }
    // build the string recursively
    return this->label + ' ' + this->left->serialize() + ' ' + this->right->serialize() + ' ';
}

int main()
{
    //          "root"                                                            "root"
    //         /     \                                                           /     \ 
    //    "left"    "right"  -> "root left left.left # # # right # # " ->   "left"    "right"
    //      /                                                                 /
    // "left.left"                                                       "left.left"

    auto root = std::make_shared<node>("root", node("left", node("left.left")), node("right"));
    assert(node::deserialize(root->serialize())->getLeft()->getLeft()->getLabel() == "left.left");
    return 0;
}