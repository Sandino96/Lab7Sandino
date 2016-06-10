#pragma once
#include <string>
#include "soldados.h"

using std::string;

class arqueros : public soldados{
	int cantidadDeFlechas;
	double precision;

  public:
  	arqueros(string,string,int,int,double);
  	double ataque();
  	int defensa();
};