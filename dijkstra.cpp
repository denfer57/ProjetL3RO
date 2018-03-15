/*int static N = 10; //graphe de taille 10

void Initialisation(list<int> G[], int sdeb)//on initialise le degré des sommets
{
    for(int i = 0; i < N; i++)
        G[i] = 2147483647;
    G[sdeb] = 0;
}

void Trouve_min(list<int> G[])
{
    int mini = 2147483647;//infini
    int sommet = -1;
    for(int i = 0; i < N; i++)
    {
        if G[i] < mini{
            mini = G[i];
            sommet = i;
        }
    }
    return sommet;
}

void Maj_distances(int s1, int s2)
{
    if(G[s2] > G[s1] + Poids(s1,s2))
    {
        G[s2] = G[s1] + Poids(s1,s2);
        //prédecesseur[s2] = s1;
    }
}

void Dijkstra(list<int> G[], int Poids, int sdeb)
{
    Initialisation(G, sdeb);
    //Q = ensemble des noeuds
    while (G != 0)
    {
        int s1 = Trouve_min(G);
        G = G - s1;
        for(int i = 0; i < N; i++)
            Maj_distances(s1,s2);
        list<int> A[];
        int s = sfin;
        while(s != sdeb)
        {
            A = A + s;
            //s = prédecesseur[s];
        }
    }
}
*/
