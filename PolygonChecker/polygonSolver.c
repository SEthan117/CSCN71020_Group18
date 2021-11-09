#include<stdio.h>

#include<polygonSolver.h>

int polygonPoints(int point1, int point2, int point3)
{
	if (point1 > 0 && point2 > 0 && point3 > 0)
	{
		if (point1 + point2 > point3 && point1 + point3 > point2 && point3 + point2 > point1)
		{
			printf("Triangle");
		}
		else
		{
			printf("Can't be Traingle");
		}
	}
	return 0;
}