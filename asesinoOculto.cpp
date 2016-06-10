#include "soldados.h"
#include "asesinoOculto.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

asesinoOculto::asesinoOculto(string nombre, string procedencia, int edad, int asesinatos, int capacidadDesapercibido):soldados(nombre,procedencia,edad), asesinatos(asesinatos){
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

string asesinoOculto::toString() const{
	stringstream ss;
	ss << "Asesino -> Nombre " << nombre << ", Asesinatos " << asesinatos << ", capacidadDesapercibido " << capacidadDesapercibido;
	return ss.str();
}