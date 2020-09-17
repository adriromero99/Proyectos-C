
#ifndef VALIDADOR_H_
#define VALIDADOR_H_

#include "Tablero.h"

/*Un Validador se encarga de verificar si se ha logrado poner 4 Fichas seguidas iguales en un Tablero. Para esto, el Validador
 * copia partes del Tablero indicado en un 'Tablero Reducido' y verifica si hay 4 Fichas iguales en este Tablero Reducido.
 * Los atributos: fila, columna y piso iniciales indican desde que seccion del Tablero se empieza a copiar y los atributos 'finales'
 * indican hasta que seccion del Tablero se copia. En el Tablero reducido la ultima ficha jugada siempre ocupa la posicion central.
 * */


class Validador{

private:

	Piso* tableroReducido;

	unsigned int filaInicial, filaFinal;

	unsigned int columnaInicial, columnaFinal;

	unsigned int pisoInicial, pisoFinal;

	unsigned int fichasEnTablero;

	//Pre: una Ficha ha sido ingresada al Tablero y por lo tanto cambia la posicion de la ultima ficha jugada
	//Post: actualiza los valores iniciales y finales que indican cuales son las secciones del Tablero que se copiaran
	void actualizarPosicionesInicialesYFinales(Tablero* tablero);

	//Pre:-
	//Post: Vacia el Tablero reducido. Coloca '%' en el tablero reducido
	void vaciarTableroReducido();

	//Pre:-
	//Post: revisa el Tablero reducido verificando si hay 4 Fichas seguidas iguales en la fila central del mismo
	bool hay4EnFila();

	//Pre:-
	//Post: revisa el Tablero reducido verificando si hay 4 fichas seguidas iguales en la columna central del mismo
	bool hay4EnColumna();

	//Pre:-
	//Post: revisa una diagonal del Tablero reducido verificando si hay 4 fichas seguidas iguales
	bool hay4EnDiagonal1();

	//Pre:-
	//Post: revisa una diagonal del Tablero reducido verificando si hay 4 fichas seguidas iguales
	bool hay4EnDiagonal2();

	//Pre:-
	//Post: revisa la diagonal Transversal del tablero (no el reducido)
	bool hay4EnDiagonal1Tablero(Tablero* tablero);

	//Pre:-
	//Post: revisa la otra diagonal Transversal del tablero (no el reducido)
	bool hay4EnDiagonal2Tablero(Tablero* tablero);

	//Pre: El Tablero reducido esta vacio.
	//Post:	Copia una seccion relevante del Tablero en el tablero reducido.
	void cargarTableroReducido1(Tablero* tablero);

	//Pre: El Tablero reducido esta vacio.
	//Post:	Copia una seccion relevante del Tablero en el tablero reducido.
	void cargarTableroReducido2(Tablero* tablero);

	//Pre: El Tablero reducido esta vacio.
	//Post:	Copia una seccion relevante del Tablero en el tablero reducido.
	void cargarTableroReducido3(Tablero* tablero);


public:

	//Pre:-
	//Post: El validador es creado con un Tablero reducido vacio y con valores iniciales y finales no utilizables
	Validador();

	//Pre: una Ficha fue ingresada al Tablero
	//Post: indica si hay 4 fichas seguidas en algun lugar del Tablero
	bool hayGanador(Tablero* tablero);

	//Pre: una Ficha fue ingresada al Tablero
	//Post: indica si el Tablero esta lleno y por lo tanto hay un empate
	bool hayEmpate(Tablero* tablero);

	//Pre:-
	//Post: Libera los recursos utilizados
	~Validador();

};

#endif /* VALIDADOR_H_ */
