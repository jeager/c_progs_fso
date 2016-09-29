#include "libprimo.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){
	unsigned int num = gera_primo();

	printf("number %u is prime\n", num);

	return 0;
}