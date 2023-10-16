#include "Point.hpp"

Point :: Point() : x(0), y(0)
{
	LOG("Default constructor called.");
}

Point :: Point(const float x, const float y) : x(x), y(y)
{
	LOG("Parameter constructor called.");
}

Point::Point( const Point &p ) : x(p.x), y(p.y) 
{
    LOG("Point created");
}

Point :: ~Point()
{
	LOG("Point (" << this->x << ", " << this->y << ") deleted.");
}

Point& Point :: operator=(const Point& p)
{
	if (this == &p)
		return (*this);
	(Fixed)this->x = p.getX();
	(Fixed)this->y = p.getY();
	return (*this);
}

bool Point :: operator==(const Point& p)
{
	return(this->getX() == p.getX() && this->getY() == p.getY());
}

Fixed Point :: getX() const
{
	return (Fixed(this->x));
}

Fixed Point :: getY() const
{
	return (Fixed(this->y));
}