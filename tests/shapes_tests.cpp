#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
#include "..\implementation\shapes.h"
#include "..\implementation\list_shapes.h"


namespace ShapeTests
{
	TEST_CLASS(ShapeTests)
	{
	public:
		
		TEST_METHOD(correct_rectangle_creation)
		{
			std::pair<double, double> A;
			A.first = 4.0;
			A.second = 6.0;
			std::pair<double, double> B;
			B.first = 8.0;
			B.second = 6.0;
			std::pair<double, double> C;
			C.first = 8.0;
			C.second = 12.0;
			std::pair<double, double> D;
			D.first = 4.0;
			D.second = 12.0;
			Rectangle rectangle = Rectangle(A, B, C, D);
			bool is_correct = 0;
			if (abs(rectangle.get_area() - 24.0) < rectangle.get_epsilon())
			{
				if(abs(rectangle.get_perimeter() - 20.0) < rectangle.get_epsilon())
					is_correct = true;
			}
			Assert::AreEqual(true, is_correct);

		}
		TEST_METHOD(incorrect_rectangle_creation)
		{
			std::pair<double, double> A;
			A.first = 4.0;
			A.second = 6.0;
			std::pair<double, double> B;
			B.first = 8.0;
			B.second = 12.0;
			std::pair<double, double> C;
			C.first = 8.0;
			C.second = 62.0;
			std::pair<double, double> D;
			D.first = 4.0;
			D.second = 12.0;
			bool error_thrown = false;
			try
			{
				Rectangle rectangle = Rectangle(A, B, C, D);
			}
			catch (const char* msg)
			{
				error_thrown = true;
			}
			Assert::AreEqual(error_thrown, true);
		}
		TEST_METHOD(correct_triangle_creation)
		{
			std::pair<double, double> A;
			A.first = 4.0;
			A.second = 6.0;
			std::pair<double, double> B;
			B.first = 8.0;
			B.second = 6.0;
			std::pair<double, double> C;
			C.first = 8.0;
			C.second = 12.0;
			Triangle triangle = Triangle(A, B, C);
			bool correct_values = false;
			if (abs(triangle.get_area() - 12.0) < triangle.get_epsilon())
			{
				double difference = abs(triangle.get_perimeter() - 17.21110255092797858);
				if (difference < triangle.get_epsilon())
					correct_values = true;
			}
			Assert::AreEqual(correct_values, true);
		}
		TEST_METHOD(incorrect_triangle_creation)
		{
			std::pair<double, double> A;
			A.first = 4.0;
			A.second = 6.0;
			std::pair<double, double> B;
			B.first = 4.0;
			B.second = 8.0;
			std::pair<double, double> C;
			C.first = 4.0;
			C.second = 12.0;
			bool error_thrown = false;
			try
			{
				Triangle triangle = Triangle(A, B, C);
			}
			catch (const char* msg)
			{
				error_thrown = true;
			}
			Assert::AreEqual(error_thrown, true);
		}
		TEST_METHOD(circle_creation)
		{
			std::pair<double, double> A;
			A.first = 4.0;
			A.second = 6.0;
			double r = 6.0;
			bool correct_values = false;
			Circle circle = Circle(A, r);
			if (abs(circle.get_area() - 113.09733552923255) < circle.get_epsilon())
			{
				double difference = abs(circle.get_perimeter() - 37.69911184307751886155);
				if (difference < circle.get_epsilon())
					correct_values = true;
			}
			Assert::AreEqual(correct_values, true);
		}
		TEST_METHOD(compare_equal)
		{
			std::pair<double, double> A;
			A.first = 4.0;
			A.second = 6.0;
			std::pair<double, double> B;
			B.first = 8.0;
			B.second = 6.0;
			std::pair<double, double> C;
			C.first = 8.0;
			C.second = 12.0;
			std::pair<double, double> D;
			D.first = 4.0;
			D.second = 12.0;
			Rectangle rectangle = Rectangle(A, B, C, D);
			std::pair<double, double> E;
			E.first = 4.0;
			E.second = 6.0;
			std::pair<double, double> F;
			F.first = 8.0;
			F.second = 6.0;
			std::pair<double, double> G;
			G.first = 8.0;
			G.second = 18.0;
			Triangle triangle = Triangle(E, F, G);
			bool correct_values = false;
			bool correct_values2 = true;
			if (triangle == rectangle)
				correct_values = true;
			Assert::AreEqual(correct_values, true);
			Triangle triangle2 = Triangle(A, B, C);
			if (triangle2 == rectangle)
				correct_values2 = false;
			Assert::AreEqual(correct_values2, true);
		}
		TEST_METHOD(compare_lesser)
		{
			std::pair<double, double> A;
			A.first = 4.0;
			A.second = 6.0;
			std::pair<double, double> B;
			B.first = 8.0;
			B.second = 6.0;
			std::pair<double, double> C;
			C.first = 8.0;
			C.second = 12.0;
			std::pair<double, double> D;
			D.first = 4.0;
			D.second = 12.0;
			Rectangle rectangle = Rectangle(A, B, C, D);
			std::pair<double, double> E;
			E.first = 4.0;
			E.second = 6.0;
			std::pair<double, double> F;
			F.first = 8.0;
			F.second = 6.0;
			std::pair<double, double> G;
			G.first = 8.0;
			G.second = 18.0;
			Triangle triangle = Triangle(E, F, G);
			bool correct_values = true;
			bool correct_values2 = false;
			if (triangle < rectangle)
				correct_values = true;
			Assert::AreEqual(correct_values, true);
			Triangle triangle2 = Triangle(A, B, C);
			if (triangle2 < rectangle)
				correct_values2 = true;
			Assert::AreEqual(correct_values2, true);
		}
		TEST_METHOD(compare_greater)
		{
			std::pair<double, double> A;
			A.first = 4.0;
			A.second = 6.0;
			std::pair<double, double> B;
			B.first = 8.0;
			B.second = 6.0;
			std::pair<double, double> C;
			C.first = 8.0;
			C.second = 12.0;
			std::pair<double, double> D;
			D.first = 4.0;
			D.second = 12.0;
			Rectangle rectangle = Rectangle(A, B, C, D);
			std::pair<double, double> E;
			E.first = 4.0;
			E.second = 6.0;
			double r = 6.0;
			Circle circle = Circle(E, r);
			bool correct_values = false;
			bool correct_values2 = true;
			if (circle > rectangle)
				correct_values = true;
			Assert::AreEqual(correct_values, true);
			Triangle triangle2 = Triangle(A, B, C);
			if (triangle2 > rectangle)
				correct_values2 = false;
			Assert::AreEqual(correct_values2, true);
		}
		TEST_METHOD(compare_not_greater)
		{
			std::pair<double, double> A;
			A.first = 4.0;
			A.second = 6.0;
			std::pair<double, double> B;
			B.first = 8.0;
			B.second = 6.0;
			std::pair<double, double> C;
			C.first = 8.0;
			C.second = 12.0;
			std::pair<double, double> D;
			D.first = 4.0;
			D.second = 12.0;
			Rectangle rectangle = Rectangle(A, B, C, D);
			std::pair<double, double> E;
			E.first = 4.0;
			E.second = 6.0;
			std::pair<double, double> F;
			F.first = 8.0;
			F.second = 6.0;
			std::pair<double, double> G;
			G.first = 8.0;
			G.second = 18.0;
			double r = 6.0;
			Circle circle = Circle(E, r);
			Triangle triangle = Triangle(E, F, G);
			bool correct_values = true;
			bool correct_values2 = false;
			bool correct_values3 = false;
			if (circle <= rectangle)
				correct_values = false;
			Assert::AreEqual(correct_values, true);
			if (triangle <= rectangle)
				correct_values2 = true;
			Triangle triangle2 = Triangle(A, B, C);
			if (triangle2 <= rectangle)
				correct_values3 = true;
			Assert::AreEqual(correct_values2, true);
			Assert::AreEqual(correct_values3, true);
		}
		TEST_METHOD(compare_not_lesser)
		{
			std::pair<double, double> A;
			A.first = 4.0;
			A.second = 6.0;
			std::pair<double, double> B;
			B.first = 8.0;
			B.second = 6.0;
			std::pair<double, double> C;
			C.first = 8.0;
			C.second = 12.0;
			std::pair<double, double> D;
			D.first = 4.0;
			D.second = 12.0;
			Rectangle rectangle = Rectangle(A, B, C, D);
			std::pair<double, double> E;
			E.first = 4.0;
			E.second = 6.0;
			std::pair<double, double> F;
			F.first = 8.0;
			F.second = 6.0;
			std::pair<double, double> G;
			G.first = 8.0;
			G.second = 18.0;
			double r = 6.0;
			Circle circle = Circle(E, r);
			Triangle triangle = Triangle(E, F, G);
			bool correct_values = false;
			bool correct_values2 = false;
			bool correct_values3 = true;
			if (circle >= rectangle)
				correct_values = true;
			Assert::AreEqual(correct_values, true);
			if (triangle >= rectangle)
				correct_values2 = true;
			Triangle triangle2 = Triangle(A, B, C);
			if (triangle2 >= rectangle)
				correct_values3 = false;
			Assert::AreEqual(correct_values2, true);
			Assert::AreEqual(correct_values3, true);
		}
	};
}
