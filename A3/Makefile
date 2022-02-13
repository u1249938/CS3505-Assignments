CC = g++
CFLAGS = -Wall -fsanitize=undefined -fsanitize=address -g
TrieTest: TrieTest.o Trie.o
	$(CC) $(CFLAGS) -o TrieTest TrieTest.o Trie.o

TrieTest.o: TrieTest.cpp
	$(CC) $(CFLAGS) -c TrieTest.cpp

Trie.o: Trie.cpp Trie.h
	$(CC) $(CFLAGS) -c Trie.cpp

clean:
	rm -f *.o ./TrieTest
