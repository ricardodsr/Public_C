/**
 * @file comerciais.c
 * @author Carlos Ferreira (a16475@alunos.ipca.pt)
 * @brief Criacao de conteudo para comerciais
 * com.h contem a estrutura que será utilizada neste documento
 * @version 0.1
 * @date 2021-04-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "com.h"

/**------------------GLOBAIS--------------------------------------**/
static int qtd = 0; // qtd é uma variavel do tipo estatica que conta a quantidade de trabalhadores incritos
FILE *arq;          // declarar a variável(*arq) como ponteiro do arquivo(FILE)


/*==============  Adicionar mais Comerciais  ===============*/
/**
 * @brief Adiciona comerciais na struct comerciais
 * 
 * @return char 
 */
char AddMaisC()
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

/*==============  Adicionar Trabalhadores em ficheiro  ===============*/
/**
 * @brief Cria o ficheiro comerciais.txt com a funcao fopen apos a criacao, 
 * executa um while para adicionar todos os dados especificos a um cliente
 * fclose(arq) fecha o arquivo acima criado
 * 
 */
void IncluirC(void)
{
    int cont = 0;  //cont sera a variavel contadora
    int retorno;   //retorno seve para definir se fwrite funcionou
    char op = 's'; //serve para definir a opção na função AddMais()

    arq = fopen("comerciais.txt", "a"); // fopen cria arquivo de entrada
    if (arq == NULL)
    {                                                               //caso o sistema não consiga criar o arquivo
        printf("Erro!\nO arquivo da lista não pode ser aberto!\n"); //sera mostrada esta mensagen
        getch();                                                    // espera que o usuário pressione uma tecla
        exit(1);                                                    //caso esse erro ocorra este comando encerra o programa
    }

    while ((cont < TAM) && (op == 's'))
    {

        lcom[cont].id += cont;
        printf(" Digite o nome: ");
        scanf("%s", lcom[cont].nome);
        printf(" Digite o contacto: ");
        scanf("%s", lcom[cont].contacto);
        printf(" Digite o Zona: ");
        scanf("%s", lcom[cont].zona);
        printf(" Digite o Pais: ");
        scanf("%s", lcom[cont].pais);
        printf(" Digite o Matricula: ");
        scanf("%s", lcom[cont].matricula);
        printf("Digite o valor mensal de vendas: ");
        scanf("%f", &lcom[cont].vendas);
        lcom[cont].comicao = lcom[cont].vendas * 0.05;


        /* fwrite grava 1 contato na struct Agenda
           essa lilha pode ser escrita da seguinte forma:
           retorno = fwrite (&max[cont], sizeof(struct Agenda) ,1,arq);*/
        retorno = fwrite(&lcom[cont], sizeof(Comerciais), 1, arq);
        // fwrite retornara um valor int 1 para sucesso e 0 para fracasso
        if (retorno == 1)
        {
            printf("\n Gravacao ok! ");
        }
        cont++; //enquanto cont for menor 50 adiciona mais um comercial
        printf("Adicionar novo Comercial\n");
        op = AddMaisC(); //chama a função que pergunta se deseja inserir novos comerciais
        qtd++;          //acrecenta 1 comercial a mais
    }
    fclose(arq); //fecha o arquivo comerciais.txt

    
}

/*=====================  Apagar tudo  ====================*/
/**
 * @brief Limpa tudo com o metodo de w+ do fopen
 * 
 * w+ abre um arquivo para leitura e escrita.
    Se o arquivo não existir, o sistema operacional tentará criá-lo.
    Se o arquivo existir, todo o seu conteúdo será substituído pelo novo conteúdo
 */
void FormataC(void) {
    arq = fopen("comerciais.txt","w+"); //recria um arquivo limpo
    printf("\n\tLista limpa!\n ");
    fclose(arq);//fecha o arquivo comerciais.txt
    getch();// espera que o usuário pressione uma tecla
}

/*============== Pesquisar comercial pelo nome =====================*/
/**
 * @brief Pesquisa  comercial por nome com o auxilio de uma comparacao de strings
 * (strcmp)
 * 
 */
void PesquisarCN(void){
     int i=0, retorno=1, cont=0;//
     char nome[50],op;//A variavel nome se refere ao nome a ser pesquisado

     arq = fopen("comerciais.txt", "r");//fopen abre o arquivo no modo leitura "r"
     if (arq == NULL){//caso o SO não consiga abrir o arquivo
         printf (" Erro!\nO arquivo da lista não pode ser aberto! \n");//sera mostrada esta mensagens
         getch();//espera que o usuário pressione uma tecla
         exit(1);//caso esse erro ocorra este comando encerra o programa
     }
     printf (" Digite o nome: ");// para procurar contato pelo nome
     gets(nome);
     retorno = fread(&lcom[i], sizeof(Comerciais), 1, arq);//fread le apenas 1 contato do arquivo
     while (retorno == 1){//o retorno recebe a quantidade de contatos lidos no fread
         if (strcmp(nome, lcom[i].nome) == 0 ){//strcmp compara as strings das variaveis
            printf("\n Comerciais:  %d", i+1);
            printf("\n Id....:%d",lcom[i].id);
            printf("\n Nome....: %s",lcom[i].nome);
            printf("\n Contacto....: %s",lcom[i].contacto);
            printf("\n Zona..: %s ",lcom[i].zona);
            printf("\n Pais..: %s ",lcom[i].pais);
            printf("\n Matricula..: %s \n",lcom[i].matricula);
            printf("Vendas e comicoes acessiveis so \na utilizadores credenciados\n");
         }
     i++;
     retorno = fread(&lcom[i], sizeof(Comerciais), 1, arq);//fread vai ler o proximo contato
     }
     if(cont == 0){//se strcmp não encontrar strings iguais
        printf("Nao ha comerciais com este nome!\n ");//sera mostrada essa mensagen
     }
     getch();//espera que o usuário pressione uma tecla
     fclose(arq);//fecha o arquivo comerciais.txt
}


/*================== Lista os Comerciais cadastrados ======================*/
/**
 * @brief Lista o todo o conteudo de um comercial
 * 
 */
void ListarC(void){
    int i = 0, retorno;

    arq = fopen("comerciais.txt", "r");//fopen abre o arquivo no modo leitura "r"
    if (arq == NULL){//caso o SO não consiga abrir o arquivo
       printf ("Erro!\nO arquivo da lista não pode ser aberto!\n");//sera mostrada esta mensagens
       getch();//espera que o usuário pressione uma tecla
       exit(1);//caso esse erro ocorra este comando encerra o programa
    }
    retorno = fread(&lcom[i], sizeof(Comerciais), 1, arq);//fread le apenas 1 contato do arquivo
    while (retorno == 1){ //o retorno recebe a quantidade de comerciais lidos no fread

            printf("\n Comerciais:  %d", i+1);
            printf("\n Id....:%d",lcom[i].id);
            printf("\n Nome....: %s",lcom[i].nome);
            printf("\n Contacto....: %s",lcom[i].contacto);
            printf("\n Zona..: %s ",lcom[i].zona);
            printf("\n Pais..: %s ",lcom[i].pais);
            printf("\n Matricula..: %s \n",lcom[i].matricula);
            printf("\n Vendas..: %f \n",lcom[i].vendas);
            printf("\n Comicao..: %f \n",lcom[i].comicao);

      i++;
      retorno = fread(&lcom[i], sizeof(Comerciais), 1, arq);//fread vai ler o proximo contato
    }
    
    printf(" \n\n %d Comerciais Cadastrados!\n ", i);
    getch();//espera que o usuário pressione uma tecla
    fclose(arq);//fecha o arquivo agenda.txt
}



