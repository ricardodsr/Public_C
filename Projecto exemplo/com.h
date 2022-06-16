// Este arquivo: com.h
// Breve descrição da biblioteca: Biblioteca de Comerciais
/////////////////////////////////////

#ifndef COM_H_
#define COM_H_

// Inclusão de outras interfaces
// necessárias para entender esta 
// interface.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>      //contém declarações para manipulação de caracteres.
#include <locale.h>   

// Definições das macros que 
// a biblioteca bib usa.

#define TAM 50


typedef struct Comerciais
{
    double id;
    char nome[20];
    char contacto[20];
    char zona[20];
    char pais[20];
    char matricula[20];
    float comicao;
    float vendas;

} Comerciais;

Comerciais lcom[TAM];

/*============  Prototipos  ===============*/

char AddMaisC();
void IncluirC(void);
void FormataC(void);
void ListarC(void);
void PesquisarCN(void);

#endif