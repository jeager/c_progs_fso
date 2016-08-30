#include "../lib/triangle.h"
#include "../lib/io.h"
#include <stdio.h>

Triangle create_triangle(){
    printf("Please, input 3 cartesian points to plot your triangle.\n");
    Triangle t;
    
    printf("Please, insert the first coordinate (X Y): ");
    scanf("%lf %lf", &t.a.x, &t.a.y);
    
    printf("Please, insert the second coordinate (X Y): ");
    scanf("%lf %lf", &t.b.x, &t.b.y);

    printf("Please, insert the third coordinate (X Y): ");
    scanf("%lf %lf", &t.c.x, &t.c.y);

    return t;
}

void print_triangle(Triangle t){
	printf("Triangle: \npoint a: (%lf, %lf)\npoint b: (%lf, %lf)\npoint c: (%lf, %lf)\n", t.a.x, t.a.y, t.b.x, t.b.y, t.c.x, t.c.y);
}