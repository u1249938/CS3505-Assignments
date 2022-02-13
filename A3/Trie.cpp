#include <iostream>
#include <vector>
#include "Trie.h"

//----------------------Node Class---------------------------------
Trie::Node::Node(bool initIsWord) : isWord(initIsWord)
{
    for (int index = 0; index < sizeof(branches); index++)
    {
        Node* ptr = nullptr;
        branches[index] = ptr;
    }
}

Trie::Node::~Node()
{
    for(int index = 0; index < sizeof(branches); index++)
    {
        delete branches[index];
    }
}

bool Trie::Node::getIsWord()
{
    return isWord;
}

Trie::Node* Trie::Node::getBranch(int index)
{
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

    for (int index = 0; index < sizeof(branches); index++)
    {
        branches[index] = nullptr;
    }

    for (int index = 0; index < sizeof(other.branches); index++)
    {
        if (other.branches[index])
        {
            branches[index] = new Node(*(other.branches[index]));
        }
    }
}

Trie::Node & Trie::Node::operator=(Node& other)
{
    std::swap(isWord, other.isWord);

    for (int index = 0; index < sizeof(branches); index++)
    {
        branches[index] = nullptr;
    }
    
    for (int index = 0; index < sizeof(other.branches); index++)
    {
        std::swap(branches[index], other.branches[index]);
    }

    return *this;
}

//-----------------------End of Node Class-------------------------

//-----------------------Trie Class--------------------------------
Trie::Trie() : node(new Node(false)) { }

