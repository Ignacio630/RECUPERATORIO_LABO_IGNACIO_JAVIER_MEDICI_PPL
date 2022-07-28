#ifndef SINTOMAS_H_
#define SINTOMAS_H_

#include "utn_funciones.h"

#define TAM_S 10

typedef struct{
	int id;
	char sintomas[50];
	int duracion;
} eSintomas;

/// @brief lista los sintomas ingresados
///
/// @param listaSintomas eSintomas*
/// @param tamS int
void listarSintomas(eSintomas* listaSintomas, int tamS);

/// @brief Busca la posicion del id buscado por parametro
///
/// @param listaSintomas eSintomas*
/// @param tamM int
/// @param idsintoma int
/// @return retorno la posicion del sintoma en la lista
int buscarSintomaPorId(eSintomas* listaSintomas, int tamS, int idSintoma);

#endif /* SINTOMAS_H_ */
