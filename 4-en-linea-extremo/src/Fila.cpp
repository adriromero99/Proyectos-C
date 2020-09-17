
#include "Fila.h"
#include "Lista.h"
#include <iostream>


Fila::Fila(unsigned int longitud){
	this->longitud = longitud;
	this->casilleros = new Lista<char>;

	for(unsigned int i = 1; i <= this->longitud; i++){
		this->casilleros->agregar('0');
	}

}

Lista<char>* Fila::obtenerCasilleros(){
	return(this->casilleros);
}

unsigned int Fila::obtenerLongitud(){
	return(this->longitud);
}

char Fila::obtenerFichaEn(unsigned int posicion){

	char ficha = '0';

	if(posicion<= this->longitud){
		ficha = this->casilleros->obtener(posicion);
	}else{
		std::cout<<"La posicion donde se desea obtener la ficha no es valida, se devuelve un 0"<<std::endl;
	}

	return (ficha);
}

void Fila::vaciarCasilleroEn(unsigned int posicion){

	if(posicion <= this->longitud){
		this->casilleros->asignar('0', posicion);
	}else{
		std::cout<<"No se puede vaciar ese casillero pues la posicion no es valida"<<std::endl;
	}

}

bool Fila::estaVacioCasillero(unsigned int posicion){
	return(this->obtenerFichaEn(posicion)=='0');
}

void Fila::ubicarFichaEn(unsigned int posicion, char ficha){

	if(posicion <= this->longitud){
		this->casilleros->asignar(ficha, posicion);
	}else{
		std::cout<<"No se puede agregar una ficha en ese casillero pues la posicion no es valida"<<std::endl;
	}

}

void Fila::imprimir(){

	for(unsigned int i = 1; i <= this->longitud; i++){
		std::cout<< this->obtenerFichaEn(i);
	}
	std::cout<<std::endl;

}

Fila::~Fila(){
	this->casilleros->removerTodos();
	delete(this->casilleros);
}







