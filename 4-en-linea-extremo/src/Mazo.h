

#ifndef JUGADORPRUEBA_H_
#define JUGADORPRUEBA_H_

#include "Lista.h"
#include "Carta.h"

class Mazo{

public:

	Lista <Carta> cartas;

	// POST: Muesta todas las cartas del mazo
	void mostrarCartas();

};



#endif /* JUGADORPRUEBA_H_ */
