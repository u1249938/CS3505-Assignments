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
        void setIsWord(bool isAWord);
        Node* getBranch(int index);
        void setBranch(int index, Node* newBranch);
        Node(const Node& other);
        Node & operator=(Node& other);
        
    };

private:
    Node root;
    int asciiAdjuster;

public:

    Trie(); // make this default
    void addAWord(std::string word); // word passed is added to the trie, if already in trie don't add
    bool isAWord(std::string word); // if passed an empty string, return false
    std::vector<std::string> allWordsStartingWithPrefix(std::string prefix); // empty prefix should return all words in trie
    void getAllWords(std::vector<std::string>& allWords, Node* current, std::string currentWord);
};

#endif