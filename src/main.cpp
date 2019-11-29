#include <iostream>
#include <fstream>
#include <sstream>
#include <ostream>
#include "../include/core.h"

using namespace std;


void
simulate(CPU* cpus,istream & stream, int qCores, int* mainMem)
{
	string linha;
	while (getline(stream, linha)){
		stringstream line(linha);
		string comando;
		line>>comando;
		int addr, core;
		line>>addr>>core;
		if (comando == "read"){
			int cPU = core / 2;
			read(&cpus[cPU], addr, core, mainMem);
		}
		else {
			int info;
			line>> info;
			write(cpus, addr, info, qCores, mainMem);
		}
	}
}

CPU*
buildChip(int qCores, int* mainMem)
{
	mainMem = new int[memSize];
	CPU* chip = new CPU[qCores/2];
	for (int i = 0; i < qCores/2; ++i){
		int l = 0;
		for(; l < l2Size; ++l)
			chip[i].l2[l] = -1;
		for(l = 0; l < l1Size; ++l)
			chip[i].core1.l1[l] = -1;
		for(l = 0; l < l1Size; ++l)
			chip[i].core2.l1[l] = -1;
	}
	for (int i = 0; i < memSize; ++i)
		mainMem[i] = i + 1;
	return chip;
}


int
main(int argc, char** argv){
	int qtdCores;
	cout << "Digite a quantidade de cores: ";
	cin>>qtdCores;
	if (qtdCores % 2 !=0)
		return 1;
	int* mainMem;
	CPU* cpus = buildChip(qtdCores, mainMem);
	if(argv == nullptr)
		simulate(cpus, cin, qtdCores, mainMem);
	else {
		ifstream file;
		file.open(argv[1]);
		simulate(cpus, file, qtdCores, mainMem);
		file.close();
	}
	return 0;
}

