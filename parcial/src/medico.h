#ifndef MEDICO_H_
#define MEDICO_H_
#include "utn_funciones.h"
#include "especialidad.h"

#define TAM_M 5

typedef struct{
	int id;
	char nombreMedico[50];
	int idEspecialdiad;
} eMedico;

/// @brief Lista los medicos ingresados
///
/// @param lista eMedico*
/// @param tamM int
/// @param listaEspecialidad eEspecialidad*
/// @param tamE int
void listarMedicos(eMedico* lista, int tamM, eEspecialidad* listaEspecialidad,int tamE);
/// @brief Busca la posicion del id buscado por parametro
///
/// @param lista
/// @param tamM
/// @param idMedico
/// @return retorno la posicion del medico en la lista
int idMedico(eMedico* lista, int tamM, int idMedico);

#endif /* MEDICO_H_ */
