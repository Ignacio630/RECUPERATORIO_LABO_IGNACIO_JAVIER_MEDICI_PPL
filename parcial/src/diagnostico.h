#ifndef DIAGNOSTICO_H_
#define DIAGNOSTICO_H_
#include "utn_funciones.h"


#define TAM_D 4

typedef struct{
	int idDiag;
	char diagnositco[20];
	int sintomaUno;
	int sintomaDos;
	int sintomaTres;
} eDiagnostico;

/// @brief lista los diagnosticos ingresados
///
/// @param listaDiagnosticos eDiagnostico*
/// @param tamD int
void listarDiagnostico(eDiagnostico* listaDiagnosticos,int tamD);

/// @brief Busca la posicion del id buscado por parametro
///
/// @param listaDiagnosticos eDiagnostico*
/// @param tam int
/// @param idDiagnostico int
/// @return retorno la posicion del sintoma en la lista
int buscarIdDiagnostico(eDiagnostico* listaDiagnosticos,int tam,int idDiagnostico);


#endif /* DIAGNOSTICO_H_ */
