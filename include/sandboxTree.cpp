#include <cassert>
#include <memory>
#include <string>
#include "binaryTree.hpp"

int main() {
    using sNode = node<std::string>;
    auto exampleStringTree =
        std::make_unique<sNode>("root", sNode("left", sNode("left.left")), sNode("right"));
    assert(sNode::deserialize(exampleStringTree->serialize())->getLeft()->getLeft()->getLabel() ==
           "left.left");

    using iNode = node<int>;
    auto exampleIntTree =
        std::make_shared<iNode>(0, iNode(1), iNode(0, iNode(1, iNode(1), iNode(1)), iNode(0)));
    assert(iNode::univalSubtrees(exampleIntTree) == 5);
}