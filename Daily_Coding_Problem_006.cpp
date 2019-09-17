/*
This problem was asked by Google.
An XOR linked list is a more memory efficient doubly linked list.
Instead of each node holding nextElement and prevElement fields, it holds a field 
named both, which is an XOR of the nextElement node and the previous node. 
Implement an XOR linked list; it has an add(node) which adds 
the node to the end, and a get(index) which returns the node at index.

If using a language that has no pointers (such as Python), 
you can assume you have access to get_pointer and dereference_pointer 
functions that converts between nodes and memory addresses.
*/

#include <cstring>
#include <cstddef>
#include <iostream>

template<class C>
class node{
private:
    C value;
    node<C>* both;
    auto xOr(const node<C>*, const node<C>*) const -> node<C>*;
public:
    node() = delete; //explicit forbid of the default constructor
    node(const C& initVal) : value(initVal), both(nullptr) {};
    auto add(const C&) -> void;
    auto get(std::size_t) -> C;
    auto print() -> void;
};

//returns the last entry in the list if the requested index is larger
//then the lists size
template<class C>
C node<C>::get(std::size_t position){
    if (position == 0) return this->value;
    node<C>* prevElement = this, *currentElement = this->both, *nextElement;
    while (--position && (currentElement->both != prevElement)){
        nextElement = this->xOr(prevElement, currentElement->both);  
        prevElement = currentElement;  
        currentElement = nextElement;
    }
    return currentElement->value;
}

template<class C>
node<C>* node<C>::xOr(const node<C>* first, const node<C>* second) const {
    return (node<C>*)((uintptr_t)(first) ^ (uintptr_t)(second));
}

template<class C>
void node<C>::add(const C& value){
    //case there is only 1 element in the list -> 'both' is nullptr
    if (!this->both){
        node<C>* newNode(new node(value));
        this->both = this->xOr(nullptr, newNode);
        newNode->both = this->xOr(this, nullptr);
    //else we need to traverse through the list, to find the last element
    } else {
        node<C>* prevElement = this, *currentElement = this->both, *nextElement;
        while(currentElement->both != prevElement){
            nextElement = this->xOr(prevElement, currentElement->both);  
            prevElement = currentElement;  
            currentElement = nextElement;
        }
        //now we can append the new element and andjust the 'both'-bitfields
        node<C>* newNode(new node(value));
        currentElement->both = this->xOr(prevElement, newNode);
        newNode->both = this->xOr(currentElement, nullptr);
    }
}

template<class C>
void node<C>::print(){
    node<C>* prevElement = nullptr, *currentElement = this, *nextElement;
    while (currentElement){  
        std::cout << currentElement->value << " ";  
        nextElement = this->xOr(prevElement, currentElement->both);  
        prevElement = currentElement;  
        currentElement = nextElement;  
    } 
    std::cout << std::endl;
}

int main(){
    node<int> headOfExampleList(5);
    headOfExampleList.add(206);
    headOfExampleList.add(123);
    headOfExampleList.add(58967);
    headOfExampleList.print();
    std::cout << headOfExampleList.get(2) << std::endl;

    node<std::string> headOfExampleList1("Hello,");
    headOfExampleList1.add("World!");
    headOfExampleList1.add("Here");
    headOfExampleList1.add("is");
    headOfExampleList1.add("my");
    headOfExampleList1.add("xOr");
    headOfExampleList1.add("List!");
    headOfExampleList1.print();
    return 0;
}