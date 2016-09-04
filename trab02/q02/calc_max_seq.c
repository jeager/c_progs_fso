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

pthread_t f_tid[30];
pthread_t c_tid[30];
pthread_t s_tid[30];

typedef struct {
    int i;
    int j;
    int *w;
    int *x;
} args_struct;

void *fill_array(void *args){
	args_struct *m_args = args;
	printf("preenchendo w[%d]\n",m_args->i);
	m_args -> w[m_args->i] = 1;
	free(m_args);
	pthread_exit(0);
}

void *compare_array(void *args){
	args_struct *m_args = args;
	printf("comparando x[%d]: %d e x[%d]: %d\n",m_args->i, m_args -> x[m_args->i], m_args->j, m_args -> x[m_args->j]);
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
		printf("\nO max eh: %d\n", m_args -> x[m_args->i]);
	}
	free(m_args);
	pthread_exit(0);
}

int calc_max (int * x, int n){
	int max = x[0], i;
	for(i = 1; i < n; i++){
		if(x[i] > max)
			max = x[i];
	}
	return max;
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

int main(){
	int x[4] = {3,7,5,4};
	int w[4];
	int i;

	fill_array_threads(4, w);

	for(i = 0; i < 4; i++){
		pthread_join(f_tid[i], NULL);
	}

	compare_threads(4,w,x);

	for(i = 0; i < 6; i++){
		pthread_join(c_tid[i], NULL);
	}

	search_thread(4,w,x);

	for(i = 0; i < 4; i++){
		pthread_join(s_tid[i], NULL);
	}
	
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