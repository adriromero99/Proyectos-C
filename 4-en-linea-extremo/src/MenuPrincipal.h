/*
 * Item.h
 *
 *  Created on: 20 abr. 2019
 *      Author: matias
 */
#ifndef MENUPRINCIPAL_H_
#define MENUPRINCIPAL_H_

	#include <vector>
	#include <string>

	#include "Item.h"


	class MenuPrincipal {
		private:
			unsigned int totalItems;
			vector<Item <estadoJuego>> items;
			vector<string> teclasValidas;

			/*
			 * post: carga los items que tendrá el Menú
			 * */
			void cargarItemsAlMenu();

			/*
			 * post: Devuelve la cantidad de Items que tiene el Menú
			 * */
			unsigned int getTotalItems();

		public:
			/*
			 * post: se crea el Menú Principal.
			 * */
			MenuPrincipal();

			/*
			 * post: Se liberan los recursos
			 * */
			virtual ~MenuPrincipal();

			/*
			 * post: imprime el Menú Principal por pantalla
			 * */
			void mostrarPantalla();

			/*
			 * pre: se le pasa la acción del usuario "accionUsuario"
			 * post: Devuelve el estado asociado al Item del menú que desea ir el Usuario:
			 * 		Jugar
			 * 		Ir a la sección Opciones
			 * 		Ir a la sección de Estadísticas
			 * 		Ir a la sección Acerca De
			 * 		Salir del programa
			 * */
			estadoJuego ejecutarAccionUsuario(string accionUsuario);

			/*
			 * pre: opcionElegida es lo ingresado por el usuario
			 *
			 * post: valida que 'opcionElegida' esté definida en el listado de posibles Opciones Válidas. Si lo está, entonces devuelve True. Caso contrario, False
			 * */
			bool validarOpcionElegida(string opcionElegida);

			/*
			 * pre: Dada una 'opcionElegida' válida
			 *
			 * post: Devuelve la accion del Item
			 * */
			estadoJuego getAccionItem(string opcionElegida);
	};

#endif /* MENUPRINCIPAL_H_ */
