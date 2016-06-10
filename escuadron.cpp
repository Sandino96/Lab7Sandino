#include <string>
#include <sstream>
#include <vector>
#include "escuadron.h"
#include "soldados.h"

using std::string;
using std::stringstream;
using std::vector;

escuadron::escuadron(string name,vector <soldados*> tropa):name(name),tropa(tropa){}

escuadron::~escuadron(){
	for (int i = 0; i < tropa.size(); i++){
		delete tropa[i];
	}
}
string escuadron::toString()const{
	stringstream ss;
	ss << name;
	return ss.str();
}

double escuadron::ataque(vector <soldados*> tropa){
	double totalAtaque;
	for (int i = 0; i < tropa.size(); i++){
		totalAtaque += tropa.at(i) -> ataque();
	}
	return totalAtaque;
}

double escuadron::defensa(vector <soldados*> tropa){
	double totalDefensa;
	for (int i = 0; i < tropa.size(); i++){
		totalDefensa += tropa.at(i) -> defensa();
	}
	return totalDefensa;
}