#include <math.h>
#include <stdlib.h>
#include "../lib/triangle.h"
#include "../lib/t_calc.h"

double perimeter(Triangle triangle){
	double perimeter = 0.0;
	perimeter += distance_two_points(triangle.a, triangle.b);
	perimeter += distance_two_points(triangle.a, triangle.c);
	perimeter += distance_two_points(triangle.b, triangle.c);
	return perimeter;
}

double distance_two_points(Point a, Point b){
	return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

int is_valid(Triangle triangle){
	double a, b, c;
	a = distance_two_points(triangle.a, triangle.b);
	b = distance_two_points(triangle.a, triangle.c);
	c = distance_two_points(triangle.b, triangle.c);

	if((a + b) < c || (abs(a - b) > c))
		return 0;
	else if((a + c) < b || (abs(a - c) > b))
		return 0;
	else if((b + c) < a || (abs(b - c) > a))
		return 0;

	return 1;
}

double triangle_area(Triangle triangle){
	double a,b,c,p,area;
	p = perimeter(triangle)/2;
	a = distance_two_points(triangle.a, triangle.b);
	b = distance_two_points(triangle.a, triangle.c);
	c = distance_two_points(triangle.b, triangle.c);
	area = sqrt(p*(p-a)*(p-b)*(p-c));

	return area;
}