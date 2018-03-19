#pragma once

#include <sstream>
#include "Point.h"

using namespace std;

//Sommet d�fini par un nom et par une position g�ographique
class InfoSommet
{
public:
	//diff�rents "types" d'un sommet
	enum TypeSommet { Normal = 0, Source = 1, Puits = 2 };

	string nom;
	bool visit�;
	unsigned int borneInf;
	unsigned int borneSup;
	TypeSommet type;
	int numerotation;
	Point position;

	InfoSommet(const string & nom, const unsigned int & borneInf, const unsigned int & borneSup) :
		nom(nom), borneInf(borneInf), borneSup(borneSup), type(TypeSommet::Normal), visit�(false), numerotation(0), position(Point(0, 0)) { }

	InfoSommet(const string & nom, const unsigned int & borneInf, const unsigned int & borneSup, const TypeSommet & type, const Point & point) :
		nom(nom), borneInf(borneInf), borneSup(borneSup), type(type), visit�(false), numerotation(0), position(point) { }

	operator string() const;
};

ostream & operator<<(ostream & os, const InfoSommet & infoSommetCarte);
