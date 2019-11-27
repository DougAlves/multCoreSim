#include "../include/core.h"
#include <iostream>


void read(CPU* cpu, int addr, int core)
{
	if (addr < 0 or addr > 79)
		return;
	int info = mainMem[addr];
	if (cpu->l2[info%40] != -1;){
		cout << "Substituindo posiçao " << info%40 << " por mapeamento direto!
               \n saindo:" <<cpu->l2[info%40] << " entrando :" << info << endl;
		cpu->l2[info%40] = info;
	}
	else {
		cout << "Escrevendo em lacal vazio " << info % 40
			 << "informação: " << info
	}	
}

void write(CPU*, int addr, int core, int info)
{
}
