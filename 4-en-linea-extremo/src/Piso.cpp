#include "Fila.h"
#include "Lista.h"
#include "Piso.h"
#include <iostream>

Piso::Piso(unsigned int cantidadDeFilas, unsigned int cantidadDeColumnas){
	this->cantidadDeFilas = cantidadDeFilas;
	this->cantidadDeColumnas = cantidadDeColumnas;
	this->filas = new Lista<Fila*>;

	unsigned int longitud = cantidadDeColumnas;

	for(unsigned int i = 1; i<= cantidadDeFilas; i++){
		Fila* unaFila = new Fila(longitud);
		this->filas->agregar(unaFila);
	}
}

unsigned int Piso::obtenerCantidadDeFilas(){
	return(this->cantidadDeFilas);
}

unsigned int Piso::obtenerCantidadDeColumnas(){
	return(this->cantidadDeColumnas);
}

Lista<Fila*>* Piso::obtenerFilas(){
	return(this->filas);
}

void Piso::vaciarCasilleroEn(unsigned int numeroDeLaFila, unsigned int numeroDeLaColumna){
	this->obtenerFilaNumero(numeroDeLaFila)->vaciarCasilleroEn(numeroDeLaColumna);
}

bool Piso::estaVacioCasillero(unsigned int numeroDeLaFila, unsigned int numeroDeLaColumna){
	return(this->obtenerFilaNumero(numeroDeLaFila)->estaVacioCasillero(numeroDeLaColumna));
}

void Piso::ubicarFichaEn(unsigned int numeroDeLaFila, unsigned int numeroDeLaColumna, char ficha){
	this->obtenerFilaNumero(numeroDeLaFila)->ubicarFichaEn(numeroDeLaColumna, ficha);
}

char Piso::obtenerFichaEn(unsigned int numeroDeLaFila, unsigned int numeroDeLaColumna){
	return(this->obtenerFilaNumero(numeroDeLaFila)->obtenerFichaEn(numeroDeLaColumna));
}


Fila* Piso::obtenerFilaNumero(unsigned int numeroDeLaFila){
	return(this->filas->obtener(numeroDeLaFila));
}

void Piso::imprimir(){
	for(unsigned int i = 1; i<= this->cantidadDeFilas; i++){
			this->obtenerFilaNumero(i)->imprimir();
	}
}

Piso::~Piso(){
	for(unsigned int i = 1; i<= cantidadDeFilas; i++){
		this->obtenerFilaNumero(i)->obtenerCasilleros()->removerTodos();
		delete(this->obtenerFilaNumero(i));
	}
	delete(this->filas);
}

