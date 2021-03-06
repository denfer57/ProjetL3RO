#pragma once

#include "GrapheComposant.h"

//Classe template repr�sentant un sommet d'un graphe.
template <class T>
class Sommet : public GrapheComposant
{
public:
	int degre;

	T info;

	//Construit un sommet du graphe � partir d'une cl� unique et d'une information. Le d�gr� est � 0 par d�faut.
	Sommet(const int cle, const T & info) : GrapheElement(cle), degre(0), info(info) { }

	//Convertit en chaine de caract�re
	operator toString() const;
};

template<class T>
Sommet<T>::operator toString() const
{
	ostringstream oss;

	oss << "Sommet (" << endl;
	oss << GrapheElement::operator string() << endl;
	oss << "degre = " << degre << endl;
	oss << "info = " << info << endl;
	oss << ")";

	return oss.str();
}

template <class T>
ostream & operator<<(ostream & os, const Sommet<T> & sommet)
{
	return os << (string)sommet;
}
