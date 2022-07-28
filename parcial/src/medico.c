#include "medico.h"

void listarMedicos(eMedico* lista, int tamM, eEspecialidad* listaEspecialidad,int tamE){
	int indice;
	if(lista != NULL && tamM > 0 && listaEspecialidad != NULL && tamE > 0){
		for(int i=0;i<tamM;i++){
			indice = buscarIdEspecialidad(listaEspecialidad, tamE, lista[i].idEspecialdiad);
			printf("ID:%3d Nombre: %5s Especialidad: %5s\n",lista[i].id,lista[i].nombreMedico,listaEspecialidad[indice].especialidad);
		}
	}
}

int idMedico(eMedico* listaMedico, int tamM, int idMedico){
	int retorno;
	retorno = -1;

	if(listaMedico != NULL && tamM > 0){
		for(int i=0;i<tamM;i++){
			if(idMedico >= 0 && (listaMedico[i].id == idMedico)){
				retorno = i;
				break;
			}
		}
	}


	return retorno;
}

