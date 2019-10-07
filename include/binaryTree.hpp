#include <iostream>
#include <memory>
#include <optional>
#include <queue>

template <class C>
class node {
private:
    C label;
    std::shared_ptr<node<C>> left;
    std::shared_ptr<node<C>> right;

public:
    node(const C& name, std::optional<node<C>>&& leftChild = {},
         std::optional<node<C>>&& rightChild = {})
        : label(name),
          left(leftChild ? std::make_shared<node<C>>(*leftChild) : nullptr),
          right(rightChild ? std::make_shared<node<C>>(*rightChild) : nullptr) {}
    inline auto getLabel() const -> C { return this->label; }
    inline auto getLeft() const -> std::shared_ptr<node<C>> { return this->left; }
    inline auto getRight() const -> std::shared_ptr<node<C>> { return this->right; }
    inline auto setLeft(std::shared_ptr<node<C>> leftChild) { this->left = leftChild; }
    inline auto setRight(std::shared_ptr<node<C>> rightChild) { this->right = rightChild; }
    auto serialize() const -> std::string;
    static auto deserialize(std::string) -> std::shared_ptr<node<C>>;
    static auto _deserialize(std::queue<std::string>&) -> std::shared_ptr<node<C>>;
    static auto univalSubtrees(const std::shared_ptr<node<C>>&) -> int;
};

// only works for data-types that support the equality-operator
template <class C>
int node<C>::univalSubtrees(const std::shared_ptr<node<C>>& root) {
    if (!root) return 0;
    if (!root->getLeft() && !root->getRight()) return 1;
    if (!root->getLeft() && (root->getLabel() == root->getRight()->getLabel()))
        return 1 + node::univalSubtrees(root->getRight());
    if (!root->getRight() && (root->getLabel() == root->getLeft()->getLabel()))
        return 1 + node::univalSubtrees(root->getLeft());
    if (root->getLabel() == root->getLeft()->getLabel() &&
        root->getLabel() == root->getRight()->getLabel())
        return 1 + node::univalSubtrees(root->getLeft()) + node::univalSubtrees(root->getRight());
    else
        return node::univalSubtrees(root->getLeft()) + node::univalSubtrees(root->getRight());
}

// recursively building up the tree again
template <class C>
std::shared_ptr<node<C>> node<C>::_deserialize(std::queue<std::string>&) {}
template <>
std::shared_ptr<node<std::string>> node<std::string>::_deserialize(std::queue<std::string>& tree) {
    std::shared_ptr<node<std::string>> newNode;
    if (!tree.empty()) {
        std::string label(tree.front());
        tree.pop();
        if (label != "#") {
            newNode = std::make_shared<node<std::string>>(label);
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
template <class C>
std::shared_ptr<node<C>> node<C>::deserialize(std::string) {}
template <>
std::shared_ptr<node<std::string>> node<std::string>::deserialize(std::string tree) {
    std::string temp;
    std::queue<std::string> list;
    for (char& ch : tree) {
        if (ch == ' ') {
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
template <class C>
std::string node<C>::serialize() const {
    std::cerr << "Cannot serialize tree - missing template specialization";
    return "";
}
template <>
std::string node<std::string>::serialize() const {
    // case the current node has no children
    if (!this->left && !this->right) {
        return this->label + " # #";
    }
    // case the current node only has a left children
    if (this->left && !this->right) {
        return this->label + ' ' + this->left->serialize() + " #";
    }
    // case the current node only has a right children
    if (!this->left && this->right) {
        return this->label + " # " + this->right->serialize();
    }
    // build the string recursively
    return this->label + ' ' + this->left->serialize() + ' ' + this->right->serialize() + ' ';
}