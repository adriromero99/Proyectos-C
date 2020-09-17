/*
 * ManagerListaJugadores.cpp
 *
 *  Created on: 9 jun. 2019
 *      Author: matias
 */

#include "ManagerListaJugadores.h"

ManagerListaJugadores::ManagerListaJugadores() {

}
ManagerListaJugadores::~ManagerListaJugadores() {

}

// Métodos nuevos
void ManagerListaJugadores::irAlPrimerJugador() {
	this->reiniciarCursor();
}

void ManagerListaJugadores::cambiarJugador() {
	if(!this -> avanzarCursor()) {
		this -> irAlPrimerJugador();
	}
}

void ManagerListaJugadores::cargarJugadores(unsigned int totalJugadores) {
	Jugador jugador;

	if(totalJugadores < 1) {
		throw std::string("ERROR: la cantidad cantidad de jugadores debe ser un número entero mayor a 0");
	}


	this -> removerTodos();

	for(unsigned int i = 0; i < totalJugadores; i++) {
		jugador.setearId(i + 1);
		jugador.setearFicha((char)(i + 1 + 48));
		jugador.setearColorFichaIntRGB(jugador.generarColorFicha());

		this -> agregar(jugador, i+1);
	}
	this -> iniciarCursor();
	this -> irAlPrimerJugador();
}

void ManagerListaJugadores::imprimirInfoJugadores() {
	for(unsigned int i = 0; i < this->contarElementos(); i++) {
		cout << "Jugador " << "id_ " << this->obtener(i+1).obtenerId() << " Ficha: " << this->obtener(i+1).obtenerFicha() << " Color: " << this->obtener(i+1).obtenerColorFichaIntRGB() << endl;
	}
}

unsigned int ManagerListaJugadores::contarJugadores() {
	return this->contarElementos();
}

Jugador ManagerListaJugadores::obtenerJugadorActual() {
	return this->obtenerCursor();
}

Jugador ManagerListaJugadores::obtenerJugadorPorId(unsigned int posicion) {
	return this->obtener(posicion);
}

