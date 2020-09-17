
#include "Validador.h"
#include <iostream>

Validador::Validador(){
	this->tableroReducido = new Piso(7,7);
	this->fichasEnTablero = 0;
	this->filaInicial = 0;
	this->filaFinal = 0;
	this->columnaInicial = 0;
	this->columnaFinal = 0;
	this->pisoInicial = 0;
	this->pisoFinal = 0;
}

bool Validador::hayGanador(Tablero* tablero){

	//Aumenta el contador que indica la cantidad de fichas que hay en el Tablero
	this->fichasEnTablero++;

	bool hay4FichasSeguidas = false;
	this->actualizarPosicionesInicialesYFinales(tablero);

	this->vaciarTableroReducido();
	this->cargarTableroReducido1(tablero);

	if(this->hay4EnFila() || this->hay4EnColumna() || this->hay4EnDiagonal1() || this->hay4EnDiagonal2()){
		hay4FichasSeguidas = true;
	}else{
		this->vaciarTableroReducido();
		this->cargarTableroReducido2(tablero);
	}

	if(!hay4FichasSeguidas){
		if(this->hay4EnFila() || this->hay4EnColumna() || this->hay4EnDiagonal1() || this->hay4EnDiagonal2()){
			hay4FichasSeguidas = true;
		}else{
			this->vaciarTableroReducido();
			this->cargarTableroReducido3(tablero);
		}
	}

	if(!hay4FichasSeguidas){
		if(this->hay4EnFila() || this->hay4EnColumna() || this->hay4EnDiagonal1() || this->hay4EnDiagonal2()){
			hay4FichasSeguidas = true;
		}
	}

	if(!hay4FichasSeguidas){
		if(this->hay4EnDiagonal1Tablero(tablero) || this->hay4EnDiagonal2Tablero(tablero)){
			hay4FichasSeguidas = true;
		}
	}

	return(hay4FichasSeguidas);

}

bool Validador::hayEmpate(Tablero* tablero){
	unsigned int fichasMaximasPosibles = tablero->obtenerCantidadDePisos()*tablero->obtenerCantidadDeFilas()*tablero->obtenerCantidadDeColumnas();
	return(fichasMaximasPosibles == this->fichasEnTablero);
}

void Validador::vaciarTableroReducido(){
	for(unsigned int i=1; i<=7; i++){
		for(unsigned int j=1; j<=7; j++){
			this->tableroReducido->ubicarFichaEn(i,j,'%');
		}
	}
}

bool Validador::hay4EnFila(){

	unsigned int columnaActual=1;
	unsigned int fichasSeguidas=1;

	while(fichasSeguidas!=4 && columnaActual<7){
		char fichaActual = this->tableroReducido->obtenerFichaEn(4,columnaActual);
		char fichaSiguiente = this->tableroReducido->obtenerFichaEn(4,columnaActual+1);

		if(fichaActual==fichaSiguiente && fichaActual != '0' && fichaActual != '%'){
			fichasSeguidas++;
		}else{
			fichasSeguidas=1;
		}
		columnaActual++;
	}

	return(fichasSeguidas == 4);

}

bool Validador::hay4EnColumna(){

	unsigned int filaActual=1;
	unsigned int fichasSeguidas=1;

	while(fichasSeguidas!=4 && filaActual<7){
		char fichaActual = this->tableroReducido->obtenerFichaEn(filaActual,4);
		char fichaSiguiente = this->tableroReducido->obtenerFichaEn(filaActual+1,4);

		if(fichaActual==fichaSiguiente && fichaActual != '0' && fichaActual != '%'){
			fichasSeguidas++;
		}else{
			fichasSeguidas=1;
		}
		filaActual++;
	}

	return(fichasSeguidas == 4);

}

bool Validador::hay4EnDiagonal1(){
	unsigned int filaActual=1;
	unsigned int columnaActual=1;
	unsigned int fichasSeguidas=1;

	while(fichasSeguidas!=4 && filaActual<7 && columnaActual<7){
		char fichaActual = this->tableroReducido->obtenerFichaEn(filaActual,columnaActual);
		char fichaSiguiente = this->tableroReducido->obtenerFichaEn(filaActual+1,columnaActual+1);

		if(fichaActual==fichaSiguiente && fichaActual != '0' && fichaActual != '%'){
			fichasSeguidas++;
		}else{
			fichasSeguidas=1;
		}
		filaActual++;
		columnaActual++;
	}

	return(fichasSeguidas == 4);
}

bool Validador::hay4EnDiagonal2(){

	unsigned int filaActual=1;
	unsigned int columnaActual=7;
	unsigned int fichasSeguidas=1;

	while(fichasSeguidas!=4 && filaActual<7){
		char fichaActual = this->tableroReducido->obtenerFichaEn(filaActual,columnaActual);
		char fichaSiguiente = this->tableroReducido->obtenerFichaEn(filaActual+1,columnaActual-1);

		if(fichaActual==fichaSiguiente && fichaActual != '0' && fichaActual != '%'){
			fichasSeguidas++;
		}else{
			fichasSeguidas=1;
		}
		filaActual++;
		columnaActual--;
	}

	return(fichasSeguidas == 4);

}

bool Validador::hay4EnDiagonal1Tablero(Tablero* tablero){

	unsigned int fichasSeguidas = 1;
	bool hay4EnDiagonal1Tablero = false;

	unsigned int filaActual = this->filaInicial;
	unsigned int columnaActual = this->columnaInicial;
	unsigned int pisoActual = this->pisoFinal;

	while(filaActual<tablero->obtenerCantidadDeFilas() &&
		  columnaActual<tablero->obtenerCantidadDeColumnas() &&
		  pisoActual<tablero->obtenerCantidadDePisos() && fichasSeguidas <4){

		char fichaActual = tablero->obtenerFichaEn(pisoActual, filaActual, columnaActual);
		char fichaSiguiente = tablero->obtenerFichaEn(pisoActual+1, filaActual+1, columnaActual+1);

		if(fichaActual == fichaSiguiente && fichaActual != '0'){
			fichasSeguidas++;
		}else{
			fichasSeguidas=1;
		}

		pisoActual++;
		filaActual++;
		columnaActual++;

	}

	if(fichasSeguidas == 4){
		hay4EnDiagonal1Tablero = true;
	}

	return(hay4EnDiagonal1Tablero);

}

bool Validador::hay4EnDiagonal2Tablero(Tablero* tablero){

	unsigned int fichasSeguidas = 1;
	bool hay4EnDiagonal2Tablero = false;

	unsigned int filaActual = this->filaInicial;
	unsigned int columnaActual = this->columnaFinal;
	unsigned int pisoActual = this->pisoFinal;

	std::cout<<" filaFinal "<< filaInicial;
	std::cout<<" colFinal"<< columnaFinal;
	std::cout<<" pisoFinal"<< pisoFinal;

	while(filaActual<tablero->obtenerCantidadDeFilas() &&
		  columnaActual>1 &&
		  pisoActual<tablero->obtenerCantidadDePisos() && fichasSeguidas <4){

		char fichaActual = tablero->obtenerFichaEn(pisoActual, filaActual, columnaActual);
		char fichaSiguiente = tablero->obtenerFichaEn(pisoActual+1, filaActual+1, columnaActual-1);

		if(fichaActual == fichaSiguiente && fichaActual != '0'){
			fichasSeguidas++;
		}else{
			fichasSeguidas=1;
		}

		pisoActual++;
		filaActual++;
		columnaActual--;

	}

	if(fichasSeguidas == 4){
		hay4EnDiagonal2Tablero = true;
	}

	return(hay4EnDiagonal2Tablero);

}

void Validador::cargarTableroReducido3(Tablero* tablero){

	unsigned int diferenciaPisos= this->pisoInicial - this->pisoFinal;
	unsigned int diferenciaFilas = this->filaFinal - this->filaInicial;
	unsigned int corrimientoPiso = 0;
	unsigned int corrimientoFila = 0;

	if(tablero->obtenerCantidadDePisos()-tablero->obtenerPisoUltimaFicha()<3){
		corrimientoPiso = 3-(tablero->obtenerCantidadDePisos()-tablero->obtenerPisoUltimaFicha());
	}

	if(tablero->obtenerFilaUltimaFicha()<=3){
		corrimientoFila = 4-tablero->obtenerFilaUltimaFicha();
	}

	for(unsigned int i =1; i<=diferenciaPisos+1; i++){
		for(unsigned int j=1; j<=diferenciaFilas+1; j++){
			this->tableroReducido->ubicarFichaEn(corrimientoPiso+i, corrimientoFila+j, tablero->obtenerFichaEn(this->pisoInicial-i+1, this->filaInicial+j-1, tablero->obtenerColumnaUltimaFicha()));
		}
	}

}

void Validador::cargarTableroReducido2(Tablero* tablero){

	unsigned int diferenciaPisos= this->pisoInicial - this->pisoFinal;
	unsigned int diferenciaColumnas = this->columnaFinal - this->columnaInicial;
	unsigned int corrimientoPiso = 0;
	unsigned int corrimientoCol = 0;

	if(tablero->obtenerCantidadDePisos()-tablero->obtenerPisoUltimaFicha()<3){
		corrimientoPiso = 3-(tablero->obtenerCantidadDePisos()-tablero->obtenerPisoUltimaFicha());
	}

	if(tablero->obtenerColumnaUltimaFicha()<=3){
		corrimientoCol = 4-tablero->obtenerColumnaUltimaFicha();
	}

	for(unsigned int i=1; i<=diferenciaPisos+1; i++){
		for(unsigned int j=1; j<=diferenciaColumnas+1; j++){
			this->tableroReducido->ubicarFichaEn(corrimientoPiso+i,corrimientoCol+j,tablero->obtenerFichaEn(this->pisoInicial-i+1, tablero->obtenerFilaUltimaFicha(), this->columnaInicial+j-1));
		}
	}

}

void Validador::cargarTableroReducido1(Tablero* tablero){

	unsigned int diferenciaFilas = this->filaFinal - this->filaInicial;
	unsigned int diferenciaColumnas = this->columnaFinal - this->columnaInicial;
	unsigned int corrimientoFila = 0;
	unsigned int corrimientoCol = 0;

	if(tablero->obtenerFilaUltimaFicha()<=3){
		corrimientoFila = 4-tablero->obtenerFilaUltimaFicha();
	}
	if(tablero->obtenerColumnaUltimaFicha()<=3){
		corrimientoCol = 4-tablero->obtenerColumnaUltimaFicha();
	}

	for(unsigned int i=1; i<=diferenciaFilas+1; i++){
		for(unsigned int j=1; j<=diferenciaColumnas+1; j++){
			this->tableroReducido->ubicarFichaEn(i+corrimientoFila, j+corrimientoCol, tablero->obtenerFichaEn(tablero->obtenerPisoUltimaFicha(), this->filaInicial+i-1, this->columnaInicial+j-1));
		}
	}

}

void Validador::actualizarPosicionesInicialesYFinales(Tablero* tablero){

	unsigned int distanciaPrimeraColumna = tablero->obtenerColumnaUltimaFicha()-1;
	unsigned int distanciaUltimaColumna = tablero->obtenerCantidadDeColumnas()-tablero->obtenerColumnaUltimaFicha();
	unsigned int distanciaPrimeraFila = tablero->obtenerFilaUltimaFicha()-1;
	unsigned int distanciaUltimaFila = tablero->obtenerCantidadDeFilas()-tablero->obtenerFilaUltimaFicha();
	unsigned int distanciaPrimerPiso = tablero->obtenerPisoUltimaFicha()-1;
	unsigned int distanciaUltimoPiso = tablero->obtenerCantidadDePisos()-tablero->obtenerPisoUltimaFicha();

	if(distanciaPrimeraColumna >= 3){
		this->columnaInicial = tablero->obtenerColumnaUltimaFicha()-3;
	}else{
		this->columnaInicial = tablero->obtenerColumnaUltimaFicha() - distanciaPrimeraColumna;
	}

	if(distanciaUltimaColumna >= 3){
		this->columnaFinal = tablero->obtenerColumnaUltimaFicha()+3;
	}else{
		this->columnaFinal = tablero->obtenerColumnaUltimaFicha()+distanciaUltimaColumna;
	}

	if(distanciaPrimeraFila >= 3){
		this->filaInicial = tablero->obtenerFilaUltimaFicha()-3;
	}else{
		this->filaInicial = tablero->obtenerFilaUltimaFicha() - distanciaPrimeraFila;
	}

	if(distanciaUltimaFila >= 3){
		this->filaFinal = tablero->obtenerFilaUltimaFicha()+3;
	}else{
		this->filaFinal = tablero->obtenerFilaUltimaFicha()+distanciaUltimaFila;
	}

	if(distanciaPrimerPiso >= 3){
		this->pisoFinal = tablero->obtenerPisoUltimaFicha()-3;
	}else{
		this->pisoFinal = tablero->obtenerPisoUltimaFicha() - distanciaPrimerPiso;
	}

	if(distanciaUltimoPiso >= 3){
		this->pisoInicial = tablero->obtenerPisoUltimaFicha()+3;
	}else{
		this->pisoInicial = tablero->obtenerPisoUltimaFicha()+distanciaUltimoPiso;
	}

}

Validador::~Validador(){
	for(unsigned int i = 1; i<= this->tableroReducido->obtenerCantidadDeFilas(); i++){
		this->tableroReducido->obtenerFilaNumero(i)->obtenerCasilleros()->removerTodos();
		delete(this->tableroReducido->obtenerFilaNumero(i));
	}
	delete(this->tableroReducido);
}
