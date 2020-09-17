/*
 * Item.h
 *
 *  Created on: 20 abr. 2019
 *      Author: matias
 */
#ifndef ACERCADE_H_
#define ACERCADE_H_

	#include <string>
	#include <iostream>
	#include <vector>

	#include "defines.h"

	#include "Alumno.h"


	class AcercaDe {
		private:
			string version;
			vector<Alumno> alumnos;

			vector<string> teclasValidas;

			// POST: carga en un vector, informacion de los desarrolladores del juego/
			void cargarAlumnos();

			// PRE: tener cargado al menos a un desarrollador
			// POST: Imprime por pantalla informacion de los desarrolladores del juego
			void imprimirInformacionAlumnos();

			// POST: Devuelve la version del juego
			string getVersionJuego();

			// POST: Devuelve el string q representa a la tecla para Volver al Menú Principal
			string getTeclaVolver();

		public:
			/*
			 * POST: se crea un objeto AcercaDe, seteando:
			 * 	1) la versión del juego
			 * 	2) Nombre, apellido y padrón de los desarrolladores
			 * 	3) Tecla que debe presionar el usuario para volver al Menú Principal
			 * */
			AcercaDe();

			// POST: Libera la memoria/
			~AcercaDe();

			// POST: Muestra por pantalla el contenido de la sección Acerca De
			void mostrarPantalla();

			// POST: Sale de Aceca De y vuelve al Menú Principal
			estadoJuego ejecutarAccionUsuario(string accionUsuario);
	};

#endif /* ACERCADE_H_ */
