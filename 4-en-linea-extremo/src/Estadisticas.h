#ifndef ESTADISTICAS_H_
#define ESTADISTICAS_H_	

	#include <string>
	#include <iostream>

	#include "defines.h"

	#include "ManagerListaJugadores.h"


	class Estadisticas {
		private:
			string teclaVolver;

			// POST: devuelve la tecla asociada a al acción VOLVER
			string getTeclaVolver();


		public:
			// POST: se construye el objeto Estadísticas
			Estadisticas();

			// POST: Libera la memoria
			~Estadisticas();

			// PRE: La cantidad de 'jugadores' debe ser mayor a 1
			// POST: uestra por pantalla el contenido de la sección ESTADISTICAS
			void mostrarPantalla(ManagerListaJugadores * jugadores);

			// POST: Setea el estado del juego a ESTADISTICAS (Si 'opcionElegida' es != TECLA_VOLVER)
			// 		 o MENU_PRINCIPAL (Si 'opcionElegida' es TECLA_VOLVER)
			estadoJuego ejecutarAccionUsuario(string opcionElegida);

	};
#endif /* ESTADISTICAS_H_ */
