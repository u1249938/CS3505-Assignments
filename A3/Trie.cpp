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

bool Trie::Node::getIsWord()
{
    return isWord;
}

Trie::Node::Node* Trie::Node::getBranch(int index)
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
//-----------------------End of Node Class-------------------------