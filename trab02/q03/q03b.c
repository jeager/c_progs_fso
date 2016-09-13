#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>
#include <stdint.h>
#include <inttypes.h>


#define MATRIX_A_ROWS 3
#define MATRIX_A_COLUMNS 2
#define MATRIX_B_ROWS 2
#define MATRIX_B_COLUMNS 3
#define NUM_THREADS 9

void *calc_cell(void *args);
int **init_matrix(int row, int column);
void fill_matrix(int row, int column, int **matrix);

pthread_t tid[9];

typedef struct {
    int i;
    int j;
    int **mr;
    int **ma;
    int **mb;
} args_struct;


struct timespec start, stop;

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


void *calc_cell(void *args){
	int sum,k;
	sum = 0;
	args_struct *m_args = args;
	for (k = 0; k < MATRIX_B_ROWS; k++) {
    sum = sum + m_args -> ma[m_args->i][k] * m_args -> mb[k][m_args->j];
  }
  m_args -> mr[m_args->i][m_args->j] = sum;
  free(m_args);
	pthread_exit(0);
}


void matrix_multiplication(int **ma, int **mb, int **mr){
	int i,j,k = 0;
	for (i = 0; i < MATRIX_A_ROWS; i++) {
    for (j = 0; j < MATRIX_B_COLUMNS; j++) {
   		args_struct *args = (args_struct*)malloc(sizeof(args_struct));
			args -> i = i;
			args -> j = j;
			args -> mr = mr;
			args -> ma = ma;
			args -> mb = mb;
			printf("creating thread\n");
			pthread_create(&(tid[k]), NULL, &calc_cell, args);
			k++;
    }
  }
}

void print_matrix(int row, int column, int **matrix){
	int i,j;
	for(i = 0; i < row; i++){
	printf("|");
		for (j = 0; j < column; j++){
			if(j != column - 1)
				printf("%d,", matrix[i][j]);
			else
				printf("%d", matrix[i][j]);
		}
		printf("|\n");
	}
}

int** init_matrix(int row, int column){
	int **matrix = (int**)malloc(sizeof(int *)*row);
	int i;
	for(i = 0; i < row; i++){
		int cell_size = sizeof(int)*column;
		matrix[i] = (int*)malloc(cell_size);
	}
	return matrix;
}

void fill_matrix(int row, int column, int **matrix){
	int i,j;
	for(i = 0; i < row; i++){
		for (j = 0; j < column; j++){
			printf("Insert [%d][%d] element: ",i,j);
			scanf("%d",&matrix[i][j]);
			printf("\n");
		}
	}
}

void fill_matrix_with_zeros(int row, int column, int **matrix){
	int i,j;
	for(i = 0; i < row; i++){
		for (j = 0; j < column; j++){
			matrix[i][j] = 0;
		}
	}
}

int main(){

	set_start();

	int **matrix_a = init_matrix(MATRIX_A_ROWS, MATRIX_A_COLUMNS);
	int **matrix_b = init_matrix(MATRIX_B_ROWS, MATRIX_B_COLUMNS);
	int **mr = init_matrix(MATRIX_A_ROWS, MATRIX_B_COLUMNS);

	printf("Fill matrix a: \n");
	fill_matrix(MATRIX_A_ROWS,MATRIX_A_COLUMNS, matrix_a);
	printf("Fill matrix b: \n");
	fill_matrix(MATRIX_B_ROWS,MATRIX_B_COLUMNS, matrix_b);
	fill_matrix_with_zeros(MATRIX_A_ROWS,MATRIX_B_COLUMNS, mr);

	matrix_multiplication(matrix_a, matrix_b, mr);

	int i;
	for(i = 0; i < NUM_THREADS; i++){
		printf("joining thread n: %d\n", i);
		pthread_join(tid[i], NULL);
	}
	set_stop();
	print_matrix(MATRIX_A_ROWS,MATRIX_B_COLUMNS, mr);
	get_time();
	return 0;
}