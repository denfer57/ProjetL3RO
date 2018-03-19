#pragma once
#include "Graphe.h"
#include "InfoArete.h"
#include "InfoSommet.h"

class Fichier
{
private:
	static string trim(const string & str);
	static vector<string> split(const string & str, char delim);

public:
	static string * serialiseGraphe(Graphe<InfoArete, InfoSommet>* graphe);
	static Graphe<InfoArete, InfoSommet> * deserialiseGraphe(const string & str, vector<string> * sortieCommentaires);
};
