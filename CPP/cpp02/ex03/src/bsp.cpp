#include "Point.hpp"

/*
 	Equation of a line segment: y = mx + b
		* m - slope
		* b - Coordinate of the y axis intersection (0, b)
	m = (y2 - y1)/(x2 - x1)
	b = y - mx
 */
bool inSegment(const Point p1, const Point p2, const Point p)
{
	Fixed m((p1.getY() - p2.getY()) / (p1.getX() - p2.getX()));
	Fixed b(p1.getY() - m * p1.getX());

	return (p.getY() == m * p.getX() + b);
}

float myAbs(float x)
{
	return (x < 0 ? -x : x);
}

//! Using the Shoelace Formula to calculate the area of a triangle with any orientation
float area(const Point p1, const Point p2, const Point p3)
{
	Fixed first(p1.getX() * p2.getY() - p3.getX() * p2.getY());
	Fixed second(p3.getX() * p1.getY() - p1.getX() * p3.getY());
	Fixed third(p2.getX() * p3.getY() - p2.getX() * p1.getY());
	Fixed result(first + second + third);

	return (myAbs(result.toFloat()) / 2);
}

//! Dividing the triangle in 3 triangles, the sum of the inners should equal the total
bool bsp(Point const a, Point const b, Point const c, Point const point)
{	
	//! If the point belongs to one of the sides of the triangle
	if (inSegment(a, b, point) || inSegment(b, c, point) || inSegment(c, a, point))
		return (false);

	float areaABP = area(a, b, point);
	float areaBCP = area(b, c, point);
	float areaCAP = area(c, a, point);
	float areaABC = area(a, b, c);

	return (areaABC == areaABP + areaBCP + areaCAP);
}