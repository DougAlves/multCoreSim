#ifndef CORE
#define CORE
#include <string>
#define AlphaSize
#define memSize 80

int mainMem[80];

struct Core {
	int l1[20];
};

struct CPU{
	Core core1;
	Core Core2;
	int l2[40];
};

void read(CPU*, int addr, int core);

void write(CPU*, int addr, int core, int info);


#endif
