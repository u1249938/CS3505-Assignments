#include "Trie.h";
#include <iostream>
#include <fstream>
#include <vector>


void readInTrie(Trie& newTrie, std::string filename)
{
    std::ifstream createTrieFile(filename);
    std::string currentLine;
    if (createTrieFile.is_open())
    {
        while (createTrieFile.good())
        {
            createTrieFile >> currentLine;
            newTrie.addAWord(currentLine);
        }
    }
    else
    {
        std::cout << "Could Not Find File";
    }
}

void testTrieAgainstWordsInFile(Trie& myTrie, std::string filename)
{
    std::ifstream testFile(filename);
    std::string currentLine;
    if (testFile.is_open())
    {
        while (testFile.good())
        {
            testFile >> currentLine;
            bool isInTrie = myTrie.isAWord(currentLine);
            if (isInTrie)
            {
                std::cout << currentLine << " is found" << std::endl;
            }
            else
            {
                std::cout << currentLine << " is not found, do you mean:" << std::endl;
                std::vector<std::string> relatedWords = myTrie.allWordsStartingWithPrefix(currentLine);
                if (relatedWords.size() == 0)
                {
                    std::cout << "   no alternatives found" << std::endl;
                }
                else 
                {
                    for (int index = 0; index < relatedWords.size(); index++)
                    {
                        std::cout << "   " << relatedWords[index] << std::endl;
                    }
                }
            }
        }
    }
    else
    {
        std::cout << "Could Not Find File";
    }
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        std::cout << "Incorrect Number of Arguments";
        return 0;
    }

    Trie newTrie;
    readInTrie(newTrie, argv[1]);
    testTrieAgainstWordsInFile(newTrie, argv[2]);
    return 0;
}

