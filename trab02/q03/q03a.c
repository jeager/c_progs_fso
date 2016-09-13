#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <stdint.h>
#include <inttypes.h>

#define MATRIX_A_ROWS 3
#define MATRIX_A_COLUMNS 2
#define MATRIX_B_ROWS 2
#define MATRIX_B_COLUMNS 3

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


void matrix_multiplication(int ma[3][2], int mb[2][3], int mr[3][3]){
	int i,j,k, sum = 0;

	for (i = 0; i < MATRIX_A_ROWS; i++) {
    for (j = 0; j < MATRIX_B_COLUMNS; j++) {
      for (k = 0; k < MATRIX_B_ROWS; k++) {
        sum = sum + ma[i][k]*mb[k][j];
      }

      mr[i][j] = sum;
      sum = 0;
    }
  }
}

void print_matrix(int matrix[3][3]){
	int i,j;
	for(i = 0; i < MATRIX_A_ROWS; i++){
	printf("|");
		for (j = 0; j < MATRIX_B_COLUMNS; j++){
			if(j != 2)
				printf("%d,", matrix[i][j]);
			else
				printf("%d", matrix[i][j]);
		}
		printf("|\n");
	}
}

void fill_matrix(int row, int column, int matrix[row][column]){
	int i,j;
	for(i = 0; i < row; i++){
		for (j = 0; j < column; j++){
			printf("Insert [%d][%d] element: ",i,j);
			scanf("%d",&matrix[i][j]);
			printf("\n");
		}
	}
}

int main(){
	set_start();
	int matrix_a[MATRIX_A_ROWS][MATRIX_A_COLUMNS];
	int matrix_b[MATRIX_B_ROWS][MATRIX_B_COLUMNS];
	int mr [MATRIX_A_ROWS][MATRIX_B_COLUMNS];

	printf("Fill matrix a: \n");
	fill_matrix(MATRIX_A_ROWS,MATRIX_A_COLUMNS, matrix_a);
	printf("Fill matrix b: \n");
	fill_matrix(MATRIX_B_ROWS,MATRIX_B_COLUMNS, matrix_b);
	
	matrix_multiplication(matrix_a, matrix_b, mr);
	set_stop();
	print_matrix(mr);
	get_time();

}