/*
 * Item.h
 *
 *  Created on: 20 abr. 2019
 *      Author: matias
 */
#ifndef ALUMNO_H_
#define ALUMNO_H_

	#include <string>
	#include <iostream>
	#include <cctype>

	using namespace std;

	class Alumno {
		private:
			string nombre;
			string apellido;
			unsigned int padron;

			/*
			 * pre: 'apellidoPersona' debe ser distinto de null, vacío y solo debe contener letras
			 *
			 * post: Valida si 'apellidoPersona' es válido.
			 *		 Devuelve True si 'apellidoPersona' es válido. Caso contrario, devuelve False
			 * */
			bool validarApellido(const string& apellidoPersona);

			/*
			 * pre: 'nombrePersona' debe ser distinto de null, vacío y solo debe contener letras
			 *
			 * post: Valida si 'nombrePersona' es válido.
			 *		 Devuelve True si 'nombrePersona' es válido. Caso contrario, devuelve False
			 * */
			bool validarNombre(const string& nombrePersona);

			/*
			 * pre: 'padronPersona' debe ser distinto de null, vacío y solo debe contener números
			 *
			 * post: Valida si 'padronPersona' es válido.
			 *		 Devuelve True si 'padronPersona' es válido. Caso contrario, devuelve False
			 * */
			bool validarPadron(const string& padronPersona);

		public:
			/*
			 * post: se crea un objeto Alumno, seteando un nombre, apellido y padron por defecto
			 * */
			Alumno();

			/*
			 * post: libera la memoria del HEAP ocupada por este objeto
			 * */
			~Alumno();

			/*
			 * pre: el nombre, apellido y padron deben ser válidos
			 * 	nombre: debe ser distinto de null, vacío y solo debe contener letras
			 * 	apellido: debe ser distinto de null, vacío y solo debe contener letras
			 * 	padron: debe ser un número entero positivo
			 *
			 * post: se crea un objeto Alumno, seteando el nombre, apellido y padron pasados como argumento
			 * */
			Alumno(const string nombre, const string apellido, const string padron);

			const string getApellido();
			const string getNombre();
			const unsigned int getPadron();
};

#endif /* ALUMNO_H_ */
