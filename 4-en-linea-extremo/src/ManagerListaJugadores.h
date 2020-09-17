/*
 * ManagerListaJugadores.h
 *
 *  Created on: 9 jun. 2019
 *      Author: matias
 */

#ifndef SRC_MANAGERLISTAJUGADORES_H_
#define SRC_MANAGERLISTAJUGADORES_H_

	#include <string>
	#include <iostream>

	#include "Lista.h"
	#include "Jugador.h"

	class ManagerListaJugadores : public Lista<Jugador> {
		public:
			// post: se construye el objeto ManagerListaJugadores
			ManagerListaJugadores();

			//post: Libera la memoria
			~ManagerListaJugadores();

			/*
			 * pre : el cursor est� posicionado sobre un elemento de la Lista,
			 *       (fue invocado el m�todo avanzarCursor() y devolvi� true)
			 * post: devuelve el elemento en la posici�n del cursor.
			 *
			 */
			Jugador obtenerJugadorActual();

			/*
			 * pre : se ha iniciado un recorrido (invocando el m�todo
			 *       iniciarCursor()) y desde entonces no se han agregado o
			 *       removido elementos de la Lista.
			 * post: mueve el cursor y lo posiciona en el siguiente elemento
			 *       del recorrido. Si llegó al final, entonces vuelve a comenzar por el primero.
			 */
			void cambiarJugador();

			/*
			 * post: mueve el cursor al primer jugador
			 * */
			void irAlPrimerJugador();

			/*
			 * Usado para debuguear
			 * post: imprime por pantalla el estado de cada jugador
			 * */
			void imprimirInfoJugadores();

			/*
			 * pre: 'totalJugadores' debe ser un número entero mayor a 0
			 * post: Carga 'totalJugadores' con una configuración por defecto.
			 * */
			void cargarJugadores(unsigned int totalJugadores);

			// post: devuelve la cantidad de jugadores
			unsigned int contarJugadores();

			// pre: 'posicion' debe pertencer al intevalo [1, contarElementos()]
			// post: devuelve el Jugador que está en la posición 'posición' del listado de jugadores
			Jugador obtenerJugadorPorId(unsigned int posicion);
	};



#endif /* SRC_MANAGERLISTAJUGADORES_H_ */
