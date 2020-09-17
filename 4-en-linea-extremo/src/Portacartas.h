

#ifndef PORTACARTAS_H_
#define PORTACARTAS_H_

#include "Mazo.h"
#include "Opciones.h"



class Portacartas{

public:
	unsigned int variableDificultad;
	unsigned int contadorCambioColor;

	Lista <Mazo*> casilleros; // se tendrá tantos casilleros, como jugadores estén jugando

	void mostrarCartasJugador(unsigned int nroJugador);

	//void usarCartaJugador(unsigned int nroJugador, unsigned int nroCarta, char ficha, Tablero* tablero, ManagerListaJugadores * jugadores);
	void usarCartaJugador(unsigned int nroCarta, Tablero* tablero, ManagerListaJugadores * jugadores);

	Portacartas();

	~Portacartas();

	void inicializar(unsigned int totalJugadores, menuNivelDificultad nivelDificultad);

	void vaciarPortaCartas();

	bool tieneAlMenos1Carta(unsigned int nroJugador);

	void removerCarta(unsigned int nroJugador, unsigned int numeroCarta);

	void darCartaAlJugador(unsigned int nroJugador);

	bool tieneMaximoDeCartas(unsigned int nroJugador);

};



#endif /* PORTACARTAS_H_ */
