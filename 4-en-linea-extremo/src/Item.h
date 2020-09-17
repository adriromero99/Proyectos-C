/*
 * Item.h
 *
 *  Created on: 20 abr. 2019
 *      Author: matias
 */
#ifndef SRC_ITEM_H_
#define SRC_ITEM_H_

	#include <string>
	#include <iostream>

	#include "defines.h"

	using namespace std;

	template <class T> class Item {
		private:
			string nombre;
			string teclaParaAcceder;
			//estadoJuego accion;
			T accion;

		public:
			/*
			 * post: Construye un item
			 * */
			Item(string nombre, string tecla, T accion);

			/*
			 * post: se liberan los recursos
			 * */
			~Item();

			/*
			 * post: Devuelve el nombre del Item
			 * */
			string getNombre();

			/*
			 * post: Devuelve la representacion como String de la tecla que el usuario debe presionar para acceder a dicho Item
			 * */
			string getTeclaParaAcceder();

			/*
			 * post: Devuelve la accion del Item
			 * */
			T getAccion();
	};

	template <class T>
	Item <T>::Item(string nombre, string tecla, T accion) {
		this->nombre = nombre;
		this->teclaParaAcceder = tecla;
		this->accion = accion;
	}

	template <class T>
	Item <T>::~Item() {
		// TODO Auto-generated destructor stub
	}

	template <class T>
	string Item <T>::getNombre() {
		return this->nombre;
	}

	template <class T>
	string Item <T>::getTeclaParaAcceder() {
		return this->teclaParaAcceder;
	}

	template <class T>
	T Item <T>::getAccion() {
		return this->accion;
	}

#endif /* SRC_ITEM_H_ */
