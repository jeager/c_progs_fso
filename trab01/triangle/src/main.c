#include "../lib/triangle.h"
#include "../lib/t_calc.h"
#include "../lib/io.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	Triangle t = create_triangle();
	if(is_valid(t) > 0){
		print_triangle(t);
		printf("Triangle perimeter: %lf\n", perimeter(t));
		printf("Triangle area: %lf\n", triangle_area(t));
	} else {
		printf("Invalid triangle.");
	}
	return 0;
}