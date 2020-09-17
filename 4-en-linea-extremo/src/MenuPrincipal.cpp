#include "MenuPrincipal.h"

MenuPrincipal::MenuPrincipal() {
	cargarItemsAlMenu();
}

MenuPrincipal::~MenuPrincipal() {
}

void MenuPrincipal::cargarItemsAlMenu() {
	string itemsMenuTextoTecla[][2] = {
		{"Jugar", "1"}
		,{"Opciones", "2"}
		,{"Acerca de", "3"}
		,{"Estadisticas", "4"}
		,{"Salir", "5"}
	};
	const unsigned int ITEM_TEXTO = 0;
	const unsigned int ITEM_TECLA = 1;

	estadoJuego accionItems [] = {
		CARGAR_JUEGO
		,OPCIONES
		,ACERCA_DE
		,ESTADISTICAS
		,SALIR
	};

	this->totalItems = 5;


	for(unsigned int i = 0; i < this->totalItems; i++) {
		Item <estadoJuego> item(
			itemsMenuTextoTecla[i][ITEM_TEXTO],
			itemsMenuTextoTecla[i][ITEM_TECLA],
			accionItems[i]
		);
		items.push_back(item);

		this->teclasValidas.push_back(itemsMenuTextoTecla[i][ITEM_TECLA]);
	}
}

void MenuPrincipal::mostrarPantalla() {
	cout << endl;
	cout << endl;
	for(unsigned int i = 0; i < getTotalItems(); i++) {
		cout << "\t\t" << items[i].getTeclaParaAcceder() << " - " << items[i].getNombre() << endl;
	}
	cout << endl;
	cout << endl;
}

unsigned int MenuPrincipal::getTotalItems() {
	return this->totalItems;
}


estadoJuego MenuPrincipal::ejecutarAccionUsuario(string accionUsuario) {
	return getAccionItem(accionUsuario);
}

estadoJuego MenuPrincipal::getAccionItem(string opcionElegida) {
	estadoJuego accion = MENU_PRINCIPAL;

	bool accionItemDetectada = false;

	for(unsigned int i = 0; !accionItemDetectada && i < getTotalItems(); i++) {

		accionItemDetectada = (opcionElegida.compare(this->items[i].getTeclaParaAcceder()) == 0);

		if(accionItemDetectada) {
			accion = this->items[i].getAccion();
		}
	}

	return accion;
}

