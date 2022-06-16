/**
 * @file clientes.c
 * @author Carlos Ferreira (a16475@alunos.ipca.pt)
 * @brief Criacao de conteudo para clientes
 * cli.h contem a estrutura que será utilizada neste documento
 * @version 0.1
 * @date 2021-04-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "cli.h"

/**------------------GLOBAIS--------------------------------------**/
static int qtd = 0; // qtd é uma variavel do tipo estatica que conta a quantidade de trabalhadores incritos
FILE *arq;          // declarar a variável(*arq) como ponteiro do arquivo(FILE)


/*==============  Adicionar mais clientes  ===============*/
/**
 * @brief Adiciona clientes a stuct
 * 
 * @return char 
 */
char AddMaisCli()
{
    char op;
    do
    {
        printf("\n Deseja inserir novos dados? [S ou N]? ");
        op = getch();
        printf("\n");
    } while (op != 's' && op != 'n');
    return op;
}

/*==============  Adicionar Clientes em ficheiro  ===============*/
/**
 * @brief Cria o ficheiro clientes.txt com a funcao fopen apos a criacao, 
 * executa um while para adicionar todos os dados especificos a um cliente
 * fclose(arq) fecha o arquivo acima criado
 * 
 */
void IncluirCli(void)
{
    int cont = 0;  //cont sera a variavel contadora
    int retorno;   //retorno seve para definir se fwrite funcionou
    char op = 's'; //serve para definir a opção na função AddMais()

    arq = fopen("clientes.txt", "a"); // fopen cria arquivo de entrada
    if (arq == NULL)
    {                                                               //caso o sistema não consiga criar o arquivo
        printf("Erro!\nO arquivo da lista não pode ser aberto!\n"); //sera mostrada esta mensagen
        getch();                                                    // espera que o usuário pressione uma tecla
        exit(1);                                                    //caso esse erro ocorra este comando encerra o programa
    }

    while ((cont < TAM) && (op == 's'))
    {

        lcli[cont].id += cont;
        printf(" Digite o nome cliente: ");
        scanf("%s", lcli[cont].nome);
        printf(" Digite o NIF: ");
        scanf("%s", lcli[cont].nif);
        printf(" Digite o Contacto: ");
        scanf("%s", lcli[cont].contacto);
        printf(" Digite o Morada: ");
        scanf("%s", lcli[cont].morada);
        printf(" Digite o E-mail: ");
        scanf("%s", lcli[cont].email);
        printf("Digite o nome do comercial: ");
        scanf("%s", lcli[cont].marc.nomeComercial);
        printf("Digite a referencia da encomenda: ");
        scanf("%s", lcli[cont].marc.referenciaEncomenda);
        printf("Digite o tipo de encomenda: ");
        scanf("%s", lcli[cont].marc.tipoEncomenda);
        printf("Digite a quantidade de encomendada: ");
        scanf("%d", &lcli[cont].marc.quantidade);
        printf("Digite o Pais: ");
        scanf("%s", lcli[cont].marc.pais);
        printf("Digite o preco por unidade: ");
        scanf("%f",&lcli[cont].marc.preco);

        /* fwrite grava 1 contato na struct Agenda
           essa lilha pode ser escrita da seguinte forma:
           retorno = fwrite (&max[cont], sizeof(struct Agenda) ,1,arq);*/
        retorno = fwrite(&lcli[cont], sizeof(clientes), 1, arq);
        // fwrite retornara um valor int 1 para sucesso e 0 para fracasso
        if (retorno == 1)
        {
            printf("\n Gravacao ok! ");
        }
        cont++; //enquanto cont for menor 50 adiciona mais um cliente
        printf("Adicionar novo Cliente\n");
        op = AddMaisCli(); //chama a função que pergunta se deseja inserir novos clientes
        qtd++;          //acrecenta 1 clientes a mais
    }
    fclose(arq); //fecha o arquivo clientes.txt

    
}

/*=====================  Apagar tudo  ====================*/
/**
 * @brief Limpa tudo com o metodo de w+ do fopen
 * 
 */
void FormataCli(void) {
    /* w+ abre um arquivo para leitura e escrita.
    Se o arquivo não existir, o sistema operacional tentará criá-lo.
    Se o arquivo existir, todo o seu conteúdo será substituído pelo novo conteúdo.*/
    arq = fopen("clientes.txt","w+"); //recria um arquivo limpo
    printf("\n\tLista limpa!\n ");
    fclose(arq);//fecha o arquivo clientes.txt
    getch();// espera que o usuário pressione uma tecla
}

/*================== Lista os Clientes cadastrados ======================*/
/**
 * @brief Lista o todo o conteudo de um cliente
 * 
 */
void ListarCli(void){
    int i = 0, retorno;

    arq = fopen("clientes.txt", "r");//fopen abre o arquivo no modo leitura "r"
    if (arq == NULL){//caso o SO não consiga abrir o arquivo
       printf ("Erro!\nO arquivo da lista não pode ser aberto!\n");//sera mostrada esta mensagens
       getch();//espera que o usuário pressione uma tecla
       exit(1);//caso esse erro ocorra este comando encerra o programa
    }
    retorno = fread(&lcli[i], sizeof(clientes), 1, arq);//fread le apenas 1 contato do arquivo
    while (retorno == 1){ //o retorno recebe a quantidade de comerciais lidos no fread

            printf("\n Clientes:  %d", i+1);
            printf("\n Id....:%d",lcli[i].id);
            printf("\n Nome....: %s",lcli[i].nome);
            printf("\n Nif....: %s",lcli[i].nif);
            printf("\n Contacto..: %s ",lcli[i].contacto);
            printf("\n Morada..: %s ",lcli[i].morada);
            printf("\n E-mail..: %s ",lcli[i].email);
            printf("\n Referencia d Encomenda..: %s ",lcli[i].marc.referenciaEncomenda);
            printf("\n Nome do Comercial..: %s ",lcli[i].marc.nomeComercial);
            printf("\n Tipo de Encomenda..: %s ",lcli[i].marc.tipoEncomenda);
            printf("\n Quantidade encomendada..: %d ",lcli[i].marc.quantidade);
            printf("\n Pais encomendada..: %s ",lcli[i].marc.pais);
            printf("\n Preco encomendada..: %f ",lcli[i].marc.preco);
             

      i++;
      retorno = fread(&lcli[i], sizeof(clientes), 1, arq);//fread vai ler o proximo contato
    }
    
    printf(" \n\n %d Clientes Cadastrados!\n ", i);
    getch();//espera que o usuário pressione uma tecla
    fclose(arq);//fecha o arquivo agenda.txt
}

/*============== Pesquisar clientes por nome =====================*/
/**
 * @brief Pesquisa  cliente por nome com o auxilio de uma comparacao de strings
 * (strcmp)
 * 
 */
void PesquisarCli(void){
     int i=0, retorno=1, cont=0;//
     char nomeC[50],op;//A variavel nome se refere a zona a ser pesquisada

     arq = fopen("clientes.txt", "r");//fopen abre o arquivo no modo leitura "r"
     if (arq == NULL){//caso o SO não consiga abrir o arquivo
         printf (" Erro!\nO arquivo da lista não pode ser aberto! \n");//sera mostrada esta mensagens
         getch();//espera que o usuário pressione uma tecla
         exit(1);//caso esse erro ocorra este comando encerra o programa
     }
     printf (" Digite o nome do cliente: ");// para procurar contato pelo nome
     scanf("%s", &nomeC);
     retorno = fread(&lcli[i], sizeof(clientes), 1, arq);//fread le apenas 1 contato do arquivo
     while (retorno == 1){//o retorno recebe a quantidade de contatos lidos no fread
         if (strcmp(nomeC, lcli[i].nome) == 0 ){//strcmp compara as strings das variaveis
            
            printf("\n Clientes:  %d", i+1);
            printf("\n Id....:%d",lcli[i].id);
            printf("\n Nome....: %s",lcli[i].nome);
            printf("\n Nif....: %s",lcli[i].nif);
            printf("\n Contacto..: %s ",lcli[i].contacto);
            printf("\n Morada..: %s ",lcli[i].morada);
            printf("\n E-mail..: %s ",lcli[i].email);
            printf("\n Referencia d Encomenda..: %s ",lcli[i].marc.referenciaEncomenda);
            printf("\n Nome do Comercial..: %s ",lcli[i].marc.nomeComercial);
            printf("\n Tipo de Encomenda..: %s ",lcli[i].marc.tipoEncomenda);
            printf("\n Quantidade encomendada..: %d ",lcli[i].marc.quantidade);
            cont++;
         }
     i++;
     retorno = fread(&lcli[i], sizeof(clientes), 1, arq);//fread vai ler o proximo contato
     }
     if(cont == 0){//se strcmp não encontrar strings iguais
        printf("Nao ha clientes nesta [ %s ]!\n ", nomeC);//sera mostrada essa mensagen
     }
     getch();//espera que o usuário pressione uma tecla
     fclose(arq);//fecha o arquivo clientes.txt
}


