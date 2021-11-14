#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#include "triangleAngle.h"

char* triangleAngle(int side1, int side2, int side3, char* stringptr)
{
	char* result = "";
	char angle1c[50];
	char angle2c[50];
	char angle3c[50];
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
	if ((side1 > 1 && side2 > 1 && side3 > 1))
	{
		angle1 = (180 / pi) * asin(side1 / (2 * Lower));
		angle2 = (180 / pi) * asin(side2 / (2 * Lower));
		angle3 = (180 / pi) * asin(side3 / (2 * Lower));
		printf("This creates a triangle.\n");
		snprintf(angle1c, 50, "%.2f", angle1);
		snprintf(angle2c, 50, "%.2f", angle2);
		snprintf(angle3c, 50, "%.2f", angle3);
		strcpy(stringptr, angle1c);
		strcat(stringptr, ",");
		strcat(stringptr, angle2c);
		strcat(stringptr, ",");
		strcat(stringptr, angle3c); 
		result = stringptr;
		printf("angles are: %s\n", result);
		return result;
	}
	else
	{
		result = "This is not a triangle\n";
		return result;
	}
}