#include "../include/core.h"
#include <iostream>
using namespace std;

void
read(CPU* cpu, int addr, int core, int *& mainMem)
{
	if (addr < 0 or addr > 79)
		return;
	int info = mainMem[addr]; // informação a ser carregada

	int pInfo = cpu->l2[ info % l2Size ]; // informação que está no lugar onde a informação nova vai ser escrita

	if (cpu->l2[ info % l2Size ] != -1){ // se a posição pra escrita não estiver vazia substituo 
		cout << "Substituindo posiçao " << info % l2Size << " por mapeamento direto!" << 
               "\n saindo:" <<cpu->l2[info% l2Size] << " entrando :" << info << endl;
		cpu->l2[info%l2Size] = info;
	}

	else {
		cout << "Escrevendo em lacal vazio " << info % 40 << endl// se não simplesmente escrevo a informação
			 << "informação: " << info << endl;
		cpu->l2[info%l2Size] = info;
	}	

	if (core == 1){ // para saber em qual core da cpu a informação será escrita 
	  
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
	else {
		if (cpu->core2.l1[ info % l1Size] != -1 )
		{
			cout << "Em core 1 :\n";
			cout << "Substituindo posiçao " << info% l1Size << " por mapeamento direto!" <<
               "\n saindo:" << cpu->core2.l1[info% l1Size] << " entrando :" << info << endl;
			cpu->core1.l1[info% l1Size] = info;
		}
		else {
			cout << "Escrevendo em lacal vazio " << info % 40
				 << "informação: " << info << endl;
			cpu->core2.l1[info % l1Size] = info;
		}
	}
}


void
write(CPU* cpu, int addr, int info, int qCPU, int *& mainMem)
{
	int pInfo = mainMem[addr]; //informação antiga para poder localizar o endereço a ser atualizado
	cout << "propagando Informação" << endl;
	mainMem[addr] = info; // escrevendo a nova informação no lugar solicitado
	for (int i = 0; i < qCPU; i++){ // for para percorrer todos as cpus do chip
		if (cpu[i].l2[ pInfo % l2Size ] == pInfo){ //para saber se informação antiga está na l2 da CPU atual, se sim substitue por -1
			cout << "Referencia a informação encontrada em cache l2 de CPU:" << i << "Substituindo .." << endl;
			cpu[i].l2[pInfo % l2Size] = info % l2Size == pInfo % l2Size ? info : -1;
			if (cpu[i].core1.l1[pInfo % l2Size] == pInfo){//para saber se informação antiga está na l1 do core atual, se sim substitue por -1
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
