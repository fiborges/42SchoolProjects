#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"

// # define DEBUG

# ifdef DEBUG
#	define LOG(str) std::cout << str << std::endl;
# else
#	define LOG(str)
# endif

class Point
{
	private:
		const Fixed x;
		const Fixed y;

	public:
		//! Construtors and destructor
		Point();
		Point(const float x, const float y);
		Point(const Point& p);
		~Point();

		//! Operator overloading
		Point& operator=(const Point& p);		
		bool operator==(const Point& p);

		//! Getters and setters
		Fixed getX() const;
		Fixed getY() const;
};

#endif