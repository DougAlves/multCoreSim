#ifndef CORE
#define CORE
#include <string>

const int memSize = 80;
const int l2Size = 40;
const int l1Size = 20;


struct Core {
	int l1[l1Size];
};

struct CPU{
	Core core1;
	Core core2;
	int l2[l2Size];
};

void
read(CPU*, int addr, int core, int* mainMem);

void
write(CPU*, int addr, int info, int qCores,int* mainMem);


#endif
