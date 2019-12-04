#ifndef CORE
#define CORE
#include <string>
/// Constantes que definem o tamanhos da memória pricipal e das memórias cache

const int memSize = 80;
const int l2Size = 40;
const int l1Size = 20;

struct Core {
	int l1[l1Size];
};

/** Estrutura que define a hierarquia de memória de um processador 
	com uma cache l2 pública e cada core da CPU tem uma memória l1 privada
 */
struct CPU{
	Core core1;
	Core core2;
	int l2[l2Size];
};

/**
   função que carrega as informações da mémoria pricipal para a l1 do core que a solicitou,
   passando também pela l2 da CPU em que o core está
 */
void
read(CPU&, int addr, int core, int* mainMem);

/**
   Função que escreve na mémoria principal e atualiza nas mémorias cache todas as referências a informação antiga
 */
void
write(CPU*, int addr, int info, int qCores,int* mainMem);


#endif
