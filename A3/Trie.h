#ifndef Trie_H
#define Trie_H
#include <iostream>
#include <vector>

class Trie 
{
private:
    class Node
    {
    private:
        Node* branches[26];
        bool isWord;

    public:
        Node(bool initIsWord);
        ~Node();
        bool getIsWord();
        Node* getBranch(int index);
        void setBranch(int index, Node* newBranch);
        Node(const Node& other);
        Node & operator=(Node& other);
        
    };

private:
    Node node;

public:

    Trie(); // make this default
    void addAWord(std::string); // word passed is added to the trie, if already in trie don't add
    bool isAWord(std::string); // if passed an empty string, return false
    std::vector<std::string> allWordsStartingWithPrefix(std::string); // empty prefix should return all words in trie
};

#endif