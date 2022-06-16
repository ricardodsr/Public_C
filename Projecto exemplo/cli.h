// Este arquivo: trab.h
// Breve descrição da biblioteca: Biblioteca de Trabalhadores
/////////////////////////////////////

#ifndef CLI_H_
#define CLI_H_

// Inclusão de outras interfaces
// necessárias para entender esta 
// interface.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>      //contém declarações para manipulação de caracteres.
#include <locale.h>  

#define TAM 50


typedef struct Marcacoes
{
    char referenciaEncomenda[20];
    char nomeComercial[20];
    char tipoEncomenda[20];
    int quantidade;
    float preco;
    char pais[20];
}marcacoes;

typedef struct Clientes
{
    int id;
    char nome[20];
    char nif[20];
    char contacto[20];
    char morada[20];
    char email[20];
    marcacoes marc;
    
}clientes;

clientes lcli[TAM];



// Definições das macros que 
// a biblioteca bib usa.


char AddMaisCli();
void IncluirCli(void);
void FormataCli(void);
void ListarCli(void);
void PesquisarCli(void);
void PesquisarCliRef(void);



#endif