#include "especialidad.h"


void listarEspecialidades(eEspecialidad* listaEspecialidades, int tamE){

	if(listaEspecialidades != NULL && tamE > 0){
		puts("----ID----ESPECIALIDAD-------");
		for(int i=0;i<tamE;i++){
			printf("ID: %3d\tEspecialidad: %5s",listaEspecialidades[i].id,listaEspecialidades[i].especialidad);
		}
	}

}

int buscarIdEspecialidad(eEspecialidad* listaEspecialidades,int tamE,int idEspecialidad){
	int retorno;
	retorno = -1;

	if(listaEspecialidades != NULL && tamE > 0){
		for(int i=0;i<tamE;i++){
			if(idEspecialidad >= 0 && (listaEspecialidades[i].id == idEspecialidad)){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

