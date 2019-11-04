#ifndef CORE
#define CORE

#define l1Size 100
#define l2Size 500

typedef int* Thread;

typedef Core* CPU;

typedef struct Core {

	Thread t1;

	Thread t2;

	int * l2;
	
} Core;

// This function writes a info in a memory addres, mapping 
void
write(Core*, int, int);

// This function reads a info.
void
read(Core*, int);

// generate a processor 
CPU
createProcessor(int cCores)
#endif
