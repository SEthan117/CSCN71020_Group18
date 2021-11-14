#include<stdio.h>

#include"polygonSolver.h"


char* polygonPoints(POINT p1, POINT p2, POINT p3, POINT p4)
{
	char* result;
	int line1 = abs(p1.x - p2.x);
	int line2 = abs(p1.y - p2.y);
	int line3 = abs(p3.x - p4.x);
	int line4 = abs(p3.y - p4.y);
	int perimeter;
	double area;

	if (line1 == line3 && line2 == line4)
	{
		perimeter = line1 + line2 + line3 + line4;
		area = line1 * line2;
		result = "This is a rectangle. \nArea is %lf\nPerimeter is %d", & area, & perimeter;
	}
	result = "This is not a rectangle.";
	return result;
}

