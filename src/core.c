#include "../include/core.h"
#include <stdlib.h>

typedef struct Core {

	Thread t1;

	Thread t2;

	int * l2;
	
} Core;

Core*
createProcessor(int cCores)
{
	Core* cores = malloc(sizeof(Core)*cCores);
	for(int i = 0; i< cCores; ++i){
		cores[i].t1 = malloc(sizeof(int)*liSize);
		cores[i].t2 = malloc(sizeof(int)*liSize);
		cores[i].l2 = malloc(sizeof(int)*l2Size);
	}
	return cores;
}
