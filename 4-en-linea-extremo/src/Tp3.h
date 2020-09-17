/*
 * Tp2.h
 *
 *  Created on: 28 abr. 2019
 *      Author: matias
 */

#ifndef SRC_TP3_H_
#define SRC_TP3_H_

	#include <string>
	#include <iostream>
	#include <vector>

	#include "defines.h"

	#include "Jugador.h"

	#include "Splash.h"
	#include "MenuPrincipal.h"
	#include "AcercaDe.h"
	#include "Opciones.h"
	#include "Estadisticas.h"

	#include "EnJuego.h"

	#include "Lista.h"

	#include "Tablero.h"
	#include "Validador.h"

	#include "ManagerListaJugadores.h"


	#include "Portacartas.h"


	using namespace std;

	class Tp3 {

		public:
			// post: se contruye el objeto
			Tp3();

			// post: se libera la memoria
			~Tp3();

			// post: devuelve una máquina de estados para monitorear todos los posibles estados del juego
			void run(void);

			// post: se cargan jugadores por defecto
			void cargarJugadoresPorDefecto();

			// post: se carga un tablero por defecto
			void cargarTableroPorDefecto();

			// pre: 'estado' es el estado en el q se encuentra el juego
			// post: devuelve un string con lo ingresado por teclado
			string leerAccion(estadoJuego estado);

			// pre: 'accionUsuario' es lo ingresado por el usuario. 'estado' es el estado en el q se encuentra el juego
			// post: devuelve el estado en el q se encuentra el juego
			estadoJuego ejecutarAccion(string accionUsuario, estadoJuego estado);

			// post: devuelve el estado en el q se encuentra el juego
			estadoJuego obtenerEstadoJuego();


			// post: TEST > Jugadores
			void testJugadores();

			// post: TEST > PortaCartas
			bool testPortaCartas();



		private:
			MenuPrincipal menuPrincipal;
			AcercaDe acercaDe;
			Splash splash;
			Opciones opciones;
			Estadisticas estadisticas;
			EnJuego enJuego;

			Tablero tablero;
			Validador validadorPartida;

			ManagerListaJugadores jugadores;

			Portacartas portaCartas;

			menuNivelDificultad nivelDificultad;

			estadoJuego estado;

			// pre: 'estado' es el estado en el q se encuentra el juego
			// post: dibuja por pantalla el contenido correspondiente asociado a su 'estado'
			void dibujar(estadoJuego estado);
	};

#endif /* SRC_TP3_H_ */
