#include "libprimo.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>

int gera_primo(){

	//random seed
	time_t t;
	srand((unsigned) time(&t));
	unsigned int num;
	do{
		// biggest number a unsigned int can be
		num = rand() % 4294967295;
	} while(testa_primo(num) > 0);

	return num;
}

int testa_primo(int prime){
	int test = 2;
	while (test <= (prime / 2)) {
		if (prime % test == 0)
			return 1;
		test = test + 1;
    }
    return 0;
}
