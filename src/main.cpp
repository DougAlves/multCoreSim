#include <iostream>
#include <fstream>
#include <sstream>
#include <ostream>
#include "../include/core.h"

using namespace std;
void simulate(CPU* cpus, ostream & os, int qCores)
{
	string linha;
	while (getline(os, linha)){
		sstream line(linha);
		string comando;
		line>>comando;
		int addr, core;
		line>>addr>>core;
		int cPU = core / 2;
		if (comando == "read"){
			read(&cpus[cPU], addr, core);
		}
		else {
			int info;
			line>> info;
			write(&cpus[cPU], addr, core, info);
		}
	}
}

CPU* buildTrie(char* path)
{
}


int main(int argc, char** argv){
	ostream stream;
	if(argv == nullptr)
		stream = cin;
	else {
		fstream file;
		file.open(argv[1]);
		stream = file;
	}
	int qtdCores;

	stream>>qtdCores;
	if (qtdCores % 2 !=0)
		return 1;

	CPU* cpus = new CPU[qtdCores];
	simulate(cpus, stream, qtdCores);
	stream.close();
	return 0;
}

