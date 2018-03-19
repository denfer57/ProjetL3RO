#pragma once

#include "SDL.h"
#include "Graphe.h"
#include "InfoSommet.h"
#include "InfoArete.h"

class DessineGraphe {
private:
	SDL_Event event; // Cette variable pour gérer les événements
	SDL_Renderer* renderer = NULL;
	SDL_Window* pWindow = NULL;
	void creeDessinSommet(const Sommet<InfoSommet> & sommet);
	void creeDessinArete(const Arete<InfoArete, InfoSommet> & arete);
	void creeDessinSommets(const Graphe<InfoArete, InfoSommet> & graphe);
	void creeDessinAretes(const Graphe<InfoArete, InfoSommet> & graphe);
public :
	int tailleSommet;

	DessineGraphe() : tailleSommet(20) { };
	DessineGraphe(int tailleSommet) : tailleSommet(tailleSommet) { };

	void creeDessinGraphe(const Graphe<InfoArete, InfoSommet> & graphe);
};
