/*
 * defines.h
 *
 *  Created on: 4 may. 2019
 *      Author: matias
 */

#ifndef SRC_DEFINES_H_
#define SRC_DEFINES_H_

	#define VERSION_JUEGO 							"3.0.2"

	#define TECLA_VOLVER 							"v"

	#define TABLERO_DEFAULT_TOTAL_PISOS 			1
	#define TABLERO_DEFAULT_TOTAL_FILAS_POR_PISO	7
	#define TABLERO_DEFAULT_TOTAL_COLUMNAS_POR_PISO	7

	#define DEFAULT_TOTAL_JUGADORES 				3

	#define JUEGO_TOTAL_FICHAS_POR_JUGADOR 			(TABLERO_DEFAULT_TOTAL_PISOS * TABLERO_DEFAULT_TOTAL_FILAS_POR_PISO * TABLERO_DEFAULT_TOTAL_COLUMNAS_POR_PISO / DEFAULT_TOTAL_JUGADORES)

	////////////////////////////////////////////////////////////////////////
	//Configuracion Visualizador

	#define ID_MINIMO								48	      // Es el ascii del '0'. Usado al momento de convertir el char id que representa al jugador guardado en el tablero, a un int (usado en la clase Jugador)
	#define COLOR_MAX_INT_VALUE 					16777215  // Usado para generar el color de la ficha. Representa al valor máximo q puede tomar el int

	#define PATH_IMAGEN_TABLERO_PISO				"Piso.bmp"
	#define PATH_IMAGEN_TABLERO_CASILLERO			"casilleroPiso.bmp"

	#define PROFUNDIDAD_DE_BITS						8
	#define SEPARACION_ENTRE_CASILLEROS_EN_PIXELES	5
	#define ANCHO_FICHA_EN_PIXELES					50
	#define ALTO_FICHA_EN_PIXELES					50
	#define BORDE_TABLERO_EN_PIXELES				10
	#define COLOR_TABLERO							1984640
	////////////////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////////////////
	// Cartas

	#define CARTA_CAMBIAR_COLOR								"cambiarColorFicha" 		// OK
	#define CARTA_ELIMINAR_FICHA_POR_UBICACION				"eliminarFicha" 			// OK
	#define CARTA_INTERCAMBIAR_FICHA_VECINA					"intercambiarFichaVecina" 	// ok (ultimo)
	#define CARTA_PORTAL									"portal" 					// ok (ultimo)
	#define CARTA_ELIMINAR_ULTIMA_FICHA_JUGADOR_ANTERIOR	"ignorarUltimaJugada" 		// OK
	#define CARTA_PONER_FICHA_2_VECES						"ponerFicha2Veces" 			// OK (nuestra carta)

	#define CARTAS_TOTAL									6

	#define MAXIMA_CANTIDAD_CARTAS_POR_JUGADOR				4
	////////////////////////////////////////////////////////////////////////

	enum estadoJuego {
		TEST,
		LOAD_INICIAL,
		SPLASH,
		MENU_PRINCIPAL,
		CARGAR_JUEGO,
		JUGANDO,
		OPCIONES,
		ESTADISTICAS,
		ACERCA_DE,
		SALIR
	};

	enum menuOpciones {
		CONFIGURAR_CANTIDAD_JUGADORES,
		CONFIGURAR_DIMENSIONES_TABLERO,
		CONFIGURAR_NIVEL_DIFICULTAD,
		VOLVER,
		NINGUNO
	};

	enum menuDimensionesTablero {
		MENU_CONFIGURAR_DIMENSIONES_ITEM_INGRESAR_PISOS,
		MENU_CONFIGURAR_DIMENSIONES_ITEM_INGRESAR_FILAS,
		MENU_CONFIGURAR_DIMENSIONES_ITEM_INGRESAR_COLUMNA,
		MENU_CONFIGURAR_DIMENSIONES_ITEM_VOLVER,
		MENU_CONFIGURAR_DIMENSIONES_ITEM_NINGUNO
	};

	enum menuNivelDificultad {
		FACIL,
		INTERMEDIO,
		DIFICIL,
		DIFICULTAD_NO_VALIDA
	};

	enum enJuegoEstadoAccionJugador {
		ENJUEGO_JUGADOR_TIRAR_CARTA,
		ENJUEGO_JUGADOR_INGRESAR_FILA,
		ENJUEGO_JUGADOR_INGRESAR_COLUMNA,
		ENJUEGO_JUGADOR_DATOS_INGRESADOS,
		JUEGO_TERMINADO
	};


#endif /* SRC_DEFINES_H_ */
