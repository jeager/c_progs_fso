#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>

struct timespec start, stop;

// high precision time check
void get_time(){
	uint64_t delta_us = (stop.tv_sec - start.tv_sec) * 1000000 + (stop.tv_nsec - start.tv_nsec) / 1000;
	printf("Took %" PRIu64 "ms\n", delta_us);
	//printf("took %lu\n", delta_us);
}

void set_start(){
	clock_gettime(CLOCK_MONOTONIC_RAW, &start);
}

void set_stop(){
	clock_gettime(CLOCK_MONOTONIC_RAW, &stop);
}


void fill_array(int size, int * w){
	int i;
	for(i = 0; i < size; i++){
		w[i] = 1;
	}
}

void compare(int size, int *w, int *x){
	int i,j;
	for(i = 0; i < size; i++){
		for(j = i + 1; j < size; j++){
			printf("\nCompares x[%d] = %d and x[%d] = %d",i,x[i], j, x[j]);
			if(x[i] < x[j]){
				w[i] = 0;
			}
			else{
				w[j] = 0;
			}
		}
	}
}

void search(int size, int *w, int *x){
	int i;
	for(i = 0; i < size; i++){
		if(w[i] == 1){
			printf("\nMaximum: %d\nPosition: %d\n", x[i], i + 1);
			break;
		}
	}
}

int main(int argc, char *argv[]){
	set_start();
	int size = atoi(argv[1]);

	printf("Number of input values: %d\n", size);
	int x[size];
	int w[size];
	int i;

	printf("Input values: ");
	for(i = 0; i < size; i++){
		x[i] = atoi(argv[i+2]);
		printf("%d ", x[i]);
	}
	

	fill_array(size, w);
	printf("\nAfter Initialization: ");
	for(i = 0; i < size; i++){
		printf("%d ", w[i]);
	}

	compare(size,w,x);

	printf("\nAfter Comparsion: ");
	for(i = 0; i < size; i++){
		printf("%d ", w[i]);
	}

	search(size,w,x);
	set_stop();
	get_time();

	return 0;
}

