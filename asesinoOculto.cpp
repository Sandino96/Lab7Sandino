#include "soldados.h"
#include "asesinoOculto.h"
#include <string>

using std::string;

asesinoOculto::asesinoOculto(string nombre, string procedencia, int edad, int asesinatos, int capacidadDesapercibido):nombre(nombre),procedencia(procedencia),
					   edad(edad), asesinatos(asesinatos){
	if(capacidadDesapercibido > 0 && capacidadDesapercibido < 11){
		this -> capacidadDesapercibido = capacidadDesapercibido;
	} else {
		this -> capacidadDesapercibido = 1;
	}
}

double asesinoOculto::ataque(){
	return asesinatos;
}

int asesinoOculto::defensa(){
	return capacidadDesapercibido * 10;
}