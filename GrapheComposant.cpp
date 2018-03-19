#include "GrapheComposant.h"

GrapheComposant::GrapheComposant(const int cle) : cle(cle) { }

GrapheComposant::operator string() const
{
	ostringstream oss;
	oss << "Clé du composant = " << cle;
	return oss.str();
}

ostream & operator<<(ostream & os, const GrapheComposant & grapheElement)
{
	return os << (string)grapheElement;
}
