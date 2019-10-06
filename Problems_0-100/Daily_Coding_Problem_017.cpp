/*
This problem was asked by Google.
Suppose we represent our file system by a string in the following manner:
The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:

dir
    subdir1
    subdir2
        file.ext

The directory dir contains an empty sub-directory subdir1 
and a sub-directory subdir2 containing a file file.ext.

The string "dir\n\tsubdir1\n\t\tfile1.ext\n
    \t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:

dir
    subdir1
        file1.ext
        subsubdir1
    subdir2
        subsubdir2
            file2.ext

The directory dir contains two sub-directories subdir1 and subdir2. 
subdir1 contains a file file1.ext and an empty second-level sub-directory 
subsubdir1. subdir2 contains a second-level sub-directory subsubdir2 
containing a file file2.ext.
We are interested in finding the longest (number of characters) absolute 
path to a file within our file system. For example, in the second example 
above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", 
and its length is 32 (not including the double quotes).
Given a string representing the file system in the above format, return 
the length of the longest absolute path to a file in the abstracted file 
system. If there is no file in the system, return 0.

Note:
The name of a file contains at least a period and an extension.
The name of a directory or sub-directory will not contain a period.
*/

#include <algorithm>
#include <iostream>
#include <cassert>
#include <sstream>
#include <string>
#include <vector>

class directoryTree{
private:
    int level;
    bool file;
    std::string dirName;
    directoryTree* parentDir;
    std::vector<directoryTree*> subdirectorys;
public:
    directoryTree() : level(-1), file(false), dirName("*"), parentDir(nullptr){}
    directoryTree(int level, const std::string& dirName, bool isFile, directoryTree* parent) :
        level(level), dirName(dirName), file(isFile), parentDir(parent) {}

    auto parent(){return this->parentDir;}
    auto add(directoryTree* newSubdir){this->subdirectorys.push_back(newSubdir);}
    static auto generateTree(const std::string& path){
        auto split = [](const std::string& str, char delimiter){
            std::vector<std::string> tokens;
            std::string token;
            std::istringstream tokenStream(str);
            while (std::getline(tokenStream, token, delimiter)) tokens.push_back(token);
            return tokens;
        };

        auto tokens = split(path, '\n');
        auto newTree = new directoryTree();
        auto returnTree(newTree);
        directoryTree* nextNode = nullptr;
        int currentLevel = -1;

        std::for_each(tokens.begin(), tokens.end(), 
            [&tokens, &newTree, &nextNode, &currentLevel, &split](const auto& token){
                int tab(0);
                while (token.at(tab) == '\t') tab++;
                if (currentLevel >= tab){
                    int i = currentLevel - tab + 1;
                    while (i--) newTree = newTree->parent();
                }
                if (split(token, '.').size() > 1) 
                    nextNode = new directoryTree(tab, token.substr(tab), true, newTree);
                else nextNode = new directoryTree(tab, token.substr(tab), false, newTree);
                newTree->add(nextNode);
                currentLevel = tab;
                newTree = nextNode;
            }
        );
        return returnTree;
    }

    int longestFilepath() {
        if (this->file) return this->dirName.size();
        if (this->subdirectorys.size() == 0) return 0;
        int maxLength(0);
        std::for_each(this->subdirectorys.begin(), this->subdirectorys.end(),
            [&maxLength](const auto& subdir){
                maxLength = std::max(maxLength, subdir->longestFilepath());
            }
        );
        return this->level < 0 ? maxLength : maxLength + this->dirName.size() + 1;
    }
    ~directoryTree(){for (auto& node : this->subdirectorys) delete node; delete this;}
};

int main(){
    std::string example = "dir\n\tsubdir1\n\t\tfile1.ext\n"\
        "\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
    auto exampleTree = directoryTree::generateTree(example);
    assert(exampleTree->longestFilepath() == 32);
}