#ifndef CORE
#define CORE
#include <string>
#define AlphaSize

struct TrieNode{
	TrieNode* filhos[128];
	int terminator;

	inline
	TrieNode():terminator {0}{
	}
};

void inserir(TrieNode*, std::string);

int buscarContar(TrieNode*, std::string);


#endif
