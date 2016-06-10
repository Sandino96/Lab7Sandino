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
	for (int i = 0; i < tropa.size(); ++i){
		delete tropa[i];
	}
}
string escuadron::toString()const{
	stringstream ss;
	ss << name;
	return ss.str();
}