/*
 * jugador.cpp
 *
 *  Created on: 11 may. 2019
 *      Author: matias
 */

#include "Jugador.h"


Jugador::Jugador() {
	this->totalFichasPorJugar = JUEGO_TOTAL_FICHAS_POR_JUGADOR;
	this->totalPartidosGanados = 0;
	this->totalPartidosEmpatados = 0;
	this->totalPartidosPerdidos = 0;

	this->id = 0;
	this->tipoFicha = '0';
	this->colorFichaIntRGB = 0;
}

Jugador::~Jugador() {
}

int Jugador::generarColorFicha() {
	int color;

	do {
		color = rand();

	}while(COLOR_MAX_INT_VALUE < color);

	return color;
}

void Jugador::setearColorFichaIntRGB(int colorFichaIntRGB) {
	if(0 <= colorFichaIntRGB && colorFichaIntRGB <= COLOR_MAX_INT_VALUE) {
		this->colorFichaIntRGB = colorFichaIntRGB;
	}
	else {
		throw std::string("ERROR: El valor entero para setear el color de la ficha debe estar entre [0, 16777215]");
	}
}


int Jugador::obtenerColorFichaIntRGB() {
	return this->colorFichaIntRGB;
}

void Jugador::configurarJugador(unsigned int id) {
	this->id = id;
	this->tipoFicha = (char)id;
	this->colorFichaIntRGB = this -> generarColorFicha();
	this->totalFichasPorJugar = JUEGO_TOTAL_FICHAS_POR_JUGADOR;
	this->totalPartidosGanados = 0;
	this->totalPartidosEmpatados = 0;
	this->totalPartidosPerdidos = 0;
}


void Jugador::setearId(unsigned int idDeseado) {
	this->id = idDeseado;
}

unsigned int Jugador::obtenerId() {
	return this->id;
}

void Jugador::setearFicha(char simbolosDeseados) {
	this->tipoFicha = simbolosDeseados;
}

char Jugador::obtenerFicha() {
	return this->tipoFicha;
}

unsigned int Jugador::obtenerTotalFichasPorJugar() {
	return this->totalFichasPorJugar;
}

void Jugador::decrementarTotalFichasPorJugar() {
	this->totalFichasPorJugar--;
}

unsigned int Jugador::obtenerTotalPartidosGanados() {
	return this->totalPartidosGanados;
}

void Jugador::incrementarTotalPartidosGanados() {
	this->totalPartidosGanados++;
}

unsigned int Jugador::obtenerTotalPartidosEmpatados() {
	return this->totalPartidosEmpatados;
}

void Jugador::incrementarTotalPartidosEmpatados() {
	this->totalPartidosEmpatados++;
}

unsigned int Jugador::obtenerTotalPartidosPerdidos() {
	return this->totalPartidosPerdidos;
}

void Jugador::incrementarTotalPartidosPerdidos() {
	this->totalPartidosPerdidos++;
}

