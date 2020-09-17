/*
 * Portacartas.cpp
 *
 *  Created on: 25 jun. 2019
 *      Author: adrianstarly
 */


#include "Portacartas.h"
#include <stdlib.h>
#include <time.h>

Portacartas::Portacartas(){
}

Portacartas::~Portacartas(){
	vaciarPortaCartas();
}

void Portacartas::inicializar(unsigned int totalJugadores, menuNivelDificultad nivelDificultad){
	unsigned int i;

	this->vaciarPortaCartas();

	for(i=0; i<totalJugadores; i++){
		Mazo* mazo = new Mazo;
		this->casilleros.agregar(mazo);
	}

	std::cout<<"El portacartas tiene lugar para "<< i <<" mazos"<<std::endl<<std::endl;


	switch(nivelDificultad){

		case (FACIL):{
			std::cout<<"Esta en facil"<<std::endl;
			variableDificultad = 1;
			break;
		}
		case (INTERMEDIO):{
			std::cout<<"Esta en intermedio"<<std::endl;
			variableDificultad = 2;
			break;
		}
		case (DIFICIL):{
			std::cout<<"Esta en dificil"<<std::endl;
  			variableDificultad = 4;
  			break;
		}
		case (DIFICULTAD_NO_VALIDA):{
			std::cout<<"Esta en DIFICULTAD_NO_VALIDA"<<std::endl;
			variableDificultad = 1;
			break;
		}
	}

}

void Portacartas::vaciarPortaCartas() {
	// Recorrer el porta cartas
	for (unsigned int i = 1; i <= this->casilleros.contarElementos(); i++) {
		// Se libera la memoria usada para las cartas
		this->casilleros.obtener(i)->cartas.removerTodos();
	}
	this->casilleros.removerTodos();
}

void Portacartas::mostrarCartasJugador(unsigned int nroJugador){
	this->casilleros.obtener(nroJugador)->mostrarCartas();
}

void Portacartas::usarCartaJugador(unsigned int nroCarta, Tablero* tablero, ManagerListaJugadores * jugadores){
	unsigned int nroJugador = jugadores -> obtenerJugadorActual().obtenerId();
	char ficha = jugadores -> obtenerJugadorActual().obtenerFicha();

	this->casilleros.obtener(nroJugador)->cartas.obtener(nroCarta).usar(tablero, ficha, jugadores, &contadorCambioColor);
	this->removerCarta(nroJugador, nroCarta);
}

void Portacartas::removerCarta(unsigned int nroJugador, unsigned int nroCarta){
	this->casilleros.obtener(nroJugador)->cartas.remover(nroCarta);
	std::cout<<"Se ha removido la carta"<<std::endl;
	std::cout<<"Usted tiene "<<this->casilleros.obtener(nroJugador)->cartas.contarElementos()<<" cartas restantes"<<endl;
}

void Portacartas::darCartaAlJugador(unsigned int nroJugador){

	srand(time(NULL));

	unsigned int numeroAleatorio =  1 + rand() % (variableDificultad);
	if(numeroAleatorio == 1){
		Carta unaCarta;

		std::cout<<"Se ha entregado la carta: "<<unaCarta.identificador<<std::endl;

		this->casilleros.obtener(nroJugador)->cartas.agregar(unaCarta);
		std::cout<<"Usted tiene ahora: "<<this->casilleros.obtener(nroJugador)->cartas.contarElementos()<<" cartas"<<std::endl;
	}
	else{
		std::cout<<"Este turno no se le entregara Carta"<<std::endl;
	}

}

bool Portacartas::tieneAlMenos1Carta(unsigned int nroJugador){
	return(this->casilleros.obtener(nroJugador)->cartas.contarElementos()>=1);
}

bool Portacartas::tieneMaximoDeCartas(unsigned int nroJugador){
	return(this->casilleros.obtener(nroJugador)->cartas.contarElementos()==4);
}
