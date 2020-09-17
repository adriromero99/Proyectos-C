/*
 * Opciones.cpp
 *
 *  Created on: 11 may. 2019
 *      Author: matias
 */
#include "Opciones.h"

Opciones::Opciones() {
	cargarItemsAlMenu();
	//this->itemMenuElegido = NINGUNO;
	setItemMenuElegido(NINGUNO);

	setItemMenuDimensionesTableroElegido(MENU_CONFIGURAR_DIMENSIONES_ITEM_NINGUNO);
	cargarItemsAlMenuConfigurarNivelDificultad();

	cargarItemsAlMenuDimensionesTablero();
}

Opciones::~Opciones() {

}

void Opciones::cargarItemsAlMenu() {
	this->teclaVolver = "v";

	string itemsMenuTextoTecla[][2] = {
		{"Elegir la cantidad de Jugadores", "1"}
		,{"Elegir las medidas del tablero", "2"}
		,{"Elegir Nivel de Dificultad", "3"}
		,{"Volver", this->teclaVolver}
	};
	const unsigned int ITEM_TEXTO = 0;
	const unsigned int ITEM_TECLA = 1;

	menuOpciones accionItems [] = {
		CONFIGURAR_CANTIDAD_JUGADORES,
		CONFIGURAR_DIMENSIONES_TABLERO,
		CONFIGURAR_NIVEL_DIFICULTAD,
		VOLVER
	};

	this->totalItems = 4;


	for(unsigned int i = 0; i < this->totalItems; i++) {
		Item <menuOpciones> item(
			itemsMenuTextoTecla[i][ITEM_TEXTO],
			itemsMenuTextoTecla[i][ITEM_TECLA],
			accionItems[i]
		);
		items.push_back(item);

		this->teclasValidas.push_back(itemsMenuTextoTecla[i][1]);
	}
	//cout << "SETEO INICIAL " << endl;
}



void Opciones::mostrarPantalla() {
	//cout << "mostrarPantalla() > getItemMenuElegido(): " + getItemMenuElegido() << endl;
	switch(getItemMenuElegido()) {
		case NINGUNO:
			this->mostrarPantallaPrincipal();
			break;

		case CONFIGURAR_CANTIDAD_JUGADORES:
			this->mostrarPantallaConfigurarJugadores();
			break;

		case CONFIGURAR_DIMENSIONES_TABLERO:

			switch(this->getItemMenuDimensionesTableroElegido()) {
				case MENU_CONFIGURAR_DIMENSIONES_ITEM_INGRESAR_PISOS:
					mostrarPantallaConfigurarCantidadPisosTablero();
					break;

				case MENU_CONFIGURAR_DIMENSIONES_ITEM_INGRESAR_FILAS:
					mostrarPantallaConfigurarCantidadFilasTablero();
					break;

				case MENU_CONFIGURAR_DIMENSIONES_ITEM_INGRESAR_COLUMNA:
					mostrarPantallaConfigurarCantidadColumnasTablero();
					break;

				default:
					mostrarPantallaConfigurarDimensionesDelTablero();
			}

			break;

		case CONFIGURAR_NIVEL_DIFICULTAD:
			this->mostrarPantallaConfigurarNivelDeDificultad();
			break;

		case VOLVER:
			break;
	}

}

void Opciones::mostrarPantallaConfigurarJugadores() {
	cout << endl;
	cout << "\tConfigurando la Cantidad de Jugadores" << endl ;
	cout << "" << endl;
	cout << "\t\tIngrese la cantidad de Jugadores (debe ser mayor a 0)" << endl;
	cout << endl;
}


void Opciones::mostrarPantallaPrincipal() {
	cout << endl;
	cout << "\tOPCIONES" << endl;
	cout << endl;
	for(unsigned int i = 0; i < this->totalItems; i++) {
		cout << "\t\t" << items[i].getTeclaParaAcceder()<< " - " << items[i].getNombre() << endl;
	}
	cout << endl;
	cout << endl;
}


string Opciones::getTeclaVolver() {
	return this->teclaVolver;
}

void Opciones::setItemMenuElegido(menuOpciones nuevoItemElegido) {
	this->itemMenuElegido = nuevoItemElegido;
}
menuOpciones Opciones::getItemMenuElegido() {
	return this->itemMenuElegido;
}

////////////////////////////////////////////////////////////////////////////////
// SubMenu: Nivel de Dificultad
void Opciones::cargarItemsAlMenuConfigurarNivelDificultad() {
	this->teclaVolver = "v";

	string itemsMenuTextoTecla[][2] = {
		{"Facil", "1"}
		,{"Intermedio", "2"}
		,{"Dificil", "3"}
	};
	const unsigned int ITEM_TEXTO = 0;
	const unsigned int ITEM_TECLA = 1;

	menuNivelDificultad accionItems [] = {
		FACIL,
		INTERMEDIO,
		DIFICIL
	};

	this->totalItemsMenuNivelDificultad = 3;


	for(unsigned int i = 0; i < this->totalItemsMenuNivelDificultad; i++) {
		Item <menuNivelDificultad> item(
			itemsMenuTextoTecla[i][ITEM_TEXTO],
			itemsMenuTextoTecla[i][ITEM_TECLA],
			accionItems[i]
		);
		itemsMenuDificultad.push_back(item);

		this->teclasValidas.push_back(itemsMenuTextoTecla[i][1]);
	}
	//cout << "SETEO INICIAL " << endl;
}

void Opciones::mostrarPantallaConfigurarNivelDeDificultad() {
	cout << endl;
	cout << "\tOPCIONES > Configurando el Nivel de Dificultad" << endl ;
	cout << "" << endl;
	for(unsigned int i = 0; i < this->totalItemsMenuNivelDificultad; i++) {
		cout << "\t\t" << itemsMenuDificultad[i].getTeclaParaAcceder()<< " - " << itemsMenuDificultad[i].getNombre() << endl;
	}
	cout << "" << endl;
	cout << "" << endl;
}

void Opciones::setItemMenuNivelDificultadElegido(menuNivelDificultad nuevoItemElegido) {
	this->itemsMenuDificultadElegido = nuevoItemElegido;
}

menuNivelDificultad Opciones::getItemMenuNivelDificultadElegido() {
	return this->itemsMenuDificultadElegido;
}

menuNivelDificultad Opciones::buscarNivelDificultad(string nivelDeseado) {
	menuNivelDificultad nivelDetectado = DIFICULTAD_NO_VALIDA;

	for(unsigned int i = 0; i < this->totalItemsMenuNivelDificultad; i++) {

		if(itemsMenuDificultad[i].getTeclaParaAcceder().compare(nivelDeseado.c_str()) == 0) {
			nivelDetectado = itemsMenuDificultad[i].getAccion();
		}
	}

	return nivelDetectado;
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// SubMenu: Dimensiones del Tablero
void Opciones::cargarItemsAlMenuDimensionesTablero(){
	//this->teclaVolver = "v";

	string itemsMenuTextoTecla[][2] = {
		{"Piso", "1"}
		,{"Fila", "2"}
		,{"Columna", "3"}
	};
	const unsigned int ITEM_TEXTO = 0;
	const unsigned int ITEM_TECLA = 1;

	menuDimensionesTablero accionItems [] = {
		MENU_CONFIGURAR_DIMENSIONES_ITEM_INGRESAR_PISOS
		,MENU_CONFIGURAR_DIMENSIONES_ITEM_INGRESAR_FILAS
		,MENU_CONFIGURAR_DIMENSIONES_ITEM_INGRESAR_COLUMNA
	};

	this->totalItemsMenuDimensionesTablero = 3;


	for(unsigned int i = 0; i < this->totalItemsMenuDimensionesTablero; i++) {
		Item <menuDimensionesTablero> item(
			itemsMenuTextoTecla[i][ITEM_TEXTO],
			itemsMenuTextoTecla[i][ITEM_TECLA],
			accionItems[i]
		);

		itemsMenuDimensionesTablero.push_back(item);

		this->teclasValidas.push_back(itemsMenuTextoTecla[i][1]);
	}
	//cout << "SETEO INICIAL " << endl;
}

void Opciones::mostrarPantallaConfigurarDimensionesDelTablero() {
	cout << endl;
	cout << "\tOPCIONES > Configurando Dimensiones del tablero" << endl ;
	cout << "" << endl;
	for(unsigned int i = 0; i < this->totalItemsMenuDimensionesTablero; i++) {
		cout << "\t\t" << itemsMenuDimensionesTablero[i].getTeclaParaAcceder()<< " - " << itemsMenuDimensionesTablero[i].getNombre() << endl;
	}
	cout << "" << endl;
	cout << "" << endl;
	cout << endl;
}

void Opciones::mostrarPantallaConfigurarCantidadPisosTablero() {
	cout << endl;
	cout << "\tConfigurando la Cantidad de Pisos del Tablero" << endl ;
	cout << "" << endl;
	cout << "\t\tIngrese la cantidad de pisos" << endl;
	cout << endl;
}

void Opciones::mostrarPantallaConfigurarCantidadFilasTablero() {
	cout << endl;
	cout << "\tConfigurando la Cantidad de Filas del Tablero" << endl ;
	cout << "" << endl;
	cout << "\t\tIngrese la cantidad de Filas" << endl;
	cout << endl;
}

void Opciones::mostrarPantallaConfigurarCantidadColumnasTablero() {
	cout << endl;
	cout << "\tConfigurando la Cantidad de Columnas del Tablero" << endl ;
	cout << "" << endl;
	cout << "\t\tIngrese la cantidad de Columnas" << endl;
	cout << endl;
}


void Opciones::setItemMenuDimensionesTableroElegido(menuDimensionesTablero nuevoItemElegido){
	this->itemsMenuDimensionesTableroElegido = nuevoItemElegido;
}

menuDimensionesTablero Opciones::getItemMenuDimensionesTableroElegido() {
	return this->itemsMenuDimensionesTableroElegido;
}

menuDimensionesTablero Opciones::buscarItemMenuDimensionesTablero(string itemMenuDeseado) {
	menuDimensionesTablero itemDetectado = MENU_CONFIGURAR_DIMENSIONES_ITEM_NINGUNO;

	for(unsigned int i = 0; i < this->totalItemsMenuDimensionesTablero; i++) {

		if(itemsMenuDimensionesTablero[i].getTeclaParaAcceder().compare(itemMenuDeseado.c_str()) == 0) {
			itemDetectado = itemsMenuDimensionesTablero[i].getAccion();
		}
	}

	return itemDetectado;
}
////////////////////////////////////////////////////////////////////////////////


estadoJuego Opciones::ejecutarAccionUsuario(string accionUsuario, ManagerListaJugadores * listaJugadores, Tablero * tablero, menuNivelDificultad * nivelDificultad) {
	return getAccionItem(accionUsuario, listaJugadores, tablero, nivelDificultad);
}

estadoJuego Opciones::getAccionItem(string opcionElegida, ManagerListaJugadores * listaJugadores, Tablero * tablero, menuNivelDificultad * nivelDificultad) {
	estadoJuego accion = OPCIONES;
	menuOpciones accionActualMenuOpciones;
	menuOpciones accionAnteriorMenuOpciones = getItemMenuElegido();
	menuDimensionesTablero accionAnteriorMenuDimensionesTablero = getItemMenuDimensionesTableroElegido();

	bool accionItemDetectada = false;

	for(unsigned int i = 0; !accionItemDetectada && i < getTotalItems(); i++) {

		accionItemDetectada = (opcionElegida.compare(this->items[i].getTeclaParaAcceder()) == 0)
				|| (getItemMenuElegido() == CONFIGURAR_CANTIDAD_JUGADORES)
				|| (getItemMenuElegido() == CONFIGURAR_DIMENSIONES_TABLERO)
				|| (getItemMenuElegido() == CONFIGURAR_NIVEL_DIFICULTAD);

		if(accionItemDetectada) {

			if(getItemMenuElegido() == NINGUNO) {
				accionActualMenuOpciones = this->items[i].getAccion();
				setItemMenuElegido(accionActualMenuOpciones);
			}

			switch(getItemMenuElegido()) {
				case NINGUNO:
					//cout << "ACCION > NINGUNO" << endl;
					accion = MENU_PRINCIPAL;
					break;

				case CONFIGURAR_CANTIDAD_JUGADORES:
					//cout << "ACCION > CONFIGURAR_CANTIDAD_JUGADORES" << endl;

					if(accionAnteriorMenuOpciones != getItemMenuElegido()) {
						setItemMenuElegido(CONFIGURAR_CANTIDAD_JUGADORES);
						accionAnteriorMenuOpciones = getItemMenuElegido();
					}
					else if(esNumero(opcionElegida) && 1 < atoi(opcionElegida.c_str())) {
						listaJugadores -> cargarJugadores(atoi(opcionElegida.c_str()));
						listaJugadores -> imprimirInfoJugadores();

						setItemMenuElegido(NINGUNO);
						accion = MENU_PRINCIPAL;
					}
					break;

				case CONFIGURAR_DIMENSIONES_TABLERO:
					//cout << "ACCION > CONFIGURAR_DIMENSIONES_TABLERO" << endl;

					if(accionAnteriorMenuOpciones != getItemMenuElegido()) {
						setItemMenuElegido(CONFIGURAR_DIMENSIONES_TABLERO);
						accionAnteriorMenuOpciones = getItemMenuElegido();
					}
					else {
						//cout << "opcionElegida: " << opcionElegida << endl;

						if(accionAnteriorMenuDimensionesTablero != getItemMenuDimensionesTableroElegido()) {
							setItemMenuElegido(CONFIGURAR_NIVEL_DIFICULTAD);

							accionAnteriorMenuOpciones = getItemMenuElegido();
						}
						else {

							if(getItemMenuDimensionesTableroElegido() == MENU_CONFIGURAR_DIMENSIONES_ITEM_NINGUNO) {
								menuDimensionesTablero itemElegido = buscarItemMenuDimensionesTablero(opcionElegida);
								setItemMenuDimensionesTableroElegido(itemElegido);
							}


							switch(getItemMenuDimensionesTableroElegido()) {
								case MENU_CONFIGURAR_DIMENSIONES_ITEM_INGRESAR_PISOS:
									//cout << "ACCION > INGRESAR_PISOS" << endl;

									if(accionAnteriorMenuDimensionesTablero != getItemMenuDimensionesTableroElegido()) {
										accionAnteriorMenuDimensionesTablero = getItemMenuDimensionesTableroElegido();
									}
									else if(esNumero(opcionElegida) && 0 < atoi(opcionElegida.c_str())) {
										unsigned int pisos = atoi(opcionElegida.c_str());
										unsigned int filasPorPiso = tablero -> obtenerCantidadDeFilas();
										unsigned int columnasPorPiso = tablero -> obtenerCantidadDeColumnas();

										tablero->cambiarDimensiones(pisos, filasPorPiso, columnasPorPiso);

										cout << "Cantidad de Pisos configurada !" << endl;
										setItemMenuElegido(NINGUNO);
										setItemMenuDimensionesTableroElegido(MENU_CONFIGURAR_DIMENSIONES_ITEM_NINGUNO);
										accion = MENU_PRINCIPAL;
									}
									break;

								case MENU_CONFIGURAR_DIMENSIONES_ITEM_INGRESAR_FILAS:
									//cout << "ACCION > INGRESAR_FILAS" << endl;

									if(accionAnteriorMenuDimensionesTablero != getItemMenuDimensionesTableroElegido()) {
										accionAnteriorMenuDimensionesTablero = getItemMenuDimensionesTableroElegido();
									}
									else if(esNumero(opcionElegida) && 0 < atoi(opcionElegida.c_str())) {
										unsigned int pisos = tablero -> obtenerCantidadDePisos();
										unsigned int filasPorPiso = atoi(opcionElegida.c_str());
										unsigned int columnasPorPiso = tablero -> obtenerCantidadDeColumnas();

										tablero->cambiarDimensiones(pisos, filasPorPiso, columnasPorPiso);

										cout << "Cantidad de Filas configurada !" << endl;
										setItemMenuElegido(NINGUNO);
										setItemMenuDimensionesTableroElegido(MENU_CONFIGURAR_DIMENSIONES_ITEM_NINGUNO);
										accion = MENU_PRINCIPAL;
									}
									break;

								case MENU_CONFIGURAR_DIMENSIONES_ITEM_INGRESAR_COLUMNA:
									//cout << "ACCION > INGRESAR_COLUMNA" << endl;

									if(accionAnteriorMenuDimensionesTablero != getItemMenuDimensionesTableroElegido()) {
										accionAnteriorMenuDimensionesTablero = getItemMenuDimensionesTableroElegido();
									}
									else if(esNumero(opcionElegida) && 0 < atoi(opcionElegida.c_str())) {
										unsigned int pisos = tablero -> obtenerCantidadDePisos();
										unsigned int filasPorPiso = tablero -> obtenerCantidadDeFilas();
										unsigned int columnasPorPiso = atoi(opcionElegida.c_str());

										tablero->cambiarDimensiones(pisos, filasPorPiso, columnasPorPiso);

										cout << "Cantidad de Columnas configurada !" << endl;
										setItemMenuElegido(NINGUNO);
										setItemMenuDimensionesTableroElegido(MENU_CONFIGURAR_DIMENSIONES_ITEM_NINGUNO);
										accion = MENU_PRINCIPAL;
									}
									break;

								default:
									break;
							}
						}
					}
					break;

				case CONFIGURAR_NIVEL_DIFICULTAD:
					//cout << "ACCION > CONFIGURAR_DIMENSIONES_TABLERO" << endl;

					if(accionAnteriorMenuOpciones != getItemMenuElegido()) {
						setItemMenuElegido(CONFIGURAR_NIVEL_DIFICULTAD);

						accionAnteriorMenuOpciones = getItemMenuElegido();
					}
					else {
						menuNivelDificultad nivelDificultadDetectado = buscarNivelDificultad(opcionElegida);
						if(nivelDificultadDetectado != DIFICULTAD_NO_VALIDA) {
							setItemMenuNivelDificultadElegido(nivelDificultadDetectado);

							*nivelDificultad = nivelDificultadDetectado;

							setItemMenuElegido(NINGUNO);
							accion = MENU_PRINCIPAL;
						}
					}
					break;


				case VOLVER:
					//cout << "VOLVER AL MENU_PRINCIPAL" << endl;
					accion = MENU_PRINCIPAL;
					setItemMenuElegido(NINGUNO);
					break;
			}
		}
	}

	return accion;
}

unsigned int Opciones::getTotalItems() {
	return this->totalItems;
}

bool Opciones::esNumero(const string& dato) {
	char* p;
	strtol(dato.c_str(), &p, 10);
	return *p == 0;
}

