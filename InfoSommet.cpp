#include "InfoSommet.h"

InfoSommet::operator string() const
{
	ostringstream oss;
	oss << "nom du sommet = " << nom;
	oss << "position = " << position;
	return oss.str();
}

ostream & operator<<(ostream & os, const InfoSommet & infoSommet)
{
	return os << (string)infoSommet;
}