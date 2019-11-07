#include "../include/core.h"
#include <stdlib.h>


CPU
createProcessor(int cCores)
{
	Core* cores = malloc(sizeof(Core)*cCores);
	for(int i = 0; i< cCores; ++i){
		cores[i].t1 = malloc(sizeof(int)*l1Size);
		cores[i].t2 = malloc(sizeof(int)*l1Size);
		cores[i].l2 = malloc(sizeof(int)*l2Size);
	}
	return cores;
}

void
write( Core* cores, int core, int addr, int info ){
	
}
