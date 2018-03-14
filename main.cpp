    #include <iostream>
    #include <cstdlib>
    #include <cstdio>
    #include <stdlib.h>
    #include <stdio.h>

#include <SDL2/SDL.h>

int main(int argc, char** argv)
{
    SDL_Event event; // Cette variable servira plus tard à gérer les événements

    /* Création de la fenêtre */
    SDL_Window* pWindow = NULL;
    pWindow = SDL_CreateWindow("Gestionnaire des chemins",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1366, 768, SDL_WINDOW_SHOWN);

    // Setup renderer
    SDL_Renderer* renderer = NULL;
    renderer =  SDL_CreateRenderer( pWindow, -1, SDL_RENDERER_ACCELERATED);

    // Set render color to red ( background will be rendered in this color )
    SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );

    // Clear winow
    SDL_RenderClear( renderer );

    /*SDL_Surface *ecran = NULL;
    ecran = SDL_GetWindowSurface(pWindow);*/


    //------ Espace de dessin du graph------

    //Traits horisontaux

    int coordonneHX[3];
    int coordonneHY[5];
    SDL_Rect nomTraitH[15];

    int posNom = 0;

    for(int i=0; i<3; i++)
    {
        coordonneHX[i] = i;

        for(int j=0; j<5; j++)
        {
            coordonneHY[j] = j;

            nomTraitH[posNom].x = 100+(250*i);
            nomTraitH[posNom].y = 50+(167*j);
            nomTraitH[posNom].w = 150;
            nomTraitH[posNom].h = 5;

            posNom = posNom + 1;
        }
    }

    //Traits verticaux

    int coordonneVX[4];
    int coordonneVY[4];
    SDL_Rect nomTraitV[16];

    posNom = 0;

    for(int i=0; i<4; i++)
    {
        coordonneVX[i] = i;

        for(int j=0; j<4; j++)
        {
            coordonneVY[j] = j;

            nomTraitV[posNom].x = 50+(250*i);
            nomTraitV[posNom].y = 80+(167*j);
            nomTraitV[posNom].w = 5;
            nomTraitV[posNom].h = 100;

            posNom = posNom + 1;
        }
    }

    //Sommets

    int coordonneSX[4];
    int coordonneSY[4];
    SDL_Rect nomSommet[16];

    posNom = 0;

    for(int i=0; i<4; i++)
    {
        coordonneSX[i] = i;

        for(int j=0; j<5; j++)
        {
            coordonneVY[j] = j;

            nomSommet[posNom].x = 43+(250*i);
            nomSommet[posNom].y = 43+(167*j);
            nomSommet[posNom].w = 20;
            nomSommet[posNom].h = 20;

            posNom = posNom + 1;
        }
    }


    // Set render color to blue ( rect will be rendered in this color )
    SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );

    // Render rect
    for(int k=0; k<15; k++)
    {
        SDL_RenderFillRect( renderer, &nomTraitH[k] );
    }
    for(int l=0; l<16; l++)
    {
        SDL_RenderFillRect( renderer, &nomTraitV[l] );
    }
    for(int m=0; m<20; m++)
    {
        SDL_RenderFillRect( renderer, &nomSommet[m] );
    }


    // Render the rect to the screen
    SDL_RenderPresent(renderer);


    //---------------------------------------


    bool continuer = true;

    while (continuer)
    {
        SDL_WaitEvent(&event); /* Récupération de l'événement dans event */
        switch(event.type) /* Test du type d'événement */
        {
            /*case SDL_MOUSEBUTTONDOWN:

                if (MovePossible(BaseX, BaseY, cibleX, cibleY, PM)) //Si le mouvement est réalisable
                {

                SDL_Flip(ecran);

                }

                break;*/

            case SDL_QUIT: /* Si c'est un événement de type "Quitter" */
                continuer = false;
                break;

        }
    }

    //SDL_FreeSurface(ecran);
    SDL_DestroyWindow(pWindow);
    SDL_Quit();

    return 0;
}
