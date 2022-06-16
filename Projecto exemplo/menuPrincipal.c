#include "rjG.h"

/*=====================   Menu Trabalhadores  =======================*/
void menuTrabalhadores()
{
    int confirma;
    char op; //variavel de opção
    do
    {
        system("cls"); // limpar tela
        printf("\n\n\t\tRJ - Trabalhadores\n");
        printf("\n 1 = Incluir\n 2 = Listar\n 3 = Pesquisar por nome");
        printf(" 4 = Formatar lista\n 5 = Voltar ao menu Inicial\n");
        op = getch();
        switch (op)
        {
        case '1':
            Incluir();
            break;
        case '2':
            Listar();
            system("pause");
            break;
        case '3':
            Pesquisar();
            break;
        case '4':
            printf("Deseja APAGAR todos os dados ?\n\t PARA CONFIRMAR DIGITE QUATRO ZEROS");
            scanf("%d", &confirma);
            if (confirma == 0000)
            {
                Formata();
            }
            else
            {
                menuTrabalhadores();
            }
            break;
        case '5':
            menuPrincipal();
            break;
        default:
            printf("\a Digite uma opcao valida\n");
            system("pause");
            menuTrabalhadores();
        }
    } while (op);
}
/*=====================   Menu Comerciais  =======================*/
void menuComeriais()
{
    int confirma;
    char op; //variavel de opção
    do
    {
        system("cls"); // limpar tela
        printf("\n\n\t\tRJ - Comerciais\n");
        printf("\n 1 = Incluir\n 2 = Listar\n 3 = Pesquisar por zona\n");
        printf(" 4 = Formatar lista\n 5 = Voltar ao menu Inicial\n");
        op = getch();
        switch (op)
        {
        case '1':
            IncluirC();
            break;
        case '2':
            ListarC();
            system("pause");
            break;
        case '3':
            PesquisarCN();
            system("pause");
            break;
        case '4':
            printf("Deseja APAGAR todos os dados ?\n\t PARA CONFIRMAR DIGITE QUATRO ZEROS");
            scanf("%d", &confirma);
            if (confirma == 0000)
            {
                FormataC();
            }
            else
            {
                menuComeriais();
            }
            break;
        case '5':
            menuPrincipal();
            break;
        default:
            printf("\a Digite uma opcao valida\n");
            system("pause");
            menuComeriais();
        }
    } while (op);
}

/*=====================   Menu Clientes  =======================*/
void menuClientes()
{
    int confirma;
    char op; //variavel de opção
    do
    {
        system("cls"); // limpar tela
        printf("\n\n\t\tRJ - Clientes\n");
        printf("\n 1 = Incluir\n 2 = Listar\n 3 = Pesquisar por nome Cliente\n");
        printf(" 4 = Formatar lista\n 5 = Voltar ao menu Inicial\n");
        op = getch();
        switch (op)
        {
        case '1':
            IncluirCli();
            break;
        case '2':
            ListarCli();
            system("pause");
            break;
        case '3':
            PesquisarCli();
            system("pause");
            break;
        case '4':
            printf("Deseja APAGAR todos os dados ?\n\t PARA CONFIRMAR DIGITE QUATRO ZEROS");
            scanf("%d", &confirma);
            if (confirma == 0000)
            {
                FormataCli();
            }
            else
            {
                menuClientes();
            }
            break;
        case '5':
            menuPrincipal();
            break;
        default:
            printf("\a Digite uma opcao valida\n");
            system("pause");
            menuClientes();
        }
    } while (op);
}


/*=====================   Menu Estatisticas  =======================*/
void menuEstatisticas()
{
    int confirma;
    char op; //variavel de opção
    do
    {
        system("cls"); // limpar tela
        printf("\n\n\t\tRJ - Estatisticas\n");
        printf("\n 1 = Estatisticas Trabalhadores por seccao\n 2 = Pesquisa Cliente por Referencia\n 3 = Pesquisar Comercial por Zona\n 4 = Pesquisar Comercial por Pais\n 5 = Calculo do IVA\n");
        printf("6 = Voltar ao menu Inicial\n");
        op = getch();
        switch (op)
        {
        case '1':
            pesquisarSeccao();
            break;
        case '2':
            PesquisarCliRef();
            break;
        case '3':
            PesquisarC();
            break;
        case '4':
            PesquisarCP();
            break;
        case '5':
            clientesIva();
            break;
        case '6':
            menuPrincipal();
            break;
        
        default:
            printf("\a Digite uma opcao valida\n");
            system("pause");
            menuEstatisticas();
        }
    } while (op);
}

/*=====================   Menu Principal  =======================*/
void menuPrincipal()
{
    char op1; //variavel de opção
    do
    {
        system("cls"); // limpar tela
        printf("\n\n\t\tRJ - Trabalhadores\n");
        printf("\n 1 = Menu Trabalhadores\n 2 = Menu Comerciais\n 3 = Menu Cliente\n 4 = Estatisticas Globais\n");
        printf(" 5 = Sair do programa\n\n");
        op1 = getch();
        switch (op1)
        {
        case '1':
            menuTrabalhadores();
            break;
        case '2':
            menuComeriais();
            break;
        case '3':
            menuClientes();
            break;
        case '4':
            menuEstatisticas();
            break;
        case '5':
            exit(0);
            break;
        default:
            printf("\a Digite uma opcao valida\n");
            system("pause");
        }
    } while (op1);
}

int main()
{
    int var;
    system("title Menu Global");
    system("color 1f"); // Define a o plano de Fundo Azul Marinho e o texto em Branco
    //setlocale(LC_ALL, "Portuguese");//Define no console o idioma Portugues
    printf("\n\n\t\tGestor de pessoal RJ\n\n");
    printf("\tVeja todas as funcoes disponiveis no menu.\n");
    printf("\tUse os numeros para selecionar a opcao desejada.\n");
    printf("\tPressione qualquer tecla para continuar ou \n\tEspaço para sair do programa agora.\n\t");
    system("pause");
    menuPrincipal();
}