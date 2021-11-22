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
	double alt;
	double pi;
	double Lower;

	simplify = (side1 + side2 + side3) / 2; //Simplification of a common equation
	pi = acos(-1); //Creation of pi
	alt = sqrt(simplify * (simplify - side1) * (simplify - side2) * (simplify - side3)); //Simplify another long equation
	Lower = ((double)side1 * (double)side2 * (double)side3) / (4 * alt); //Simplify a long equation for a final time
	if (side1 > 1 && side2 > 1 && side3 > 1 && ((side1 + side2) >= side3) && ((side1 + side3) >= side2) && ((side2 + side3) >= side1)) //Confirm if triangle, now also uses triangle inequality rule
	{
		angle1 = (180 / pi) * asin(side1 / (2 * Lower)); //Get the angles
		angle2 = (180 / pi) * asin(side2 / (2 * Lower));
		angle3 = (180 / pi) * asin(side3 / (2 * Lower));
		printf("This creates a triangle.\n"); //Confirmation statement
		snprintf(angle1c, 50, "%.2f", angle1); //Create result
		snprintf(angle2c, 50, "%.2f", angle2);
		snprintf(angle3c, 50, "%.2f", angle3);
		strcpy(stringptr, angle1c);
		strcat(stringptr, ",");
		strcat(stringptr, angle2c);
		strcat(stringptr, ",");
		strcat(stringptr, angle3c); 
		result = stringptr;
		printf("angles are: %s\n", result);
		return result; //output
	}
	else
	{
		printf("This is not a triangle.\n"); 
		result = "This is not a triangle\n"; //Result if not triangle
		return result;
	}
}