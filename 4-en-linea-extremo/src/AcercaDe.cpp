#include "AcercaDe.h"

AcercaDe::AcercaDe() {
	cargarAlumnos();

	this->version = VERSION_JUEGO;
	this->teclasValidas.push_back(TECLA_VOLVER);
}

AcercaDe::~AcercaDe() {

}

string AcercaDe::getVersionJuego() {
	return this->version;
}



void AcercaDe::mostrarPantalla() {
	cout << endl;
	cout << "\tACERCA DE.." << endl ;
	cout << "" << endl;
	cout << "\t\tTP 3: Juego 4 en L"<< char(161) << "nea." << endl;
	cout << "" << endl;
	cout << "\t\tVersi"<< char(162) << "n: " <<  getVersionJuego() << endl;
	cout << "" << endl;
	cout << "\t\tDesarrollado por: " << endl;
	cout << "" << endl;

	for(unsigned int i = 0; i < alumnos.size(); i++) {
		cout << "\t\t\t" << alumnos[i].getApellido() << ", " << alumnos[i].getNombre() <<" - Padr"<< char(162) << "n " << alumnos[i].getPadron() << endl;
	}

	cout << "" << endl;
	cout << "\t\tPresione '"<< getTeclaVolver() <<"' para Volver" << endl;
	cout << endl;
}

void AcercaDe::cargarAlumnos() {
	const string infoAlumno [4][3] = {
		{"Penafiel", "Matias", "85080"}
		,{"Jara", "Claudia", "98270"}
		,{"Sagman", "Emanuel", "103439"}
		,{"Romero", "Adrian", "103371"}
	};

	for(unsigned int i = 0; i < 4; i++) {
		Alumno alumno(infoAlumno[i][0], infoAlumno[i][1], infoAlumno[i][2]);
		this->alumnos.push_back(alumno);
	}
}

void AcercaDe::imprimirInformacionAlumnos() {
	for (unsigned int i = 0; i < alumnos.size(); i++) {
		cout << "Apellido: " << alumnos[i].getApellido()
			 << " - Nombre: " << alumnos[i].getNombre()
			 << " - Padron: " << alumnos[i].getPadron() << endl;
	}
}

string AcercaDe::getTeclaVolver() {
	return this->teclasValidas[0];
}

estadoJuego AcercaDe::ejecutarAccionUsuario(string accionUsuario) {
	if(accionUsuario.compare(this->getTeclaVolver()) == 0) {
		return MENU_PRINCIPAL;
	}
	else {
		return ACERCA_DE;
	}
}
