/*
 * EnJuego.cpp
 *
 *  Created on: 26 may. 2019
 *      Author: matias
 */
#include "EnJuego.h"


EnJuego::EnJuego() {
	//setearEstadoAccionJugador(ENJUEGO_JUGADOR_INGRESAR_FILA);
	setearEstadoAccionJugador(ENJUEGO_JUGADOR_TIRAR_CARTA);
}


EnJuego::~EnJuego() {
}


void EnJuego::mostrarPantalla(Tablero * tablero, ManagerListaJugadores * jugadores) {
	if(jugadores->contarJugadores() < 2) {
		throw string("ERROR: La cantidad de jugadores debe ser mayor a 1");
	}
	if(!tablero->estaInicializado()) {
		throw string("ERROR: El Tablero debe estar inicializado");
	}


	if(obtenerEstadoAccionJugador() == ENJUEGO_JUGADOR_INGRESAR_FILA) {
		cout << "\tTurno > Jugador " << jugadores->obtenerJugadorActual().obtenerId() << endl;
		cout << "Ingrese la Fila" << endl;
	}
	else if(obtenerEstadoAccionJugador() == ENJUEGO_JUGADOR_INGRESAR_COLUMNA) {
		cout << "\tTurno > Jugador " << jugadores->obtenerJugadorActual().obtenerId() << endl;
		cout << "Ingrese la Columna" << endl;
	}

	if(obtenerEstadoAccionJugador() == ENJUEGO_JUGADOR_DATOS_INGRESADOS) {
		cout << "\tTurno > Jugador " << jugadores->obtenerJugadorActual().obtenerId() << endl;

		cout<< "...Jugando..."<<endl;
		// Mostrar info de jugadores
		jugadores -> imprimirInfoJugadores();

		// Dibujar Tablero
		tablero -> imprimir();

		// Sacar foto del piso donde se puso la última ficha en el Tablero
		sacarFotoTablero(tablero, jugadores);
	}
	else if(obtenerEstadoAccionJugador() == JUEGO_TERMINADO) {
		cout << "\tTurno > Jugador " << jugadores->obtenerJugadorActual().obtenerId() << endl;
		cout<< "...Juego Terminado..."<<endl;
	}
}

void EnJuego::sacarFotoTablero(Tablero * tablero, ManagerListaJugadores * jugadores) {
	if(jugadores->contarJugadores() < 2) {
		throw string("ERROR: La cantidad de jugadores debe ser mayor a 1");
	}
	if(!tablero->estaInicializado()) {
		throw string("ERROR: El Tablero debe estar inicializado");
	}

	cout << "...Sacando foto del tablero..." << endl << endl;
	Visualizador unVisualizador(tablero->obtenerCantidadDeFilas(), tablero->obtenerCantidadDeFilas());
	unVisualizador.generarFotoPiso(tablero->obtenerPiso(tablero->obtenerPisoUltimaFicha()), jugadores);
}

estadoJuego EnJuego::ejecutarAccionUsuario(string opcionElegida, Tablero * tablero, Validador * validadorPartida, ManagerListaJugadores * jugadores, menuNivelDificultad nivelDificultad, Portacartas * portaCartas) {
	if(jugadores->contarJugadores() < 2) {
		throw string("ERROR: La cantidad de jugadores debe ser mayor a 1");
	}
	if(!tablero->estaInicializado()) {
		throw string("ERROR: El Tablero debe estar inicializado");
	}

	if(nivelDificultad == FACIL) {
		cout << "nivel de dificultad > FACIL" << endl;
	}
	else if(nivelDificultad == INTERMEDIO) {
		cout << "nivel de dificultad > INTERMEDIO" << endl;
	}
	else if(nivelDificultad == DIFICIL) {
		cout << "nivel de dificultad > DIFICIL" << endl;
	}
	else {
		cout << "nivel de dificultad > otro" << endl;
	}

	//cout<< "...Acciones > Jugando..."<<endl;
	estadoJuego estado = JUGANDO;

	if(obtenerEstadoAccionJugador() == ENJUEGO_JUGADOR_TIRAR_CARTA) {
		unsigned int idJugadorActual = jugadores->obtenerJugadorActual().obtenerId();
		bool jugadorActualTieneCartaEnPortaCarta = portaCartas->tieneAlMenos1Carta(idJugadorActual);

		if(jugadorActualTieneCartaEnPortaCarta) {
			// Preguntarle al usuario que carta desea jugar (una de las opciones puede ser NINGUNA)
			string opcionElegida;
			portaCartas->mostrarCartasJugador(idJugadorActual);
			cout<< "Quiere usar una carta? Y/N "<<endl;
			cout << ">: ";
			getline(cin, opcionElegida);
			if(opcionElegida.compare("Y") == 0 || opcionElegida.compare("y") == 0){
				cout<< "Cual?"<<endl;

				cout << ">: ";
				getline(cin, opcionElegida);
				unsigned int numero = atoi (opcionElegida.c_str());
				portaCartas->usarCartaJugador(
					//idJugadorActual,
					numero,
					//jugadores->obtenerJugadorActual().obtenerFicha(),
					tablero,
					jugadores
				);

				tablero->imprimir();

				if(validadorPartida->hayGanador(tablero)) {
					estado = ejecutarAccionHuboGanador(tablero, jugadores);
				}
				else if(validadorPartida->hayEmpate(tablero)) {
					estado = ejecutarAccionHuboEmpate(tablero, jugadores);
				}
			}
		}

		setearEstadoAccionJugador(ENJUEGO_JUGADOR_INGRESAR_FILA);
	}
	else if(obtenerEstadoAccionJugador() == ENJUEGO_JUGADOR_INGRESAR_FILA) {
		this->ficha_fila = atoi(opcionElegida.c_str());

		setearEstadoAccionJugador(ENJUEGO_JUGADOR_INGRESAR_COLUMNA);
	}
	else if(obtenerEstadoAccionJugador() == ENJUEGO_JUGADOR_INGRESAR_COLUMNA) {
		this->ficha_columna = atoi(opcionElegida.c_str());

		setearEstadoAccionJugador(ENJUEGO_JUGADOR_DATOS_INGRESADOS);


		// Paso 1
		bool puedeUsarCarta = false;
		if(puedeUsarCarta) {
			cout << "El jugador " << jugadores -> obtenerJugadorActual().obtenerId() << " va a usar su carta" << endl << endl;
		}

		// Paso 2
		char fichaJugador = jugadores -> obtenerJugadorActual().obtenerFicha();

		if(tablero -> pudoPonerFicha(this->ficha_fila, this->ficha_columna, fichaJugador)){
			// Paso 3
			//cout << "Determinar si hay ganador o empate" << endl;
			if(validadorPartida->hayGanador(tablero)) {
				estado = ejecutarAccionHuboGanador(tablero, jugadores);
			}
			else if(validadorPartida->hayEmpate(tablero)) {
				estado = ejecutarAccionHuboEmpate(tablero, jugadores);
			}
			else {
				// Paso 3.a.
				cout << endl;
				cout << "Levantar Carta" << endl << endl;

				// Se obtiene el jugador Actual
				Jugador jugadorActual = jugadores -> obtenerJugadorActual();

				// Se busca una carta y se la asigna al jugadorActual
				//managerCartas->verQueCartaSeEntrega(jugadorActual, carta, portaCartas);
				if(!portaCartas->tieneMaximoDeCartas(jugadorActual.obtenerId())){
					portaCartas->darCartaAlJugador(jugadorActual.obtenerId());
				}

				// Paso 3.b: Cambiar Turno
				jugadores -> cambiarJugador();

				setearEstadoAccionJugador(ENJUEGO_JUGADOR_DATOS_INGRESADOS);
			}
		}
		else {
			cout << ">>> No se pudo poner ficha. ";
			cout << "Verifique que el casillero no este ocupado y que 1 <= filaDeseada <= " << tablero->obtenerCantidadDeFilas();
			cout << "y 1 <= columnaDesada <= " << tablero->obtenerCantidadDeColumnas() << endl;

			setearEstadoAccionJugador(ENJUEGO_JUGADOR_INGRESAR_FILA);
		}
	}
	else if(obtenerEstadoAccionJugador() == ENJUEGO_JUGADOR_DATOS_INGRESADOS) {
		setearEstadoAccionJugador(ENJUEGO_JUGADOR_TIRAR_CARTA);
	}

	return estado;
}

estadoJuego EnJuego::ejecutarAccionHuboGanador(Tablero * tablero, ManagerListaJugadores * jugadores) {
	if(jugadores->contarJugadores() < 2) {
		throw string("ERROR: La cantidad de jugadores debe ser mayor a 1");
	}
	if(!tablero->estaInicializado()) {
		throw string("ERROR: El Tablero debe estar inicializado");
	}

	tablero -> imprimir();

	cout << "El jugador " << jugadores -> obtenerJugadorActual().obtenerId() << " gano la partida !" << endl << endl;
	Jugador jugadorActual = jugadores -> obtenerJugadorActual();
	jugadorActual.incrementarTotalPartidosGanados();
	jugadores -> asignar(jugadorActual, jugadorActual.obtenerId());

	unsigned int idJugadorGanador = jugadores -> obtenerJugadorActual().obtenerId();

	for(unsigned int i = 0; i < jugadores->contarJugadores(); i++) {
		unsigned int idJugadorLeido = i + 1;

		if(idJugadorGanador != idJugadorLeido) {
			Jugador jugadorActual = jugadores -> obtenerJugadorPorId(idJugadorLeido);
			jugadorActual.incrementarTotalPartidosPerdidos();
			jugadores -> asignar(jugadorActual, jugadorActual.obtenerId());
		}
	}

	setearEstadoAccionJugador(JUEGO_TERMINADO);

	sacarFotoTablero(tablero, jugadores);

	return ESTADISTICAS;
}

estadoJuego EnJuego::ejecutarAccionHuboEmpate(Tablero * tablero, ManagerListaJugadores * jugadores) {
	if(jugadores->contarJugadores() < 2) {
		throw string("ERROR: La cantidad de jugadores debe ser mayor a 1");
	}
	if(!tablero->estaInicializado()) {
		throw string("ERROR: El Tablero debe estar inicializado");
	}

	tablero -> imprimir();

	cout << "Empate !" << endl;
	// Incrementa una partida empatada a todos los jugadores
	for(unsigned int i = 0; i < jugadores->contarJugadores(); i++) {
		unsigned int idJugadorLeido = i + 1;

		Jugador jugadorActual = jugadores -> obtenerJugadorPorId(idJugadorLeido);
		jugadorActual.incrementarTotalPartidosEmpatados();
		jugadores -> asignar(jugadorActual, jugadorActual.obtenerId());
	}

	setearEstadoAccionJugador(JUEGO_TERMINADO);

	sacarFotoTablero(tablero, jugadores);

	return ESTADISTICAS;
}

void EnJuego::setearEstadoAccionJugador(enJuegoEstadoAccionJugador estadoAccionJugador) {
	this -> estadoAccionJugador = estadoAccionJugador;
}

enJuegoEstadoAccionJugador EnJuego::obtenerEstadoAccionJugador() {
	return this -> estadoAccionJugador;
}
