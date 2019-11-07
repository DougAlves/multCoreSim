#ifndef CORE
#define CORE

#define l1Size 100
#define l2Size 500

typedef struct {
	int isEmpty;
	int data;
} Data;

typedef Data* Thread;

typedef struct {
	Thread t1;
	Thread t2;
	int * l2;
} Core;

typedef Core* CPU;

// This function writes a info in a memory addres, mapping 
void
write(Core*, int, int, int);

// This function reads a info.
void
read(Core*, int, int);

// generate a processor 
CPU
createProcessor(int cCores);

#endif
