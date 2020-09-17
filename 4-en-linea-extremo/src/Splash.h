/*
 * Splash.h
 *
 *  Created on: 27 abr. 2019
 *      Author: matias
 */
#ifndef SRC_SPLASH_H_
#define SRC_SPLASH_H_

	#include <iostream>
	#include <string>
	#include <vector>

	#include "defines.h"

	using namespace std;

	class Splash {
		private:
			vector<string> teclasValidas;

		public:
			// POST: construye un Splash
			Splash();

			// POST: se libera la memoria
			~Splash();

			//post: dibuja la presentación del juego
			void mostrarPantalla();

			/*
			 * pre: 'accionUsuario' es una tecla válida definida en el constructor
			 * POST: Devuelve el estado que prosigue al Splash
			 */
			estadoJuego ejecutarAccionUsuario(string accionUsuario);
	};
#endif /* SRC_SPLASH_H_ */
