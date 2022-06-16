// Este arquivo: trab.h
// Breve descrição da biblioteca: Biblioteca de Trabalhadores
/////////////////////////////////////

#ifndef TRAB_H_
#define TRAB_H_

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

typedef struct Tabalhadores
{
    int id;
    char nome[20];
    char nomeSeccao[20];
    char horario[20];
    char cargo[20];
    int ordenado;

}trabalhadores;

trabalhadores max[TAM];

/*============  Prototipos  ===============*/
void Incluir(void);    // função para Incluir dados
void Listar(void);     // função para Mostrar os contatos ja incluidos
void Organizar(void);  // função para Colocar em ordem os contatos da agenda
void Pesquisar(void);  // função para Pesquisar contatos
char AddMais();        // função para Adicionar mais contatos na agenda
void Formata(void);    // função para Apaga todos os contatos na agenda
void pesquisarSeccao(void); // função que retorna o numero total de trabalhadores em uma seccao

#endif