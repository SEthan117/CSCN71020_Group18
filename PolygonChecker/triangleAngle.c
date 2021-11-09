#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "triangleAngle.h"

int* triangleAngle(int side1, int side2, int side3)
{

	double angle1;
	double angle2;
	double angle3;
	double simplify;
	double area;
	double pi;
	double Lower;

	simplify = (side1 + side2 + side3) / 2;
	pi = acos(-1);
	area = sqrt(simplify * (simplify - side1) * (simplify - side2) * (simplify - side3));
	Lower = (side1 * side2 * side3) / (4 * area);
	if ((side1 > 1 || side2 > 1 || side3 > 1))
	{
		angle1 = (180 / pi) * asin(side1 / (2 * Lower));
		angle2 = (180 / pi) * asin(side2 / (2 * Lower));
		angle3 = (180 / pi) * asin(side3 / (2 * Lower));
		printf("This creates a triangle.\n");
		printf("%lf, %lf, %lf", angle1, angle2, angle3);
	}

	else
		printf("This is not a triangle.\n");

	return 0;
}