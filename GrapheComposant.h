#pragma once

#include <sstream>

using namespace std;

//Classe de base des composants du graphe (sommets ou aretes)
class GrapheComposant
{
public:
	//Clé unique, non nulle, qui différentie les différents composants du graphe.
	int cle;

	//Construit une élément d'un graphe (pouvant être des sommets ou des arêtes).
	GrapheComposant(const int cle);

	//Convertir en chaine de caractère
	operator string() const;
};

//Opérateur de sortie.
ostream & operator<<(ostream & os, const GrapheComposant & grapheElement);