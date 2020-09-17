#include "Alumno.h"


Alumno::Alumno() {
	this->apellido = "Casas";
	this->nombre = "Armando";
	this->padron = 123456;
}

Alumno::~Alumno() {
}

Alumno::Alumno(const string apellidoNuevo, const string nombreNuevo, const string padronNuevo) {

	bool apellidoEsValido = validarApellido(apellidoNuevo);
	bool nombreEsValido = validarNombre(nombreNuevo);
	bool padronEsValido = validarPadron(padronNuevo);


	if(apellidoEsValido && nombreEsValido && padronEsValido) {
		this->apellido = apellidoNuevo;
		this->nombre = nombreNuevo;
		this->padron = std::stoi(padronNuevo);
	}
	else {
		cout << "ERROR al cargar los datos del Alumno: Verifique que 'Apellido' y 'Nombre' contengan solo letras y 'Padron' solo numeros." << endl;
	}
}


bool Alumno::validarApellido(const string& nombrePersona) {
    /*if (nombrePersona == null) {
        return false;
    }*/

	if (nombrePersona.length() < 2) { // Tiene menos de 2 letras
		return false;
	}

    for (unsigned int i = 0; i < nombrePersona.length(); ++i) {
        if (! isalpha(nombrePersona[i])) {
        	return false;
        }
    }
    return true;
}

bool Alumno::validarNombre(const string& nombrePersona) {
    return validarApellido(nombrePersona);
}

bool Alumno::validarPadron(const string& padron) {
	/*if (padron == NULL) {
		return false;
	}*/

	for (unsigned int i = 0; i < padron.length(); i++) {
		if (! isalnum(padron[i])) {
			return false;
		}
	}
	return true;
}

const string Alumno::getApellido() {
	return this->apellido;
}


const string Alumno::getNombre() {
	return this->nombre;
}


const unsigned int Alumno::getPadron() {
	return this->padron;
}
