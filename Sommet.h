#pragma once

#include "GrapheComposant.h"

//Classe template représentant un sommet d'un graphe.
template <class T>
class Sommet : public GrapheComposant
{
public:
	int degre;

	T info;

	//Construit un sommet du graphe à partir d'une clé unique et d'une information. Le dégré est à 0 par défaut.
	Sommet(const int cle, const T & info) : GrapheElement(cle), degre(0), info(info) { }

	//Convertit en chaine de caractère
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
