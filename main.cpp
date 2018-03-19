#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <list>
#include "SDL.h"
#include "Fichier.h"
#include "Graphe.h"
#include "InfoArete.h"
#include "InfoSommet.h"
#include "DessineGraphe.h"

using namespace std;

Graphe<InfoArete, InfoSommet> * creeGrapheTest()
{
	//données issues de data_VRPTW_10_3_2_4.gpr
	cout << "Construction d'un graphe complet avec 8 sommets..." << endl;

	const int nbSommet = 8;
	const int nbArete = nbSommet * (nbSommet - 1) / 2;//nombre max d'arêtes possibles

	Graphe<InfoArete, InfoSommet> * graphe = new Graphe<InfoArete, InfoSommet>();

	// Création des sommets
	Sommet<InfoSommet> * sommets[nbSommet];
	sommets[0] = graphe->creeSommet(InfoSommet("i1", 0, 0));
	sommets[1] = graphe->creeSommet(InfoSommet("i2", 2, 12));
	sommets[2] = graphe->creeSommet(InfoSommet("i3", 15, 25));
	sommets[3] = graphe->creeSommet(InfoSommet("i4", 5, 15));
	sommets[4] = graphe->creeSommet(InfoSommet("i5", 1, 36));
	sommets[5] = graphe->creeSommet(InfoSommet("i6", 3, 47));
	sommets[6] = graphe->creeSommet(InfoSommet("i7", 1, 41));
	sommets[7] = graphe->creeSommet(InfoSommet("i8", 1, 58));

	// Création des arêtes
	Arete<InfoArete, InfoSommet> * aretes[nbArete];
	aretes[0] = graphe->creeArete(sommets[0], sommets[1], InfoArete("arc1", 4, 7));
	aretes[1] = graphe->creeArete(sommets[0], sommets[2], InfoArete("arc2", 18, 20));
	aretes[2] = graphe->creeArete(sommets[2], sommets[3], InfoArete("arc3", 14, 10));
	aretes[3] = graphe->creeArete(sommets[3], sommets[4], InfoArete("arc4", 20, 6));
	aretes[4] = graphe->creeArete(sommets[2], sommets[4], InfoArete("arc5", 17, 12));
	aretes[5] = graphe->creeArete(sommets[4], sommets[5], InfoArete("arc6", 20, 6));
	aretes[6] = graphe->creeArete(sommets[5], sommets[6], InfoArete("arc7", 12, 1));
	aretes[7] = graphe->creeArete(sommets[7], sommets[5], InfoArete("arc8", 8, 11));
	
	return graphe;
}

int main(int argc, char** argv)
{
	Graphe<InfoArete, InfoSommet> * graphe = creeGrapheTest();
	//copie 
	//Graphe<InfoArete, InfoSommet> * graphe1 = new Graphe<InfoArete, InfoSommet>(*graphe);

	/*DessineGraphe * dessin = new DessineGraphe();
	dessin->creeDessinGraphe(*graphe);*/

	delete graphe;
	//delete graphe1;

	system("pause");
	return 0;
}

