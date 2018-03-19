#include "DessineGraphe.h"

void DessineGraphe::creeDessinSommet(const Sommet<InfoSommet>& sommet)
{
	SDL_Rect Sommet;

	Sommet.x = sommet.info.position.getX();
	Sommet.y = sommet.info.position.getY();
	Sommet.h = tailleSommet;
	Sommet.w = tailleSommet;

	SDL_RenderFillRect(renderer, &Sommet);
}

void DessineGraphe::creeDessinArete(const Arete<InfoArete, InfoSommet>& arete)
{
	
}

void DessineGraphe::creeDessinSommets(const Graphe<InfoArete, InfoSommet>& graphe)
{
	for (vector<Sommet<InfoSommet>*>::const_iterator it = graphe.listeSommets.cbegin(); it != graphe.listeSommets.cend(); ++it)
	{
		creeDessinSommet(**it);
	}
}

void DessineGraphe::creeDessinAretes(const Graphe<InfoArete, InfoSommet>& graphe)
{
	for (vector<Arete<InfoArete, InfoSommet>*>::const_iterator it = graphe.listeAretes.cbegin(); it != graphe.listeAretes.cend(); ++it)
	{
		creeDessinArete(**it);
	}
}

void DessineGraphe::creeDessinGraphe(const Graphe<InfoArete, InfoSommet>& graphe)
{
	 // Cr�ation de la fen�tre
	pWindow = SDL_CreateWindow("Gestionnaire de chemins", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1366, 768, SDL_WINDOW_SHOWN);

	
	renderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	SDL_RenderClear(renderer);

	creeDessinAretes(graphe);
	creeDessinSommets(graphe);
	
	SDL_RenderPresent(renderer);

	bool continuer = true;

	while (continuer)
	{
		SDL_WaitEvent(&event); //R�cup�ration de l'�v�nement dans event 
		switch (event.type) //Test du type d'�v�nement
		{

		case SDL_QUIT: //Si c'est un �v�nement de type "Quitter"
			continuer = false;
			break;

		}
	}

	SDL_DestroyWindow(pWindow);
	SDL_Quit();
}
