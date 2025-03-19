#ifndef EDITARPRODUTO_H_INCLUDED
#define EDITARPRODUTO_H_INCLUDED

void editarProduto();

void editarProduto() {

    char idBusca[10];
    int encontrado = 0;

    system("cls");
    printf("---------- Editar Produto ----------\n");
    printf("\nDigite o ID do produto que deseja editar: ");
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
    struct Produtos produto;

    while (fgets(linha, sizeof(linha), arqProdutos) != NULL) {
        if (strstr(linha, " ID: ") != NULL && strstr(linha, idBusca) != NULL) {
            encontrado = 1;
            printf("\nProduto encontrado! Digite os novos dados.\n");

            printf("\n... - Digite o novo nome do produto: ");
            fgets(produto.nomeProduto, sizeof(produto.nomeProduto), stdin);
            produto.nomeProduto[strcspn(produto.nomeProduto, "\n")] = 0;

            int catValida = 0;
            while (!catValida) {
                printf("... - Digite a nova categoria do produto (F - Fruta, L - Legumes, V - Verduras): ");
                scanf(" %c", &produto.categoriaProduto);
                getchar();

                switch (produto.categoriaProduto) {
                    case 'F': case 'f':
                        produto.categoriaProduto = 'F';
                        catValida = 1;
                        break;
                    case 'L': case 'l':
                        produto.categoriaProduto = 'L';
                        catValida = 1;
                        break;
                    case 'V': case 'v':
                        produto.categoriaProduto = 'V';
                        catValida = 1;
                        break;
                    default:
                        printf("\nValor inválido, tente novamente!\n");
                        break;
                }
            }

            printf("... - Digite a nova data de validade: ");
            fgets(produto.dataVal, sizeof(produto.dataVal), stdin);
            produto.dataVal[strcspn(produto.dataVal, "\n")] = 0;

            printf("... - Digite o novo preço em KG: ");
            scanf("%f", &produto.precoKG);
            getchar();

            printf("... - Digite o novo preço em Unidade: ");
            scanf("%f", &produto.precoUN);
            getchar();

            printf("... - Digite o novo estoque: ");
            scanf("%d", &produto.estoque);
            getchar();

            fprintf(tempFile, " ID: %s\n Nome do Produto: %s\n Categoria: %c\n Validade: %s\n Preço em KG: %.2f R$\n Preço em UN: %.2f R$\n Estoque: %d\n\n",
                    idBusca, produto.nomeProduto, produto.categoriaProduto, produto.dataVal, produto.precoKG, produto.precoUN, produto.estoque);

            for (int i = 0; i < 6; i++) {
                fgets(linha, sizeof(linha), arqProdutos);
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
        printf("\nProduto editado com sucesso!\n\n");
        system("pause");
        menuGereProduto();
    } else {
        printf("Produto com ID %s não encontrado.\n", idBusca);
        system("pause");
    }
}

#endif // EDITARPRODUTO_H_INCLUDED
