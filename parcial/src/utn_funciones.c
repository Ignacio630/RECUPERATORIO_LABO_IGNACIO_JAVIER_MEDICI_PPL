#include "utn_funciones.h"

//static declaration
static int GetInt(int*);
static int GetFloat(float* );
static int esCaracter(char*);
static int esNumerica(char*);
static int esFlotante(char*);
static int esNumericaAndCadena(char* );

//Declarated funcions
static int esCaracter(char* cadena){
	int retorno = -1;

	if(cadena != NULL){
		for(int i=0;i != '\0';i++){
			if(cadena[i] != ' ' && (cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'Z' || cadena[i] > 'Z')){
				retorno = 0;
			}
		}
	}

	return retorno;
}
static int esNumerica(char* cadena)
{
	int retorno = -1;
	int i;
	int len;
	len=strlen(cadena);
	if(cadena != NULL && len > 0)
	{
		retorno = 1;
		for(i=0;i<len && cadena[i] != '\0' ;i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i == '-']))
			{
				continue;
			}
			if(cadena[i] > '9' || cadena[i] < '0')
			{
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}
static int GetInt(int* pResultado)
{
	int retorno = -1;
	char bufferString[50];
	if(pResultado != NULL && myGets(bufferString, sizeof(bufferString))== 0 && esNumerica(bufferString))
	{
		retorno = 0;
		*pResultado = atoi(bufferString);
	}
	return retorno;
}

static int esFlotante(char* numero)
{
	int retorno = -1;
	int i;
	int len;
	int punto=0;
	len=strlen(numero);
	if(numero != NULL && len > 0)
	{
		retorno = 1;
		for(i=0;i<len && numero[i] != '\0' ;i++)
		{
			if(i !=0 && (numero[i] == '+' || numero[i] == '-') )
			{
				punto = 1;
				continue;
			}
			if(numero[i] > '9' || numero[i]  < '0')
			{
				if(numero[i] == '.' && punto == 0)
				{
					punto = 1;
					continue;
				}
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
static int esNumericaAndCadena(char* numero){
	int retorno = -1;
	int len;
	int flagChar;
	int flagInt;
	flagInt = 0;
	flagInt = 0;
	len=strlen(numero);
	if(numero != NULL && len > 0)
	{
		retorno = 1;
		for(int i=0;i<len && numero[i] != '\0' ;i++)
		{
			if(!isdigit(numero[i]))
			{
				flagInt = 1;
			}
			if(!isalpha(numero[i]))
			{
				flagChar = 1;
			}

			if(flagChar == 1 && flagInt == 0)
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
static int GetFloat(float* pResultado)
{
	int retorno = -1;
	char bufferFloat[50];
	if(pResultado != NULL && myGets(bufferFloat, sizeof(bufferFloat))== 0 && esFlotante(bufferFloat))
	{
		retorno = 0;
		*pResultado = atof(bufferFloat);
	}
	return retorno;
}
int myGets(char* cadena, int len)
{
	int retorno = -1;
	char bufferString[4096];

	if(cadena != NULL && len > 0)
	{
		fflush(stdin);
		if(fgets(bufferString, sizeof(bufferString), stdin)!= NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= len)
			{
				strncpy(cadena, bufferString, len);
				retorno = 0;
			}
		}
	}

	return retorno;
}

int ValidarCadena(char* cadena)
{
	int retorno=1;
	int len;
	if(cadena!=NULL)
	{
		len=strlen(cadena);
		for(int i=0;i<len;i++)
		{
			if(!isalpha(cadena[i]))
			{
				retorno=0;
			}
		}
	}
	return retorno;
}

int ValidarCadenaConNumero(char* cadena)
{
	int retorno=1;
	int len;
	if(cadena!=NULL)
	{
		len=strlen(cadena);
		for(int i=0;i<len;i++)
		{
			if(!esNumericaAndCadena(cadena))
			{
				retorno=0;
			}
		}
	}
	return retorno;
}
int utn_GetEntero(int* pResultado, char* mensaje, char* MensajeError, int minimo, int maximo, int reintentos)
{
	int retorno;
	retorno = -1;
	int bufferInt;
	do{
		printf("%s", mensaje);
		if(GetInt(&bufferInt)== 0 && bufferInt >= minimo && bufferInt <= maximo )
		{
			retorno = 0;
			*pResultado = bufferInt;
			break;
		}

		printf("%s", MensajeError);
		reintentos++;
	}while(reintentos >= 0);

	return retorno;
}
int utn_GetCadena(char* pResultado,int len ,char* mensaje, char* MensajeError, int reintentos){
	int retorno = -1;
	char bufferChar[len];
	if(pResultado != NULL && len> 0 && mensaje != NULL && MensajeError != NULL && reintentos >= 0){
		do{
			printf("%s", mensaje);

			if(myGets(bufferChar, len) == 0 && esCaracter(bufferChar) == 0)
			{
				strcpy(pResultado,bufferChar);
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", MensajeError);
				reintentos++;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

float utn_GetFlotante(float* pResultado, char* mensaje, char* MensajeError, int minimo, int maximo, int reintentos)
{
	int retorno;
	retorno = -1;
	float bufferFloat;
	do{
		printf("%s", mensaje);
		if(GetFloat(&bufferFloat)== 0 && bufferFloat >= minimo && bufferFloat <= maximo )
		{
			retorno = 0;
			*pResultado = bufferFloat;
			break;
		}
		printf("%s", MensajeError);
		reintentos++;
	}while(reintentos >= 0);

	return retorno;
}
int PedirCaracter(char caracter, char* mensaje, char* mensajeError){
	int retorno = -1;

	printf("%s",mensaje);
	fflush(stdin);
	scanf("%c",&caracter);
	if(isalpha(caracter) == 0){
		retorno = 0;
	}
	else{
		printf("%s", mensajeError);
		fflush(stdin);
		scanf("%c",&caracter);
	}

	return retorno;
}
int PedirCadena(char* cadena, char* mensaje)
{
	int retorno;

	retorno = 0;
	printf("%s",mensaje);
	scanf("%s",cadena);
	while(!ValidarCadena(cadena))
	{
		retorno = -1;
		printf("Ups! a ocurrido un error!\n");
		printf("%s",mensaje);
		scanf("%s",cadena);
	}
	return retorno;
}
void PedirCadenaConNumero(char* cadena,char* mensaje)
{
	printf("%s",mensaje);
	fflush(stdin);
	scanf("%s",cadena);
	while(!ValidarCadenaConNumero(cadena))
	{
		printf("Ups! a ocurrido un error!\n");
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%s",cadena);
	}
}
int PedirEntero(char* numero, char* mensaje, char* mensajeError)
{
	int retorno;
	puts(mensaje);
	scanf("%s",numero);
	while(!esNumerica(numero))
	{
		printf("%s",mensajeError);
		printf("%s", mensaje);
		scanf("%s",numero);
	}
	retorno=atoi(numero);
	return retorno;
}
int PedirOpciones(char* mensaje, char* mensajeError)
{
	int retorno;
	char opciones[1000];
	printf("%s",mensaje);
	scanf("%s",opciones);
	while(!esNumerica(opciones))
	{
		printf("%s",mensajeError);
		printf("%s", mensaje);
		scanf("%s",opciones);
	}
	retorno=atoi(opciones);
	return retorno;
}
float PedirFlotante(char* numero, char* mensaje, char* mensajeError)
{
	int retorno;
	printf("%s",mensaje);
	scanf("%s",numero);
	while(!esFlotante(numero))
	{
		printf("%s",mensajeError);
		printf("%s",mensaje);
		scanf("%s",numero);
	}
	retorno= atof(numero);
	return retorno;
}
void MostrarCadena(char cadena[])
{
	printf("%s", cadena);
}
int ValidarFloatMinimo(float numero, int minimo, char mensaje[])
{
	int retorno;

	if(numero > minimo)
	{
		retorno=0;
	}
	else
	{
		*mensaje = ValidarCadena(mensaje);
	}


	return retorno;
}
int ValidarNumeroMinimoMaximo(int numero, int maximo, int minimo, char mensaje[])
{
	int retorno;
	if(numero <= maximo && numero >= minimo)
	{
		retorno = 0;
	}
	else
	{
		retorno = -1;
		printf("%s", mensaje);
	}

	return retorno;
}
int ValidarParidad(int numeroIngresado)
{
	int resultado;

	resultado = -1;

	if(numeroIngresado % 2 == 0)
	{
		printf("Es par\n");
	}
	else
	{
		printf("Es impar\n");
	}

	return resultado;
}
int ValidarEntero(int* entero)
{
	int retorno = -1;
	int i;

	if(entero != NULL && sizeof(entero) > 0)
	{
		retorno = 1;
		for(i=0;i<sizeof(entero) && entero[i] != '\0' ;i++)
		{
			if(i==0 && (entero[i] == '+' || entero[i == '-']))
			{
				continue;
			}
			if(entero[i] > '9' || entero[i] < '0')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
