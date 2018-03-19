#include <iostream>
#include <fstream>
#include "Fichier.h"
#include <string>

using namespace std;

void Fichier::LectureFichier(char f)
{
	ifstream fichier("ExemplesGraphes/data_VRPTW_10.gpr", ios::in);  // on ouvre en lecture

	if (fichier)  // si l'ouverture a fonctionné
	{
		string ligne;
		while (getline(fichier, ligne))  // tant que l'on peut mettre la ligne dans "contenu"
		{
			cout << ligne << endl;  // on l'affiche
		}
		fichier.close();
	}
	else
		cerr << "Impossible d'ouvrir le fichier !" << endl;
}
