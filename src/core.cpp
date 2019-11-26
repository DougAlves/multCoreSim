#include "../include/core.h"
#include <iostream>


void inserir(TrieNode* root, std::string key){
	TrieNode* it = root;
	for (int i = 0; i < key.length(); i++){
		char c = key[i];
		if ( it->filhos[c] == nullptr)
			it->filhos[c] = new TrieNode();
		it = it->filhos[c];
	}
	it->terminator++;
}

int buscarContar(TrieNode* root, std::string key){
	TrieNode* it = root;
	for (char c : key){
		if (it->filhos[c] == nullptr)
			return 0;
		it = it->filhos[c];
	}
	return it->terminator;
}
