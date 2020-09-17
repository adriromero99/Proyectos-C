################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/AcercaDe.cpp \
../src/Alumno.cpp \
../src/Carta.cpp \
../src/EasyBMP.cpp \
../src/EnJuego.cpp \
../src/Estadisticas.cpp \
../src/Fila.cpp \
../src/Jugador.cpp \
../src/ManagerListaJugadores.cpp \
../src/Mazo.cpp \
../src/MenuPrincipal.cpp \
../src/Opciones.cpp \
../src/Piso.cpp \
../src/Portacartas.cpp \
../src/Splash.cpp \
../src/Tablero.cpp \
../src/Tp3.cpp \
../src/Validador.cpp \
../src/Visualizador.cpp \
../src/main.cpp 

OBJS += \
./src/AcercaDe.o \
./src/Alumno.o \
./src/Carta.o \
./src/EasyBMP.o \
./src/EnJuego.o \
./src/Estadisticas.o \
./src/Fila.o \
./src/Jugador.o \
./src/ManagerListaJugadores.o \
./src/Mazo.o \
./src/MenuPrincipal.o \
./src/Opciones.o \
./src/Piso.o \
./src/Portacartas.o \
./src/Splash.o \
./src/Tablero.o \
./src/Tp3.o \
./src/Validador.o \
./src/Visualizador.o \
./src/main.o 

CPP_DEPS += \
./src/AcercaDe.d \
./src/Alumno.d \
./src/Carta.d \
./src/EasyBMP.d \
./src/EnJuego.d \
./src/Estadisticas.d \
./src/Fila.d \
./src/Jugador.d \
./src/ManagerListaJugadores.d \
./src/Mazo.d \
./src/MenuPrincipal.d \
./src/Opciones.d \
./src/Piso.d \
./src/Portacartas.d \
./src/Splash.d \
./src/Tablero.d \
./src/Tp3.d \
./src/Validador.d \
./src/Visualizador.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


