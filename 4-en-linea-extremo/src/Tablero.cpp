#include <iostream>
#include "Tablero.h"


Tablero::Tablero(){
	this->inicializarTablero(4, 4, 4);
}

Tablero::Tablero(unsigned int cantidadDePisos, unsigned int cantidadDeFilas, unsigned int cantidadDeColumnas){
	this->inicializarTablero(cantidadDePisos, cantidadDeFilas, cantidadDeColumnas);
}

void Tablero::inicializarTablero(unsigned int cantidadDePisos, unsigned int cantidadDeFilas, unsigned int cantidadDeColumnas){
	this->cantidadDePisos = cantidadDePisos;
	this->cantidadDeFilas = cantidadDeFilas;
	this->cantidadDeColumnas = cantidadDeColumnas;
	this->filaUltimaFicha = 0;
	this->columnaUltimaFicha = 0;
	this->pisoUltimaFicha = 0;

	this->pisos = new Lista<Piso*>;

	for(unsigned int i = 1; i<= cantidadDePisos; i++){
		Piso* unPiso = new Piso(cantidadDeFilas, cantidadDeColumnas);
		this->pisos->agregar(unPiso);
	}

	this->inicializado = true;

}

bool Tablero::estaInicializado() {
	return this->inicializado;
}

void Tablero::cambiarDimensiones(unsigned int cantidadDePisos, unsigned int cantidadDeFilas, unsigned int cantidadDeColumnas){
	this->destruirTablero();
	this->inicializarTablero(cantidadDePisos, cantidadDeFilas, cantidadDeColumnas);
}

bool Tablero::pudoPonerFicha(unsigned int fila, unsigned int columna, char ficha) {

	bool pudoPoner = false;
	unsigned int pisoActual = 1;

	if(fila<=this->cantidadDeFilas && columna<=this->cantidadDeColumnas&& fila>=1 && columna>=1){
		while(!this->estaVacioCasillero(pisoActual, fila, columna) &&pisoActual!=this->cantidadDePisos){
			pisoActual++;
		}

		if(this->estaVacioCasillero(pisoActual, fila, columna)){
			this->ubicarFichaEn(pisoActual, fila, columna, ficha);
			this->actualizarUltimaFicha(fila, columna, pisoActual);
			pudoPoner = true;
		}
	}

	return (pudoPoner);
}

unsigned int Tablero::obtenerCantidadDeFilas(){
	return(this->cantidadDeFilas);
}

unsigned int Tablero::obtenerCantidadDeColumnas(){
	return(this->cantidadDeColumnas);
}

unsigned int Tablero::obtenerCantidadDePisos(){
	return(this->cantidadDePisos);
}

void Tablero::actualizarUltimaFicha(unsigned int nuevaFila, unsigned int nuevaColumna, unsigned int nuevoPiso){
	this->filaUltimaFicha = nuevaFila;
	this->columnaUltimaFicha = nuevaColumna;
	this->pisoUltimaFicha = nuevoPiso;
}

unsigned int Tablero::obtenerFilaUltimaFicha(){
	return(this->filaUltimaFicha);
}

unsigned int Tablero::obtenerColumnaUltimaFicha(){
	return(this->columnaUltimaFicha);
}

unsigned int Tablero::obtenerPisoUltimaFicha(){
	return(this->pisoUltimaFicha);
}

void Tablero::vaciarCasilleroEn(unsigned int numeroDelPiso, unsigned int numeroDeLaFila, unsigned int numeroDeLaColumna){
	this->ubicarFichaEn(numeroDelPiso, numeroDeLaFila, numeroDeLaColumna, '0');
}

bool Tablero::estaVacioCasillero(unsigned int numeroDelPiso, unsigned int numeroDeLaFila, unsigned int numeroDeLaColumna){
	return(this->obtenerPiso(numeroDelPiso)->obtenerFilaNumero(numeroDeLaFila))->estaVacioCasillero(numeroDeLaColumna);
}

void Tablero::ubicarFichaEn(unsigned int numeroDelPiso, unsigned int numeroDeLaFila, unsigned int numeroDeLaColumna, char ficha){
	this->obtenerPiso(numeroDelPiso)->ubicarFichaEn(numeroDeLaFila, numeroDeLaColumna, ficha);
	this->actualizarUltimaFicha(numeroDeLaFila, numeroDeLaColumna, numeroDelPiso);
}

char Tablero::obtenerFichaEn(unsigned int numeroDelPiso, unsigned int numeroDeLaFila, unsigned int numeroDeLaColumna){
	return(this->obtenerPiso(numeroDelPiso)->obtenerFichaEn(numeroDeLaFila, numeroDeLaColumna));
}

Piso* Tablero::obtenerPiso(unsigned int numeroDelPiso){
	return(this->pisos->obtener(numeroDelPiso));
}

void Tablero::imprimir(){
	for(unsigned int i = 1; i<= this->cantidadDePisos; i++){
		std::cout<<":::::Piso "<<i<<":::::"<<std::endl;
		this->obtenerPiso(i)->imprimir();
		std::cout<<std::endl;
	}
}

void Tablero::destruirTablero(){
	for(unsigned int i = 1; i<= cantidadDePisos; i++){
		for(unsigned int j=1; j<= cantidadDeFilas; j++){
			this->obtenerPiso(i)->obtenerFilas()->obtener(j)->obtenerCasilleros()->removerTodos();
		}
		delete(this->obtenerPiso(i));
	}
	delete(this->pisos);
	this->inicializado = false;
}

void Tablero::reiniciarTablero() {
	unsigned int cantidadDePisos = this->cantidadDePisos;
	unsigned int cantidadDeFilas = this->cantidadDeFilas;
	unsigned int cantidadDeColumnas = this->cantidadDeColumnas;
	this->destruirTablero();
	this->inicializarTablero(cantidadDePisos, cantidadDeFilas, cantidadDeColumnas);
}

Tablero::~Tablero(){
	this->destruirTablero();
}


