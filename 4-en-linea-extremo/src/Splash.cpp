/*
 * Splash.cpp
 *
 *  Created on: 27 abr. 2019
 *      Author: matias
 */

#include "Splash.h"

using namespace std;

Splash::Splash() {
	this->teclasValidas.push_back("c");
}
Splash::~Splash() {
}

void Splash::mostrarPantalla() {
	cout << "TP 3: JUEGO 4 EN LINEA" << endl;
	cout << "Cantidad de jugadores: N (N: número cargado por el usuario) " << endl;
	cout << "Dimensiones del tablero 3D: X, Y, Z (todas las dimensiones son cargadas por el usuario) " << endl;
	cout << endl << endl;
	cout << "Presione '"<< this->teclasValidas[0] << "' para continuar" << endl;
	cout << endl << endl << endl;
}

estadoJuego Splash::ejecutarAccionUsuario(string accionUsuario) {
	if(accionUsuario.compare(this->teclasValidas[0]) == 0) {
		return MENU_PRINCIPAL;
	}
	else {
		return SPLASH;
	}
}
