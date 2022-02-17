#include <iostream>
#include <vector>
#include "Trie.h"

//----------------------Node Class---------------------------------
Trie::Node::Node(bool initIsWord) : isWord(initIsWord)
{
    for (int index = 0; index < 26; index++)
    {
        branches[index] = nullptr;
    }
}

Trie::Node::~Node()
{
    for(int index = 0; index < 26; index++)
    {
        delete branches[index];
    }
}

bool Trie::Node::getIsWord()
{
    return isWord;
}

void Trie::Node::setIsWord(bool isAWord)
{
    isWord = isAWord;
}

Trie::Node* Trie::Node::getBranch(int index)
{
    if (index > 25 || index < 0)
    {
        return 0;
    }
    if (!branches[index])
    {
        return nullptr;
    }
    return branches[index];
}

// will not set new branch if one already exitists
void Trie::Node::setBranch(int index, Node* newBranch)
{
    if (branches[index] == nullptr)
    {
        return;
    }
    branches[index] = newBranch;
}

Trie::Node::Node(const Node& other)
{
    isWord = other.isWord;
    for (int index = 0; index < 26; index++)
    {
        branches[index] = nullptr;

        if (other.branches[index])
        {
            branches[index] = new Node(*(other.branches[index]));
        }
    }
}

Trie::Node & Trie::Node::operator=(Node& other)
{
    std::swap(isWord, other.isWord);
    
    for (int index = 0; index < 26; index++)
    {
        std::swap(branches[index], other.branches[index]);
    }

    return *this;
}

//-----------------------End of Node Class-------------------------

//-----------------------Trie Class--------------------------------
Trie::Trie() : root(new Node(false)), asciiAdjuster('a') { }

void Trie::addAWord(std::string word)
{
    Node *current = &root;
    for (int index = 0; index < word.length(); index++)
    {
        int position = word[index] - asciiAdjuster;
        if (!(current->getBranch(position)))
        {
            current->setBranch(position, new Node(false));
        }
        if (index == word.length() - 1)
        {
            current->setIsWord(true);
        }

        current = current->getBranch(position);
    }
}

bool Trie::isAWord(std::string word)
{
    Node* current = &root;
    for (int index = 0; index < word.length(); index++)
    {
        int character = word[index] - asciiAdjuster;
        if (!(current->getBranch(character)))
        {
            return false;
        }
        else
        {
            current = current->getBranch(character);
        }
    }
    if (!(current->getIsWord()))
    {
        return false;
    }
    
    return true;
}

std::vector<std::string> Trie::allWordsStartingWithPrefix(std::string prefix)
{
    std::vector<std::string> allWords;
    Node* current = &root;
    for (int index = 0; index < prefix.length(); index++)
    {
        int character = prefix[index] - asciiAdjuster;
        if (!(current->getBranch(character)))
        {
            return allWords;
        }
        else
        {
            current = current->getBranch(character);
        }
    }
    if (current->getIsWord())
    {
        allWords.push_back(prefix);
    }
    getAllWords(allWords, current, prefix);
    return allWords;
}

void Trie::getAllWords(std::vector<std::string>& allWords, Node* current, std::string currentWord)
{
    int numOfLetters = 26;
    for (int index = 0; index < numOfLetters; index++)
    {
        if (current->getIsWord())
        {
            currentWord = currentWord + char(index + asciiAdjuster);
            allWords.push_back(currentWord);
        }
        if (current->getBranch(index))
        {
            current = current->getBranch(index);
            getAllWords(allWords, current, currentWord);
            currentWord = currentWord + char(index + asciiAdjuster);
        }
    }
}

