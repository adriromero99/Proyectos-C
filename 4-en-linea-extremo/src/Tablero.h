#ifndef TABLERO_H_
#define TABLERO_H_


#include "Piso.h"


/*Un Tablero es un arreglo ordenado de Pisos. Cada Piso tiene un numero que lo identifica. En el Tablero cada piso
 * se ubica uno arriba del otro de manera que el Piso inferior sea siempre el numero 1 y el piso superior sea igual
 * a la cantidad de pisos del Tablero. Cuando un Tablero es creado este se crea con todos sus casilleros vacios.
 * Un casillero se considera vacio si en el hay un '0'
 *
 *
 * Otorga funcionalidades para:
 *
 * 		-obtener la cantidad de Pisos que tiene el Tablero
 * 		-obtener la cantidad de Filas de cada Piso del Tablero
 * 		-obtener la cantidad de Columnas de cada Piso del Tablero
 * 		-cambiar las dimensiones del Tablero
 * 		-acceder a un Piso deseado
 * 		-vaciar un casillero deseado del Tablero
 * 		-indicar si un casillero del Tablero esta vacio o no
 *		-obtener la ficha que ocupa un casillero del Tablero
 *		-ubicar una ficha en una posicion deseda del Tablero
 *		-devolver Piso, Fila y Columna de la ultima ficha que fue ingresada en el Tablero
 *		-actualizar Piso, Fila y Columna de la ultima ficha que ingreso al Tablero
 *
 *	Un ejemplo:
 *
 *		Tablero miTablero(2,3,4) // Crea un Tablero de 2 pisos, 3 filas y 4 columnas
 *		miTablero.imprimir() // muestra por pantalla lo siguiente:
 *
 *		:::Piso 1:::	:::Piso 2:::
 *		0000			0000
 *		0000			0000
 *		0000			0000
 *
 *		ubicarFichaEn(2,1,3,'#') // coloca la ficha '#' en el piso 2, fila 1 y columna 3 y el Tablero queda asi:
 *
 *		:::Piso 1:::	:::Piso 2:::
 *		0000			00#0
 *		0000			0000
 *		0000			0000
 *
 * */

class Tablero{

private:

	unsigned int cantidadDePisos;

	unsigned int cantidadDeFilas;

	unsigned int cantidadDeColumnas;

	Lista<Piso*>* pisos;

	unsigned int pisoUltimaFicha;

	unsigned int columnaUltimaFicha;

	unsigned int filaUltimaFicha;

	bool inicializado;

	//Pre: El Tablero no habia sido inicializado o el se desean modificar las dimensiones del Tablero
	//Post: Se crea el Tablero vacio con las dimensiones deseadas
	void inicializarTablero(unsigned int cantidadDePisos, unsigned int cantidadDeFilas, unsigned int cantidadDeColumnas);

public:

	//Post: se crea el Tablero con las dimensiones por defecto
	Tablero();

	//Pre: la cantidad de pisos, filas y columnas con las que se crea un Tablero es estrictamente mayor que 0
	//Post: se crea el Tablero con las dimensiones especificadas
	Tablero(unsigned int cantidadDePisos, unsigned int cantidadDeFilas, unsigned int cantidadDeColumnas);

	//Pre: la cantidad de pisos, filas y columnas con las que se crea un Tablero es estrictamente mayor que 0
	//Post: se liberan los recursos que necesitaba el Tablero anterior y se crea uno nuevo, vacio con las dimensiones especificadas
	void cambiarDimensiones(unsigned int cantidadDePisos, unsigned int cantidadDeFilas, unsigned int cantidadDeColumnas);

	//Pre: la fila y la columna donde se deja caer la ficha deben estar en las dimensiones del tablero
	//Post: la ficha cae por el tablero hasta que se encuentre con otra ficha. Ademas como ingresa una ficha al Tablero
	//		queda modificado la posicion de la ultima ficha que ingreso al Tablero
	bool pudoPonerFicha(unsigned int fila, unsigned int columna, char ficha);

	//POST: devuelve True si el tablero esta incializado y false si no lo esta
	bool estaInicializado();

	//Pre:-
	//Post: Devuelve la Fila en la que se encuentra la ultima ficha que ingreso al tablero. Devuelve '0' si ninguna
	//Ficha fue ingresada en el Tablero
	unsigned int obtenerFilaUltimaFicha();

	//Pre:-
	//Post: Devuelve la Columna en la que se encuentra la ultima ficha que ingreso al tablero. Devuelve '0' si ninguna
	//Ficha fue ingresada en el Tablero
	unsigned int obtenerColumnaUltimaFicha();

	//Pre:-
	//Post: Devuelve el Piso en la que se encuentra la ultima ficha que ingreso al tablero. Devuelve '0' si ninguna
	//Ficha fue ingresada en el Tablero
	unsigned int obtenerPisoUltimaFicha();

	//Pre: Fue ingresada una ficha al Tablero
	//Post: Se actualizan los datos de la nueva ficha ingresada
	void actualizarUltimaFicha(unsigned int nuevaFila, unsigned int nuevaColumna, unsigned int nuevoPiso);

	//Pre:
	//Post: devuelve la cantidad de filas que tiene cualquier Piso del Tablero
	unsigned int obtenerCantidadDeFilas();

	//Pre:
	//Post: devuelve la cantidad de columnas que tiene cualquier Piso del Tablero
	unsigned int obtenerCantidadDeColumnas();

	//Pre:
	//Post: devuelve la cantidad de Pisos del Tablero
	unsigned int obtenerCantidadDePisos();

	//Pre: el numero del Piso que se desea obtener esta en el rango [1, cantidadDePisos]
	//Post: devuelve el Piso numero numeroDelPiso
	Piso* obtenerPiso(unsigned int numeroDelPiso);

	//Pre: el numero del Piso pertenece al intervalo [1, cantidadDePisos], el numero de la fila pertenece al intervalo
	// [1, cantidadDeFilas], el numero de la columna pertenece al intervalo [1, numeroDeLaColumna]
	//Post: Vacia el casillero en la posicion deseada. El casillero esta vacio: tiene un '0'
	void vaciarCasilleroEn(unsigned int numeroDelPiso, unsigned int numeroDeLaFila, unsigned int numeroDeLaColumna);

	//Pre: el numero del Piso pertenece al intervalo [1, cantidadDePisos], el numero de la fila pertenece al intervalo
	// [1, cantidadDeFilas], el numero de la columna pertenece al intervalo [1, numeroDeLaColumna]
	//Post: indica si el casillero en la posicion deseada esta vacio
	bool estaVacioCasillero(unsigned int numeroDelPiso, unsigned int numeroDeLaFila, unsigned int numeroDeLaColumna);

	//Pre: el numero del Piso pertenece al intervalo [1, cantidadDePisos], el numero de la fila pertenece al intervalo
	// [1, cantidadDeFilas], el numero de la columna pertenece al intervalo [1, numeroDeLaColumna]
	//Post: la Ficha deseada queda colocada en la posicion indicada
	void ubicarFichaEn(unsigned int numeroDelPiso, unsigned int numeroDeLaFila, unsigned int numeroDeLaColumna, char ficha);

	//Pre: el numero del Piso pertenece al intervalo [1, cantidadDePisos], el numero de la fila pertenece al intervalo
	// [1, cantidadDeFilas], el numero de la columna pertenece al intervalo [1, numeroDeLaColumna]
	//Post: se devuelve la ficha en la posicion indicada
	char obtenerFichaEn(unsigned int numeroDelPiso, unsigned int numeroDeLaFila, unsigned int numeroDeLaColumna);

	//Pre:-
	//Post: Se muestra el Tablero por pantalla
	void imprimir();

	//Pre:-
	//Post: Se liberan los recursos utilizados por el Tablero
	void destruirTablero();

	// Post: reinicia el tablero, dejándolo sin fichas en su interior
	void reiniciarTablero();

	//Pre:-
	//Post: se liberan los recursos utilizados
	~Tablero();

};



#endif /* TABLERO_H_ */
