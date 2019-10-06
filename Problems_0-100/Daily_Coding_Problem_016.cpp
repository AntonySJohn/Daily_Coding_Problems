/*
This problem was asked by Twitter.

You run an e-commerce website and want to record the 
last N order ids in a log. Implement a data structure 
to accomplish this, with the following API:

record(order_id): adds the order_id to the log
get_last(i): gets the ith last element from the log. 
    i is guaranteed to be smaller than or equal to N.

You should be as efficient with time and space as possible.
*/

#include <algorithm>
#include <cassert>
#include <list>

class log{
private:
    const int n = 5;
    std::list<int> orderIDs;
public:
    log(int size) : n(size) {}
    auto record(int orderID){
        if (this->orderIDs.size() >= this->n)
            this->orderIDs.pop_back();
        this->orderIDs.emplace_front(orderID);
    }
    auto get_last(int i) const{
        assert(i > 0);
	    std::list<int>::const_iterator it = this->orderIDs.begin();
	    std::advance(it, i-1);
        return *it;
    }
};

int main(){
    log example(4);
    example.record(2);
    example.record(4);
    example.record(6);
    example.record(8);
    example.record(10);
    example.record(12);
    auto a = example.get_last(1);
    auto b = example.get_last(4);
    assert(a == 12 && b == 6);
    return 0;
}