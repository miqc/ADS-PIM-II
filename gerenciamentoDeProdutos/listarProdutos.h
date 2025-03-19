#ifndef LISTARPRODUTOS_H_INCLUDED
#define LISTARPRODUTOS_H_INCLUDED

void listarProdutos();

void listarProdutos() {
    FILE *arqProdutos = fopen("gerenciamentoDeProdutos\\produtos.txt", "r");
    if (arqProdutos == NULL) {
        printf("Erro ao abrir o arquivo para leitura\n");
        return;
    }

    char linha[256];
    system("cls");
    printf("---------- Lista de Produtos ----------\n\n");


    while (fgets(linha, sizeof(linha), arqProdutos) != NULL) {
        printf("%s", linha);
    }

    fclose(arqProdutos);
    printf("\n-------------------------------------------\n\n");
    system("pause");
}


#endif // LISTARPRODUTOS_H_INCLUDED
