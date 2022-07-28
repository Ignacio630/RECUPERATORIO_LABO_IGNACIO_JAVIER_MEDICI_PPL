#ifndef MEDICAMENTO_H_
#define MEDICAMENTO_H_
#include "utn_funciones.h"


#define TAM_ME 3
typedef struct{
	int id;
	char medicamento[20];
	int tiempoDeUso;
} eMedicamento;

/// @brief Lista los medicamentos ingresados
///
/// @param listaMedicamento eMedicamento*
/// @param tamMe int
void listarMedicamento(eMedicamento* listaMedicamento, int tamMe);

/// @brief Busca la posicion del id buscado por parametro
///
/// @param listaMedicamento eMedicamento*
/// @param tamMe int
/// @param idMedicamento int
/// @return retorno la posicion del sintoma en la lista
int buscarMedicamentoPorId(eMedicamento* listaMedicamento, int tamMe, int idMedicamento);


#endif /* MEDICAMENTO_H_ */
