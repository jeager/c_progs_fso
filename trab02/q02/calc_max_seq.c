#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdint.h>
#include <inttypes.h>
#include <pthread.h>
#include <stdlib.h>

struct timespec start, stop;
void *fill_array(void *args);
void *compare_array(void *args);

pthread_t f_tid[10000];
pthread_t c_tid[10000];
pthread_t s_tid[10000];

typedef struct {
    int i;
    int j;
    int *w;
    int *x;
} args_struct;

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


void *fill_array(void *args){
	args_struct *m_args = args;
	m_args -> w[m_args->i] = 1;
	free(m_args);
	pthread_exit(0);
}

void *compare_array(void *args){
	args_struct *m_args = args;
	printf("\nThread (%d,%d) compares x[%d] = %d and x[%d] = %d",m_args->i,m_args->j,m_args->i, m_args -> x[m_args->i], m_args->j, m_args -> x[m_args->j]);
	if(m_args -> x[m_args->i] < m_args -> x[m_args->j]){
		m_args -> w[m_args->i] = 0;
	}
	else
		m_args -> w[m_args->j] = 0;
	free(m_args);
	pthread_exit(0);
}

void *show_value(void *args){
	args_struct *m_args = args;
	if(m_args -> w[m_args->i] == 1){
		printf("\nMaximum: %d\nPosition: %d\n", m_args -> x[m_args->i], m_args->i + 1);
	}
	free(m_args);
	pthread_exit(0);
}

void fill_array_threads(int size, int * w){
	int i;
	for(i = 0; i < size; i++){
		args_struct *args = (args_struct*)malloc(sizeof(args_struct));
		args -> i = i;
		args -> w = w;
		pthread_create(&(f_tid[i]), NULL, &fill_array, args);
	}
}

void compare_threads(int size, int *w, int *x){
	int i,j,k = 0;
	for(i = 0; i < size; i++){
		for(j = i + 1; j < size; j++){
			args_struct *args = (args_struct*)malloc(sizeof(args_struct));
			args -> i = i;
			args -> j = j;
			args -> w = w;
			args -> x = x;
			pthread_create(&(c_tid[k]), NULL, &compare_array, args);
			k++;
		}
	}
}

void search_thread(int size, int *w, int *x){
	int i;
	for(i = 0; i < size; i++){
		args_struct *args = (args_struct*)malloc(sizeof(args_struct));
		args -> i = i;
		args -> w = w;
		args -> x = x;
		pthread_create(&(s_tid[i]), NULL, &show_value, args);
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
	

	fill_array_threads(size, w);
	printf("\nAfter Initialization: ");
	for(i = 0; i < size; i++){
		printf("%d ", w[i]);
	}

	for(i = 0; i < size; i++){
		pthread_join(f_tid[i], NULL);
	}

	compare_threads(size,w,x);
	int t_size = (size*(size-1))/2;

	for(i = 0; i < t_size; i++){
		pthread_join(c_tid[i], NULL);
	}

	printf("\nAfter Comparsion: ");
	for(i = 0; i < size; i++){
		printf("%d ", w[i]);
	}

	search_thread(size,w,x);

	for(i = 0; i < size; i++){
		pthread_join(s_tid[i], NULL);
	}
	set_stop();
	get_time();
	return 0;
}




// // high precision.
// void get_time(){
// 	uint64_t delta_us = (stop.tv_sec - start.tv_sec) * 1000000 + (stop.tv_nsec - start.tv_nsec) / 1000;
// 	printf("took %" PRIu64 "\n", delta_us);
// 	//printf("took %lu\n", delta_us);
// }

// void set_start(){
// 	clock_gettime(CLOCK_MONOTONIC_RAW, &start);
// }

// void set_stop(){
// 	clock_gettime(CLOCK_MONOTONIC_RAW, &stop);
// }