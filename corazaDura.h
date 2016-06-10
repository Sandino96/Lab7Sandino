#pragma once
#include "soldados.h"
#include <string>

using std::string;

class corazaDura : public soldados{
	int durezaDeArmadura;
	int cantidadDeLanzas;

  public:
  	corazaDura(string,string,int,int,int);
  	double ataque();
  	int defensa();
};