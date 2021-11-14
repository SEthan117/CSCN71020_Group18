#include<stdio.h>

#include"polygonSolver.h"


char* polygonPoints(int pointX1, int pointY1, int pointX2, int pointY2, int pointX3, int pointY3, int pointX4, int pointY4)
{
	POINT p1, p2, p3, p4;
	p1.x = pointX1;
	p1.y = pointY1;
	p2.x = pointX2;
	p2.y = pointY2;
	p3.x = pointX3;
	p3.y = pointY3;
	p4.x = pointX4;
	p4.y = pointY4;
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

