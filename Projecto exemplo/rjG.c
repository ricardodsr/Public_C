#include "cli.h"
#include "com.h"
#include "trab.h"

/**------------------GLOBAIS--------------------------------------**/
static int qtd = 0;     // qtd é uma variavel do tipo estatica que conta a quantidade de trabalhadores incritos
FILE *arq;              // declarar a variável(*arq) como ponteiro do arquivo(FILE)

/*--------------------------------------------------------------Trabalhadores--------------------------------------------------------------*/

/*================== Pesquisar Trabalhadores por secção ======================*/
/**
 * @brief Pesquisa trabalhadores por seccao com auxilio de uma comparacao de strings
 * (strcmp)
 * 
 */
void pesquisarSeccao(void){
    int i=0, retorno=1, cont=0, valortotal=0;//
    float media = 0;
     char seccao[50],op;//A variavel nome se refere ao nome a ser pesquisado
     arq = fopen("trabalhadores.txt", "r");//fopen abre o arquivo no modo leitura "r"
     if (arq == NULL){//caso o SO não consiga abrir o arquivo
         printf (" Erro!\nO arquivo da lista não pode ser aberto! \n");//sera mostrada esta mensagens
         getch();//espera que o usuário pressione uma tecla
         exit(1);//caso esse erro ocorra este comando encerra o programa
     }
          printf (" Digite a seccao: ");// para procurar contato pelo nome
        scanf("%s",&seccao);
     retorno = fread(&max[i], sizeof(trabalhadores), 1, arq);//fread le apenas 1 contato do arquivo
     while (retorno == 1){//o retorno recebe a quantidade de contatos lidos no fread
         if (strcmp(seccao, max[i].nomeSeccao) == 0 ){//strcmp compara as strings das variaveis
            cont++;
            valortotal += max[i].ordenado;
            media = valortotal / cont;

         }
     i++;
     retorno = fread(&max[i], sizeof(trabalhadores), 1, arq);//fread vai ler o proximo contato
     }
     printf("Numero total de trabalhadores na seccao [ %s ] e de %d\n\t com um volume total de ordenados : %d\n Media salarial %f",seccao,cont,valortotal,media);

     if(cont == 0){//se strcmp não encontrar strings iguais
        printf("Nao ha Trabalhadores nesta secao!\n ");//sera mostrada essa mensagen
     }
     getch();//espera que o usuário pressione uma tecla
     fclose(arq);//fecha o arquivo agenda.txt
}

/*--------------------------------------------------------------Clientes--------------------------------------------------------------*/

/*============== Pesquisar clientes por referencia =====================*/
/**
 * @brief Pesquisa clientes por referencia com o auxilio de uma comparacao de strings
 * (strcmp)
 * 
 */
void PesquisarCliRef(void){
     int i=0, retorno=1, cont=0;//
     char ref[50],op;//A variavel nome se refere a zona a ser pesquisada

     arq = fopen("clientes.txt", "r");//fopen abre o arquivo no modo leitura "r"
     if (arq == NULL){//caso o SO não consiga abrir o arquivo
         printf (" Erro!\nO arquivo da lista não pode ser aberto! \n");//sera mostrada esta mensagens
         getch();//espera que o usuário pressione uma tecla
         exit(1);//caso esse erro ocorra este comando encerra o programa
     }
     printf (" Digite a referencia da encomenda: ");// para procurar contato pelo nome
     scanf("%s", &ref);
     retorno = fread(&lcli[i], sizeof(clientes), 1, arq);//fread le apenas 1 contato do arquivo
     while (retorno == 1){//o retorno recebe a quantidade de contatos lidos no fread
         if (strcmp(ref, lcli[i].marc.referenciaEncomenda) == 0 ){//strcmp compara as strings das variaveis
            
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
        printf("Nao ha clientes com encomendas com esta referencia [ %s ]!\n ", ref);//sera mostrada essa mensagen
     }
     getch();//espera que o usuário pressione uma tecla
     fclose(arq);//fecha o arquivo clientes.txt
}


/*============== Pesquisar clientes Iva =====================*/
void clientesIva(void){
     int i=0, retorno=1, cont=0;//
     float valorTotal=0;
     char pais[8] ="Portugal";
     char ref[50],op;//A variavel nome se refere a zona a ser pesquisada

     arq = fopen("clientes.txt", "r");//fopen abre o arquivo no modo leitura "r"
     if (arq == NULL){//caso o SO não consiga abrir o arquivo
         printf (" Erro!\nO arquivo da lista não pode ser aberto! \n");//sera mostrada esta mensagens
         getch();//espera que o usuário pressione uma tecla
         exit(1);//caso esse erro ocorra este comando encerra o programa
     }
     printf (" Digite a referencia da encomenda: ");// para procurar contato pelo nome
     scanf("%s", &ref);
     retorno = fread(&lcli[i], sizeof(clientes), 1, arq);//fread le apenas 1 contato do arquivo
     while (retorno == 1){//o retorno recebe a quantidade de contatos lidos no fread
         if ((strcmp(ref, lcli[i].marc.referenciaEncomenda) == 0) && (strcmp("Portugal",lcli[i].marc.pais) == 0)){//strcmp compara as strings das variaveis
           valorTotal  = lcli[i].marc.preco;
           valorTotal = valorTotal + (valorTotal * 0.23);
           valorTotal = valorTotal * (lcli[i].marc.quantidade);
           printf("%f",valorTotal);
           cont ++;
         }
     i++;
     retorno = fread(&lcli[i], sizeof(clientes), 1, arq);//fread vai ler o proximo contato
        }
       
     if(cont == 0){//se strcmp não encontrar strings iguais
        printf("Nao ha clientes com encomendas com esta referencia em Portugal[ %s ]!\n ", ref);//sera mostrada essa mensagen
     }
     
     
     getch();//espera que o usuário pressione uma tecla
     fclose(arq);//fecha o arquivo clientes.txt
}

/*--------------------------------------------------------------Comerciais--------------------------------------------------------------*/

/*============== Pesquisar comercial por zona =====================*/
/**
 * @brief Pesquisa comercial por zona com o auxilio de uma comparacao de stings
 * (strcmp)
 * 
 */
void PesquisarC(void){
     int i=0, retorno=1, cont=0;//
     char zona[50],op;//A variavel nome se refere a zona a ser pesquisada

     arq = fopen("comerciais.txt", "r");//fopen abre o arquivo no modo leitura "r"
     if (arq == NULL){//caso o SO não consiga abrir o arquivo
         printf (" Erro!\nO arquivo da lista não pode ser aberto! \n");//sera mostrada esta mensagens
         getch();//espera que o usuário pressione uma tecla
         exit(1);//caso esse erro ocorra este comando encerra o programa
     }
     printf (" Digite a zona: ");// para procurar contato pelo nome
     scanf("%s", &zona);
     retorno = fread(&lcom[i], sizeof(Comerciais), 1, arq);//fread le apenas 1 contato do arquivo
     while (retorno == 1){//o retorno recebe a quantidade de contatos lidos no fread
         if (strcmp(zona, lcom[i].zona) == 0 ){//strcmp compara as strings das variaveis
            
            printf("\n Comerciais:  %d", i+1);
            printf("\n Id....:%d",lcom[i].id);
            printf("\n Nome....: %s",lcom[i].nome);
            printf("\n Contacto....: %s",lcom[i].contacto);
            printf("\n Zona..: %s ",lcom[i].zona);
            printf("\n Pais..: %s ",lcom[i].pais);
            printf("\n Matricula..: %s \n",lcom[i].matricula);
            printf("Vendas e comicoes acessiveis so \na utilizadores credenciados\n");
            //printf("\n Vendas..: %f \n",lcom[i].vendas); 
            //printf("\n Comicao..: %f \n",lcom[i].comicao);
            cont++;
         }
     i++;
     retorno = fread(&lcom[i], sizeof(Comerciais), 1, arq);//fread vai ler o proximo contato
     }
     if(cont == 0){//se strcmp não encontrar strings iguais
        printf("Nao ha comerciais nesta [ %s ]!\n ", zona);//sera mostrada essa mensagen
     }
     getch();//espera que o usuário pressione uma tecla
     fclose(arq);//fecha o arquivo comercias.txt
}



/*============== Pesquisar comercial por pais =====================*/
/**
 * @brief Pesquisa comercial por pais com o auxilio de uma comparacao de strings
 * (strcmp)
 * 
 */
void PesquisarCP(void){
     int i=0, retorno=1, cont=0;//
     char zona[50],op;//A variavel nome se refere a zona a ser pesquisada

     arq = fopen("comerciais.txt", "r");//fopen abre o arquivo no modo leitura "r"
     if (arq == NULL){//caso o SO não consiga abrir o arquivo
         printf (" Erro!\nO arquivo da lista não pode ser aberto! \n");//sera mostrada esta mensagens
         getch();//espera que o usuário pressione uma tecla
         exit(1);//caso esse erro ocorra este comando encerra o programa
     }
     printf (" Digite a pais: ");// para procurar contato pelo nome
     scanf("%s", &zona);
     retorno = fread(&lcom[i], sizeof(Comerciais), 1, arq);//fread le apenas 1 contato do arquivo
     while (retorno == 1){//o retorno recebe a quantidade de contatos lidos no fread
         if (strcmp(zona, lcom[i].pais) == 0 ){//strcmp compara as strings das variaveis
            cont++;
            printf("\n Nome....: %s\n",lcom[i].nome);
            printf("\n Matricula..: %s \n",lcom[i].matricula);
            printf("\n Contacto....: %s\n",lcom[i].contacto);
            
         }
     i++;
     retorno = fread(&lcom[i], sizeof(Comerciais), 1, arq);//fread vai ler o proximo contato
     }
     printf("Numero total de comerciais neste pais e : %d\n", cont);
     if(cont == 0){//se strcmp não encontrar strings iguais
        printf("Nao ha comerciais nesta [ %s ]!\n ", zona);//sera mostrada essa mensagen
     }
     getch();//espera que o usuário pressione uma tecla
     fclose(arq);//fecha o arquivo comercias.txt
}

