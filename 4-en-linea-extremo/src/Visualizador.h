#ifndef VISUALIZADOR_H_
#define VISUALIZADOR_H_

#include "EasyBMP.h"
#include "defines.h"
#include "Tablero.h"
#include "Lista.h"
#include "Jugador.h"
#include "ManagerListaJugadores.h"

class Visualizador{

private:
	unsigned int altoPixelesPiso;
	unsigned int anchoPixelesPiso;
	unsigned int filasPiso;
	unsigned int columnasPiso;
	BMP imagenPiso;
	BMP casilleroPiso;
public:
	//pre:-
	//post: Se crea por defecto un visualizador vacio.
	Visualizador();
	//pre: filasPiso, columnasPiso deben ser numeros positivos.
	//post: crea el visualizador dividido en filasPiso x columnasPiso casilleros.
	Visualizador(unsigned int filasPiso,unsigned int columnasPiso);
	//pre: recibe un puntero a pisoASacarFoto
	//post: genera la foto del estado del piso con las fichas que contiene.
	void generarFotoPiso(Piso* pisoASacarFoto, ManagerListaJugadores * managerListaJugadores);
	//pre:-
	//post: inicializa el tablero en donde se colocaran las fichas.
	bool dibujarTablero(BMP & imagenMapaBits, unsigned int anchoPx, unsigned int altoPx, unsigned int colorARGB, unsigned int profundidadDeBits);
	//pre:-
	//post: dibuja la ficha segun el color de cada jugador.
	bool dibujarFicha(BMP & imagenMapaBits, unsigned int anchoPx, unsigned int altoPx, unsigned int colorARGB, unsigned int profundidadDeBits);
	//pre:-
	//post: asigna tamaño de la ficha en pixeles y actuliza el color de la ficha.
	bool completarMapaBits(BMP & imagenMapaBits, unsigned int anchoPx, unsigned int altoPx, unsigned int colorARGB, unsigned int profundidadDeBits);
	//pre:-
	//post: actualiza la imagen con las fichas de los colores jugados.
	bool actualizarColorMapaBits(BMP & imagenMapaBits, unsigned int argb, unsigned int profundidadDeBits);
	//pre: imagenMapaBitsFicha y imagenMapaBitsTablero deben estar inicializados.
	//post:dibuja imagenMapaBitsFicha en la posicion x e y del imagenMapaBitsTablero.
	void dibujarFichaEnTablero(BMP & imagenMapaBitsFicha, unsigned int x, unsigned int y, BMP & imagenMapaBitsTablero);
	//pre:-
	//post:obtiene el valor del atributo altoPixelesPiso
	unsigned int getAltoPixelesPiso();
	//pre:-
	//post:modifica el valor del atributo altoPixelesPiso por altoPixelesPiso
	void setAltoPixelesPiso(unsigned int altoPixelesPiso);
	//pre:-
	//post:obtiene el valor del atributo anchoPixelesPiso
	unsigned int getAnchoPixelesPiso();
	//pre:-
	//post:modifica el valor del atributo anchoPixelesPiso por anchoPixelesPiso
	void setAnchoPixelesPiso(unsigned int anchoPixelesPiso);
	//pre:-
	//post: obtiene el valor del atributo filasPiso.
	unsigned int getFilasPiso();
	//pre:-
	//post: modifica el valor del atributo filasPiso por filasPiso
	void setFilasPiso(unsigned int filasPiso);
	//pre:-
	//post: obtiene el valor del atributo columnasPiso.
	unsigned int getColumnasPiso();
	//pre: -
	//post: modifica el valor del atributo columnasPiso por columnasPiso
	void setColumnasPiso(unsigned int columnasPiso);
	//pre: el visualizador debe estar inicializado con la cantidad de columnas necesarias
	//post: devuelve el ancho en pixeles del tablero.
	unsigned int obtenerAnchoTablero();
	//pre: el visualizador debe estar inicializado con la cantidad de filas necesarias
	//post: devuelve el alto en pixeles del tablero.
	unsigned int obtenerAltoTablero();

};

#endif /* VISUALIZADOR_H_ */
