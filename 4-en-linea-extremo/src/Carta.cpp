#include <cstdlib>
#include <time.h>

#include "defines.h"
#include "Carta.h"

Carta::Carta(){
	srand(time(NULL));

	//contadorCambioDeColor = 0;
	//limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;
	unsigned int numeroAlAzar =  1 + rand() % (CARTAS_TOTAL);

	switch(numeroAlAzar){
		case 1:
			identificador = CARTA_ELIMINAR_ULTIMA_FICHA_JUGADOR_ANTERIOR;
			break;

		case 2:
			identificador = CARTA_ELIMINAR_FICHA_POR_UBICACION;
			break;

		case 3:
			identificador = CARTA_CAMBIAR_COLOR;
			break;

		case 4:
			identificador = CARTA_PONER_FICHA_2_VECES;
			break;

		case 5:
			identificador = CARTA_INTERCAMBIAR_FICHA_VECINA;
			break;

		case 6:
			identificador = CARTA_PORTAL;
			break;

	}

}

void Carta::usar(Tablero* tablero, char fichaJugador, ManagerListaJugadores * jugadores, unsigned int *contadorCambioColor){
	if(this->identificador == CARTA_ELIMINAR_ULTIMA_FICHA_JUGADOR_ANTERIOR){
		this->ignorarUltimaJugada(tablero);
	}else if(this->identificador == CARTA_ELIMINAR_FICHA_POR_UBICACION){
		this->eliminarFicha(tablero);
	}else if(this->identificador == CARTA_CAMBIAR_COLOR){
		this->cambiarColorFicha(tablero, fichaJugador, jugadores, contadorCambioColor);
	}else if(this->identificador == CARTA_PONER_FICHA_2_VECES){
		this->ponerFicha2Veces(tablero, fichaJugador);
	}else if(this->identificador == CARTA_INTERCAMBIAR_FICHA_VECINA){
		this->intercambioConVecina(tablero);
	}else if(this->identificador == CARTA_PORTAL){
		this->portal(tablero);
	}
}
void Carta::ignorarUltimaJugada(Tablero* tablero){
	unsigned int pisoUltimaFicha = tablero->obtenerPisoUltimaFicha();
	unsigned int filaUltimaFicha = tablero->obtenerFilaUltimaFicha();
	unsigned int columnaUltimaFicha = tablero->obtenerColumnaUltimaFicha();
	std::cout<<"Se ha eliminado la ultima ficha jugada"<<std::endl;
	tablero->vaciarCasilleroEn(pisoUltimaFicha, filaUltimaFicha, columnaUltimaFicha);
}

void Carta::eliminarFicha(Tablero* tablero){
	string opcionElegida;
	unsigned int piso,fila,columna;

	std::cout<<"Se usa la carta 'Eliminar una Ficha'"<<std::endl;

	do{
		std::cout<<"Ingrese el piso de la ficha a eliminar"<<std::endl;
		cout << ">: ";
		getline(cin, opcionElegida);
		piso = atoi (opcionElegida.c_str());

		std::cout<<"Ingrese la fila de la ficha a eliminar"<<std::endl;
		cout << ">: ";
		getline(cin, opcionElegida);
		fila = atoi (opcionElegida.c_str());

		std::cout<<"Ingrese la columna de la ficha a eliminar"<<std::endl;
		cout << ">: ";
		getline(cin, opcionElegida);
		columna = atoi (opcionElegida.c_str());
	}while(!esValidaLaPosicion(piso,fila,columna,tablero) || this->elCasilleroEstaVacio(piso,fila,columna, tablero));

	tablero->vaciarCasilleroEn(piso, fila, columna);
}

void Carta::cambiarColorFicha(Tablero* tablero, char ficha, ManagerListaJugadores* jugadores, unsigned int *contadorCambioColor){
	string opcionElegida;
	unsigned int piso,fila,columna;

	std::cout<<"Se usa la carta 'cambiar Color de una Ficha'"<<std::endl;

	do{
		std::cout<<"Ingrese el piso de la ficha a cambiar"<<std::endl;
		cout << ">: ";
		getline(cin, opcionElegida);
		piso = atoi (opcionElegida.c_str());

		std::cout<<"Ingrese la fila de la ficha a cambiar"<<std::endl;
		cout << ">: ";
		getline(cin, opcionElegida);
		fila = atoi (opcionElegida.c_str());

		std::cout<<"Ingrese la columna de la ficha a cambiar"<<std::endl;
		cout << ">: ";
		getline(cin, opcionElegida);
		columna = atoi (opcionElegida.c_str());
	}while(!esValidaLaPosicion(piso,fila,columna,tablero) || (this->elCasilleroEstaVacio(piso,fila,columna,tablero)));


	if(*contadorCambioColor < (jugadores ->contarJugadores())){
		*contadorCambioColor = *contadorCambioColor + 1;
	}
	else{
		*contadorCambioColor = 1;
	}
	char fichaQueSePone = jugadores->obtenerJugadorPorId(*contadorCambioColor).obtenerFicha();
	tablero->ubicarFichaEn(piso, fila, columna, fichaQueSePone);

}

void Carta::ponerFicha2Veces(Tablero* tablero, char ficha){
	string opcionElegida;
	unsigned int fila, columna;

	std::cout<<"Se usa la carta 'Poner Ficha 2 veces'"<<std::endl;

	for(unsigned int i = 1; i<=2; i++){
		do{
			std::cout<<"Ingrese la fila donde desea ingresar la ficha numero "<< i <<std::endl;
			cout << ">: ";
			getline(cin, opcionElegida);
			fila = atoi (opcionElegida.c_str());

			std::cout<<"Ingrese la columna donde desea ingresar la ficha numero "<< i <<std::endl;
			cout << ">: ";
			getline(cin, opcionElegida);
			columna = atoi (opcionElegida.c_str());
		}while(!esValidaLaPosicion(1,fila,columna,tablero));

		tablero->pudoPonerFicha(fila, columna, ficha);

	}

}

void Carta::intercambioConVecina(Tablero* tablero){
	string opcionElegida;
	unsigned int piso,fila,columna,casilleroConElQueCambia;
	std::cout<<"Se usa la carta 'Intercambiar Ficha con Vecina'"<<std::endl;

		do{
			std::cout<<"Ingrese el piso de la ficha a intercambiar"<<std::endl;
			cout << ">: ";
			getline(cin, opcionElegida);
			piso = atoi (opcionElegida.c_str());

			std::cout<<"Ingrese la fila de la ficha a intercambiar"<<std::endl;
			cout << ">: ";
			getline(cin, opcionElegida);
			fila = atoi (opcionElegida.c_str());

			std::cout<<"Ingrese la columna de la ficha a intercambiar"<<std::endl;
			cout << ">: ";
			getline(cin, opcionElegida);
			columna = atoi (opcionElegida.c_str());
		}while(!esValidaLaPosicion(piso,fila,columna,tablero)||(this->elCasilleroEstaVacio(piso,fila,columna,tablero)));

		if ((fila == tablero->obtenerCantidadDeFilas())&&(columna == tablero->obtenerCantidadDeColumnas())){
				cout<<"¿Con quien desea intercambiarla?: "
					<<"\n>1: Casillero de la izquierda"
					<<"\n>3: Casillero superior\n>"
					<<endl;
				//cin>>casilleroConElQueCambia;
				getline(cin, opcionElegida);
				casilleroConElQueCambia = atoi (opcionElegida.c_str());
				while((casilleroConElQueCambia!=1)&&(casilleroConElQueCambia!=3)){
					cargarDenuevo(&casilleroConElQueCambia);
				}
		}else
			if((fila == 1)&&(columna == tablero->obtenerCantidadDeColumnas())){
				cout<<"¿Con quien desea intercambiarla?: "
					<<"\n>1: Casillero de la izquierda"
					<<"\n>4: Casillero inferior\n>"
					<<endl;
				//cin>>casilleroConElQueCambia;
				getline(cin, opcionElegida);
				casilleroConElQueCambia = atoi (opcionElegida.c_str());
				while((casilleroConElQueCambia!=1)&&(casilleroConElQueCambia!=4)){
					cargarDenuevo(&casilleroConElQueCambia);
				}
		}else
			if((fila == tablero->obtenerCantidadDeFilas())&&(columna == 1)){
				cout<<"¿Con quien desea intercambiarla?: "
					<<"\n>2: Casillero de la derecha"
					<<"\n>3: Casillero superior\n>"
					<<endl;
				//cin>>casilleroConElQueCambia;
				getline(cin, opcionElegida);
				casilleroConElQueCambia = atoi (opcionElegida.c_str());
				while((casilleroConElQueCambia!=2)&&(casilleroConElQueCambia!=3)){
					cargarDenuevo(&casilleroConElQueCambia);
				}
		}else
			if((fila == 1)&&(columna == 1)){
				cout<<"¿Con quien desea intercambiarla?: "
					<<"\n>2: Casillero de la derecha"
					<<"\n>4: Casillero inferior\n>"
					<<endl;
				//cin>>casilleroConElQueCambia;
				getline(cin, opcionElegida);
				casilleroConElQueCambia = atoi (opcionElegida.c_str());
				while((casilleroConElQueCambia!=2)&&(casilleroConElQueCambia!=4)){
					cargarDenuevo(&casilleroConElQueCambia);
				}
		}else
			if (fila == 1){
				cout<<"¿Con quien desea intercambiarla?: "
					<<"\n>1: Casillero de la izquierda"
					<<"\n>2: Casillero de la derecha"
					<<"\n>4: Casillero inferior\n>"
					<<endl;
				//cin>>casilleroConElQueCambia;
				getline(cin, opcionElegida);
				casilleroConElQueCambia = atoi (opcionElegida.c_str());
				while((casilleroConElQueCambia!=1)&&(casilleroConElQueCambia!=2)&&(casilleroConElQueCambia!=4)){
					cargarDenuevo(&casilleroConElQueCambia);
				}
		}else
			if (fila == tablero->obtenerCantidadDeFilas()){
				cout<<"¿Con quien desea intercambiarla?: "
					<<"\n>1: Casillero de la izquierda"
					<<"\n>2: Casillero de la derecha"
					<<"\n>3: Casillero superior\n>"
					<<endl;
				//cin>>casilleroConElQueCambia;
				getline(cin, opcionElegida);
				casilleroConElQueCambia = atoi (opcionElegida.c_str());
				while((casilleroConElQueCambia!=1)&&(casilleroConElQueCambia!=2)&&(casilleroConElQueCambia!=3)){
					cargarDenuevo(&casilleroConElQueCambia);
				}
		}else
			if(columna == 1){
				cout<<"¿Con quien desea intercambiarla?: "
					<<"\n>2: Casillero de la derecha"
					<<"\n>3: Casillero superior"
					<<"\n>4: Casillero inferior\n>"
					<<endl;
				//cin>>casilleroConElQueCambia;
				getline(cin, opcionElegida);
				casilleroConElQueCambia = atoi (opcionElegida.c_str());
				while((casilleroConElQueCambia!=2)&&(casilleroConElQueCambia!=3)&&(casilleroConElQueCambia!=4)){
					cargarDenuevo(&casilleroConElQueCambia);
				}
		}else
			if(columna == tablero->obtenerCantidadDeColumnas()){
				cout<<"¿Con quien desea intercambiarla?: "
					<<"\n>1: Casillero de la izquierda"
					<<"\n>3: Casillero superior"
					<<"\n>4: Casillero inferior\n>"
					<<endl;
				//cin>>casilleroConElQueCambia;
				getline(cin, opcionElegida);
				casilleroConElQueCambia = atoi (opcionElegida.c_str());
				while((casilleroConElQueCambia!=1)&&(casilleroConElQueCambia!=3)&&(casilleroConElQueCambia!=4)){
					cargarDenuevo(&casilleroConElQueCambia);
				}
		}else{
			cout<<"¿Con quien desea intercambiarla?: "
				<<"\n>1: Casillero de la izquierda"
				<<"\n>2: Casillero de la derecha"
				<<"\n>3: Casillero superior"
				<<"\n>4: Casillero inferior\n>"
				<<endl;
			//cin>>casilleroConElQueCambia;
			getline(cin, opcionElegida);
			casilleroConElQueCambia = atoi (opcionElegida.c_str());
			while((casilleroConElQueCambia<1)&&(casilleroConElQueCambia>4)){
				cargarDenuevo(&casilleroConElQueCambia);
			}
		}

		intercambiar(tablero, casilleroConElQueCambia, piso, fila, columna);
}

void Carta::cargarDenuevo(unsigned int *casilleroConElQueCambia){
	string opcionElegida;
	cout<<"\nOpcion invalida. Vuelva a ingresar."<<endl;
	//cin>>*casilleroConElQueCambia;
	getline(cin, opcionElegida);
	*casilleroConElQueCambia = atoi (opcionElegida.c_str());
}

void Carta::intercambiar(Tablero* tablero, unsigned int casilleroConElQueCambia, unsigned int piso, unsigned int fila, unsigned int columna){


	switch(casilleroConElQueCambia){
	case 1:
		{
		cambiarConIzquierda(tablero, piso, fila, columna);
		cout<<"\nSe realizo el cambio con la vecina de la izquierda.\n"<<endl;
		break;
		}

	case 2:
		{
		cambiarConDerecha(tablero, piso, fila, columna);
		cout<<"\nSe realizo el cambio con la vecina de la derecha.\n"<<endl;
		break;
		}

	case 3:
		{
		cambiarConSuperior(tablero, piso, fila, columna);
		cout<<"\nSe realizo el cambio con la vecina superior.\n"<<endl;
		break;
		}

	case 4:
		{
		cambiarConInferior(tablero, piso, fila, columna);
		cout<<"\nSe realizo el cambio con la vecina inferior.\n"<<endl;
		break;
		}
	}

}


void Carta::cambiarConIzquierda(Tablero* tablero, unsigned int piso, unsigned int fila, unsigned int columna){
	char auxFichaEnElCasillero = tablero -> obtenerFichaEn(piso, fila, columna);
	tablero -> ubicarFichaEn(piso, fila, columna, tablero -> obtenerFichaEn(piso, fila, columna-1));
	tablero -> ubicarFichaEn(piso, fila, columna-1, auxFichaEnElCasillero);
}

void Carta::cambiarConDerecha(Tablero* tablero, unsigned int piso, unsigned int fila, unsigned int columna){
	char auxFichaEnElCasillero = tablero -> obtenerFichaEn(piso, fila, columna);
	tablero -> ubicarFichaEn(piso, fila, columna, tablero -> obtenerFichaEn(piso, fila, columna+1));
	tablero -> ubicarFichaEn(piso, fila, columna+1, auxFichaEnElCasillero);
}

void Carta::cambiarConSuperior(Tablero* tablero, unsigned int piso, unsigned int fila, unsigned int columna){
	char auxFichaEnElCasillero = tablero -> obtenerFichaEn(piso, fila, columna);
	tablero -> ubicarFichaEn(piso, fila, columna, tablero -> obtenerFichaEn(piso, fila-1, columna));
	tablero -> ubicarFichaEn(piso, fila-1, columna, auxFichaEnElCasillero);
}

void Carta::cambiarConInferior(Tablero* tablero, unsigned int piso, unsigned int fila, unsigned int columna){
	char auxFichaEnElCasillero = tablero -> obtenerFichaEn(piso, fila, columna);
	tablero -> ubicarFichaEn(piso, fila, columna, tablero -> obtenerFichaEn(piso, fila+1, columna));
	tablero -> ubicarFichaEn(piso, fila+1, columna, auxFichaEnElCasillero);
}

bool Carta::elCasilleroEstaVacio(unsigned int piso, unsigned int fila, unsigned int columna, Tablero* tablero){

	if(tablero->estaVacioCasillero(piso,fila,columna)){
		std::cout<<"El casillero seleccionado no esta ocupado por una ficha, ingrese otro casillero:"<<std::endl;
	}

	return(tablero->estaVacioCasillero(piso,fila,columna));
}

bool Carta::esValidaLaPosicion(unsigned int piso, unsigned int fila, unsigned int columna, Tablero* tablero){
	bool esValida = false;

	if(piso>0 && fila>0 && columna>0 && piso<=tablero->obtenerCantidadDePisos()
			&& fila<=tablero->obtenerCantidadDeFilas() && columna<=tablero->obtenerCantidadDeColumnas()){
		esValida = true;
	}
	else{
		std::cout<<"La posicion ingresada no esta en los limites del tablero"<<std::endl;
	}

	return(esValida);
}

void Carta::portal(Tablero* tablero){
		string opcionElegida;
		unsigned int piso,fila,columna;

		std::cout<<"Se usa la carta 'PORTAL'"<<std::endl;

		do{
			std::cout<<"Ingrese el piso del portal"<<std::endl;
			cout << ">: ";
			getline(cin, opcionElegida);
			piso = atoi (opcionElegida.c_str());

			std::cout<<"Ingrese la fila del portal"<<std::endl;
			cout << ">: ";
			getline(cin, opcionElegida);
			fila = atoi (opcionElegida.c_str());

			std::cout<<"Ingrese la columna del portal"<<std::endl;
			cout << ">: ";
			getline(cin, opcionElegida);
			columna = atoi (opcionElegida.c_str());
		}while(!esValidaLaPosicion(piso,fila,columna,tablero) || (this->elCasilleroEstaVacio(piso,fila,columna,tablero)));

		this->unirCasilleros(tablero,piso,fila,columna);

}

void Carta::unirCasilleros(Tablero* tablero, unsigned int piso, unsigned int fila, unsigned int columna){
	for (unsigned int i = columna+1;i<tablero->obtenerCantidadDeColumnas()+1; i++){
		char ficha = tablero->obtenerFichaEn(piso,fila,i);
		tablero->ubicarFichaEn(piso, fila, i-1, ficha);
	}
	tablero->ubicarFichaEn(piso, fila, tablero->obtenerCantidadDeColumnas(), '0');
}
