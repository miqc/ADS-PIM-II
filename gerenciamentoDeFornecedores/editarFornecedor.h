#ifndef EDITARFORNECEDOR_H_INCLUDED
#define EDITARFORNECEDOR_H_INCLUDED

void editarFornecedor() {

    char idFornecedor[10];
    struct Fornecedores fornecedor;
    int fornecedorEncontrado = 0;

    system("cls");
    printf("---------- Editar Fornecedor ----------\n");
    printf("\nDigite o ID do fornecedor que deseja editar: ");
    scanf("%s", idFornecedor);

    if (strcmp(idFornecedor, "exit") == 0) {
        menuGereFornecedores();
    }

    FILE *arqFornecedor = fopen("gerenciamentoDeFornecedores\\fornecedores.txt", "r");
    if (arqFornecedor == NULL) {
        printf("Erro ao abrir o arquivo de fornecedores.\n");
        system("pause");
        return;
    }

    FILE *arqTemp = fopen("gerenciamentoDeFornecedores\\fornecedores_temp.txt", "w");
    if (arqTemp == NULL) {
        printf("Erro ao criar arquivo temporário.\n");
        fclose(arqFornecedor);
        system("pause");
        return;
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), arqFornecedor) != NULL) {
        if (sscanf(linha, " ID: %s", fornecedor.idFornecedor) == 1) {
            if (strcmp(fornecedor.idFornecedor, idFornecedor) == 0) {
                fornecedorEncontrado = 1;

                printf("Fornecedor encontrado!\n");
                printf("\n- (Você pode pressionar enter para manter o atual)\n");

                printf("\nDigite o novo nome do fornecedor: ");
                getchar();
                fgets(fornecedor.nomeFornecedor, sizeof(fornecedor.nomeFornecedor), stdin);
                fornecedor.nomeFornecedor[strcspn(fornecedor.nomeFornecedor, "\n")] = 0;

                if (strlen(fornecedor.nomeFornecedor) == 0) {
                    sscanf(linha, " Nome: %[^\n]", fornecedor.nomeFornecedor);
                }

                printf("Digite o novo CNPJ do fornecedor: ");
                fgets(fornecedor.cnpj, sizeof(fornecedor.cnpj), stdin);
                fornecedor.cnpj[strcspn(fornecedor.cnpj, "\n")] = 0;

                if (strlen(fornecedor.cnpj) == 0) {
                    sscanf(linha, " CNPJ: %[^\n]", fornecedor.cnpj);
                }

                printf("Digite o novo telefone do fornecedor: ");
                fgets(fornecedor.telFornecedor, sizeof(fornecedor.telFornecedor), stdin);
                fornecedor.telFornecedor[strcspn(fornecedor.telFornecedor, "\n")] = 0;

                if (strlen(fornecedor.telFornecedor) == 0) {
                    sscanf(linha, " Telefone: %[^\n]", fornecedor.telFornecedor);
                }

                fprintf(arqTemp, " ID: %s\n Nome: %s\n CNPJ: %s\n Telefone: %s\n",
                        fornecedor.idFornecedor, fornecedor.nomeFornecedor,
                        fornecedor.cnpj, fornecedor.telFornecedor);

                fgets(linha, sizeof(linha), arqFornecedor);
                fgets(linha, sizeof(linha), arqFornecedor);
                fgets(linha, sizeof(linha), arqFornecedor);
            } else {
                fputs(linha, arqTemp);
            }
        } else {
            fputs(linha, arqTemp);
        }
    }

    fclose(arqFornecedor);
    fclose(arqTemp);

    if (fornecedorEncontrado) {
        remove("gerenciamentoDeFornecedores\\fornecedores.txt");
        rename("gerenciamentoDeFornecedores\\fornecedores_temp.txt", "gerenciamentoDeFornecedores\\fornecedores.txt");

        printf("\nFornecedor editado com sucesso!\n");
    } else {
        printf("\nFornecedor com ID %s não encontrado.\n", idFornecedor);
        remove("gerenciamentoDeFornecedores\\fornecedores_temp.txt");
    }

    system("pause");
    menuGereFornecedores();
}

#endif // EDITARFORNECEDOR_H_INCLUDED
