/*
 * Tp3.cpp
 *
 *  Created on: 09 jun. 2019
 *      Author: matias
 */

#include "Tp3.h"

Tp3::Tp3() {
	this->estado=LOAD_INICIAL;
	//this->estado=TEST;
}

Tp3::~Tp3() {
	this->jugadores.removerTodos();
}

void Tp3::testJugadores() {
	Jugador jugadorActual = this->jugadores.obtenerCursor();
	jugadorActual.setearId(jugadorActual.obtenerId() + 1);
	jugadorActual.incrementarTotalPartidosGanados();

	cout << "jugadorActual.obtenerId(): " << jugadorActual.obtenerId() << endl;
	cout << "jugadorActual.partidosGanados: " << jugadorActual.obtenerTotalPartidosGanados() << endl;

	jugadores.agregar(jugadorActual);

	jugadores.iniciarCursor();
	jugadores.reiniciarCursor();

	jugadorActual.incrementarTotalPartidosGanados();
	cout << "jugadorActual.obtenerId(): " << jugadorActual.obtenerId() << endl;
	cout << "jugadorActual.partidosGanados: " << jugadorActual.obtenerTotalPartidosGanados() << endl;

	cout << "Cantidad de Jugadores: " << this -> jugadores.contarJugadores() << endl;


	this-> jugadores.asignar(jugadorActual, 1);
	cout << "Partidos ganados = " << this-> jugadores.obtenerCursor().obtenerTotalPartidosGanados() << endl;
}

bool Tp3::testPortaCartas() {
	return true;// this ->portaCartas.testPortaCartas(DEFAULT_TOTAL_JUGADORES);
}


void Tp3::run() {
	string accionUsuario = "";

	estadoJuego estado = obtenerEstadoJuego();

	do {
		dibujar(estado);

		accionUsuario = leerAccion(estado);

		estado = ejecutarAccion(accionUsuario, estado);

	} while(estado != SALIR);

}


void Tp3::dibujar(estadoJuego estado) {
	switch(estado) {
		case SPLASH:
			//cout << "Pintado > SPLASH" << endl;
			this->splash.mostrarPantalla();

			break;

		case MENU_PRINCIPAL:
			//cout << "Pintado > MENU_PRINCIPAL" << endl;
			this->menuPrincipal.mostrarPantalla();
			break;

		case JUGANDO:
			//cout << "Pintado > JUGANDO" << endl;
			this->enJuego.mostrarPantalla(&(this -> tablero), &(this->jugadores));
			break;

		case OPCIONES:
			//cout << "Pintado > OPCIONES" << endl;
			this->opciones.mostrarPantalla();
			break;

		case ESTADISTICAS:
			//cout << "Pintado > ESTADISTICAS" << endl;
			this->estadisticas.mostrarPantalla(&(this->jugadores));
			break;

		case ACERCA_DE:
			//cout << "Pintado > ACERCA_DE" << endl;
			this->acercaDe.mostrarPantalla();
			break;

		case SALIR:
			break;

		default:
			break;
	}
}


string Tp3::leerAccion(estadoJuego estado) {
	string opcionElegida = "";
	bool saltarLecturaDatos = (
		estado == LOAD_INICIAL
		|| estado == CARGAR_JUEGO
		|| estado == TEST
		|| this->enJuego.obtenerEstadoAccionJugador() == ENJUEGO_JUGADOR_DATOS_INGRESADOS
		|| (estado == JUGANDO && this->enJuego.obtenerEstadoAccionJugador() == ENJUEGO_JUGADOR_TIRAR_CARTA)
	);

	if (!saltarLecturaDatos) {
		cout << ">: ";
		getline(cin, opcionElegida);
	}

	return opcionElegida;
}

estadoJuego Tp3::ejecutarAccion(string accionUsuario, estadoJuego estado) {
	switch(estado) {
		case LOAD_INICIAL:
			//cout << "Estado Actual > LOAD_INICIAL" << endl;
			cargarJugadoresPorDefecto();
			cargarTableroPorDefecto();

			estado = SPLASH;
			break;

		case SPLASH:
			//cout << "Estado Actual > SPLASH" << endl;
			estado = this->splash.ejecutarAccionUsuario(accionUsuario);

			break;

		case MENU_PRINCIPAL:
			//cout << "Estado Actual > MENU_PRINCIPAL" << endl;
			estado = this->menuPrincipal.ejecutarAccionUsuario(accionUsuario);

			break;

		case CARGAR_JUEGO:
			this->tablero.reiniciarTablero();
			this->enJuego.setearEstadoAccionJugador(ENJUEGO_JUGADOR_INGRESAR_FILA);

			this->portaCartas.inicializar(this->jugadores.contarJugadores(), this->nivelDificultad);

			estado = JUGANDO;
			break;

		case JUGANDO:
			//cout << "Estado Actual > JUGANDO" << endl;
			estado = this->enJuego.ejecutarAccionUsuario(accionUsuario, &(this -> tablero), &(this -> validadorPartida), &(this->jugadores), this -> nivelDificultad, &(this->portaCartas));
			break;

		case OPCIONES:
			//cout << "Estado Actual > OPCIONES" << endl;
			estado = this->opciones.ejecutarAccionUsuario(accionUsuario, &(this->jugadores), &(this -> tablero), &(this -> nivelDificultad));
			break;

		case ESTADISTICAS:
			//cout << "Estado > ESTADISTICAS" << endl;
			estado = this->estadisticas.ejecutarAccionUsuario(accionUsuario);
			break;

		case ACERCA_DE:
			//cout << "Estado Actual > ACERCA_DE" << endl;
			estado = this->acercaDe.ejecutarAccionUsuario(accionUsuario);
			break;

		case SALIR:
			cout << "Fin del 4 en Linea" << endl;
			this->jugadores.removerTodos();
			this->tablero.destruirTablero();
			this->portaCartas.vaciarPortaCartas();
			break;

		case TEST: // usado para probar métodos
			cargarJugadoresPorDefecto();
			this -> jugadores.imprimirInfoJugadores();

			estado = SALIR;
			break;

	}
	return estado;
}

void Tp3::cargarJugadoresPorDefecto() {
	this -> jugadores.cargarJugadores(DEFAULT_TOTAL_JUGADORES);

	this -> jugadores.irAlPrimerJugador();
}


void Tp3::cargarTableroPorDefecto() {
	this -> tablero.cambiarDimensiones(TABLERO_DEFAULT_TOTAL_PISOS, TABLERO_DEFAULT_TOTAL_FILAS_POR_PISO, TABLERO_DEFAULT_TOTAL_COLUMNAS_POR_PISO);
}

estadoJuego Tp3::obtenerEstadoJuego() {
	return this->estado;
}

