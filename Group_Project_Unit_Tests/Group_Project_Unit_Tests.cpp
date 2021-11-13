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

	};



}
