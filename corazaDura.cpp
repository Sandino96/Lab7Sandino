#include "corazaDura.h"
#include "soldados.h"
#include <string>

using std::string;

corazaDura::corazaDura(string nombre, string procedencia, int edad, int durezaDeArmadura, int cantidadDeLanzas):nombre(nombre),procedencia(procedencia),
					   edad(edad), cantidadDeLanzas(cantidadDeLanzas){
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