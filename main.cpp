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
					if(posiciones1.size() > 0){
						for (int j = 0; j < posiciones1.size(); j++){
							int contadorInterno = 0;
							if (tropa != posiciones1.at(j)){
								contadorInterno++;
							}
							if (contadorInterno == posiciones1.size()){
								posiciones1.push_back(tropa);
								jugador1.push_back(escuadronesCreados.at(tropa));
							}
						}
					} else {
						posiciones1.push_back(tropa);
						jugador1.push_back(escuadronesCreados.at(tropa));
					}
				}
				int posiciones2 = new posiciones2[4];
				jugador++;
				cout << "Jugador " << jugador << " seleccione cuatro escuadrones según los indices de arriba"<< endl;
				for (int i = 1; i < 5; i++){
					int tropa;
					cout << "Tropa " << i;
					cin >> tropa;
					if(posiciones2.size() > 0){
						for (int j = 0; j < posiciones2.size(); j++){
							int contadorInterno = 0;
							if (tropa != posiciones2.at(j)){
								contadorInterno++;
							}
							if (contadorInterno == posiciones2.size()){
								posiciones2.push_back(tropa);
								jugador2.push_back(escuadronesCreados.at(tropa));
							}
						}
					} else {
						posiciones2.push_back(tropa);
						jugador2.push_back(escuadronesCreados.at(tropa));
					}
				}
				for (int i = 0; i < posiciones1.size(); i++){
					delete posiciones1.at(i);
					delete posiciones2.at(i);
				}
				bool nadieHaGanado = true;
				while(nadieHaGanado){
					for (int i = 0; i < ; ++i){
						
					}
				}
				for (int i = 0; i < jugador1.size(); i++){
					delete jugador1.at(i);
					delete jugador2.at(i);
				}
			} else {
				cout << "No hay suficientes escuadrones" << endl;
			}
		} else {
			break;
		}
	}
	for (int i = 0; i < escuadronesCreados.size(); i++){
		delete escuadronesCreados.at(i);
	}
	return 0;
}