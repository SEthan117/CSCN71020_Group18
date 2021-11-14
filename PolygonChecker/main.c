#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "triangleSolver.h"
#include "triangleAngle.h"
#include "polygonSolver.h"

int side = 0;

int main() {

	char result[50] = { 0 };
	char* test = "";
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
			test = triangleAngle(triangleSideLengthPtr[0], triangleSideLengthPtr[1], triangleSideLengthPtr[2], &result);
			printf("%s", test);
			break;
			case 3:
			printf("Rectangle selected. \n");
			int pointX[4] = { 0,0,0,0 };
			int pointY[4] = { 0,0,0,0 };
			int* rectanglePoints = getRectanglePoints(pointX, pointY);
			rectangle = polygonPoints(pointX[1], pointY[1], pointX[2], pointY[2], pointX[3], pointY[3], pointX[4], pointY[4]);
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
	scanf_s("%1o", &shapeChoice);

	return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle: ");
	for (int i = 0; i < 3; i++)
	{
		scanf_s("%d", &triangleSides[i]);
	}
	return triangleSides;
}

int getRectanglePoints(int* pointX, int* pointY)
{
	int points = (pointX, pointY);
	printf("Input x values:");
	for (int i = 1; i < 5; i++)
	{
		scanf_s("%d %d", &pointX[i], &pointY[i]);
	}
	return points;
}