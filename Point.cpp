#include "Point.h"

Point::operator string() const
{
	ostringstream os;
	os << "( " << x << ", " << y << " )";
	return os.str();
}

ostream & operator << (ostream & os, const Point & u)
{
	os << (string)u;
	return os;
}
