#include "utn_funciones.h"
#include "consulta.h"

#define TAM 10

int main(void) {
	setbuf(stdout,NULL);

	//Inicializacion de variables, funciones, estructuras y hardcodeo;

	//Variables
	int opcionesMenu;
	int opcionesInforme;
	int contadorAlta = 0;
	int banderaAlta = 0;
	//Estructuras
	eConsulta listaConsultas[TAM];
	//Funciones
	initArrayStatus(listaConsultas,TAM);

	//Hardcodeo
	eConsulta listaForzada[TAM] = {{5,"Carlos",{12,4,2020},0,1,OCUPADO},
									 {6,"Wanda",{1,1,2019},1,3,OCUPADO},
									 {7,"Pedro",{23,5,2021},2,2,OCUPADO},
									 {8,"Manu",{19,3,2022},4,2,OCUPADO},
									 {9,"Luciano",{30,5,2021},2,1,OCUPADO}};

	eMedico ListaMedicos[TAM_M] ={{0,"JUAN",0},{1,"MARCOS", 2},{2,"PEDRO", 1},{3,"MARTIN",2},{4,"LOPEZ",0}};
	eEspecialidad listaEspecialidades[TAM_E] = {{0,"Clinico"},{1,"Oftalmologo"},{2,"Cardiologo"}};
	eDiagnostico ListaDiagnosticos[TAM_D] = {{0,"Sin Diagnostico",0,0,0},{1,"Gripe-A",1,2,3},{2,"Covid-19",4,1,2},{3,"Pre-infarto",7,6,8}};
	eMedicamento listaMedicamentos[TAM_ME] = {{0,"Aspirina",5},{1,"Paracetamol",4},{2,"Ibuprofeno 600",6}};
	eSintomas listaSintomas[TAM_S] ={{0,"Sin sintoams",0},{1,"Fiebre",5},{2,"Tos",14},{3,"Malestar general",7},{4,"Pedida de gusto o olfato",14},{5,"Cansancio",14},{6,"Sudor Frio",15},{7,"Dolor toracico",15},{8,"Vomito",15}};
	//Menu
	do{
		puts("*************Menu*************");
		puts("1-ALTA CONSULTA");
		puts("2-MODIFICAR CONSULTA");
		puts("3-CANCELAR CONSULTA");
		puts("4-DIAGNOSTICAR CONSULTA");
		puts("5-LISTAR");
		puts("6-ALTA FORZADA");
		puts("7-Salir");

		opcionesMenu = PedirOpciones("Ingrese una opcion: ", "Ups! Opcion invalida!!\n");
		switch (opcionesMenu) {
			//ALTA DE LA CONSULTA
			case 1:
				if(consulta_Alta(listaConsultas, TAM, ListaMedicos, TAM_M, listaEspecialidades, TAM_E) == 0){
					contadorAlta++;
					puts("Dada de alta con exito!!");
					ordenarConsultasPorId(listaConsultas, TAM);
				}
				else{
					puts("No hay mas espacio!");
				}
				break;
			case 2:
				if(contadorAlta > 0){
					listarConsultasConMedico(listaConsultas, TAM, ListaMedicos, TAM_M);
					if(modificarConsultas(listaConsultas, TAM, ListaMedicos, TAM_M, listaEspecialidades, TAM_E, ListaDiagnosticos, TAM_D,listaSintomas,TAM_S,listaConsultas->idConsulta) == -1){
						puts("El ID ingresado no es valido");
					}
				}else{
					puts("Tiene que hacer un alta para poder modificar una consulta!");
				}
				break;
			case 3:
				if(contadorAlta > 0){
					listarConsultas(listaConsultas, TAM);
					if(darDeBajaConsulta(listaConsultas, TAM,ListaMedicos,TAM_M,listaEspecialidades,TAM_E,ListaDiagnosticos,TAM_D,listaSintomas,TAM_S,listaConsultas->idConsulta) == 0){
						puts("Consulta Cancelada con exito!");
						contadorAlta--;
					}else{
						puts("No hay mas consultas para dar de baja");
					}
				}else{
					puts("Tiene que hacer un alta para poder cancelar una consulta!");
				}
				break;
			case 4:
				if(contadorAlta > 0){
					listarConsultas(listaConsultas, TAM);
					if(cargarDiagnostico(listaConsultas, TAM, ListaDiagnosticos, TAM_D,ListaMedicos,TAM_M,listaConsultas->idConsulta) == 0){
						puts("Consulta diagnosticada con exito!");
					}
				}else{
					puts("Tiene que hacer un alta para poder diagnosticar!");
				}
				break;
			case 5:
				if(contadorAlta == 0){
					puts("Tiene que hacer un alta para poder listar!");
				}
				else{
					do{
					puts("1. Todos los médicos.");
					puts("2. Todas las consultas.");
					puts("3. Todos los médicos con consultas diagnosticadas.");
					puts("4. Listado de consultas ordenadas por fecha, desde la más reciente hasta la más antigua.");
					puts("5. Listado de consultas que ya fueron diagnosticadas.");
					puts("6. Listado de las consultas diagnosticadas con covid-19 desde el inicio de la pandemia hasta la actualidad. Pero solo de una especialidad ingresada (Tener en cuenta que varios médicos pueden tener la misma especialidad).");
					puts("7. Listado de consultas ordenadas por especialidad alfabéticamente");
					puts("8. Listado de todas las consultas entre el mes de abril y julio para una especialidad determinada.");
					puts("9. Porcentaje de consultas diagnosticadas que atiende cada médico en función del total de diagnósticos.");
					puts("10. La enfermedad menos diagnosticada.");
					puts("11. La especialidad más estudiada por los médicos.");
					puts("12. Listado de medicamentos necesarios segun sintomas del paciente");
					puts("13. Los sintomas mas comunes");
					puts("14. Salir");

					opcionesInforme = PedirOpciones("Ingrese una opcion: ", "Ups! Opcion incorrecta!!");

					switch (opcionesInforme) {
						case 1:
							listarMedicos(ListaMedicos, TAM_M, listaEspecialidades, TAM_E);
							break;
						case 2:
							consulta_MostrarTodas(listaConsultas, TAM, ListaMedicos, TAM_M, listaEspecialidades, TAM_E, ListaDiagnosticos, TAM_D,listaSintomas,TAM_S);
							break;
						case 3:
							if(listarMedicoConConsultaDiagnosticadas(listaConsultas,TAM,ListaMedicos,TAM_M,ListaDiagnosticos,TAM_D,listaEspecialidades, TAM_E) == -1){
								puts("Error, no hay medico con consulta diagnosticada");
							}
							break;
						case 4:
							listarConsultaFechaMasReciente(listaConsultas, TAM);
							break;
						case 5:
							listarConsultasDiagnosticadas(listaConsultas, TAM, ListaDiagnosticos, TAM_D);
							break;
						case 6:
							listarDiagnosticoCovid19(listaConsultas,TAM,ListaDiagnosticos,TAM_D);
							break;
						case 7:
							listarConsultasEspecialidadAlfa(listaConsultas, TAM,ListaMedicos ,TAM_M,listaEspecialidades, TAM_E);
							break;
						case 8:
							listarConsultasEspecialidadDeterminada(listaConsultas,TAM,ListaMedicos,TAM_M,ListaDiagnosticos,TAM_D,listaEspecialidades,TAM_E);
							break;
						case 9:
							porcentajeConsultasDiagnosticadas(listaConsultas, TAM, ListaMedicos, TAM_M, ListaDiagnosticos, TAM_D);
							break;
						case 10:
							enfermedadMenosDiagnosticada(listaConsultas,TAM,ListaDiagnosticos,TAM_D);
							break;
						case 11:
							especialidadMasEstudiada(ListaMedicos, TAM_M, listaEspecialidades, TAM_E);
							break;
						case 12:
							puts("12. Listado de medicamentos necesarios segun sintomas del paciente");
							break;
						case 13:
							SintomasMasComunes(listaSintomas, TAM);
							break;
						case 14:
							puts("Saliendo!!");
							break;
						default:
							puts("Ups! Opcion invalida!!");
							break;
						}
					}while(opcionesInforme != 14);
				}
				break;
			//SALIDA DEL PROGRAMA
			case 6:
				if(banderaAlta == 0)
				{
					AltaForzada(listaConsultas, listaForzada, TAM);
					puts("Carga forzada realizada con exito");
					contadorAlta += TAM;
					banderaAlta=1;
				}
				else
				{
					puts("Ya se dio el alta!");
				}
				break;
			case 7:
				puts("Saliendo...!!");
				break;
			//OPCION INVALIDA
			default:
				puts("Ups! Opcion invalida!!");
				break;
		}
	}while(opcionesMenu != 7);
	system("cls");

	return EXIT_SUCCESS;
}
