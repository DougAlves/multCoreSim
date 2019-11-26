#include <iostream>
#include <fstream>
#include <sstream>
#include "../include/core.h"

using namespace std;
void replaceComa(std::string & str)
{
	for(int i = 0; i < str.length(); i++){
		str[i] = str[i] == ',' ? ' ' : str[i];
	}
}

TrieNode* buildTrie(char* path)
{
	TrieNode* root = new TrieNode();
	std::fstream file;
	file.open(path);
	std::string line;
	while (getline(file, line)){
		if (line[0] == '#')
			continue;
		if (line.back() == ':'){
			std::string test = line.substr(0, line.length() - 1);
			std::cout << test << std::endl;
			inserir(root,test);
			continue;
		}
		cout << line << endl;
		replaceComa(line);
		cout << line << endl;
		std::stringstream st(line);
		string inst;
		while (st>>inst){
			if (inst[0] >= '0' && inst[0] <='9')
				continue;
			inserir(root, inst);
			std::cout << inst <<std::endl;
		}
	}
	return root;
}


int main(int argc, char** argv){
	TrieNode* pedro = buildTrie(argv[1]);
	cout << buscarContar(pedro, "add");
	return 0;
}

