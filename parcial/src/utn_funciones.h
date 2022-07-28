#ifndef UTN_FUNCIONES_H_
#define UTN_FUNCIONES_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int myGets(char* , int );

int PedirEntero(char* ,char* ,char*);

int PedirOpciones(char* ,char*);

float PedirFlotante(char *, char *, char *);

int PedirCaracter(char , char* , char* );

int PedirCadena(char *,char *);

void PedirCadenaConNumero(char *,char *);

int SumarArrays();

void MostrarCadena(char []);

int utn_GetEntero(int* ,char* ,char* ,int ,int ,int );

float utn_GetFlotante(float* ,char* ,char* ,int ,int ,int );

int utn_GetCadena(char*,int ,char* , char* ,int);

int ValidarCadena(char *);

int ValidarParidad(int);

int ValidarNumeroMinimoMaximo(int, int, int, char[]);

int ValidarFloatMinimo(float ,int ,char[] );

int ValidarNumero(int*);

#endif /* UTN_FUNCIONES_H_ */
