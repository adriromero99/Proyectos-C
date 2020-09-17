/*
 * Jugador.h
 *
 *  Created on: 11 may. 2019
 *      Author: matias
 */

#ifndef SRC_JUGADOR_H_
#define SRC_JUGADOR_H_

	#include <string>
	#include <iostream>
	#include <cstdlib> // para rand()

	#include "defines.h"

	using namespace std;

	class Jugador {
		private:
			unsigned int id;
			char tipoFicha;
			int colorFichaIntRGB;

			unsigned int totalFichasPorJugar;
			unsigned int totalPartidosGanados;
			unsigned int totalPartidosEmpatados;
			unsigned int totalPartidosPerdidos;

		public:
			/*
			 * pre: 'id' es un número natural para identificar a un jugador
			 * post: Se crea un jugador con
			 * */
			Jugador();

			/*
			 * post: se liberan los recursos
			 * */
			~Jugador();

			/*
			 * post: carga la configuración inicial del jugador
			 * */
			void configurarJugador(unsigned int id);

			/*
			 * post: Setea el ID de la ficha
			 * */
			void setearId(unsigned int idDeseado);

			/*
			 * post: Devuelve el ID de la ficha
			 * */
			unsigned int obtenerId();

			/*
			 * post: Setea el simbolos deseado a la Ficha
			 * */
			void setearFicha(char simbolosDeseados);

			/*
			 * pre: colorFichaIntRGB es un entero y pertenece al intervalo [0, COLOR_MAX_INT_VALUE]
			 * post: Setea el color de la ficha
			 * */
			void setearColorFichaIntRGB(int colorFichaIntRGB);

			/*
			 * post: Devuelve color de la ficha
			 * */
			int obtenerColorFichaIntRGB();

			/*
			 * post: Devuelve la Ficha
			 * */
			char obtenerFicha();

			/*
			 * post: Devuelve el Total de Fichas por jugar
			 * */
			unsigned int obtenerTotalFichasPorJugar();

			/*
			 * post: Decrementa en 1 al Total de Fichas por jugar
			 * */
			void decrementarTotalFichasPorJugar();

			/*
			 * post: Devuelve el Total de Partidos Ganados
			 * */
			unsigned int obtenerTotalPartidosGanados();

			/*
			 * post: Incrementa en 1, la cantidad de partidos Ganados
			 * */
			void incrementarTotalPartidosGanados();

			/*
			 * post: Devuelve el Total de Partidos Empatados
			 * */
			unsigned int obtenerTotalPartidosEmpatados();

			/*
			 * post: Incrementa en 1, la cantidad de partidos Empatados
			 * */
			void incrementarTotalPartidosEmpatados();

			/*
			 * post: Devuelve el Total de Partidos Perdidos
			 * */
			unsigned int obtenerTotalPartidosPerdidos();

			/*
			 * post: Incrementa en 1, la cantidad de partidos Perdidos
			 * */
			void incrementarTotalPartidosPerdidos();

			/*
			 * post: Devuelve un numero aleatorio entre [0, ] que representa al color de la ficha
			 * */
			int generarColorFicha();
	};


#endif /* SRC_JUGADOR_H_ */
