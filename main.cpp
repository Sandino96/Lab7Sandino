#include "escuadron.h"
#include "soldados.h"
#include <string>
#include <iostream>
#include <vector>

using std::cout;
using std::vector;
using std::cin;
using std::endl;

int main(){
	int opcion = 1;
	while(opcion != 3){
		cout << "1.- Agregar escuadron: " << endl;
		cout << "1.- Simulacion: " << endl;
		cout << "3.- Salir: " << endl;
		cout << "Opcion: ";
		cin >> opcion;
		if (opcion == 1){
			string nombre;
			cout << "Nombre del escuadron: ";
			cin.ignore();
			getline(cin,nombre);
			int opcionSoldados = 1;
			while(opcion != 4){
				cout << "1.-Agregar arquero: " << endl;
				cout << "2.-Agregar asesino oculto: " << endl;
				cout << "3.-Agregar coraza dura: " << endl;
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
					cout << "Edad";
					cin >> edadArquero;
					cout << "Flechas en su aljaba: ";
					cin >> flechas;
					cout << "Precision en milimetros: ";
					cin >> precision;
				} else if (opcionSoldados == 1){
					string nombreCoraza, procedenciaCoraza;
					int edadCoraza,dureza,lanzas;
					cout << "Nombre: ";
					cin >> nombreCoraza;
					cout << "Ciudad de procedencia: ";
					cin >> procedenciaCoraza;
					cout << "Edad";
					cin >> edadCoraza;
					cout << "Dureza de su armadura (1-10): ";
					cin >> dureza;
					if(dureza < 0 && dureza > 11){
						cout << "Usted valio porque no respeto los limites: Dureza = 1";
					}
					cout << "Precision en milimetros: ";
					cin >> lanzas;
				} else if (opcionSoldados == 1){
					string nombreAsesino, procedenciaAsesino;
					int edadAsesino,asesinos,capacidadDesapercibido;
					cout << "Nombre: ";
					cin >> nombreAsesino;
					cout << "Ciudad de procedencia: ";
					cin >> procedenciaAsesino;
					cout << "Edad";
					cin >> edadAsesino;
					cout << "Capacidad de pasar desapercibido (1-10): ";
					cin >> capacidadDesapercibido;
					if(dureza < 0 && dureza > 11){
						cout << "Usted valio porque no respeto los limites: Capacidad de pasar desapercibido = 1" << endl;
					}
					cout << "Cantidad de asesinatos: ";
					cin >> asesinos;
				}
			}
			vector <escuadron> escuadronesCreados;
			escuadronesCreado.push_back(new escuadron);
		}
	}
	return 0;
}