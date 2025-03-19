#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

void menu();
void menuGereVendas();
void menuGereProduto();
void menuGereFornecedores();
void menuGereFuncionarios();
void pausaCurta();


void menu(){
    int menuSele;
    char confirmarSaida[1];
    char ch;

    while (1) {
        system("cls");
        printf("---------- Menu Principal ----------\n");
        printf("\nBem vindo(a) %s!\n", login);
        printf("\nO que gostaria de acessar?\n");
        printf("\n... 1 - Gerenciamento de Vendas\n");
        printf("\n... 2 - Gerenciamento de Produtos\n");
        printf("\n... 3 - Gerenciamento de Fornecedores\n");
        printf("\n... 4 - Gerenciamento de Funcionários\n");
        printf("\n... 5 - Sair\n");

        printf("\nEscolha uma opção: ");
            if (scanf("%d%c", &menuSele, &ch) != 2 || ch != '\n') {
                printf("\nEntrada Inválida! Por favor, digite um número.\n");
                fflush(stdin);
                system("pause");
                continue;}

                switch (menuSele){
                    case 1:
                        menuGereVendas();
                        break;
                    case 2:
                        menuGereProduto();
                        break;
                    case 3:
                        if (strcmp(login, "admin") != 0){
                            system("cls");
                            printf("Acesso negado! Somente Administradores tem acesso a essa função.\n\n");
                            system("pause");
                            menu();
                            break;}
                        else{
                            menuGereFornecedores();
                        break;}
                    case 4:
                        if (strcmp(login, "admin") != 0){
                            system("cls");
                            printf("Acesso negado! Somente Administradores tem acesso a essa função.\n\n");
                            system("pause");
                            menu();
                            break;}
                        else {
                            menuGereFuncionarios();
                            break;}
                    case 5:
                        fflush(stdin);
                        system("cls");
                        printf("Você tem certeza que deseja sair? s/n\n");
                        printf("\nSelecione uma opção: ");
                        scanf("%s", confirmarSaida);
                        if (strcmp(confirmarSaida, "S") == 0 || strcmp(confirmarSaida, "s") == 0){
                            system("cls");
                            pausaCurta();
                            system("cls");
                            menuLogin();}
                        else if (strcmp(confirmarSaida, "N") == 0 || strcmp(confirmarSaida, "n") == 0){
                            system("cls");
                            menu();}
                        else {
                            printf("\nValor Invalido, tente novamente.\n");
                            system("pause");
                            fflush(stdin);
                            menu();}
                        break;
                    default:
                        printf("\nEntrada Invalida! Por favor, tente novamente.\n");
                        system("pause");
                        menu();
                }
            }
        }

#endif // MENU_H_INCLUDED
