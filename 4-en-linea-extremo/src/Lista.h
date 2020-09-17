/*
 * Lista.h
 *
 *  Created on: 1 jun. 2019
 *      Author: matias
 */
#ifndef LISTA_H_
#define LISTA_H_

	#include <iostream>

	#include "Nodo.h"


	using namespace std;

	template<class T>
	class Lista {

		private:

			Nodo<T>* primero;

			unsigned int tamanio;

			Nodo<T>* cursor;

		public:

			/*
			 * post: Lista vac�a.
			 */
			Lista();

			/*
			 * post: Lista que tiene los mismos elementos que otraLista.
			 *       La instancia resulta en una copia de otraLista.
			 */
			Lista(Lista<T>& otraLista);

			/*
			 * post: indica si la Lista tiene alg�n elemento.
			 */
			bool estaVacia();

			/*
			 * post: devuelve la cantidad de elementos que tiene la Lista.
			 */
			unsigned int contarElementos();

			/*
			 * post: agrega el elemento al final de la Lista, en la posici�n:
			 *       contarElementos() + 1.
			 */
			void agregar(T elemento);

			/*
			 * pre : posici�n pertenece al intervalo: [1, contarElementos() + 1]
			 * post: agrega el elemento en la posici�n indicada.
			 *
			 */
			void agregar(T elemento, unsigned int posicion);

			/*
			 * post: agrega todos los elementos de otraLista
			 *       a partir de la posici�n contarElementos() + 1.
			 */
			void agregar(Lista<T> &otraLista);

			/*
			 * pre : posici�n pertenece al intervalo: [1, contarElementos()]
			 * post: devuelve el elemento en la posici�n indicada.
			 */
			T obtener(unsigned int posicion);

			/*
			 * pre : posicio� pertenece al intervalo: [1, contarElementos()]
			 * post: cambia el elemento en la posici�n indicada por el
			 *       elemento dado.
			 */
			void asignar(T elemento, unsigned int posicion);

			/*
			 * pre : posici�n pertenece al intervalo: [1, contarElementos()]
			 * post: remueve de la Lista el elemento en la posici�n indicada.
			 */
			void remover(unsigned int posicion);

			/*
			 * post: remueve todos los elementos de la lista
			 */
			void removerTodos();

			/*
			 * post: mueve el cursor al primer nodo
			 * */
			void reiniciarCursor();

			/*
			 * post: deja el cursor de la Lista preparado para hacer un nuevo
			 *       recorrido sobre sus elementos.
			 */
			void iniciarCursor();

			/*
			 * pre : se ha iniciado un recorrido (invocando el m�todo
			 *       iniciarCursor()) y desde entonces no se han agregado o
			 *       removido elementos de la Lista.
			 * post: mueve el cursor y lo posiciona en el siguiente elemento
			 *       del recorrido.
			 *       El valor de retorno indica si el cursor qued� posicionado
			 *       sobre un elemento o no (en caso de que la Lista est� vac�a o
			 *       no existan m�s elementos por recorrer.)
			 */
			bool avanzarCursor();

			/*
			 * pre : el cursor est� posicionado sobre un elemento de la Lista,
			 *       (fue invocado el m�todo avanzarCursor() y devolvi� true)
			 * post: devuelve el elemento en la posici�n del cursor.
			 *
			 */
			T obtenerCursor();

			/*
			 * post: libera los recursos asociados a la Lista.
			 */
			~Lista();

		private:
			/*
			 * pre : posici�n pertenece al intervalo: [1, contarElementos()]
			 * post: devuelve el nodo en la posici�n indicada.
			 */
			Nodo<T>* obtenerNodo(unsigned int posicion);


	};

	template<class T>
	Lista<T>::Lista() {
		this->primero = NULL;
		this->tamanio = 0;
		this->cursor = NULL;
	}

	template<class T>
	Lista<T>::Lista(Lista<T>& otraLista) {
		this->primero = NULL;
		this->tamanio = 0;
		this->cursor = NULL;

		/* copia los elementos de otraLista */
		this->agregar(otraLista);
	}

	template<class T>
	bool Lista<T>::estaVacia() {

		return (this->tamanio == 0);
	}

	template<class T>
	unsigned int Lista<T>::contarElementos() {

		return this->tamanio;
	}

	template<class T>
	void Lista<T>::agregar(T elemento) {

		this->agregar(elemento, this->tamanio + 1);
	}

	template<class T>
	void Lista<T>::agregar(T elemento, unsigned int posicion) {

		if ((posicion > 0) && (posicion <= this->tamanio + 1)) {

			Nodo<T>* nuevo = new Nodo<T>(elemento);

			if (posicion == 1) {

				nuevo->cambiarSiguiente(this->primero);
				this->primero = nuevo;

			} else {

				Nodo<T>* anterior = this->obtenerNodo(posicion - 1);
				nuevo->cambiarSiguiente(anterior->obtenerSiguiente());
				anterior->cambiarSiguiente(nuevo);
			}

			this->tamanio++;

			/* cualquier recorrido actual queda invalidado */
			this->iniciarCursor();
		}

	}

	template<class T>
	void Lista<T>::agregar(Lista<T> &otraLista) {

		otraLista.iniciarCursor();
		while (otraLista.avanzarCursor()) {
			this->agregar(otraLista.obtenerCursor());
		}
	}

	template<class T>
	T Lista<T>::obtener(unsigned int posicion) {
		T elemento;

		if ((posicion > 0) && (posicion <= this->tamanio)) {

			elemento = this->obtenerNodo(posicion)->obtenerDato();
		}

		return elemento;
	}

	template<class T>
	void Lista<T>::asignar(T elemento, unsigned int posicion) {

		if ((posicion > 0) && (posicion <= this->tamanio)) {

			this->obtenerNodo(posicion)->cambiarDato(elemento);
		}
	}

	template<class T>
	void Lista<T>::remover(unsigned int posicion) {

		if ((posicion > 0) && (posicion <= this->tamanio)) {

			Nodo<T>* removido;

			if (posicion == 1) {

				removido = this->primero;
				this->primero = removido->obtenerSiguiente();

			} else {

				Nodo<T>* anterior = this->obtenerNodo(posicion - 1);
				removido = anterior->obtenerSiguiente();
				anterior->cambiarSiguiente(removido->obtenerSiguiente());
			}

			delete removido;
			this->tamanio--;

			/* cualquier recorrido actual queda invalidado */
			this->iniciarCursor();
		}
	}

	template<class T>
	void Lista<T>::iniciarCursor() {

		this->cursor = NULL;
	}

	template<class T>
	bool Lista<T>::avanzarCursor() {

		if (this->cursor == NULL) {

			this->cursor = this->primero;

		} else {

			this->cursor = this->cursor->obtenerSiguiente();
		}

		/* pudo avanzar si el cursor ahora apunta a un nodo */
		return (this->cursor != NULL);
	}

	template<class T>
	T Lista<T>::obtenerCursor() {

		T elemento;

		if (this->cursor != NULL) {

			elemento = this->cursor->obtenerDato();
		}

		return elemento;
	}

	template<class T>
	Lista<T>::~Lista() {
		this -> removerTodos();
	}

	template<class T>
	Nodo<T>* Lista<T>::obtenerNodo(unsigned int posicion) {

		Nodo<T>* actual = this->primero;
		for (unsigned int i = 1; i < posicion; i++) {

			actual = actual->obtenerSiguiente();
		}

		return actual;
	}
	////////////////////////////////////////////////////////////////////////////////////
	template <class T>
	void Lista<T>::removerTodos() {
		while (this->primero != NULL) {
			Nodo<T>* aBorrar = this->primero;
			this->primero = this->primero->obtenerSiguiente();

			delete aBorrar;
		}
		this->primero = NULL;
		this->cursor = NULL;
		this->tamanio = 0;
	}

	template <class T>
	void Lista<T>::reiniciarCursor() {
		this->cursor = this -> primero;
	}

#endif /* LISTA_H_ */
