#ifndef ESPECIALIDAD_H_
#define ESPECIALIDAD_H_
#include "utn_funciones.h"

#define TAM_E 3

typedef struct{
	int id;
	char especialidad[20];
	int idDiagnostico;
}eEspecialidad;

/// @brief Lista las especialidades ingresadas
///
/// @param listaEspecialidad eEspecialidad*
/// @param tam int
void listarEspecialidades(eEspecialidad* ,int );
/// @brief Busca la posicion del id buscado por parametro
///
/// @paramlistaEspecialidad eEspecialidad*
/// @param tam int
/// @param idEspecialidad int
/// @return retorno la posicion buscada
int buscarIdEspecialidad(eEspecialidad* ,int ,int);


#endif /* ESPECIALIDAD_H_ */

