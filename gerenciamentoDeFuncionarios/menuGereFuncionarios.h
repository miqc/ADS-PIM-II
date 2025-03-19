#ifndef MENUGEREFUNCIONARIOS_H_INCLUDED
#define MENUGEREFUNCIONARIOS_H_INCLUDED


void menuGereFuncionarios(){
    char menuFuncSele[10];

    while (1) {
        system("cls");
        printf("---------- Gerenciamento de Funcionarios ----------\n");
        printf("\nO que gostaria de acessar?\n");
        printf("\n... 1 - Cadastrar Funcionario\n");
        printf("\n... 2 - Editar Funcionario\n");
        printf("\n... 3 - Listar Funcionarios\n");;
        printf("\n... 4 - Voltar\n");

        printf("\nEscolha uma opção: ");
            fgets(menuFuncSele, sizeof(menuFuncSele), stdin);
            menuFuncSele[strcspn(menuFuncSele, "\n")] = 0;

                if (strcmp(menuFuncSele, "1") == 0){
                    cadastrarFuncionario();}
                else if (strcmp(menuFuncSele, "2") == 0){
                    editarFuncionario();}
                else if (strcmp(menuFuncSele, "3") == 0){
                    listarFuncionarios();}
                else if (strcmp(menuFuncSele, "4") == 0){
                    menu();}
                else {
                    printf("Valor invalido! Tente novamente.\n");
                    system("pause");
                    system("cls");}
                }
            }

#endif // MENUGEREFUNCIONARIOS_H_INCLUDED
