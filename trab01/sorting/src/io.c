#include "../lib/io.h"
#include <stdlib.h>
#include <stdio.h>

int check_existing_options(char *argv[]){
	if((strcmp (argv[1],"-d") == 0) || (strcmp (argv[1],"-r") == 0))
		return 1;
	else
		return 0;
}

int *create_numbers_array(int size){
	int *array = (int*)malloc(sizeof(int)*size);
	populate_array(array, size);
	return array;
}

int *populate_array(int *array, int size){
	int count;
	for(count = 0; count < size; count++){
		printf("Insira o número %d: ", count + 1);
		scanf("%d", &array[count]);
	}
}

void print_array(int *array, int size){
	int count;
	for(count = 0; count < size; count++){
		if(count == 0)
			printf("[");
		if(count == size - 1)
			printf("%d]\n",array[count]);
		else
			printf("%d,",array[count]);
	}
}

void print_help_message(){
	printf("The sorting application works with:\n");
	printf("-d crescent order\n");
	printf("-r decrescent order\n");
	printf("-h this helper\n");
	printf("followed by the number of inputs. If no option is provided, the crescent order is used.\n");
}