#include <stdio.h>
#include <stdlib.h>
#include "../lib/io.h"
#include "../lib/sort.h"

int main(int argc, char *argv[]){
	if(argc > 3)
		printf("Wrong number of arguments");

	int size;
	if(argc == 2)
		size = atoi(argv[1]);
	else
		size = atoi(argv[2]);

	int *array = create_numbers_array(size);

	printf("Array inserted: ");
	print_array(array, size);

	if((strcmp (argv[1],"-d") == 0) || argc == 2){
		bubble_sort_asc(array, size);
		printf("Array ordered ascendant: ");
	}
	else if(strcmp (argv[1],"-r") == 0){
		bubble_sort_desc(array, size);
		printf("Array ordered descendant: ");
	}
	
	
	print_array(array, size);
	return 0;
}