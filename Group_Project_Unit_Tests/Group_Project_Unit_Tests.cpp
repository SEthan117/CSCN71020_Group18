#include "pch.h"
#include "CppUnitTest.h"

extern "C" {

#include "main.h"
#include "polygonSolver.h"
#include "triangleAngle.h"
#include "triangleSolver.h"
#include "polygonSolver.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GroupProjectUnitTests
{
	TEST_CLASS(GroupProjectUnitTests)
	{
	public:

		TEST_METHOD(analyzeTriangleNotATriangleAllZeroesTest)
		{
			int side1 = 0;
			int side2 = 0;
			int side3 = 0;
			char* result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual("Not a triangle", result);
		}

		TEST_METHOD(analyzeTriangleNotATriangleOneZeroeTest)
		{
			int side1 = 0;
			int side2 = 5;
			int side3 = 25;
			char* result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual("Not a triangle", result);
		}

		TEST_METHOD(analyzeTriangleNotATriangleOneNegativeNumberTest)
		{
			int side1 = -37;
			int side2 = 12;
			int side3 = 4;
			char* result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual("Not a triangle", result);
		}
		TEST_METHOD(analyzeTriangleNotATriangleAllNegativeNumberTest)
		{
			int side1 = -7;
			int side2 = -19;
			int side3 = -26;
			char* result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual("Not a triangle", result);
		}

		TEST_METHOD(analyzeTriangleEquilateralTriangleTest)
		{
			int side1 = 4;
			int side2 = 4;
			int side3 = 4;
			char* result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual("Equilateral triangle", result);
		}

		TEST_METHOD(analyzeTriangleIsocelesTriangleSide1Side2Test)
		{
			int side1 = 4;
			int side2 = 4;
			int side3 = 25;
			char* result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual("Isosceles triangle", result);
		}
		TEST_METHOD(analyzeTriangleIsocelesTriangleSide2Side3Test)
		{
			int side1 = 10;
			int side2 = 25;
			int side3 = 25;
			char* result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual("Isosceles triangle", result);
		}
		TEST_METHOD(analyzeTriangleScaleneTriangleTest)
		{
			int side1 = 3;
			int side2 = 14;
			int side3 = 25;
			char* result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual("Scalene triangle", result);

		}

		TEST_METHOD(triangleangleTest1)
		{
			int side1 = -1;
			int side2 = 3;
			int side3 = 3;
			char answer[50] = "";
			char* result = triangleAngle(side1, side2, side3, answer);
			Assert::AreEqual("This is not a triangle\n", result);

		}
		TEST_METHOD(triangleangleTest2)
		{
			int side1 = 3;
			int side2 = 3;
			int side3 = 3;
			char answer[50] = "";
			char* result = triangleAngle(side1, side2, side3, answer);
			Assert::AreEqual("26.39,26.39,26.39", result);

		}
		TEST_METHOD(rectanglcheakerPERFECTSQUARETest)
		{
			int point1x = 0;
			int point1y = 0;
			int point2x = 0;
			int point2y = 4;
			int point3x = 4; 
			int point3y = 0;
			int point4x = 4;
			int point4y = 4;
			char somestring[50] = "";
			char* result = polygonPoints(point1x, point1y, point2x, point2y, point3x, point3y, point4x, point4y, somestring); 
			Assert::AreEqual("16.00,and 16", result);

		}
		TEST_METHOD(rectanglcheakerRECTANGLETest)
		{
			int point1x = 4;
			int point1y = 10;
			int point2x = 4;
			int point2y = 12;
			int point3x = 8;
			int point3y = 10;
			int point4x = 8;
			int point4y = 12;
			char somestring[50] = "";
			char* result = polygonPoints(point1x, point1y, point2x, point2y, point3x, point3y, point4x, point4y, somestring);
			Assert::AreEqual("8.00,and 12", result);

		}
		TEST_METHOD(rectanglecheckerNOTaRectangleTest1)
		{
			int point1x = 1;
			int point1y = 1;
			int point2x = 1;
			int point2y = 1;
			int point3x = 1;
			int point3y = 1;
			int point4x = 1;
			int point4y = 1;
			char somestring[50] = "";
			char* result = polygonPoints(point1x, point1y, point2x, point2y, point3x, point3y, point4x, point4y, somestring);
			Assert::AreEqual("This is not a rectangle.\n", result);

		}
		TEST_METHOD(rectanglcheckerNOTaRECTANGLETest2)
		{
			int point1x = 15;
			int point1y = 7;
			int point2x = 29;
			int point2y = 16;
			int point3x = 0;
			int point3y = 8;
			int point4x = 1;
			int point4y = 1;
			char somestring[50] = "";
			char* result = polygonPoints(point1x, point1y, point2x, point2y, point3x, point3y, point4x, point4y, somestring);
			Assert::AreEqual("This is not a rectangle.\n", result);

		}

	};



}