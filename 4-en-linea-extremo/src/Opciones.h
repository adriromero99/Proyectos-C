/*
 * Opciones.h
 *
 *  Created on: 11 may. 2019
 *      Author: matias
 */

#include "Lista.h"

#ifndef SRC_OPCIONES_H_
#define SRC_OPCIONES_H_

	#include <string>
	#include <iostream>
	#include <vector>

	#include "defines.h"

	#include "Item.h"
	#include "ManagerListaJugadores.h"
	#include "Tablero.h"


	using namespace std;

	class Opciones {
		private:
			vector<Item <menuOpciones>> items;
			unsigned int totalItems;
			menuOpciones itemMenuElegido;

			string teclaVolver;
			vector<string> teclasValidas;

			vector<Item <menuNivelDificultad>> itemsMenuDificultad;
			unsigned int totalItemsMenuNivelDificultad;
			menuNivelDificultad itemsMenuDificultadElegido;

			vector<Item <menuDimensionesTablero>> itemsMenuDimensionesTablero;
			unsigned int totalItemsMenuDimensionesTablero;
			menuDimensionesTablero itemsMenuDimensionesTableroElegido;

			////////////////////////////////////////////////////
			// POST: Construye el Menú: Opciones
			void cargarItemsAlMenu();

			// POST: Muestra por pantalla el Menú > Opciones
			void mostrarPantallaPrincipal();

			// POST: Devuelve el item elegido en el Menú > Opciones
			menuOpciones getItemMenuElegido();

			// POST: Menú > Opciones: Setea el Item elegido de dicho menú
			void setItemMenuElegido(menuOpciones itemElegido);




			// POST: Construye el Menú: Nivel de Dificultad
			void cargarItemsAlMenuConfigurarNivelDificultad();

			// POST: Muestra por pantalla el Menú > Nivel de Dificultad
			void mostrarPantallaConfigurarNivelDeDificultad();

			// POST: Menú > Nivel de Dificultad: Setea el Item elegido de dicho menú
			void setItemMenuNivelDificultadElegido(menuNivelDificultad nuevoItemElegido);

			// POST: Devuelve el item elegido en el Menú > Nivel de Dificultad
			menuNivelDificultad getItemMenuNivelDificultadElegido();

			// PRE: 'nivelDeseado' debe existir
			// POST: Busca el nivel de dificultad deseado y devuelve su menuNivelDificultad asociado
			menuNivelDificultad buscarNivelDificultad(string nivelDeseado);



			// POST: Construye el Menú: Dimensiones del Tablero
			void cargarItemsAlMenuDimensionesTablero();

			// POST: Muestra por pantalla el Menú > Configurar Dimensiones del Tablero
			void mostrarPantallaConfigurarDimensionesDelTablero();

			// POST: Muestra por pantalla el Menú > Configurar Dimensiones del Tablero > Cantidad de Pisos
			void mostrarPantallaConfigurarCantidadPisosTablero();

			// POST: Muestra por pantalla el Menú > Configurar Dimensiones del Tablero > Cantidad de Filas
			void mostrarPantallaConfigurarCantidadFilasTablero();

			// POST: Muestra por pantalla el Menú > Configurar Dimensiones del Tablero > Cantidad de Columnas
			void mostrarPantallaConfigurarCantidadColumnasTablero();

			// POST: Menú > Configurar Dimensiones del Tablero: Setea el Item elegido de dicho menú
			void setItemMenuDimensionesTableroElegido(menuDimensionesTablero nuevoItemElegido);

			// POST: Devuelve el item elegido en el Menú > Dimensiones del Tablero
			menuDimensionesTablero getItemMenuDimensionesTableroElegido();

			// PRE: 'itemMenuDeseado' debe existir
			// POST: Busca el item del menú deseado y devuelve su menuDimensionesTablero asociado
			menuDimensionesTablero buscarItemMenuDimensionesTablero(string itemMenuDeseado);



			// POST: Muestra por pantalla el Menú > Configurar Cantidad de Jugadores
			void mostrarPantallaConfigurarJugadores();



			// post: Devuelve el string q representa a la tecla para Volver al Menú Principal
			string getTeclaVolver();

			// POST: Devuelve la cantidad de Items del menú Opciones
			unsigned int getTotalItems();

			// POST: valida si 'dato' es un número
			bool esNumero(const string& dato);


			// PRE: Dada una 'opcionElegida' válida
			// POST: Devuelve la accion del Item
			estadoJuego getAccionItem(string opcionElegida, ManagerListaJugadores * listaJugadores, Tablero * tablero, menuNivelDificultad * nivelDificultad);
			////////////////////////////////////////////////////

		public:
			// POST: se construye el objeto Opciones
			Opciones();

			// POST: Libera la memoria
			~Opciones();

			// POST: Muestra por pantalla el contenido de la sección OPCIONES
			void mostrarPantalla();

			// POST: Setea el estado del juego a OPCIONES (Si 'opcionElegida' es != TECLA_VOLVER)
			// 		 o MENU_PRINCIPAL (Si 'opcionElegida' es TECLA_VOLVER)
			estadoJuego ejecutarAccionUsuario(string accionUsuario, ManagerListaJugadores * listaJugadores, Tablero * tablero, menuNivelDificultad * nivelDificultad);

	};
#endif /* SRC_OPCIONES_H_ */
