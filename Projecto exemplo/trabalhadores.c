#include "trab.h"
/**------------------GLOBAIS--------------------------------------**/
static int qtd = 0;     // qtd é uma variavel do tipo estatica que conta a quantidade de trabalhadores incritos
FILE *arq;              // declarar a variável(*arq) como ponteiro do arquivo(FILE)




/*==============  Adicionar mais Trabalhadores  ===============*/
/**
 * @brief Adiciona trabalhadores na struct trabalhadores
 * 
 * @return char 
 */
char AddMais() {
   char op;
   do {
      printf("\n Deseja inserir novos dados? [S ou N]? " );
      op = getch();
      printf("\n" );
   } while (op != 's' && op != 'n');
   return op;
}

/*==============  Adicionar Trabalhadores em ficheiro  ===============*/
/**
 * @brief Cria o ficheiro trabalhadores.txt com a funcao fopen apos a criacao, 
 * executa um while para adicionar todos os dados especificos a um cliente
 * fclose(arq) fecha o arquivo acima criado
 * 
 */
void Incluir(void){
     int cont = 0;   //cont sera a variavel contadora
     int retorno;    //retorno seve para definir se fwrite funcionou
     char op = 's';  //seve para definir a opção na função AddMais()

     arq = fopen("trabalhadores.txt", "a");// fopen cria arquivo de entrada
     if (arq == NULL){//caso o sistema não consiga criar o arquivo
        printf ("Erro!\nO arquivo da lista não pode ser aberto!\n");//sera mostrada esta mensagen
        getch();// espera que o usuário pressione uma tecla
        exit(1);//caso esse erro ocorra este comando encerra o programa
     }
     while ((cont < TAM) && (op == 's')){
           
           max[cont].id +=cont;
           printf (" Digite o nome: ");
           scanf("%s",max[cont].nome); 
           printf (" Digite o nome da seccao: ");
           scanf("%s",max[cont].nomeSeccao);
           printf (" Digite o Horario: ");
           scanf("%s",max[cont].horario);
           printf (" Digite o Cargo: ");
           scanf("%s",max[cont].cargo);
           printf (" Digite o Salario: ");
           scanf("%d", &max[cont].ordenado);
            

           /* fwrite grava 1 contato na struct Agenda
           essa lilha pode ser escrita da seguinte forma:
           retorno = fwrite (&max[cont], sizeof(struct Agenda) ,1,arq);*/
           retorno = fwrite (&max[cont], sizeof(trabalhadores) ,1,arq);
           // fwrite retornara um valor int 1 para sucesso e 0 para fracasso
           if (retorno == 1) {
               printf("\n Gravacao ok! ");
           }
           cont++;//enquanto cont for menor 50 adiciona mais um contato
           printf("Adicionar novo Contacto\n");
           op = AddMais();//chama a função que pergunta se deseja inserir novos contatos
           qtd++;//acrecenta 1 contato a mais
     }
     fclose (arq);//fecha o arquivo trabalhadores.txt
}


/*=====================  Apagar tudo  ====================*/
/**
 * @brief Limpa tudo com o metodo de w+ do fopen
 * w+ abre um arquivo para leitura e escrita.
    Se o arquivo não existir, o sistema operacional tentará criá-lo.
    Se o arquivo existir, todo o seu conteúdo será substituído pelo novo conteúdo
 */
void Formata(void) {
   
    arq = fopen("trabalhadores.txt","w+"); //recria um arquivo limpo
    printf("\n\tLista limpa!\n ");
    fclose(arq);//fecha o arquivo trabalhadores.txt
    getch();// espera que o usuário pressione uma tecla
}

/*============== Pesquisar trabalhador pelo nome =====================*/
/**
 * @brief Pesquisa trabalhador por nome com o auxilio de uma comparacao de strings
 * (strcmp)
 * 
 */
void Pesquisar(void){
     int i=0, retorno=1, cont=0;//
     char nome[50],op;//A variavel nome se refere ao nome a ser pesquisado

     arq = fopen("trabalhadores.txt", "r");//fopen abre o arquivo no modo leitura "r"
     if (arq == NULL){//caso o SO não consiga abrir o arquivo
         printf (" Erro!\nO arquivo da lista não pode ser aberto! \n");//sera mostrada esta mensagens
         getch();//espera que o usuário pressione uma tecla
         exit(1);//caso esse erro ocorra este comando encerra o programa
     }
     printf (" Digite o nome: ");// para procurar contato pelo nome
     gets(nome);
     retorno = fread(&max[i], sizeof(trabalhadores), 1, arq);//fread le apenas 1 contato do arquivo
     while (retorno == 1){//o retorno recebe a quantidade de contatos lidos no fread
         if (strcmp(nome, max[i].nome) == 0 ){//strcmp compara as strings das variaveis
            printf("\n Id do funcionario....: %d",max[cont].id);
            printf("\n Nome....: %s",max[i].nome);
            printf("\n Seccao....: %s",max[i].nomeSeccao);
            printf("\n Horario..: %s ",max[i].horario);
            printf("\n Cargo..: %s ",max[i].cargo);
            printf("\n Ordenado..: %d ",max[i].ordenado);
            cont++;
         }
     i++;
     retorno = fread(&max[i], sizeof(trabalhadores), 1, arq);//fread vai ler o proximo contato
     }
     if(cont == 0){//se strcmp não encontrar strings iguais
        printf("Nao ha contatos com este nome!\n ");//sera mostrada essa mensagen
     }
     getch();//espera que o usuário pressione uma tecla
     fclose(arq);//fecha o arquivo trabalhadores.txt
}


/*================== Lista os Trabalhadores cadastrados ======================*/
/**
 * @brief Lista o todo o conteudo de um trabalhador
 * 
 */
void Listar(void){
    int i = 0, retorno;

    arq = fopen("trabalhadores.txt", "r");//fopen abre o arquivo no modo leitura "r"
    if (arq == NULL){//caso o SO não consiga abrir o arquivo
       printf ("Erro!\nO arquivo da lista não pode ser aberto!\n");//sera mostrada esta mensagens
       getch();//espera que o usuário pressione uma tecla
       exit(1);//caso esse erro ocorra este comando encerra o programa
    }
    retorno = fread(&max[i], sizeof(trabalhadores), 1, arq);//fread le apenas 1 contato do arquivo
    while (retorno == 1){ //o retorno recebe a quantidade de contatos lidos no fread

            printf("\n Trabalhadores:  %d", i+1);
            printf("\n Id....:%d",max[i].id);
            printf("\n Nome....: %s",max[i].nome);
            printf("\n Seccao....: %s",max[i].nomeSeccao);
            printf("\n Horario..: %s ",max[i].horario);
            printf("\n cargo..: %s ",max[i].cargo);
            printf("\n Ordenado..: %d \n",max[i].ordenado);
      i++;
      retorno = fread(&max[i], sizeof(trabalhadores), 1, arq);//fread vai ler o proximo contato
    }
    
    printf(" \n\n %d Trabalhadores Cadastrados!\n ", i);
    getch();//espera que o usuário pressione uma tecla
    fclose(arq);//fecha o arquivo agenda.txt
}

