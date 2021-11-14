#include<stdio.h>

#include"polygonSolver.h"

typedef struct
{
	double x[4];
	double y[4];
}point;

int* polygonPoints(p1, p2, p3, p4)
{
	int p1p2_x = p1.x - p2.x;
	int p1p2_y = p1.y - p2.y;
	int p3p4_x = p3.x - p4.x;
	int p3p4_y = p3.y - p4.y;
}

int main()
{
	point p1, p2, p3, p4;
	printf("Enter 4 Point Adrees: \n");
	scanf("%lf %lf %lf", &p1.x, &p1.y);
	scanf("%lf %lf %lf", &p2.x, &p2.y);
	scanf("%lf %lf %lf", &p3.x, &p3.y);
	scanf("%lf %lf %lf", &p4.x, &p4.y);
	if (polygonPoints(p1, p2, p3, p4))
	{
		printf("It Is Rectangle");
	}
	else
	{
		printf("It is not a Rectangle");
	}
	return 0;
}
