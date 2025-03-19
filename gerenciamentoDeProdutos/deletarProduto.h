void deletarProduto() {

    char idBusca[10];
    int encontrado = 0;

    system("cls");
    printf("---------- Deletar Produto ----------\n");
    printf("\nDigite o ID do produto que deseja deletar: ");
    fgets(idBusca, sizeof(idBusca), stdin);
    idBusca[strcspn(idBusca, "\n")] = 0;

    FILE *arqProdutos = fopen("gerenciamentoDeProdutos\\produtos.txt", "r");
    if (arqProdutos == NULL) {
        printf("Erro ao abrir o arquivo para leitura\n");
        return;
    }

    FILE *tempFile = fopen("gerenciamentoDeProdutos\\temp.txt", "w");
    if (tempFile == NULL) {
        printf("Erro ao criar arquivo temporário\n");
        fclose(arqProdutos);
        return;
    }

    char linha[256];
    int pularBloco = 0;

    while (fgets(linha, sizeof(linha), arqProdutos) != NULL) {
        if (strstr(linha, " ID: ") != NULL && strstr(linha, idBusca) != NULL) {
            char idExistente[10];
            sscanf(linha, " ID: %s", idExistente);
            if (strcmp(idExistente, idBusca) == 0) {
                encontrado = 1;
                pularBloco = 1;
            }
        }


        if (pularBloco) {
            if (strcmp(linha, "\n") == 0) {
                pularBloco = 0;
            }
        } else {
            fputs(linha, tempFile);
        }
    }

    fclose(arqProdutos);
    fclose(tempFile);

    remove("gerenciamentoDeProdutos\\produtos.txt");
    rename("gerenciamentoDeProdutos\\temp.txt", "gerenciamentoDeProdutos\\produtos.txt");

    if (encontrado) {
        printf("\nProduto deletado com sucesso!\n");
    } else {
        printf("\nProduto com ID %s não encontrado.\n", idBusca);
    }

    system("pause");
    menuGereProduto();
}
