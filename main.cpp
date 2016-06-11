#include "escuadron.h"
#include "soldados.h"
#include "corazaDura.h"
#include "arqueros.h"
#include "asesinoOculto.h"
#include <string>
#include <iostream>
#include <vector>

using std::cout;
using std::vector;
using std::cin;
using std::endl;

int main(int argc, char*argv[]){
	int opcion = 1;
	vector <escuadron*> escuadronesCreados;
	while(opcion != 3){
		cout << "1.- Agregar escuadron" << endl;
		cout << "2.- Simulacion" << endl;
		cout << "3.- Salir" << endl;
		cout << "Opcion: ";
		cin >> opcion;
		if (opcion == 1){
			string nombre;
			cout << "Nombre del escuadron: ";
			cin.ignore();
			getline(cin,nombre);
			vector <soldados*> tropas;
			int opcionSoldados = 1;
			while(opcionSoldados != 4){
				cout << "1.-Agregar arquero" << endl;
				cout << "2.-Agregar coraza dura" << endl;
				cout << "3.-Agregar asesino oculto" << endl;
				cout << "4.-Salir" << endl;
				cout << "Opcion: ";
				cin >> opcionSoldados;
				if (opcionSoldados == 1){
					string nombreArquero, procedenciaArquero;
					int edadArquero,flechas;
					double precision;
					cout << "Nombre: ";
					cin >> nombreArquero;
					cout << "Ciudad de procedencia: ";
					cin >> procedenciaArquero;
					cout << "Edad: ";
					cin >> edadArquero;
					cout << "Flechas en su aljaba: ";
					cin >> flechas;
					cout << "Precision en milimetros: ";
					cin >> precision;
					tropas.push_back(new arqueros(nombreArquero,procedenciaArquero,edadArquero,flechas,precision));
				} else if (opcionSoldados == 2){
					string nombreCoraza, procedenciaCoraza;
					int edadCoraza,dureza,lanzas;
					cout << "Nombre: ";
					cin >> nombreCoraza;
					cout << "Ciudad de procedencia: ";
					cin >> procedenciaCoraza;
					cout << "Edad: ";
					cin >> edadCoraza;
					cout << "Dureza de su armadura (1-10): ";
					cin >> dureza;
					if(dureza < 1 || dureza > 10){
						cout << "Usted valio porque no respeto los limites: Dureza = 1";
					}
					cout << "Precision en milimetros: ";
					cin >> lanzas;
					tropas.push_back(new corazaDura(nombreCoraza,procedenciaCoraza,edadCoraza,dureza,lanzas));
				} else if (opcionSoldados == 3){
					string nombreAsesino, procedenciaAsesino;
					int edadAsesino,asesinos,capacidadDesapercibido;
					cout << "Nombre: ";
					cin >> nombreAsesino;
					cout << "Ciudad de procedencia: ";
					cin >> procedenciaAsesino;
					cout << "Edad: ";
					cin >> edadAsesino;
					cout << "Capacidad de pasar desapercibido (1-10): ";
					cin >> capacidadDesapercibido;
					if(capacidadDesapercibido < 1 || capacidadDesapercibido > 10){
						cout << "Usted valio porque no respeto los limites: Capacidad de pasar desapercibido = 1" << endl;
					}
					cout << "Cantidad de asesinatos: ";
					cin >> asesinos;
					tropas.push_back(new asesinoOculto(nombreAsesino,procedenciaAsesino,edadAsesino,asesinos,capacidadDesapercibido));
				}
			}
			escuadronesCreados.push_back(new escuadron(nombre,tropas));
		} else if (opcion == 2){
			if(escuadronesCreados.size() >= 2){
				vector <escuadron*> jugador1;
				vector <escuadron*> jugador2;
				vector <int> posiciones1;
				vector <int> posiciones2;
				int jugador = 1;
				cout << "Jugador " << jugador << " seleccione cuatro escuadrones según los indices de arriba"<< endl;
				for (int i = 1; i < 5; i++){
					int tropa;
					cout << "Tropa " << i;
					cin >> tropa;
					jugador1.push_back(escuadronesCreados.at(tropa));
					escuadronesCreados.erase(escuadronesCreados.begin() + tropa);
				}
				jugador++;
				cout << "Jugador " << jugador << " seleccione cuatro escuadrones según los indices de arriba"<< endl;
				for (int i = 1; i < 5; i++){
					int tropa;
					cout << "Tropa " << i;
					cin >> tropa;
					jugador2.push_back(escuadronesCreados.at(tropa));
					escuadronesCreados.erase(escuadronesCreados.begin() + tropa);
				}
				jugador--;
				bool nadieHaGanado = true;
				while(nadieHaGanado){					
					int posicionFrontal1, posicionFrontal2;
					int posicionRetaguardia1,posicionRetaguardia2;
					for (int i = 0; i < posiciones1.size(); i++){
						cout << i << " - "<< jugador1.at(i) -> toString() << endl;
					}
					cout << "Escuadron que desee para su frontal: ";
					cin >> posicionFrontal1;
					cout << "Escuadron que desee para su retaguardia: ";
					cin >> posicionRetaguardia1;
					for (int i = 0; i < posiciones2.size(); i++){
						cout << i << " - "<< jugador2.at(i) -> toString() << endl;
					}
					cout << "Escuadron que desee para su frontal: ";
					cin >> posicionFrontal2;
					cout << "Escuadron que desee para su retaguardia: ";
					cin >> posicionRetaguardia2;
					if(jugador == 1){
						if((jugador1.at(posicionFrontal1) -> ataqueEscuadron()) > (jugador2.at(posicionRetaguardia2) -> defensaEscuadron())){
							cout << "Gana jugador 1" << endl;
							nadieHaGanado = false;
						} else {
							jugador++;
						}
					} else if (jugador == 2){
						if((jugador2.at(posicionFrontal2) -> ataqueEscuadron()) > (jugador1.at(posicionRetaguardia1)  -> defensaEscuadron())){
							cout << "Gana jugador 2" << endl;
							nadieHaGanado = false;
						} else {
							jugador--;
						}
					}
				}
				for (int i = 0; i < jugador1.size(); i++){
					delete jugador1.at(i);
					delete jugador2.at(i);
				}
			} else
				cout << "No hay suficientes escuadrones" << endl;
		} else {
			break;
		}
	}
	for (int i = 0; i < escuadronesCreados.size(); i++)
		delete escuadronesCreados.at(i);
	return 0;
}