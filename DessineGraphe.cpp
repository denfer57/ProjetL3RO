#include "DessineGraphe.h"

void DessineGraphe::creeDessinSommet(const Sommet<InfoSommet>& sommet)
{
	SDL_Rect Sommet;

	Sommet.x = (sommet.info.borneInf + (tailleSommet / 2)) * 10;
	Sommet.y = (sommet.info.borneSup + (tailleSommet / 2)) * 10;
	Sommet.h = tailleSommet;
	Sommet.w = tailleSommet;
	
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	SDL_RenderFillRect(renderer, &Sommet);
}

void DessineGraphe::creeDessinArete(const Arete<InfoArete, InfoSommet>& arete)
{
	SDL_Rect Arete;

	Arete.x = (arete.debut->info.borneInf + (tailleSommet / 2)) * 10;
	Arete.y = (arete.debut->info.borneSup + (tailleSommet / 2)) * 10;
	Arete.w = 150;
	Arete.h = 5;

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	SDL_RenderFillRect(renderer, &Arete);
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
	SDL_Rect Aretes[graphe.nombreAretes()];
	int posNom = 0;
	
	for (vector<Arete<InfoArete, InfoSommet>*>::const_iterator it = graphe.listeAretes.cbegin(); it != graphe.listeAretes.cend(); ++it)
	{
	    creeDessinArete(**it);
    	    
            Aretes[posNom].x = arete.debut->info.position.getX();
            Aretes[posNom].y = arete.debut->info.position.getY();
            Aretes[posNom].w = 150;
            Aretes[posNom].h = 5;

            posNom = posNom + 1;
        }
	
	posNom = 0;
		
	
}

void DessineGraphe::creeDessinGraphe(const Graphe<InfoArete, InfoSommet>& graphe)
{
	 // Création de la fenêtre
	pWindow = SDL_CreateWindow("Gestionnaire de chemins", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1366, 768, SDL_WINDOW_SHOWN);

	
	renderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	SDL_RenderClear(renderer);

	creeDessinAretes(graphe);
	creeDessinSommets(graphe);
<<<<<<< HEAD

=======
	
	SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
	
	for(int k=0; k<graphe.nombreAretes(); k++)
    	{
        	SDL_RenderFillRect( renderer, &Arrete[k] );
	}
	
>>>>>>> d897395875d1617e59d7fbaffd94951f2083a15e
	SDL_RenderPresent(renderer);

	bool continuer = true;

	while (continuer)
	{
		SDL_WaitEvent(&event); //Récupération de l'événement dans event 
		switch (event.type) //Test du type d'événement
		{

		case SDL_QUIT: //Si c'est un événement de type "Quitter"
			continuer = false;
			break;

		}
	}

	SDL_DestroyWindow(pWindow);
	SDL_Quit();
}
