/*
This problem was asked by Twitter.
Implement an autocomplete system. That is, given a query string s and a set of 
all possible query strings, return all strings in the set that have s as a prefix.

For example, given the query string de and the set of 
strings [dog, deer, deal], return [deer, deal].

Hint: Try preprocessing the dictionary into a more 
efficient data structure to speed up queries.
*/

/*
    Following the hint, i convert the dictionary into a prefix tree
*/

#include <unordered_map>
#include <iostream>
#include <vector>
#include <string>
#include <stack>

std::ostream& operator<<(std::ostream& os, const std::vector<std::string>& vec){
    for (const auto& entry : vec){
        if (&entry == &vec.back()) {
            os << entry << "]";
            break;
        }
        if (&entry == &vec.front()) {
            os << "[";
        }
        os << entry << ", ";
    }
}

class prefixTree{
private:
    char label = 0;
    bool leafNode = false;
    prefixTree* parent = nullptr;
    std::unordered_map<char, prefixTree*> children;
    auto getLabel() -> char {return this->label;}
    auto getParent() -> prefixTree* {return this->parent;}
    auto _collectStrings(std::vector<std::string>&) -> void;
public:
    prefixTree(){};
    prefixTree(char c, prefixTree* parent) : label(c), parent(parent){};
    auto insert(const std::string&) -> void;
    auto substringMatches(const std::string&) -> std::vector<std::string>;
    ~prefixTree(){
        //WARNING: For large Trees the stack-space for this
        // destructor wont be enough (maybe change it to iterative deeletion)
        for (auto& i : children){
            delete i.second;
        }
    }
};

void prefixTree::_collectStrings(std::vector<std::string>& vec){
    if(this->leafNode){
        std::string stringTemp;
        std::stack<char> stackTemp;
        prefixTree* itr = this;
        while (itr->getParent()){
            stackTemp.push(itr->getLabel());
            itr = itr->getParent();
        }
        while (!stackTemp.empty()){
            stringTemp += stackTemp.top();
            stackTemp.pop();
        }
        vec.push_back(stringTemp);
        return;
    }
    for(auto& child : this->children){
        child.second->_collectStrings(vec);
    }
}

std::vector<std::string> prefixTree::substringMatches(const std::string& word){
    prefixTree* curr = this;
    for (auto& ch : word){
        if (curr->children.find(ch) == curr->children.end()){
            return {};
        }
        curr = curr->children[ch];
    }
    std::vector<std::string> result;
    curr->_collectStrings(result);
    return result;
}

void prefixTree::insert(const std::string& newEntry){
	prefixTree* curr = this;
    for (auto& ch : newEntry){
        if (curr->children.find(ch) == curr->children.end()){
            curr->children[ch] = new prefixTree(ch, curr);
        }
        curr = curr->children[ch];
    }
	curr->leafNode = true;
}

int main(){
    std::vector<std::string> dict = {"dog", "deer", "deal"};
    prefixTree example;
    
    for (auto& entry : dict){
        example.insert(entry);
    }

    std::cout << example.substringMatches("de") << std::endl;

    return 0;
}