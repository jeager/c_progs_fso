#include <stdio.h>
#include <stdlib.h>
#include "../lib/io.h"
#include "../lib/sort.h"

int main(int argc, char *argv[]){
	if(argc > 3 || argc == 1){
		printf("Wrong number of arguments, use -h for help.\n");
		return 0;
	}
	
	if(strcmp (argv[1],"-h") == 0){
		print_help_message();
		return 0;
	}

	int size;
	if(argc == 2)
		size = atoi(argv[1]);
	else
		size = atoi(argv[2]);

	printf("Please insert %d numbers\n", size);
	int *array = create_numbers_array(size);

	printf("Array inserted: ");
	print_array(array, size);

	if((strcmp (argv[1],"-d") == 0) || argc == 2){
		qsort(array, size, sizeof(int), cmpfunc_asc);
		printf("Array ordered ascendant: ");
	}
	else if(strcmp (argv[1],"-r") == 0){
		qsort(array, size, sizeof(int), cmpfunc_desc);
		printf("Array ordered descendant: ");
	}
	
	
	print_array(array, size);
	return 0;
}
