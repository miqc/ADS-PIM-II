#ifndef EDITARFUNCIONARIO_H_INCLUDED
#define EDITARFUNCIONARIO_H_INCLUDED

void editarFuncionario() {

    char idFuncionario[10];
    struct Funcionarios funcionario;
    int funcionarioEncontrado = 0;

    system("cls");
    printf("---------- Editar Funcion�rio ----------\n");
    printf("\nDigite o ID do funcion�rio que deseja editar: ");
    scanf("%s", idFuncionario);

    if (strcmp(idFuncionario, "exit") == 0) {
        menuGereFuncionarios();
    }

    FILE *arqFuncionario = fopen("gerenciamentoDeFuncionarios\\funcionarios.txt", "r");
    if (arqFuncionario == NULL) {
        printf("Erro ao abrir o arquivo de funcion�rios.\n");
        system("pause");
        return;
    }

    FILE *arqTemp = fopen("gerenciamentoDeFuncionarios\\funcionarios_temp.txt", "w");
    if (arqTemp == NULL) {
        printf("Erro ao criar arquivo tempor�rio.\n");
        fclose(arqFuncionario);
        system("pause");
        return;
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), arqFuncionario) != NULL) {
        if (sscanf(linha, " ID: %s", funcionario.idFuncionario) == 1) {
            if (strcmp(funcionario.idFuncionario, idFuncionario) == 0) {
                funcionarioEncontrado = 1;

                printf("Funcion�rio encontrado!\n");
                printf("\n- (Voc� pode pressionar enter para manter o atual)\n");

                printf("\nDigite o novo nome do funcion�rio: ");
                getchar();
                fgets(funcionario.nomeFuncionario, sizeof(funcionario.nomeFuncionario), stdin);
                funcionario.nomeFuncionario[strcspn(funcionario.nomeFuncionario, "\n")] = 0;

                if (strlen(funcionario.nomeFuncionario) == 0) {
                    sscanf(linha, " Nome: %[^\n]", funcionario.nomeFuncionario);
                }

                printf("Digite o novo CPF do funcion�rio: ");
                fgets(funcionario.cpf, sizeof(funcionario.cpf), stdin);
                funcionario.cpf[strcspn(funcionario.cpf, "\n")] = 0;

                if (strlen(funcionario.cpf) == 0) {
                    sscanf(linha, " CPF: %[^\n]", funcionario.cpf);
                }

                printf("Digite a nova data de nascimento do funcion�rio (dd/mm/aaaa): ");
                fgets(funcionario.dataNasc, sizeof(funcionario.dataNasc), stdin);
                funcionario.dataNasc[strcspn(funcionario.dataNasc, "\n")] = 0;

                if (strlen(funcionario.dataNasc) == 0) {
                    sscanf(linha, " Data de Nascimento: %[^\n]", funcionario.dataNasc);
                }

                printf("Digite o novo telefone do funcion�rio: ");
                fgets(funcionario.tel, sizeof(funcionario.tel), stdin);
                funcionario.tel[strcspn(funcionario.tel, "\n")] = 0;

                if (strlen(funcionario.tel) == 0) {
                    sscanf(linha, " Telefone: %[^\n]", funcionario.tel);
                }

                getchar();
                printf("Digite o novo cargo do funcion�rio: ");
                fgets(funcionario.cargo, sizeof(funcionario.cargo), stdin);
                funcionario.cargo[strcspn(funcionario.cargo, "\n")] = 0;

                if (strlen(funcionario.cargo) == 0) {
                    sscanf(linha, " Cargo: %[^\n]", funcionario.cargo);
                }

                float salarioTemp;
                printf("Digite o novo sal�rio do funcion�rio (ou pressione enter para manter o atual): ");
                char buffer[20];
                fgets(buffer, sizeof(buffer), stdin);

                if (strlen(buffer) > 1) {
                    sscanf(buffer, "%f", &salarioTemp);
                    funcionario.salario = salarioTemp;
                } else {
                    sscanf(linha, " Sal�rio: %f", &funcionario.salario);
                }

                fprintf(arqTemp, " ID: %s\n Nome: %s\n CPF: %s\n Data de Nascimento: %s\n Telefone: %s\n Cargo: %s\n Sal�rio: %.3f R$\n\n",
                        funcionario.idFuncionario, funcionario.nomeFuncionario, funcionario.cpf,
                        funcionario.dataNasc, funcionario.tel, funcionario.cargo, funcionario.salario);

                fgets(linha, sizeof(linha), arqFuncionario);
                fgets(linha, sizeof(linha), arqFuncionario);
                fgets(linha, sizeof(linha), arqFuncionario);
                fgets(linha, sizeof(linha), arqFuncionario);
                fgets(linha, sizeof(linha), arqFuncionario);
                fgets(linha, sizeof(linha), arqFuncionario);
            } else {
                fputs(linha, arqTemp);
            }
        } else {
            fputs(linha, arqTemp);
        }
    }

    fclose(arqFuncionario);
    fclose(arqTemp);

    if (funcionarioEncontrado) {
        remove("gerenciamentoDeFuncionarios\\funcionarios.txt");
        rename("gerenciamentoDeFuncionarios\\funcionarios_temp.txt", "gerenciamentoDeFuncionarios\\funcionarios.txt");

        printf("\nFuncion�rio editado com sucesso!\n");
    } else {
        printf("\nFuncion�rio com ID %s n�o encontrado.\n", idFuncionario);
        remove("gerenciamentoDeFuncionarios\\funcionarios_temp.txt");
    }

    system("pause");
    menuGereFuncionarios();
}

#endif // EDITARFUNCIONARIO_H_INCLUDED
