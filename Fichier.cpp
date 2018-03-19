#include "Fichier.h"

#include <iostream>
#include <fstream>
#include <strstream>
#include <algorithm>

#include <string>
#include <sstream>
#include <vector>
#include <iterator>

string Fichier::trim(const string & str)
{
	size_t first = str.find_first_not_of(' ');
	if (first == string::npos)
		return str;

	size_t last = str.find_last_not_of(' ');
	if (last == string::npos)
		return str;

	return str.substr(first, (last - first + 1));
}

vector<string> Fichier::split(const string & str, char delim)
{
	vector<string> elems;
	stringstream flux(str);
	string elem;
	while (getline(flux, elem, delim))
	{
		if (elem != "")
			elems.push_back(elem);
	}
	return elems;
}

string * Fichier::serialiseGraphe(Graphe<InfoArete, InfoSommet>* graphe)
{
	string * res = new string("sectionSommets\n");

	string source = "sources\n";
	string puits = "puits\n";
	for each (auto var in graphe->listeSommets)
	{
		*res += var->info.nom + " " + to_string(var->info.borneInf) + " " + to_string(var->info.borneSup) + " " +
			to_string(var->info.position.x) + " " + to_string(var->info.position.y) + "\n";
		if (var->info.type == InfoSommet::Source)
			source += var->info.nom + "\n";
		else if (var->info.type == InfoSommet::Puits)
			puits += var->info.nom + "\n";
	}

	*res += "\n" + source + "\n" + puits + "\nsectionArcs\n";

	for each (auto var in graphe->listeAretes)
	{
		*res += var->info.nom + " " + var->debut->info.nom + " " + var->fin->info.nom + " " +
			to_string(var->info.cout) + " " + to_string(var->info.temps) + "\n";
	}
	return res;
}

Graphe<InfoArete, InfoSommet>* Fichier::deserialiseGraphe(const string & str, vector<string> * sortieCommentaires)
{
	sortieCommentaires->clear();
	Graphe<InfoArete, InfoSommet>* graphe = new Graphe<InfoArete, InfoSommet>();

	string copieStr(str);
	copieStr.erase(remove(copieStr.begin(), copieStr.end(), '\r'), copieStr.end());

	stringstream flux(copieStr);
	string ligne;

	bool sources = false;
	bool puits = false;
	bool sectionSommets = false;
	bool sectionArcs = false;
	while (getline(flux, ligne))
	{
		ligne = trim(ligne);

		if (sectionSommets)
		{
			if (ligne == "")
				sectionSommets = false;
			else
			{
				vector<string> res = split(ligne, ' ');
				int bInf = 0;
				int bSup = 0;
				int x = 0;
				int y = 0;
				if (res.size() > 1)
				{
					bInf = stoi(res.at(1));
					bSup = stoi(res.at(2));
					if (res.size() > 3)
					{
						x = stoi(res.at(3));
						y = stoi(res.at(4));
					}
				}
				graphe->creeSommet(InfoSommet(res.at(0), bInf, bSup, InfoSommet::TypeSommet::Normal, Point(x, y)));
			}
		}
		else if (sectionArcs)
		{
			if (ligne == "")
				sectionArcs = false;
			else
			{
				vector<string> res = split(ligne, ' ');

				auto liste = graphe->listeSommets;
				Sommet<InfoSommet>* debut = NULL;
				Sommet<InfoSommet>* fin = NULL;
				for (vector<Sommet<InfoSommet>*>::const_iterator it = liste.cbegin(); it != liste.cend(); ++it)
				{
					string nom = (*it)->info.nom;
					if (nom == res.at(1))
						debut = *it;
					else if (nom == res.at(2))
						fin = *it;
				}

				graphe->creeArete(debut, fin, InfoArete(res.at(0), stoi(res.at(3)), stoi(res.at(4))));
			}
		}
		else if (sources)
		{
			if (ligne == "")
				sources = false;
			else
			{
				vector<string> res = split(ligne, ' ');
				auto liste = graphe->listeSommets;
				for (vector<Sommet<InfoSommet>*>::const_iterator it = liste.cbegin(); it != liste.cend(); ++it)
				{
					if ((*it)->info.nom == res.at(0))
						(*it)->info.type = InfoSommet::TypeSommet::Source;
				}
			}
		}
		else if (puits)
		{
			if (ligne == "")
				puits = false;
			else
			{
				vector<string> res = split(ligne, ' ');
				auto liste = graphe->listeSommets;
				for (vector<Sommet<InfoSommet>*>::const_iterator it = liste.cbegin(); it != liste.cend(); ++it)
				{
					if ((*it)->info.nom == res.at(0))
						(*it)->info.type = InfoSommet::TypeSommet::Puits;
				}
			}
		}
		else
		{
			if (ligne[0] == '#')
				sortieCommentaires->push_back(ligne.substr(1, ligne.size()));
			else if (ligne == "sectionSommets")
				sectionSommets = true;
			else if (ligne == "sectionArcs")
				sectionArcs = true;
			else if (ligne == "sources")
				sources = true;
			else if (ligne == "puits")
				puits = true;
		}
	}
	return graphe;
}