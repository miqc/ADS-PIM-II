#ifndef CADASTRARFUNCIONARIOS_H_INCLUDED
#define CADASTRARFUNCIONARIOS_H_INCLUDED

struct Funcionarios{

    char idFuncionario[10];
    char nomeFuncionario[50];
    char cpf[15];
    char dataNasc[15];
    char tel[12];
    char cargo[20];
    float salario;};


int idJaExiste(const char *id) {
    FILE *funcionarios = fopen("gerenciamentoDeFuncionarios\\funcionarios.txt", "r");
    if (funcionarios == NULL) {
        printf("Erro ao abrir o arquivo para leitura\n");
        return 0;
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), funcionarios) != NULL) {
        char idExistente[10];
        if (sscanf(linha, " ID: %s", idExistente) == 1) {
            if (strcmp(idExistente, id) == 0) {
                fclose(funcionarios);
                return 1;
            }
        }
    }
    fclose(funcionarios);
    return 0;
}

int validarIdNumerico(const char *id) {
    for (int i = 0; i < strlen(id); i++) {
        if (!isdigit(id[i])) {
            return 0;
        }
    }
    return 1;}

void cadastrarFuncionario(){

    struct Funcionarios funcionario;
    int idValida = 0;

    while(!idValida){
        system("cls");
        printf("---------- Cadastro de Funcion�rio ----------\n");
        printf("\n... - Digite [exit] para sair\n");

        printf("\n... - Digite o ID do funcion�rio: ");
        scanf("%s", funcionario.idFuncionario);
        getchar();

        if (strcmp(funcionario.idFuncionario, "exit") == 0){
            menuGereFuncionarios();}

    if (!validarIdNumerico(funcionario.idFuncionario)) {
        printf("\nErro: o ID deve conter apenas n�meros. Tente novamente.\n");
        system("pause");
        continue;
        }

    int entradaValida = 0;
    if (idJaExiste(funcionario.idFuncionario)){
        printf("\nErro: o ID %s j� existe. Tente outro.\n", funcionario.idFuncionario);
        system("pause");
        cadastrarFuncionario();
    } else {
        idValida = 1;
        }
    }

        printf("... - Digite o nome do funcion�rio: ");
        fgets(funcionario.nomeFuncionario, sizeof(funcionario.nomeFuncionario), stdin);
        funcionario.nomeFuncionario[strcspn(funcionario.nomeFuncionario, "\n")] = 0;

        if (strcmp(funcionario.nomeFuncionario, "exit") == 0){
            menuGereFuncionarios();}

        printf("... - Digite o CPF do funcion�rio: ");
        fgets(funcionario.cpf, sizeof(funcionario.cpf), stdin);
        funcionario.cpf[strcspn(funcionario.cpf, "\n")] = 0;

        if (strcmp(funcionario.cpf, "exit") == 0){
            menuGereFuncionarios();}

        printf("... - Digite a data de nascimento do funcion�rio (dd/mm/aaaa): ");
        fgets(funcionario.dataNasc, sizeof(funcionario.dataNasc), stdin);
        funcionario.dataNasc[strcspn(funcionario.dataNasc, "\n")] = 0;

        if (strcmp(funcionario.dataNasc, "exit") == 0){
            menuGereFuncionarios();}

        printf("... - Digite o telefone do funcion�rio: ");
        fgets(funcionario.tel, sizeof(funcionario.tel), stdin);
        funcionario.tel[strcspn(funcionario.tel, "\n")] = 0;

        if (strcmp(funcionario.tel, "exit") == 0){
            menuGereFuncionarios();}

        getchar();
        printf("... - Digite o cargo do funcion�rio: ");
        fgets(funcionario.cargo, sizeof(funcionario.cargo), stdin);
        funcionario.cargo[strcspn(funcionario.cargo, "\n")] = 0;

        if (strcmp(funcionario.cargo, "exit") == 0){
            menuGereFuncionarios();}

        printf("... - Digite o sal�rio do funcion�rio: ");
        scanf(" %f", &funcionario.salario);


    FILE *funcionarios = fopen("gerenciamentoDeFuncionarios\\funcionarios.txt", "a");
        if (funcionarios == NULL){
        printf("Bom, n�o era pra isso estar acontecendo..");
        return;
    }


    fprintf(funcionarios, " ID: %s\n Nome: %s\n CPF: %s\n Data de Nascimento: %s\n Telefone: %s\n Cargo: %s\n Sal�rio: R$%.3f \n\n",
        funcionario.idFuncionario,
        funcionario.nomeFuncionario,
        funcionario.cpf,
        funcionario.dataNasc,
        funcionario.tel,
        funcionario.cargo,
        funcionario.salario);

    fclose(funcionarios);
    system("cls");
    pausaCurta();
    printf("\nUsu�rio cadastrado com sucesso!\n");

    char funcDenovo[2];
    do {
        printf("Deseja cadastrar outro funcion�rio? (s/n) ");
        getchar();
        scanf("%s", funcDenovo);
        getchar();

        if (strcmp(funcDenovo, "S") == 0 || strcmp(funcDenovo, "s") == 0){
            cadastrarFuncionario();
        } else if (strcmp(funcDenovo, "N") == 0 || strcmp(funcDenovo, "n") == 0){
            menuGereFuncionarios();
        } else {
            printf("\nOp��o Invalida! Tente novamente.\n");
            system("pause");}
            system("cls");}

            while (strcmp(funcDenovo, "S") != 0 && strcmp(funcDenovo, "s") != 0 &&
                   strcmp(funcDenovo, "N") != 0 && strcmp(funcDenovo, "n") != 0);
        }

#endif // CADASTRARFUNCIONARIOS_H_INCLUDED
