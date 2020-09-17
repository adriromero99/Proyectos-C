
#ifndef CARTA_H_
#define CARTA_H_

#include "Tablero.h"
#include "ManagerListaJugadores.h"
#include <iostream>

class Carta{

public:

	Carta();

	string identificador;

	void usar(Tablero* tablero, char fichaJugador, ManagerListaJugadores* jugadores, unsigned int *contadorCambioColor);

	void ignorarUltimaJugada(Tablero* tablero);

	void eliminarFicha(Tablero* tablero);

	void cambiarColorFicha(Tablero* tablero, char fichaJugador, ManagerListaJugadores* jugadores, unsigned int *contadorCambioColor);

	void ponerFicha2Veces(Tablero* tablero, char fichaJugador);

	void intercambioConVecina(Tablero* tablero);

	void portal(Tablero* tablero);

private:

	bool esValidaLaPosicion(unsigned int piso, unsigned int fila, unsigned int columna, Tablero* tablero);

	bool elCasilleroEstaVacio(unsigned int piso, unsigned int fila, unsigned int columna, Tablero* tablero);

	void cargarDenuevo(unsigned int *casilleroConElQueCambia);

	void intercambiar(Tablero* tablero,unsigned int casilleroConElQueCambia, unsigned int piso, unsigned int fila, unsigned int columna);

	void cambiarConInferior(Tablero* tablero, unsigned int piso, unsigned int fila, unsigned int columna);
	void cambiarConSuperior(Tablero* tablero, unsigned int piso, unsigned int fila, unsigned int columna);
	void cambiarConIzquierda(Tablero* tablero, unsigned int piso, unsigned int fila, unsigned int columna);
	void cambiarConDerecha(Tablero* tablero, unsigned int piso, unsigned int fila, unsigned int columna);

	void unirCasilleros(Tablero* tablero, unsigned int piso, unsigned int fila, unsigned int columna);

};



#endif /* CARTA_H_ */
