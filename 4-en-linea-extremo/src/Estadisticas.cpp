#include "Estadisticas.h"

Estadisticas::Estadisticas() {
	this->teclaVolver=TECLA_VOLVER;
}


Estadisticas::~Estadisticas() {

}


void Estadisticas::mostrarPantalla(ManagerListaJugadores * jugadores) {
	cout << "\tESTADISTICAS" << endl;

	if(jugadores->contarJugadores() < 2) {
		throw string("ERROR: La cantidad de jugadores debe ser mayor a 1");
	}

	for(unsigned int i = 0; i < jugadores->contarJugadores(); i++)  {
		cout << "\t\tJugador " << (i+1) << ":" << endl;
		cout << "\t\t\tCantidad de partidas ganadas: "<< jugadores->obtenerJugadorPorId(i+1).obtenerTotalPartidosGanados() << endl;
		cout << "\t\t\tCantidad de partidas empatadas: "<< jugadores->obtenerJugadorPorId(i+1).obtenerTotalPartidosEmpatados() << endl;
		cout << "\t\t\tCantidad de partidas perdidas: "<< jugadores->obtenerJugadorPorId(i+1).obtenerTotalPartidosPerdidos() << endl;
	}

	cout << "" << endl;
	cout << "\t\tPresione '"<< this->getTeclaVolver() <<"' para Volver" << endl;
}

estadoJuego Estadisticas::ejecutarAccionUsuario(string opcionElegida) {
	estadoJuego estado;

	if(opcionElegida.compare(this->getTeclaVolver()) == 0) {
		estado = MENU_PRINCIPAL;
	}
	else {
		estado = ESTADISTICAS;
	}
		
	return estado;
}

string Estadisticas::getTeclaVolver() {
	return this->teclaVolver;
}

