
#ifndef PISO_H_
#define PISO_H_

#include "Fila.h"
#include "Lista.h"

/*Un Piso es un arreglo ordenado de Filas. Un Piso tiene una cantidad de columnas y filas que lo caracteriza. AL crearse
 * el piso esta completamente vacio. Un casillero del piso se considera vacio si tiene un '0'.
 *
 * Otorga funcionalidades para:
 *
 * 	-Obtener la cantidad de Filas del Piso
 * 	-Obtener la cantidad de Columnas del Piso
 * 	-Obtener alguna Fila deseada del Piso
 * 	-Obtener alguna Columna deseada del Piso
 * 	-Vaciar un casillero en alguna posicion deseda del Piso
 * 	-Indicar si un casillero esta vacio
 * 	-Ubicar una ficha en un casillero deseado del Piso
 * 	-Obtener la ficha que ocupa un casillero del Piso
 * 	-Mostrar por pantalla el Piso
 *
 *Un ejemplo:
 *
 *		Piso unPiso(3,4); //Crea un Piso de 3 filas y 4 columnas que se crea vacio
 *		unPiso.imprimir(); //Muestra por pantalla lo siguiente:
 *
 *						0000
 *						0000
 *						0000
 *
 *		unPiso.ubicarFichaEn(2,1, '#'); //Ubica la ficha '#' en el casillero que esta en la fila 2 y la columna 1:
 *
 *						0000
 *						#000
 *						0000
 * */


class Piso{

private:

	unsigned int cantidadDeFilas;

	unsigned int cantidadDeColumnas;

	Lista<Fila*>* filas;

public:

	//Pre: la cantidad de filas y la cantidad de columnas deben ser un numero estrictamente mayor que 0
	//Post: se crea el Piso con la cantidad de filas y de columnas deseada. Ademas el piso esta vacio
	Piso(unsigned int cantidadDeFilas,unsigned int cantidadDeColumnas);

	Lista<Fila*>* obtenerFilas();

	//Pre:-
	//Post: devuelve la cantidad de filas del Piso
	unsigned int obtenerCantidadDeFilas();

	//Pre:-
	//Post: devuelve la cantidad de columnas del Piso
	unsigned int obtenerCantidadDeColumnas();

	//Pre: el numero de la Fila que se desea obtener pertenece al rango [1, cantidadDeFilas]
	//Post: se devuelve la Fila deseada
	Fila* obtenerFilaNumero(unsigned int numeroDeLaFila);

	//Pre: el casillero que se desea vaciar esta en una fila y columna que pertenecen al rango [1, cantidadDeFilas]
	// y [1, cantidadDeColumnas] respectivamente
	//Post: el casillero en la fila y columna deseada queda vaciado
	void vaciarCasilleroEn(unsigned int numeroDeLaFila, unsigned int numeroDeLaColumna);

	//Pre: el casillero que se desea saber si esta vacio esta en una fila y columna que pertenecen al rango
	//[1, cantidadDeFilas] y [1, cantidadDeColumnas] respectivamente.
	//Post: indica si el casillero en la fila y columna deseadas esta vacio o no
	bool estaVacioCasillero(unsigned int numeroDeLaFila, unsigned int numeroDeLaColumna);

	//Pre: el casillero donde se desea ubicar la ficha deseada esta en una fila y columna que pertenecen al rango
	//[1, cantidadDeFilas] y [1, cantidadDeColumnas] respectivamente.
	//Post: la ficha ingresada es colocada en la fila y columna deseada del Piso
	void ubicarFichaEn(unsigned int numeroDeLaFila, unsigned int numeroDeLaColumna, char ficha);

	//Pre:  el casillero donde se desea obtener la ficha esta en una fila y columna que pertenecen al rango
	//[1, cantidadDeFilas] y [1, cantidadDeColumnas] respectivamente.
	//Post: devuelve la ficha que hay en esa posicion. Si el casillero esta vacio se obtiene un '0'
	char obtenerFichaEn(unsigned int numeroDeLaFila, unsigned int numeroDeLaColumna);

	//Pre:-
	//Post: muestra por pantalla el Piso
	void imprimir();

	//Pre:-
	//Post: se liberan los recursos utilizados
	~Piso();

};



#endif /* PISO_H_ */
