/*
 * enJuego.h
 *
 *  Created on: 26 may. 2019
 *      Author: matias
 */

#ifndef SRC_ENJUEGO_H_
#define SRC_ENJUEGO_H_

	#include <iostream>
	#include <string>
	#include <vector>

	#include "defines.h"
	#include "Tablero.h"
	#include "Validador.h"
	#include "ManagerListaJugadores.h"
	#include "Visualizador.h"

	#include "Portacartas.h"
	#include "Carta.h"

	using namespace std;

	class EnJuego {
		private:
			enJuegoEstadoAccionJugador estadoAccionJugador;
			unsigned int ficha_fila;
			unsigned int ficha_columna;

		public:
			//post: construye el Juego
			EnJuego();

			//post: se libera la memoria
			~EnJuego();

			// post: Devuelve el estado actual de la accion del jugador
			enJuegoEstadoAccionJugador obtenerEstadoAccionJugador();

			// POST: setea el estado de la accion del jugador
			// 		 Esos estados pueden ser: ENJUEGO_JUGADOR_TIRAR_CARTA, ENJUEGO_JUGADOR_INGRESAR_FILA, ENJUEGO_JUGADOR_INGRESAR_COLUMNA, ENJUEGO_JUGADOR_DATOS_INGRESADOS, JUEGO_TERMINADO
			//			cuando el estado sea ENJUEGO_JUGADOR_TIRAR_CARTA > la lectura del teclado no se hará desde la máquina de estados
			//		 	cuando el estado sea ENJUEGO_JUGADOR_INGRESAR_FILA > la lectura del teclado será para cargar la Fila donde el jugador desea colocar la ficha
			// 		 	cuando el estado sea ENJUEGO_JUGADOR_INGRESAR_COLUMNA > la lectura del teclado será para cargar la Columna donde el jugador desea colocar la ficha
			//			cuando el estado sea ENJUEGO_JUGADOR_DATOS_INGRESADOS > El jugador actual terminó de ingresar la fila y columna donde desea ingresar la ficha
			//			cuando el estado sea JUEGO_TERMINADO > Fin del juego
			void setearEstadoAccionJugador(enJuegoEstadoAccionJugador estadoAccionJugador);

			// PRE: 'tablero' tiene que estar inicializado y 'jugadores' tiene q tener al menos 2 jugadores
			// POST: dibuja la presentación del juego
			void mostrarPantalla(Tablero * tablero, ManagerListaJugadores * jugadores);

			/*
			 * PRE: 'accionUsuario' es una tecla válida definida en el constructor
			 * 		'tablero'
			 * 		'validadorPartida'
			 * 		'jugadores'
			 * 		'nivelDificultad'
			 * 		'portaCartas'
			 *
			 * POST: Devuelve el estado que prosigue al Juego
			 * 		Ronda 1
			 *
						TURNO Jugador 1:
							1) Puede o No usar su CARTA DE PODER (en caso de que tenga -> evalúa si hay ganador o empate)
							2) Poner ficha
							3) Se Evaluar si hay GANADOR o EMPATE
								HAY GANADOR O EMPATE: IMPRIMIR FOTO de la region que rodea a esa última ficha > va a ESTADISTICAS
								CASO CONTRARIO:
									a)  Levantar carta
									b) Cambiar Turno > Jugador Actual = Jugador Actual + 1
									c) IMPRIMIR FOTO de la region que rodea a esa última ficha

						TURNO Jugador N:
							1) Puede o No usar su CARTA DE PODER (en caso de que tenga -> evalúa si hay ganador o empate)
							2) Poner ficha
							3) Se Evaluar si hay GANADOR o EMPATE
								HAY GANADOR O EMPATE: IMPRIMIR FOTO de la region que rodea a esa última ficha > va a ESTADISTICAS
								CASO CONTRARIO:
									a) Levantar carta
									b) Cambiar Turno > Jugador Actual = Jugador 1
									c) IMPRIMIR FOTO de la region que rodea a esa última ficha

					Ronda N : Idem anteriores
			 *
			 * */
			estadoJuego ejecutarAccionUsuario(string accionUsuario, Tablero * tablero, Validador * validadorPartida, ManagerListaJugadores * jugadores, menuNivelDificultad nivelDificultad, Portacartas * portaCartas);

			// PRE: 'tablero' tiene que estar inicializado y 'jugadores' tiene q tener al menos 2 jugadores
			// POST: Incrementa la cantidad de partidas ganadas al jugador actual y perdidas al resto, saca foto del tablero y va a ESTADISTICAS
			estadoJuego ejecutarAccionHuboGanador(Tablero * tablero, ManagerListaJugadores * jugadores);

			// PRE: 'tablero' tiene que estar inicializado y 'jugadores' tiene q tener al menos 2 jugadores
			// POST: Incrementa la cantidad de partidas empatadas a todos los jugadores, saca foto del tablero y va a ESTADISTICAS
			estadoJuego ejecutarAccionHuboEmpate(Tablero * tablero, ManagerListaJugadores * jugadores);

			// PRE: 'tablero' tiene que estar inicializado y 'jugadores' tiene q tener al menos 2 jugadores
			// POST: Saca foto del piso donde el jugador Actual puso su última ficha
			void sacarFotoTablero(Tablero * tablero, ManagerListaJugadores * jugadores);
	};

#endif /* SRC_ENJUEGO_H_ */
