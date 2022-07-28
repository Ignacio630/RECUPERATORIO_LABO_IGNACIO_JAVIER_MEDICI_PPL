#include "consulta.h"

static int incrementalId();
static int incrementalId(){
	static int id = 0;
	return id++;
}
int initArrayStatus(eConsulta* listaConsultas, int tam){
	int retorno;
	retorno = -1;

	if(listaConsultas != NULL && tam >= 0){
		for(int i=0;i<tam;i++){
			listaConsultas[i].estado = LIBRE;
			retorno = 0;
		}
	}

	return retorno;
}

int isEmptyArray(eConsulta* listaConsultas, int tam){
	int retorno;
	retorno = -1;

	if(listaConsultas != NULL && tam >= 0){
		for(int i=0;i<tam;i++){
			if(listaConsultas[i].estado == LIBRE){
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

int BuscarConsultaPorId(eConsulta* listaConsulta, int tam, int id){
	int retorno;
	retorno = -1;

	if(listaConsulta != NULL && tam > 0){
		for(int i=0;i<tam;i++){
			if(listaConsulta[i].idConsulta == id){
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

eConsulta cargarConsulta(){
	eConsulta auxConsulta;
	PedirCadena(auxConsulta.nombrePaciente, "Ingrese el nombre del paciente: ");
	//Fechas
	utn_GetEntero(&auxConsulta.fecha.dia, "Ingrese la dia de la consulta :", "Error, dia invalida\n", 1, 31, 99);
	utn_GetEntero(&auxConsulta.fecha.mes, "Ingrese la mes de la consulta :", "Error, mes invalida\n", 0, 12, 99);
	utn_GetEntero(&auxConsulta.fecha.anio, "Ingrese la año de la consulta :", "Error, año invalida\n", 0, 1000000, 99);
	//ID Medico
	utn_GetEntero(&auxConsulta.idMedico, "Ingrese el ID del medico: ", "Error, El id ingresado es invalido\n", 0, 4, 99);
	//Diagnosticos
	auxConsulta.idDiagnostico = 0;
	return auxConsulta;
}

int consulta_Alta(eConsulta* listaConsulta, int tam, eMedico* listaMedico, int tamM, eEspecialidad* listaEspecialidades, int tamE){
	int retorno;
	int bufferLibre;
	eConsulta auxConsulta;

	retorno = -1;
	bufferLibre = isEmptyArray(listaConsulta, tam);

	if(listaConsulta != NULL && listaMedico != NULL && listaEspecialidades != NULL && tam > 0 && tamM > 0 && tamE > 0){
		if(bufferLibre != -1){
			auxConsulta = cargarConsulta();

			auxConsulta.idConsulta = incrementalId();

			auxConsulta.estado = OCUPADO;

			listaConsulta[bufferLibre] = auxConsulta;

		}
			retorno = 0;
	}

	return retorno;
}

void listarConsultas(eConsulta* listaConsulta, int tam){
	if(listaConsulta != NULL && tam > 0){
		for(int i=0;i<tam;i++){
			if(listaConsulta[i].estado == OCUPADO){
				printf("ID: %d Nombre: %s Fecha %d/%d/%d\n", listaConsulta[i].idConsulta,listaConsulta[i].nombrePaciente,listaConsulta[i].fecha.dia,listaConsulta[i].fecha.mes,listaConsulta[i].fecha.anio);
			}
		}
	}
}
void listarConsultasConMedico(eConsulta* listaConsulta, int tam, eMedico* listaMedico, int tamM){
	int idM;
	if(listaConsulta != NULL && tam > 0){
		for(int i=0;i<tam;i++){
			idM = idMedico(listaMedico, tamM, listaConsulta[i].idMedico);
			if(listaConsulta[i].estado == OCUPADO){
				printf("ID: %d Nombre: %s Fecha %d/%d/%d Nombre Medico : %s\n", listaConsulta[i].idConsulta,listaConsulta[i].nombrePaciente,listaConsulta[i].fecha.dia,listaConsulta[i].fecha.mes,listaConsulta[i].fecha.anio,listaMedico[idM].nombreMedico);
			}
		}
	}
}

void listarConsultasMedicoEspecialidad(eConsulta* listaConsulta,int tam,eMedico* listaMedico,int tamM,eEspecialidad* listaEspecialidades,int tamE){
	int idM;
	int idE;
	if(listaConsulta != NULL && tam > 0){
		for(int i=0;i<tam;i++){
			idM = idMedico(listaMedico, tamM, listaConsulta[i].idMedico);
			idE = buscarIdEspecialidad(listaEspecialidades, tamE, listaMedico[idM].idEspecialdiad);
			if(listaConsulta[i].estado == OCUPADO){
				printf("ID: %d Nombre: %s Fecha %d/%d/%d Nombre Medico : %s Especialidad: %s\n", listaConsulta[i].idConsulta,listaConsulta[i].nombrePaciente,listaConsulta[i].fecha.dia,listaConsulta[i].fecha.mes,listaConsulta[i].fecha.anio,listaMedico[idM].nombreMedico,listaEspecialidades[idE].especialidad);
			}
		}
	}
}
void consulta_MostrarUna(eConsulta unaConsulta, eEspecialidad unaEspecialidad, eMedico unMedico,eDiagnostico unDiagnostico, eSintomas sintomas){
	printf("%d-%s-%d/%d/%d-%d-%s-%s-%s-%s\n",unaConsulta.idConsulta,
									   unaConsulta.nombrePaciente,
									   unaConsulta.fecha.dia,
									   unaConsulta.fecha.mes,
									   unaConsulta.fecha.anio,
									   unMedico.id,
									   unMedico.nombreMedico,
									   unaEspecialidad.especialidad,
									   unDiagnostico.diagnositco,
									   sintomas.sintomas);
}

int consulta_MostrarTodas(eConsulta* listaConsultas, int tam, eMedico* listaMedicos, int tamM,eEspecialidad* listaEspecialidades,int tamE,eDiagnostico* listaDiagnosticos, int tamD,eSintomas* listaSintomas, int tamS){
	int retorno;
	int bufferId;
	int bufferEspecialidad;
	int bufferDiagnostico;
	retorno = -1;

	if(listaConsultas != NULL && listaMedicos != NULL && listaEspecialidades != NULL && listaDiagnosticos != NULL && tam > 0 && tamM > 0 && tamE > 0 && tamD > 0){
		for(int i=0;i<tam;i++){
			bufferId = idMedico(listaMedicos, tamM, listaConsultas[i].idMedico);
			bufferEspecialidad = buscarIdEspecialidad(listaEspecialidades, tamE, listaMedicos[bufferId].idEspecialdiad);
			bufferDiagnostico = buscarIdDiagnostico(listaDiagnosticos, tamD,listaConsultas[i].idDiagnostico);
			if(listaConsultas[i].estado == OCUPADO ){
				consulta_MostrarUna(listaConsultas[i], listaEspecialidades[bufferEspecialidad], listaMedicos[bufferId],listaDiagnosticos[bufferDiagnostico],listaSintomas[bufferDiagnostico]);
			}
		}
	}

	return retorno;
}

eConsulta modificar_Consulta(eConsulta unaConsulta){
	eConsulta auxConsulta;
	int opciones;

	puts("1-Cambiar nombre paciente");
	puts("2-Cambiar fecha consulta");
	puts("3-Cambiar medico");
	puts("4-Salir");
	utn_GetEntero(&opciones, "Ingresar la opcion que quiere modificar: ", "Ups! Opcion invalida!!\n", 0, 4, 99);
	switch (opciones) {
		case 1:
			//Nombre
			PedirCadena(unaConsulta.nombrePaciente, "Ingrese el nombre del paciente: ");
			break;
		case 2:
				//Fechas
			utn_GetEntero(&unaConsulta.fecha.dia, "Ingrese la dia de la consulta :", "Error, dia invalida\n", 1, 31, 99);
			utn_GetEntero(&unaConsulta.fecha.mes, "Ingrese la mes de la consulta :", "Error, mes invalida\n", 0, 12, 99);
			utn_GetEntero(&unaConsulta.fecha.anio, "Ingrese la año de la consulta :", "Error, año invalida\n", 0, 1000000, 99);
			break;
		case 3:
			//ID Medico
			utn_GetEntero(&unaConsulta.idMedico, "Ingrese el ID del medico: ", "Error, El id ingresado es invalido\n", 0, 4, 99);
			break;
		case 4:
			puts("Saliendo...");
			break;
		default:
			puts("Ups! Opcion invalida!!");
			break;
	}
	auxConsulta = unaConsulta;

	return auxConsulta;
}

int modificarConsultas(eConsulta* listaConsultas,int tam,eMedico* listaMedicos,int tamM,eEspecialidad* listaEspecialidades,int tamE,eDiagnostico* listaDiagnosticos,int tamD,eSintomas* listaSintomas,int tamS,int idConsulta){
	int retorno;
	eConsulta auxConsulta;
	retorno = -1;

	utn_GetEntero(&idConsulta,"Ingresar el ID de la consulta que desea modificar: ","El ID ingresado no es valido\n",0,10,99);
	if(listaConsultas != NULL && tam > 0){
		for(int i=0;i<tam;i++){
			if(idConsulta == listaConsultas[i].idConsulta && listaConsultas[i].estado == OCUPADO){
				auxConsulta = modificar_Consulta(listaConsultas[i]);
				listaConsultas[i] = auxConsulta;
				retorno = 0;
			}
		}
	}

	return retorno;
}

int darDeBajaConsulta(eConsulta* listaConsultas,int tam,eMedico* listaMedicos,int tamM,eEspecialidad* listaEspecialidades,int tamE,eDiagnostico* listaDiagnosticos,int tamD,eSintomas* listaSintomas,int tamS, int idConsulta){
	int retorno;
	retorno = -1;

	utn_GetEntero(&idConsulta,"Ingresar el ID de la consulta que desea cancelar: ","El ID ingresado no es valido\n",0,10,99);
	if(listaConsultas != NULL && tam > 0){
		for(int i=0;i<tam;i++){
			if(idConsulta == listaConsultas[i].idConsulta && listaConsultas[i].estado == OCUPADO){
				listaConsultas[i].estado = LIBRE;
				retorno = 0;
			}
		}
	}

	return retorno;
}

int cargarDiagnostico(eConsulta* listaConsultas, int tam, eDiagnostico* listaDiagnostico,int tamD,eMedico* listaMedicos, int tamM, int idConsulta){
	int retorno;
	int indice;

	retorno = -1;

	utn_GetEntero(&idConsulta,"Ingresar el ID de la consulta que desea diagnosticar: ","El ID ingresado no es valido\n",0,100,99);
	if(listaConsultas != NULL && tam > 0){
		for(int i=0;i<tam;i++){
			if(listaConsultas[i].idDiagnostico == 0){
				indice = BuscarConsultaPorId(listaConsultas, tam, idConsulta);
				if(listaConsultas[i].estado == OCUPADO && listaConsultas[indice].idConsulta == idConsulta){
					listarDiagnostico(listaDiagnostico, tamD);
					utn_GetEntero(&listaConsultas[indice].idDiagnostico, "Ingrese el diagnostico: ", "Error, diagnostico invalida\n", 1, 3, 99);
					retorno = 0;
					break;
				}
				else{
					puts("No hay consultas para diagnosticar");
				}
			}
		}
	}
	return retorno;
}

int ordenarConsultasPorId(eConsulta* listaConsultas, int tam){
	int retorno;
	eConsulta auxConsulta;
	retorno = -1;

	if(listaConsultas != NULL && tam > 0){
		for(int i=0;i<tam-1;i++){
			for(int j=i+1;j<tam;j++){
				if(listaConsultas[i].idConsulta > listaConsultas[j].idConsulta){
					auxConsulta = listaConsultas[i];
					listaConsultas[i] = listaConsultas[j];
					listaConsultas[j] = auxConsulta;
				}
			}
		}
		retorno = 0;
	}

	return retorno;
}

int listarMedicoConConsultaDiagnosticadas(eConsulta* listaConsulta, int tam,eMedico* listaMedicos,int tamM,eDiagnostico*listaDiagnostico,int tamD,eEspecialidad* listaEspecialidad, int tamE){
	int retorno;
	int auxIdM;
	int auxIdE;

	retorno = -1;
	if(listaMedicos != NULL && listaDiagnostico != NULL && listaEspecialidad!= NULL && tamM > 0 && tamD > 0&& tamE > 0){
		for(int i=0;i<tamM;i++){
			auxIdM = idMedico(listaMedicos, tamM, listaConsulta[i].idMedico);
			auxIdE = buscarIdEspecialidad(listaEspecialidad, tamE, listaMedicos[auxIdM].idEspecialdiad);
			if(listaConsulta[i].idDiagnostico != 0 && listaMedicos[auxIdM].id == listaConsulta[i].idMedico){
				printf("%d-%s-%s\n",listaMedicos[auxIdM].id,listaMedicos[auxIdM].nombreMedico,listaEspecialidad[auxIdE].especialidad);
				retorno = 0;
			}
		}
	}

	return retorno;
}

int listarConsultaFechaMasReciente(eConsulta* listaConsultas, int tam){
	int retorno;
	eConsulta auxConsulta;
	retorno = -1;

	if(listaConsultas != NULL && tam > 0){
		for(int i=0;i<tam-1;i++){
			for(int j=i+1;j<tam;j++){
				if(listaConsultas[i].fecha.anio < listaConsultas[j].fecha.anio ||
			      (listaConsultas[i].fecha.anio == listaConsultas[j].fecha.anio && listaConsultas[i].fecha.mes < listaConsultas[j].fecha.mes) ||
				  (listaConsultas[i].fecha.anio == listaConsultas[j].fecha.anio && listaConsultas[i].fecha.mes == listaConsultas[j].fecha.mes && listaConsultas[i].fecha.dia < listaConsultas[j].fecha.dia)){
					auxConsulta = listaConsultas[i];
					listaConsultas[i] = listaConsultas[j];
					listaConsultas[j] = auxConsulta;
				}
			}
		}
		listarConsultas(listaConsultas, tam);
	}


	return retorno;
}

int listarConsultasDiagnosticadas(eConsulta* listaConsulta, int tam,eDiagnostico* listaDiagnosticos, int tamD){
	int retorno;
	int indice;
	retorno = -1;

	if(listaConsulta != NULL && tam > 0 && listaConsulta != NULL && tamD > 0){
		for(int i=0;i<tam;i++){
			indice = buscarIdDiagnostico(listaDiagnosticos, tamD, listaConsulta[i].idDiagnostico);
			if(listaConsulta[i].estado == OCUPADO && listaConsulta[i].idDiagnostico >= 1){
				printf("ID: %d Nombre consulta: %s Diagnostico: %s\n",listaConsulta[i].idConsulta,listaConsulta[i].nombrePaciente,listaDiagnosticos[indice].diagnositco);
				retorno = 0;
			}
		}
	}
	if(retorno == -1){
		puts("No hay consultas con diagnosticos");
	}
	return retorno;
}

int listarDiagnosticoCovid19(eConsulta* listaConsulta, int tam, eDiagnostico* listaDiagnosticos, int tamD){
	int retorno;
	int indice;
	retorno = -1;

	if(listaConsulta != NULL && tam > 0 && listaDiagnosticos != NULL && tamD > 0){
		for(int i=0;i<tam;i++){
			indice = buscarIdDiagnostico(listaDiagnosticos, tam, listaConsulta[i].idDiagnostico);
			if(listaConsulta[i].estado == OCUPADO && listaConsulta[i].idDiagnostico == 2 && (listaConsulta[i].fecha.mes >= 3 && listaConsulta[i].fecha.anio >= 2020)){
				printf("ID: %d Nombre consulta: %s Fecha: %d/%d/%d Diagnostico: %s\n",listaConsulta[i].idConsulta,listaConsulta[i].nombrePaciente,listaConsulta[i].fecha.dia,listaConsulta[i].fecha.mes,listaConsulta[i].fecha.anio,listaDiagnosticos[indice].diagnositco);
				retorno = 0;
			}
		}
	}

	if(retorno == -1){
		puts("No hay diagnosticos de covid-19 antes de la pandemia");
	}
	return retorno;
}

int listarConsultasEspecialidadAlfa(eConsulta* listaConsulta , int tam ,eMedico* listaMedico ,int tamM ,eEspecialidad* listaEspecialidades, int tamE){
	int retorno;
	int indice1;
	int indice2;
	char auxEsp1[20];
	char auxEsp2[20];
	eConsulta auxConsulta;

	retorno = 0;

	if(listaConsulta != NULL && tam > 0){
		for(int	 i=0;i<tam-1;i++){
			for(int j=i+1;j<tam;j++){
				indice1 = buscarIdEspecialidad(listaEspecialidades, tamM, listaEspecialidades[i].id);
				strcpy(auxEsp1,listaEspecialidades[indice1].especialidad);
				indice2 = buscarIdEspecialidad(listaEspecialidades, tamM, listaEspecialidades[j].id);
				strcpy(auxEsp2,listaEspecialidades[indice2].especialidad);
				if(strcmp(auxEsp1,auxEsp2) != 0){
					auxConsulta = listaConsulta[i];
					listaConsulta[i] = listaConsulta[j];
					listaConsulta[j] = auxConsulta;
				}
			}
		}
		retorno = 0;
		listarConsultasMedicoEspecialidad(listaConsulta, tam, listaMedico, tamM,listaEspecialidades, tamE);
	}

	return retorno;
}

int enfermedadMenosDiagnosticada(eConsulta* listaConsultas,int tam,eDiagnostico* listaDiagnosticos, int tamD){
	int retorno;
	int contadorGripe;
	int contadorCovid;
	int contadorInfarto;
	int auxMin;

	contadorGripe = 0;
	contadorCovid = 0;
	contadorInfarto = 0;
	auxMin = 0;
	retorno = -1;

	if(listaConsultas != NULL && tam > 0 && listaDiagnosticos != NULL && tamD > 0){
		for(int i=0;i<tam;i++){
			if((listaConsultas[i].estado == OCUPADO)){
				switch (listaConsultas[i].idDiagnostico) {
					case 1:
						contadorGripe++;
						break;
					case 2:
						contadorCovid++;
						break;
					case 3:
						contadorInfarto++;
						break;
				}
			}
		}
		if(contadorGripe <= contadorCovid && contadorGripe <= contadorInfarto){
			auxMin = contadorGripe;
		}else{
			if(contadorInfarto <= contadorGripe && contadorInfarto <= contadorCovid){
				auxMin = contadorInfarto;
			}else{
				auxMin = contadorCovid;
			}
		}
		if(contadorCovid == contadorGripe && contadorGripe == contadorInfarto){
			puts("Todos tienen la misma cantidad de diagnosticos");
		}
		retorno = 0;
	}
	if(retorno == 0){
		puts("La enfermedad menor diagnostico/s es : ");
		if(auxMin == contadorGripe){
			printf("Gripe-A con: %d diagnostico/s",auxMin);
		}else{
			if(auxMin == contadorCovid){
				printf("Covid-19 con: %d diagnostico/s",auxMin);
			}else{
				printf("Pre-Infarto con: %d diagnostico/s",auxMin);
			}
		}
	}
	else{
		puts("No hay enfermedad menos diagnosticada");
	}

	return retorno;
}

int especialidadMasEstudiada(eMedico* listaMedicos, int tamM, eEspecialidad* listaEspecialidades, int tamE){
	int retorno;
	int contadorClinico;
	int contadorOftalmologo;
	int contadorCardiologo;
	int auxMax;

	contadorCardiologo = 0;
	contadorOftalmologo = 0;
	contadorClinico = 0;
	auxMax = 0;
	retorno = -1;

	if(listaMedicos != NULL && tamM > 0 && listaEspecialidades != NULL && tamE > 0){
		for(int i=0;i<tamM;i++){
			switch(listaMedicos[i].idEspecialdiad){
				case 0:
					contadorClinico++;
					break;
				case 1:
					contadorOftalmologo++;
					break;
				case 2:
					contadorCardiologo++;
					break;
			}
		}
		if(contadorClinico > contadorOftalmologo){
			auxMax = contadorClinico;
		}else{
			if(contadorCardiologo > contadorClinico){
				auxMax = contadorCardiologo;
			}else{
				auxMax = contadorOftalmologo;
			}
		}
		retorno = 0;
	}
	if(auxMax != 0){
		printf("La profesion mas estudiada es : ");
		if(contadorClinico == auxMax){
			printf("Clinico con: %d profesional/es\n",contadorClinico);
		}else{
			if(contadorOftalmologo == auxMax){
				printf("Oftalmologo con: %d profesional/es\n",contadorOftalmologo);
			}else{
				printf("Cadiologo con: %d profesional/es\n",contadorCardiologo);
			}
		}
	}
	else{
		puts("No hay enfermedad menos diagnosticada");
	}
	return retorno;
}

int SintomasMasComunes(eSintomas* listaSintomas, int tam){
	int retorno;
	int contador1;
	int contador2;
	int contador3;
	int contador4;
	int contador5;
	int contador6;
	int contador7;
	int contador8;

	retorno = -1;

	contador1 = 0;
	contador2 = 0;
	contador3 = 0;
	contador4 = 0;
	contador5 = 0;
	contador6 = 0;
	contador7 = 0;
	contador8 = 0;


	if(listaSintomas != NULL && tam > 0){
		for(int i=0;i<tam;i++){
			switch (listaSintomas[i].id) {
				case 1:
					contador1++;
					break;
				case 2:
					contador2++;
					break;
				case 3:
					contador3++;
					break;
				case 4:
					contador4++;
					break;
				case 5:
					contador5++;
					break;
				case 6:
					contador6++;
					break;
				case 7:
					contador7++;
					break;
				case 8:
					contador8++;
					break;
			}
		}
		printf("%d-%d-%d-%d-%d-%d-%d-%d\n",contador1,contador2,contador3,contador4,contador5,contador6,contador7,contador8);
	}


	return retorno;
}

int listarConsultasAbrilJulio(eConsulta* listaConsultas,int tam,eMedico* listaMedicos,int tamM,eDiagnostico* listaDiagnosticos, int tamD, eEspecialidad* listadoEspecialidades, int tamE, int idEspecialidad, int idMedico){
    int retorno;
    retorno =0;

    if(listaConsultas != NULL && tam > 0 && listaMedicos != NULL && tamM > 0 && listaDiagnosticos != NULL && tamD > 0){
    	for(int i=0; i<tam;i++){
			if(listaMedicos[i].idEspecialdiad == idEspecialidad && listaMedicos[i].id == idMedico && (listaConsultas[i].fecha.mes >= 4 && listaConsultas[i].fecha.mes <= 7)){
//				listarConsultasMedicoEspecialidad(listaConsultas, tam, listaMedicos, tamM, listadoEspecialidades, tamE);
				listarConsultasMedicoEspecialidad(listaConsultas, tam, listaMedicos, tamM, listadoEspecialidades, tamE);
				retorno = 0;
				break;
			}
		}
    }

	return retorno;
}

int listarConsultasEspecialidadDeterminada(eConsulta* listaConsultas,int tam,eMedico* listaMedicos,int tamM,eDiagnostico* listaDiagnosticos, int tamD, eEspecialidad* listaEspecialidades, int tamE){
    int retorno;
    retorno =0;

    if(listaConsultas != NULL && tam > 0 && listaMedicos != NULL && tamM > 0 && listaDiagnosticos != NULL && tamD > 0){
    	puts("Lista de consultas por especialidad");

		for(int i=0;i<tamE;i++)
		{
			printf("Consultas de especialidad %s: \n", listaEspecialidades[i].especialidad);
			for(int j=0;j<tamM;j++)
			{
				if(listaEspecialidades[i].id == listaMedicos[j].idEspecialdiad)
				{
					listarConsultasAbrilJulio(listaConsultas, tam, listaMedicos, tamM, listaDiagnosticos, tamD, listaEspecialidades, tamE, listaMedicos[j].idEspecialdiad, listaMedicos[j].id);
					retorno = 0;
					break;
				}
			}
		}
    }

	return retorno;

}


void AltaForzada(eConsulta* listaConsulta, eConsulta* listaForzada, int tam)
{
	int espacioLibre;

	if(listaConsulta != NULL && listaForzada != NULL && tam > 0)
	{
		for(int j=0;j<tam;j++)
		{
			espacioLibre = isEmptyArray(listaConsulta, tam);
			if(espacioLibre != -1)
			{
				listaConsulta[espacioLibre] = listaForzada[j];
			}
		}
	}
}
