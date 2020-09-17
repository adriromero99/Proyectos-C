#ifndef FILA_H_
#define FILA_H_

#include "Lista.h"

/*
 * Una Fila es un conjunto ordenado de Casilleros. Cada Fila tiene una longitud que indica la cantidad de
 * Casilleros de la Fila. En cada Casillero puede colocarse una Ficha .Al crearse la Fila se crea con la
 * longitud deseada y con todos sus Casilleros vacios.
 *
 * Un Casillero en una Fila se considera vacio si tiene la ficha '0'
 *
 * Otorga funcionalidades para:
 * 	-Obtener la longitud de la Fila
 * 	-Obtener la ficha que hay en una determinada posicion de la Fila
 *  -Vaciar el Casillero en una posicion dada
 * 	-Indicar si un Casillero en una posicion esta vacio
 * 	-Ubicar una Ficha dada en alguno de los Casilleros de la Fila
 * 	-Imprimir todos las Casilleros de la Fila
 *
 * 	Un ejemplo:
 *
 * 		Fila unaFila(4); //Crea una Fila de longitud 4 y con todos sus Casilleros vacios
 * 		Fila unaFila.imprimir() //Muestra por pantalla los Casilleros de la Fila en esta caso mostraria: 0000
 * 		Fila unaFila.ubicarFichaEn(3, '#') //Ubica en la posicion 3 la ficha '#'. Resulta: 00#0
 *
 *
 * */


class Fila{

private:

	unsigned int longitud;

	Lista <char>* casilleros;

public:

	//Pre: la longitud con la que se cree la Fila debe ser un numero estrictamente mayor a 0
	//Post: la Fila se crea lista para ser usada y con todos sus Casilleros vacios (es decir con fichas '0')
	Fila(unsigned int longitud);

	//Pre:-
	//Post: devuelve todos los Casilleros de la Fila
	Lista<char>* obtenerCasilleros();

	//Pre:-
	//Post: devuelve la longitud de la Fila
	unsigned int obtenerLongitud();

	//Pre: la posicion en donde se desea obtener la Ficha pertenece al intervalo [1, longitud]
	//Post: se obtiene la ficha de la Fila en la posicion deseada, si en la posicion no hay una ficha se obtiene
	// '0'
	char obtenerFichaEn(unsigned int posicion);

	//Pre: la posicion en donde se desea vaciar el casillero pertenece al intervalo [1, longitud]. El casillero seleccionado no debe estar vacio
	//Post: vacia el casillero en la posicion seleccionada
	void vaciarCasilleroEn(unsigned int posicion);

	//Pre:-
	//Post: indica si el casillero en la posicion deseada se encuentra o no vacio
	bool estaVacioCasillero(unsigned int posicion);

	//Pre: la posicion donde se desea ubicar la ficha ingresada pertenece al intervalo [1, longitud]
	//Post: ubica la ficha ingresada en la posicion deseada
	void ubicarFichaEn(unsigned int posicion, char ficha);

	//Pre:-
	//Post: Muestra por pantalla los elementos de la fila
	void imprimir();

	//Pre:
	//Post: libera los recursos utilizados
	~Fila();

};



#endif /* FILA_H_ */
