#ifndef LISTARFUNCIONARIOS_H_INCLUDED
#define LISTARFUNCIONARIOS_H_INCLUDED

void listarFuncionarios() {
    FILE *funcionarios = fopen("gerenciamentoDeFuncionarios\\funcionarios.txt", "r");
    if (funcionarios == NULL) {
        printf("Erro ao abrir o arquivo para leitura\n");
        return;
    }

    char linha[256];
    system("cls");
    printf("---------- Lista de Funcionários ----------\n\n");

    while (fgets(linha, sizeof(linha), funcionarios) != NULL) {
        printf("%s", linha);
    }

    fclose(funcionarios);
    printf("\n-------------------------------------------\n\n");
    system("pause");
}


#endif // LISTARFUNCIONARIOS_H_INCLUDED
