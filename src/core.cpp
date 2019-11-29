#include "../include/core.h"
#include <iostream>
using namespace std;

void read(CPU* cpu, int addr, int core, int* mainMem)
{
	if (addr < 0 or addr > 79)
		return;
	int info = mainMem[addr];
	int pInfo = cpu->l2[info%40];
	if (cpu->l2[info% l2Size ] != -1){
		cout << "Substituindo posiçao " << info% l2Size << " por mapeamento direto!" << 
               "\n saindo:" <<cpu->l2[info% l2Size] << " entrando :" << info << endl;
		cpu->l2[info%l2Size] = info;
	}
	else {
		cout << "Escrevendo em lacal vazio " << info % 40
			 << "informação: " << info;
	}	
	if (core == 1){
		if (cpu->core1.l1[ info % l1Size] != -1 )
		{
			cout << "Em core 1 :\n";
			cout << "Substituindo posiçao " << info% l1Size << " por mapeamento direto!" <<
               "\n saindo:" << cpu->core1.l1[info% l1Size] << " entrando :" << info << endl;
			cpu->core1.l1[info% l1Size] = info;
		}
		else {
			cout << "Escrevendo em lacal vazio " << info % 40
				 << "informação: " << info;
		}

	}
}


void write(CPU* cpu, int addr, int info, int qCores,int* mainMem)
{
	int pInfo = mainMem[addr];
	cout << "propagando Informação" << endl;
	mainMem[addr] = info;
	for (int i = 0; i < qCores; i++){
		if (cpu[i].l2[pInfo % l2Size] == pInfo){
			cout << "Referencia a informação encontrada em cache l2 de CPU:" << i << "Substituindo .." << endl;
			cpu[i].l2[pInfo % l2Size] = info % l2Size == pInfo % l2Size ? info : -1;
			if (cpu[i].core1.l1[pInfo % l2Size] == pInfo){
				cout << "Referencia a informação encontrada em cache l1 de core 1 de CPU:" << i << "Substituindo .." << endl;
				cpu[i].core1.l1[pInfo % l1Size] = info % l1Size == pInfo % l1Size ? info : -1;
			}
			if (cpu[i].core2.l1[pInfo % l2Size] == pInfo){
				cout << "Referencia a informação encontrada em cache l1 de core 2 de CPU:" << i << "Substituindo .." << endl;
				cpu[i].core2.l1[pInfo % l1Size] = info % l1Size == pInfo % l1Size ? info : -1;
			}
		}
		cpu[i].l2[info % l2Size] = info;
		cpu[i].core1.l1[info % l1Size] = info;
		cpu[i].core2.l1[info % l1Size] = info;
	}
	
}
