
#include "Mazo.h"



void Mazo::mostrarCartas(){

	if(!this->cartas.estaVacia()){
		std::cout<<"Usted tiene las siguientes cartas: "<<std::endl;
		this->cartas.iniciarCursor();
		unsigned int i =1;
			while(this->cartas.avanzarCursor()){
				//std::cout<<"\tPresione '" << i<<"' para >>>> "<<this->cartas.obtenerCursor().identificador<<std::endl;
				std::cout<<"\t'" << this->cartas.obtenerCursor().identificador<< "' (Presione '" << i << "' para usarla)" << std::endl;
				i++;
			}
	}else{
		std::cout<<"Usted no tiene cartas"<<std::endl;
	}

}




