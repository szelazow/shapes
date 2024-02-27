#define _USE_MATH_DEFINES

#include <list>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <stdexcept>
#include "shapes.h"


void shape::check_requirements(){}			//some shapes don't have special requirements, ex.Quadrilaterals

void shape::check_if_overlap()				//if points overlap, the amount of edges and corners decreases-it'll need to be checked for every shape
{
	throw("Checking if points overlap isn't implemented for this shape.");
}

bool shape::operator < (const shape another_shape)
{
	if (abs(area - another_shape.area) > epsilon)
	{
		return area < another_shape.area;
	}
	return 0;
}

bool shape::operator > (const shape another_shape)
{
	if (abs(area - another_shape.area) > epsilon)
	{
		return area > another_shape.area;
	}
	return 0;
}

bool shape::operator >= (const shape another_shape)
{
	if (abs(area - another_shape.area) < epsilon)
		return 1;
	return area > another_shape.area;
}

bool shape::operator <= (const shape another_shape)
{
	if (abs(area - another_shape.area) < epsilon)
		return 1;
	return area < another_shape.area;
}

bool shape::operator == (const shape another_shape)
{
	if (abs(area - another_shape.area) < epsilon)
		return 1;
	return 0;
}

std::ostream& operator<<(std::ostream& os, const shape some_shape)
{
	os << "perimter: " << some_shape.perimeter << " area: " << some_shape.area;
	return os;
}

double shape::calculate_perimeter() {
	throw("Perimeter calculation is undefined for this shape.");
}

double shape::get_epsilon() const
{
	return epsilon;
}

double shape::get_perimeter() const
{
	return perimeter;
};

double shape::get_area() const
{
	return area;
};

double seg_len(std::pair<double, double> A, std::pair<double, double> B)
//calculates the length of a segment created by 2 points
{
	return sqrt(pow(A.first - B.first, 2.0) + pow(A.second - B.second, 2.0));
}

void Triangle::check_requirements()
{

}

void Triangle::check_if_overlap()
{

}

double Triangle::calculate_perimeter()
{
	return seg_len(A, B) + seg_len(B, C) + seg_len(A, C);
}

double Triangle::calculate_area() //heron's formula is used for the calculations
{
	double a = seg_len(B, C);
	double b = seg_len(A, C);
	double c = seg_len(A, B);
	double p = (a + b + c) / 2.0;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

Triangle::Triangle(std::pair<double, double> A1,
	std::pair<double, double> B1,
	std::pair<double, double> C1)
{
	A = A1;
	B = B1;
	C = C1;
	area = calculate_area();
	perimeter = calculate_perimeter();
	if ((perimeter / 2.0) - seg_len(A, B) < epsilon || (perimeter / 2.0) - seg_len(B, C) < epsilon || (perimeter / 2.0) - seg_len(A, C) < epsilon)
		throw ("This is not a triangle.");
}

void Rectangle::check_requirements()			//every vertice must be equally distant from the figure's center of mass
{
	std::pair<double, double> center_of_mass = { 0.0,0.0 };
	std::list<std::pair<double, double>> vertexes = { A, B, C, D };			//distances between A, B, C and D and the center of mass
	center_of_mass.first = (A.first + B.first + C.first + D.first) / 4.0;
	center_of_mass.second = (A.second + B.second + C.second + D.second) / 4.0;
	for (const auto &y : vertexes)
	{
		if (seg_len(y, center_of_mass) < epsilon)
		{
			throw("this is not a rectangle - the center of mass isn't equally distant from each vertex.");
		}
	}

}

void Rectangle::check_if_overlap()
{

}

double Rectangle::calculate_perimeter()
{
	return 2.0 * seg_len(A, B) + 2.0 * seg_len(A, D);
}
double Rectangle::calculate_area()
{
	return seg_len(A, B) * seg_len(A, D);
}

bool check_if_rectangle(double a, double b, double c, double d, double f, double epsilon)
//checks if a == c and b == d, for the program to work correctly AB and AD must be sides.
{
	if (abs(a - c) < epsilon && abs(b - d) < epsilon)
	{
		if (abs(f - sqrt(pow(a, 2.0) + pow(b, 2.0))) < epsilon)
			return 1;
	}
	return 0;
}

Rectangle::Rectangle(std::pair<double, double> A1,
	std::pair<double, double> B1,
	std::pair<double, double> C1,
	std::pair<double, double> D1)
{
	A = A1;
	B = B1;
	C = C1;
	D = D1;
	/*we check if the figure is a rectangle by calculating the figure's
	centre of mass, and then checking if they are "equal" (we're using double,
	so we can't use ==*/
	if (check_if_rectangle(seg_len(A, B), seg_len(A, D), seg_len(C, D), seg_len(C, B), seg_len(A, C), epsilon) == 0)
		throw ("This is not a rectangle. a != c v b != d v incorrect order.");
	area = calculate_area();
	perimeter = calculate_perimeter();
}

void Circle::check_if_overlap()   //a circle has no special requirements, but without a radius it'd be a point.
{
	if (r < epsilon) 
		throw ("The radius is too close to 0 - aborting.");
}

double Circle::calculate_perimeter()
{
	return 2 * M_PI * r;
}
double Circle::calculate_area()
{
	return M_PI * pow(r, 2.0);
}
Circle::Circle(std::pair<double, double> d, double r1)
{
	D = d;
	r = r1;
	perimeter = calculate_perimeter();
	area = calculate_area();
}