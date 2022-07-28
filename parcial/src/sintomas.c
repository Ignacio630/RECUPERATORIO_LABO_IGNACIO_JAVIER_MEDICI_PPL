#include "sintomas.h"

void listarSintomas(eSintomas* listaSintomas, int tamS){

	if(listaSintomas != NULL && tamS > 0){
		for(int i=0;i<tamS;i++){
			printf("ID: %3d Sintomas: %5s Duracion: %d dias\n",listaSintomas[i].id,listaSintomas[i].sintomas,listaSintomas[i].duracion);

		}
	}
}

int buscarSintomaPorId(eSintomas* listaSintomas, int tamS, int idSintoma){
	int retorno;

	if(listaSintomas != NULL && tamS > 0){
		for(int i=0;i<tamS;i++){
			if(listaSintomas[i].id == idSintoma){
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}
