#include "InfoArete.h"

InfoArete::operator string() const
{
	ostringstream oss;
	oss << "cout = " << cout;
	oss << "temps = " << temps;
	return oss.str();
}

ostream & operator<<(ostream & os, const InfoArete & infoArete)
{
	return os << (string)infoArete;
}