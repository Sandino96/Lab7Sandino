#include "corazaDura.h"
#include "soldados.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

corazaDura::corazaDura(string nombre, string procedencia, int edad, int durezaDeArmadura, int cantidadDeLanzas):soldados(nombre,procedencia,edad),cantidadDeLanzas(cantidadDeLanzas){
	if(durezaDeArmadura > 0 && durezaDeArmadura < 11){
		this -> durezaDeArmadura = durezaDeArmadura;
	} else {
		this -> durezaDeArmadura = 1;
	}
}

double corazaDura::ataque(){
	return this -> cantidadDeLanzas;
}

int corazaDura::defensa(){
	return this -> durezaDeArmadura;
}

string corazaDura::toString() const{
	stringstream ss;
	ss << "Coraza dura -> Nombre " << nombre << ", Cantidad de lanzas" << cantidadDeLanzas << ", Dureza de armadura" << durezaDeArmadura;
	return ss.str();
}