#include "medicamento.h"

/// @brief Lista los medicamentos ingresados
///
/// @param listaMedicamento eMedicamento*
/// @param tamMe int
void listarMedicamento(eMedicamento* listaMedicamento, int tamMe){

	if(listaMedicamento != NULL && tamMe > 0){
		for(int i=0;i<tamMe;i++){
			printf("ID: %3d Medicamento: %5s Cada %d hs\n",listaMedicamento[i].id,listaMedicamento[i].medicamento,listaMedicamento[i].tiempoDeUso);
		}
	}
}

int buscarMedicamentoPorId(eMedicamento* listaMedicamento, int tamMe, int idMedicamento){
	int retorno;

	if(listaMedicamento != NULL && tamMe > 0){
		for(int i=0;i<tamMe;i++){
			if(listaMedicamento[i].id == idMedicamento){
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}
