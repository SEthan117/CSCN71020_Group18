#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include"polygonSolver.h"


char* polygonPoints(int pointX1, int pointY1, int pointX2, int pointY2, int pointX3, int pointY3, int pointX4, int pointY4, char* stringptr)
{
	POINT p1, p2, p3, p4; //set POINT structs
	p1.x = pointX1; //Set point structs to values
	p1.y = pointY1;
	p2.x = pointX2;
	p2.y = pointY2;
	p3.x = pointX3;
	p3.y = pointY3;
	p4.x = pointX4;
	p4.y = pointY4;

	char* result = "";
	int perimeter = 0;
	double area = 0;
	char areastring[50] = "";
	char perimeterstring[50] = "";
	int delta12x = abs(p1.x - p2.x); //Creating the lines
	int delta12y = abs(p1.y - p2.y);
	int delta34x = abs(p3.x - p4.x);
	int delta34y = abs(p3.y - p4.y);
	int delta13x = abs(p1.x - p3.x);
	int delta13y = abs(p1.y - p3.y);
	int delta24x = abs(p2.x - p4.x);
	int delta24y = abs(p2.y - p4.y);
	double slope12 = 0; //Creating the slopes
	double slope13 = 0;
	double slope24 = 0;
	double slope34 = 0;
	double distance12 = 0; //Checking the distance
	double distance34 = 0;
	double distance13 = 0;
	double distance24 = 0;

	if (delta12x != 0) //Check if slope needs to be calculated
	{
		slope12 = (double)delta12y / (double)delta12x; //Slope equation
	}
	else
	{
		slope12 = 0;
	}
	if (delta13x != 0)
	{

		slope13 = (double) delta13y / (double)delta13x;
	}
	else
	{
		slope13 = 0;
	}
	if (delta24x != 0)
	{
		slope24 = (double)delta24y / (double)delta24x;
	}
	else
	{
		slope24 = 0;
	}
	if (delta34x != 0)
	{
		slope34 = (double)delta34y / (double)delta34x;
	}
	else
	{
		slope34 = 0;
	}
	distance12 = sqrt(pow(((double)p1.x - (double)p2.x), 2) + (pow(((double)p1.y - (double)p2.y), 2))); //Creates lines
	distance34 = sqrt(pow(((double)p3.x - (double)p4.x), 2) + (pow(((double)p3.y - (double)p4.y), 2)));
	distance13 = sqrt(pow(((double)p1.x - (double)p3.x), 2) + (pow(((double)p1.y - (double)p3.y), 2)));
	distance24 = sqrt(pow(((double)p2.x - (double)p4.x), 2) + (pow(((double)p2.y - (double)p4.y), 2)));

	if (slope12 == slope34 && slope13 == slope24 && distance12 == distance34 && distance13 == distance24 && distance12 >0 && distance13>0 && distance24>0 && distance34 > 0) //Verifies rectangle
	{
		perimeter = distance12 + distance13 + distance24 + distance34; //Perimeter equation
		area = (double)distance12 * (double)distance24; //Area equation
		printf("This is a rectangle\n"); //Output creation
		snprintf(areastring, 50, "%.2f", area);
		strcpy(stringptr, areastring);
		strcat(stringptr, ","); 
		strcat(stringptr, "and ");
		snprintf(perimeterstring, 50, "%d", perimeter);
		strcat(stringptr, perimeterstring); 
		result = stringptr;
		printf("The area and perimeter are: %s", result);
		return result; //Output result

	}
	else
	{
		printf("This is not a rectangle\n"); //If input is not rectangle
		result = "This is not a rectangle.\n";
	}
}

