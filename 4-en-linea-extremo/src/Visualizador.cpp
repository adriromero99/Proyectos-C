#include "Visualizador.h"

using namespace std;

Visualizador::Visualizador(unsigned int filasPiso,	unsigned int columnasPiso){

	this->setColumnasPiso(columnasPiso);
	this->setFilasPiso(filasPiso);
	this->setAltoPixelesPiso(this->obtenerAltoTablero());
	this->setAnchoPixelesPiso(this->obtenerAnchoTablero());
}

void Visualizador::generarFotoPiso(Piso* pisoASacarFoto, ManagerListaJugadores * managerListaJugadores)
{
	bool sePudoConstruirMapaBitsTablero = dibujarTablero(this->imagenPiso, this->getAnchoPixelesPiso(),
			this->getAltoPixelesPiso(), COLOR_TABLERO, PROFUNDIDAD_DE_BITS);

	bool sePudoConstruirMapaBitsFicha = false;

		for (unsigned int fila = 1; fila < this->getFilasPiso() + 1; fila++) {
			Fila* filaActual = pisoASacarFoto->obtenerFilaNumero(fila);
			for (unsigned int columna = 1; columna < this->getColumnasPiso() + 1; columna++) {
				//Va en el define
				unsigned int idJugadorActual = (unsigned int) filaActual->obtenerFichaEn(columna) - ID_MINIMO;

				Jugador jugadorActual = managerListaJugadores->obtenerJugadorPorId(idJugadorActual);
				unsigned int colorFicha = jugadorActual.obtenerColorFichaIntRGB();

				sePudoConstruirMapaBitsFicha = dibujarFicha(
					this->casilleroPiso,
					ANCHO_FICHA_EN_PIXELES,
					ALTO_FICHA_EN_PIXELES,
					colorFicha,
					PROFUNDIDAD_DE_BITS
				);

				if(sePudoConstruirMapaBitsTablero && sePudoConstruirMapaBitsFicha) {
					unsigned int x = BORDE_TABLERO_EN_PIXELES + ((ANCHO_FICHA_EN_PIXELES + SEPARACION_ENTRE_CASILLEROS_EN_PIXELES) * (columna -1 ));
					unsigned int y = BORDE_TABLERO_EN_PIXELES + ((ALTO_FICHA_EN_PIXELES + SEPARACION_ENTRE_CASILLEROS_EN_PIXELES) * (fila-1));

					dibujarFichaEnTablero(this->casilleroPiso, x, y, this->imagenPiso);
				}
			}
		}

		if(sePudoConstruirMapaBitsTablero && sePudoConstruirMapaBitsFicha) {
			this->imagenPiso.WriteToFile( PATH_IMAGEN_TABLERO_PISO );
		}else{
			throw string("Error al tomar foto del piso.");
		}
}


unsigned int Visualizador::getAltoPixelesPiso()
{
	return this->altoPixelesPiso;
}


void Visualizador::setAltoPixelesPiso(unsigned int altoPixelesPiso)
{
	this->altoPixelesPiso = altoPixelesPiso;
}


unsigned int Visualizador::getAnchoPixelesPiso()
{
	return this->anchoPixelesPiso;
}


void Visualizador::setAnchoPixelesPiso(unsigned int anchoPixelesPiso)
{
	this->anchoPixelesPiso = anchoPixelesPiso;
}


unsigned int Visualizador::getFilasPiso()
{
	return this->filasPiso;
}


void Visualizador::setFilasPiso(unsigned int filasPiso)
{
	this->filasPiso = filasPiso;
}


unsigned int Visualizador::getColumnasPiso()
{
	return this->columnasPiso;
}

void Visualizador::setColumnasPiso(unsigned int columnasPiso)
{
	this->columnasPiso = columnasPiso;
}

unsigned int Visualizador::obtenerAnchoTablero()
{
	return BORDE_TABLERO_EN_PIXELES + (this->getFilasPiso() * ANCHO_FICHA_EN_PIXELES) + ((this->getFilasPiso() - 1) * SEPARACION_ENTRE_CASILLEROS_EN_PIXELES) + BORDE_TABLERO_EN_PIXELES;
}

unsigned int Visualizador::obtenerAltoTablero()
{
	return BORDE_TABLERO_EN_PIXELES + (this->getColumnasPiso() * ALTO_FICHA_EN_PIXELES) + ((this->getColumnasPiso() - 1) * SEPARACION_ENTRE_CASILLEROS_EN_PIXELES) + BORDE_TABLERO_EN_PIXELES;
}



void Visualizador::dibujarFichaEnTablero(BMP & imagenMapaBitsFicha, unsigned int x, unsigned int y, BMP & imagenMapaBitsTablero) {
	RangedPixelToPixelCopy(imagenMapaBitsFicha, 0, imagenMapaBitsTablero.TellWidth(), 0, imagenMapaBitsTablero.TellHeight(), imagenMapaBitsTablero, x, y);
}

bool Visualizador::dibujarTablero(BMP & imagenMapaBits, unsigned int anchoPx, unsigned int altoPx, unsigned int colorARGB, unsigned int profundidadDeBits) {
	return completarMapaBits(imagenMapaBits, anchoPx, altoPx, colorARGB, profundidadDeBits);
}

bool Visualizador::dibujarFicha(BMP & imagenMapaBits, unsigned int anchoPx, unsigned int altoPx, unsigned int colorARGB, unsigned int profundidadDeBits) {
	return completarMapaBits(imagenMapaBits, anchoPx, altoPx, colorARGB, profundidadDeBits);
}

bool Visualizador::completarMapaBits(BMP & imagenMapaBits, unsigned int anchoEnPixeles, unsigned int altoEnPixeles, unsigned int colorARGB, unsigned int profundidadDeBits) {
	imagenMapaBits.SetSize(anchoEnPixeles, altoEnPixeles);
	imagenMapaBits.SetBitDepth(profundidadDeBits);

	// Para conocer colorFicha correspondiente a un color > https://www.shodor.org/stella2java/rgbint.html
	return actualizarColorMapaBits(imagenMapaBits, colorARGB, profundidadDeBits);
}

bool Visualizador::actualizarColorMapaBits(BMP & imagenMapaBits, unsigned int argb, unsigned int profundidadDeBits) {
	int cantiadadCanales = 4; // Los canales son: A R G B
	unsigned int maxValor = 1; // valor inicial
	for(int i = 0; i < cantiadadCanales; i++) {
		maxValor *= pow(2, profundidadDeBits);
	}
	maxValor--; // se le resta 1, porque el rango de posibles valores incluye al 0

	if(argb < 0 || maxValor < argb) {
		cout << "rgba debe pertenecer al intervalo [0, " << maxValor << "]" << endl;
		return false;
	}

	int red = 0;
	int green = 0;
	int blue = 0;
	int alpha = 0;

	if(profundidadDeBits == 8) {
		alpha = (argb & 0xff000000) >> 24;
		red = (argb & 0x00ff0000) >> 16;
		green = (argb & 0x0000ff00) >> 8;
		blue = (argb & 0x000000ff);
	}

	for( int j=0 ; j < imagenMapaBits.TellHeight() ; j++) {
		for( int i=0 ; i < imagenMapaBits.TellWidth() ; i++) {
			imagenMapaBits(i,j)->Alpha = alpha;
			imagenMapaBits(i,j)->Red = red;
			imagenMapaBits(i,j)->Green = green;
			imagenMapaBits(i,j)->Blue = blue;
		}
	}

	return true;
}
