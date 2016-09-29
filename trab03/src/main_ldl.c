#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <dlfcn.h>

int main(){

	void* my_lib = dlopen("q03/lib/libprimo.so", RTLD_LAZY);
	
	if (!my_lib) {
        fputs (dlerror(), stderr);
        exit(1);
    }
	unsigned int (*gera_primo)() = dlsym(my_lib,"gera_primo");
  	unsigned int num = gera_primo();


	printf("number %u is prime\n", num);

	return 0;
}