#include <iostream>
#include <fstream>
#include <sstream>
#include <ostream>
#include "../include/core.h"

using namespace std;

void
printState(const CPU* cpus, ofstream & os, int i, int qCores, int* mainMem)
{
	os << "==================================================" <<endl;
	os << "Interação "<< i << endl;
	os << "Memoria Principal : "<< endl;;
	for (int j = 0; j < memSize; j++)
		os << mainMem[j] << " ";
	os << endl;
	for (int j = 0; j < qCores; ++j){
		os << "CPU " << j << " cache l2"<< endl;
		for (int l = 0; l < l2Size ; ++l)
			os << cpus[i].l2[l] << " ";
		os << endl << "Core 1 cache l1 "<< endl;
		for (int l = 0; l < l1Size ; ++l)
			os << cpus[i].core1.l1[l] << " ";
		os << endl << "Core 2 cache l1 "<< endl;
		for (int l = 0; l < l1Size ; ++l)
			os << cpus[i].core2.l1[l] << " ";
		os << endl;
	}
	os << "==================================================" <<endl;
}

void
simulate(CPU* cpus,istream & stream, int qCores, int* mainMem)
{
	string linha;
	ofstream log("./log.txt");
	int i = 0;
	while (getline(stream, linha)){
		stringstream line(linha);
		cout << linha << endl;
		string comando;
		line>>comando;
		// read addr core 
		int addr, core;
		line>>addr;
		if (comando == "read"){
			line>>core;
			int cPU = core / 2;
			read(cpus[cPU], addr, core, mainMem);
		}
		else {
			// write addr core info
			int info;
			line>> info;
			write(cpus, addr, info, qCores / 2 , mainMem);
		}
		printState(cpus, log, ++i, qCores, mainMem);
	}
}


CPU*
buildChip(int qCores, int *& mainMem)
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
	if(argv == nullptr){
		simulate(cpus, cin, qtdCores, mainMem);
	}
	else {
		ifstream file;
		file.open(argv[1]);
		simulate(cpus, file, qtdCores, mainMem);
		file.close();
	}
	return 0;
}

