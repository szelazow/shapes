#pragma once
#include <string>
#include <memory>
#include<iostream>

//keeping the coordinates of points as double decreases precision, but enables a wider range of 
//values. Both of those are problematic, representing common fractions with a class would 
//be preferable, but would add another step to the implementation.

class shape
{
protected:
	double epsilon = 0.001; 
	double perimeter = 0.0;		
	double area = 0.0;
public:
	virtual void check_requirements();						//for checking if certain criteria are met, for example if the shape is a valid triangle 
	virtual void check_if_overlap();							//checks if any of the figure's points overlap{witin epsilon}
	bool operator < (const shape another_shape);					//^both of these throw errors if criteria aren't met to prevent invalid shapes
	bool operator > (const shape another_shape);
	bool operator >= (const shape another_shape);
	bool operator <= (const shape another_shape);
	bool operator == (const shape another_shape);
	virtual double calculate_perimeter();
	double seg_len(std::pair<double, double> point1, std::pair<double, double> point2);
	double get_epsilon() const;
	double get_perimeter() const;
	double get_area() const;							
	friend std::ostream& operator<<(std::ostream& os, const shape some_shape);
};

class Triangle : public shape
{
	void check_requirements();
	void check_if_overlap();
	std::pair<double, double> A;
	std::pair<double, double> B;
	std::pair<double, double> C;
	double calculate_perimeter();
	double calculate_area();
	public:
		Triangle(std::pair<double, double> A,
			std::pair<double, double> B,
			std::pair<double, double> C);
};

class Rectangle : public shape
{
	void check_requirements();
	void check_if_overlap();
	std::pair<double, double> A;
	std::pair<double, double> B;
	std::pair<double, double> C;
	std::pair<double, double> D;
	double calculate_perimeter();	
	double calculate_area();
	public:
		Rectangle(std::pair<double, double> A,
			std::pair<double, double> B,
			std::pair<double, double> C,
			std::pair<double, double> D);
};

class Circle : public shape
{
	void check_if_overlap();
	std::pair<double, double> D;
	double r;
	double calculate_perimeter();
	double calculate_area();
	public:
		Circle(std::pair<double, double> D, double r);
};