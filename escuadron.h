#pragma once
#include "soldados.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

class escuadron {
	string name;
	vector <soldados*> tropa;

  public:
  	escuadron(string,vector<soldados*>);
  	virtual~escuadron();
  	string toString()const;
  	double ataqueEscuadron();
  	double defensaEscuadron();
};