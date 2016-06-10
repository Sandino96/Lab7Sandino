#pragma once
#include <string>

using std::string;

class soldados {
  protected:
	string nombre;
	string procedencia;
	int edad;
  public:
  	soldados(string,string,int);
  	virtual double ataque() = 0;
  	virtual int defensa() = 0;
};