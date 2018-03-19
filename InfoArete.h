#pragma once

#include <sstream>

using namespace std;

//Ar�te d�finie par un co�t et un temps
class InfoArete
{
public:
	string nom;
	unsigned int cout;
	unsigned int temps;

	InfoArete(const string & nom, const unsigned int & cout, const unsigned int & temps) : nom(nom), cout(cout), temps(temps) { }

	operator string() const;
};

ostream & operator << (ostream & os, const InfoArete & infoAreteCarte);