#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "main.h"
#include "triangleSolver.h"
#include "triangleAngle.h"
#include "polygonSolver.h"

int side = 0;

int main() {

	char result[50] = "";
	char string[50] = "";
	char* rectangle = "";


	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1:
			printf_s("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			//printf_s("! %d\n", triangleSidesPtr[0]);
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", result);
			break;
		case 2:
			printf("Triangle angles selected.\n");
			int triangleSideLength[3] = { 0,0,0 };
			int* triangleSideLengthPtr = getTriangleSides(triangleSideLength);
			triangleAngle(triangleSideLengthPtr[0], triangleSideLengthPtr[1], triangleSideLengthPtr[2], &result);
			break;
		case 3:
			printf("Rectangle selected. \n");
			int pointX[4] = { 0,0,0,0 }; //Creating an x value for the points
			int pointY[4] = { 0,0,0,0 }; //Creating a y value for the points
			int* rectanglePoints = getRectanglePoints(pointX, pointY);
			rectangle = polygonPoints(pointX[0], pointY[0], pointX[1], pointY[1], pointX[2], pointY[2], pointX[3], pointY[3], &string);
			break;
		case 0:
			continueProgram = false;
			break;
		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	}
	return 0;
}

void printWelcome() {
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {
	printf_s("1. Triangle\n");
	printf("2. Triangle angles\n");
	printf("3. Rectangle checker\n");
	printf_s("0. Exit\n");

	int shapeChoice;

	printf_s("Enter number: ");
	if ((scanf_s("%1o", &shapeChoice) !=1) || shapeChoice<0 || shapeChoice >3 )
	{
		fprintf(stderr, "invalid input!\n");
		exit(EXIT_FAILURE); 
	}

	return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle: ");
	for (int i = 0; i < 3; i++)
	{
		if ((scanf_s("%d", &triangleSides[i]) !=1) || triangleSides[i] <0) 
		{
			fprintf(stderr, "invalid input!\n");  
			exit(EXIT_FAILURE);  
		}
	}
	return triangleSides;
}

int getRectanglePoints(int* pointX, int* pointY)
{
	int points = (pointX, pointY); //Create points int to return a value 
	for (int i = 0; i < 4; i++)
	{
		printf("Input (x,y) values:");
		if ((scanf_s("%d %d", &pointX[i], &pointY[i]) !=2) || (pointX[i]<0) || (pointY[i] <0)) //Making sure input is correct
		{
			fprintf(stderr, "invalid input!\n");
			exit(EXIT_FAILURE);
		}
		
	}
	return points;
}