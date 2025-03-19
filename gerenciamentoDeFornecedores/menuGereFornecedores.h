#ifndef MENUGEREFORNECEDORES_H_INCLUDED
#define MENUGEREFORNECEDORES_H_INCLUDED


void menuGereFornecedores(){
    char menuFornSele[10];

   while (1) {
        system("cls");
        printf("---------- Gerenciamento de Fornecedores ----------\n");
        printf("\nO que gostaria de acessar?\n");
        printf("\n... 1 - Cadastrar Fornecedor\n");
        printf("\n... 2 - Editar Fornecedor\n");
        printf("\n... 3 - Listar Fornecedor\n");;
        printf("\n... 4 - Voltar\n");

        printf("\nEscolha uma opção: ");
            fgets(menuFornSele, sizeof(menuFornSele), stdin);
            menuFornSele[strcspn(menuFornSele, "\n")] = 0;

                if (strcmp(menuFornSele, "1") == 0){
                    cadastrarFornecedor();}
                else if (strcmp(menuFornSele, "2") == 0){
                    editarFornecedor();}
                else if (strcmp(menuFornSele, "3") == 0){
                    listarFornecedores();}
                else if (strcmp(menuFornSele, "4") == 0){
                    menu();}
                else {
                    printf("Valor invalido! Tente novamente.\n");
                    system("pause");
                    system("cls");}
                }
            }


#endif // MENUGEREFORNECEDORES_H_INCLUDED
