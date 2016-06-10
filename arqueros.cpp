#include "soldados.h"
#include "arqueros.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

arqueros::arqueros(string nombre, string procedencia, int edad, int cantidadDeFlechas, double precision):soldados(nombre,procedencia,edad), cantidadDeFlechas(cantidadDeFlechas), precision(precision){}

double arqueros::ataque(){
	return this -> cantidadDeFlechas * (this -> precision / 1000);
}

int arqueros::defensa(){
	return 0;
}

string arqueros::toString() const{
	stringstream ss;
	ss << "Arquero -> Nombre " << nombre << ", Cantidad de flechas " << cantidadDeFlechas << ", Precision " << precision;
	return ss.str();
}