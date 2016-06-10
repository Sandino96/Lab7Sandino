#include "soldados.h"
#include "arqueros.h"
#include <string>

using std::string;

arqueros::arqueros(string nombre, string procedencia, int edad, int cantidadDeFlechas, double precision):nombre(nombre),procedencia(procedencia)
				   edad(edad), cantidadDeFlechas(cantidadDeFlechas), precision(precision){}

double arqueros::ataque(){
	return this -> cantidadDeFlechas * (this -> precision / 1000);
}

int arqueros::defensa(){
	return 0;
}