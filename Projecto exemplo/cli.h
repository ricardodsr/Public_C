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
    char referenciaEncomenda[20];  // Referência da encomenda
    char nomeComercial[20];  // Nome comercial
    char tipoEncomenda[20];  // Tipo de encomenda
    int quantidade;  // Quantidade
    float preco;  // Preço
    char pais[20];  // País
}marcacoes;

typedef struct Clientes
{
    int id;  // ID do cliente
    char nome[20];  // Nome do cliente
    char nif[20];  // NIF do cliente
    char contacto[20];  // Contacto do cliente
    char morada[20];  // Morada do cliente
    char email[20];  // Email do cliente
    marcacoes marc;  // Marcacoes associadas ao cliente

}clientes;

clientes lcli[TAM];

// Definições das macros que 
// a biblioteca bib usa.

/**
 * Função para adicionar mais clientes.
 * 
 * @return Retorna um caractere indicando se mais clientes devem ser adicionados ou não.
 */
char AddMaisCli();

/**
 * Função para incluir um cliente.
 */
void IncluirCli(void);

/**
 * Função para formatar um cliente.
 */
void FormataCli(void);

/**
 * Função para listar clientes.
 */
void ListarCli(void);

/**
 * Função para pesquisar clientes.
 */
void PesquisarCli(void);

/**
 * Função para pesquisar clientes por referência.
 */
void PesquisarCliRef(void);

#endif
