#pragma once
#include <string>
#include "soldados.h"

using std::string;

class asesinoOculto : public soldados{
	int asesinatos;
	int capacidadDesapercibido;

  public:
  	asesinoOculto(string,string,int,int,int);
  	string toString()const;
  	double ataque();
  	int defensa();
};