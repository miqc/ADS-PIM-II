#ifndef LISTARFORNECEDORES_H_INCLUDED
#define LISTARFORNECEDORES_H_INCLUDED

void listarFornecedores() {
    FILE *arqFornecedores = fopen("gerenciamentoDeFornecedores\\fornecedores.txt", "r");
    if (arqFornecedores == NULL) {
        printf("Erro ao abrir o arquivo para leitura\n");
        return;
    }

    char linha[256];
    int contadorLinhas = 0;
    system("cls");
    printf("---------- Lista de Fornecedores ----------\n\n");

    while (fgets(linha, sizeof(linha), arqFornecedores) != NULL) {
        printf("%s", linha);
        contadorLinhas++;
    }

    if (contadorLinhas == 0) {
        printf("Nenhum fornecedor cadastrado.\n");
    }

    fclose(arqFornecedores);
    printf("\n-------------------------------------------\n\n");
    system("pause");
    menuGereFornecedores();
}

#endif // LISTARFORNECEDORES_H_INCLUDED
