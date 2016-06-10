#pragma once
#include <string>
#include "soldados.h"

using std::string;

class arqueros : public soldados{
	int cantidadDeFlechas;
	double precision;

  public:
  	arqueros(string,string,int,int,double);
  	string toString()const;
  	double ataque();
  	int defensa();
};