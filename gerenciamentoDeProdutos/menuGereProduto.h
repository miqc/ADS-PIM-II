#ifndef MENUGEREPRODUTO_H_INCLUDED
#define MENUGEREPRODUTO_H_INCLUDED

void menuGereProduto();
void cadastrarProduto();
void editarProduto();
void listarProdutos();

void menuGereProduto() {
    char menuProdSele[10];

     while (1) {
        system("cls");
        printf("---------- Gerenciamento de Produtos ----------\n");
        printf("\nO que gostaria de acessar?\n");
        printf("\n... 1 - Cadastrar Produto\n");
        printf("\n... 2 - Editar Produto\n");
        printf("\n... 3 - Listar Produtos\n");;
        printf("\n... 4 - Deletar Produto\n");
        printf("\n... 5 - Voltar\n");

        printf("\nEscolha uma opção: ");
            fgets(menuProdSele, sizeof(menuProdSele), stdin);
            menuProdSele[strcspn(menuProdSele, "\n")] = 0;

                if (strcmp(menuProdSele, "1") == 0){
                    cadastrarProduto();}
                else if (strcmp(menuProdSele, "2") == 0){
                    if (strcmp(login, "admin") != 0){
                        system("cls");
                        printf("Acesso negado! Tente novamente.\n");
                        system("pause");
                        menuGereProduto();}
                    editarProduto();}
                else if (strcmp(menuProdSele, "3") == 0){
                    listarProdutos();}
                else if (strcmp(menuProdSele, "4") == 0){
                    if (strcmp(login, "admin") != 0){
                            system("cls");
                            printf("Acesso negado! Tente novamente.\n");
                            system("pause");
                            menuGereProduto();}
                    deletarProduto();}
                else if (strcmp(menuProdSele, "5") == 0){
                    menu();}
                else {
                    printf("Valor invalido! Tente novamente.\n");
                    system("pause");
                    system("cls");}
                }
            }

#endif // MENUGEREPRODUTO_H_INCLUDED
