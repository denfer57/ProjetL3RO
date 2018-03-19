#pragma once

#include <sstream>

using namespace std;

//Classe de base des composants du graphe (sommets ou aretes)
class GrapheComposant
{
public:
	//Cl� unique, non nulle, qui diff�rentie les diff�rents composants du graphe.
	int cle;

	//Construit une �l�ment d'un graphe (pouvant �tre des sommets ou des ar�tes).
	GrapheComposant(const int cle);

	//Convertir en chaine de caract�re
	operator string() const;
};

//Op�rateur de sortie.
ostream & operator<<(ostream & os, const GrapheComposant & grapheElement);