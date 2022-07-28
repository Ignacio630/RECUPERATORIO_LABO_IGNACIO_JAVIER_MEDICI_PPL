#include "diagnostico.h"

void listarDiagnostico(eDiagnostico* listaDiagnostico, int tamD){
	if(listaDiagnostico != NULL && tamD > 0){
		for(int i=1;i<tamD;i++){
			printf("ID:%3d-Diagnostico:%5s\n",listaDiagnostico[i].idDiag,listaDiagnostico[i].diagnositco);
		}
	}
}

int buscarIdDiagnostico(eDiagnostico* listaDiagnosticos,int tam,int idDiagnostico){
	int retorno;
	retorno = -1;

	if(listaDiagnosticos != NULL && tam > 0 && idDiagnostico >= 0){
		for(int i=0;i<tam;i++){
			if(listaDiagnosticos[i].idDiag == idDiagnostico){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
