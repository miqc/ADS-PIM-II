#ifndef CADASTRARPRODUTO_H_INCLUDED
#define CADASTRARPRODUTO_H_INCLUDED


struct Produtos{

    char idProduto[10];
    char nomeProduto[50];
    char categoriaProduto;
    char dataVal[15];
    float precoKG;
    float precoUN;
    int estoque;};


    int idJaExisteProduto(const char *id) {
    FILE *arqProdutos = fopen("gerenciamentoDeProdutos\\produtos.txt", "r");
    if (arqProdutos == NULL) {
        printf("Erro ao abrir o arquivo para leitura\n");
        return 0;}

    char linha[256];
    while (fgets(linha, sizeof(linha), arqProdutos) != NULL) {
        char idExistenteProduto[10];
        if (sscanf(linha, " ID: %s", idExistenteProduto) == 1) {
            if (strcmp(idExistenteProduto, id) == 0) {
                fclose(arqProdutos);
                return 1;
            }
        }
    }
    fclose(arqProdutos);
    return 0;
}

void cadastrarProduto(){

    struct Produtos produtos;
    produtos.precoUN = 0,00;
    system("cls");
    int catValida = 0;

    while(!catValida){
    printf("---------- Cadastro de Produto ----------\n");
    printf("\n... - Digite [exit] para sair\n");
    printf("\n... - Digite o ID do produto: ");
        fgets(produtos.idProduto, sizeof(produtos.idProduto), stdin);
        produtos.idProduto[strcspn(produtos.idProduto, "\n")] = 0;

        if (strcmp(produtos.idProduto, "exit") == 0){
            menuGereProduto();}


    if (!validarIdNumerico(produtos.idProduto)) {
        printf("\nErro: o ID deve conter apenas números. Tente novamente.\n");
        system("pause");
        system("cls");
        continue;}

    if (idJaExisteProduto(produtos.idProduto)){
        printf("\nErro: o ID %s já existe. Tente outro.\n", produtos.idProduto);
        system("pause");
        system("cls");
        cadastrarProduto();}

    printf("... - Digite o nome do produto: ");
        fgets(produtos.nomeProduto, sizeof(produtos.nomeProduto), stdin);
        produtos.nomeProduto[strcspn(produtos.nomeProduto, "\n")] = 0;

    printf("... - Digite a categoria do produto (F - Fruta, L - Legumes, V - Verduras): ");
        scanf("%c", &produtos.categoriaProduto);
        switch(produtos.categoriaProduto){
        case 'F':
        case 'f':
            produtos.categoriaProduto = 'F';
            catValida = 1;
            break;
        case 'L':
        case 'l':
            produtos.categoriaProduto = 'L';
            catValida = 1;
            break;
        case 'V':
        case 'v':
            produtos.categoriaProduto = 'V';
            catValida = 1;
            break;
        default:
            getchar();
            printf("\nValor inválido, tente novamente!\n");
            system("pause");
            system("cls");
            getchar();
            break;
        }
    }
     printf("... - Digite a data de validade do produto: ");
     getchar();
        fgets(produtos.dataVal, sizeof(produtos.dataVal), stdin);
        produtos.dataVal[strcspn(produtos.dataVal, "\n")] = 0;

    printf("... - Digite o preço em Kilo: ");
        scanf("%f", &produtos.precoKG);

    printf("... - Digite o preço em Unidade: ");
        scanf("%f", &produtos.precoUN);

    printf("... - Digite o estoque do produto: ");
        scanf("%d", &produtos.estoque);

    FILE *arqProdutos = fopen("gerenciamentoDeProdutos\\produtos.txt", "a");
    if (arqProdutos == NULL){
    printf("Bom, não era pra isso estar acontecendo..");
    return;}

    fprintf(arqProdutos, " ID: %s\n Nome do Produto: %s\n Categoria: %c\n Validade: %s\n Preço em KG: %.2f R$\n Preço em UN: %.2f R$\n Estoque: %d\n\n",
    produtos.idProduto,
    produtos.nomeProduto,
    produtos.categoriaProduto,
    produtos.dataVal,
    produtos.precoKG,
    produtos.precoUN,
    produtos.estoque);

    fclose(arqProdutos);

    system("cls");
    pausaCurta();
    printf("\nProduto cadastrado com sucesso!\n");

     char funcDenovo[2];
    do {
        printf("Deseja cadastrar outro Produto? (s/n) ");
        getchar();
        scanf("%s", funcDenovo);
        getchar();

        if (strcmp(funcDenovo, "S") == 0 || strcmp(funcDenovo, "s") == 0){
            system("cls");
            cadastrarProduto();
        } else if (strcmp(funcDenovo, "N") == 0 || strcmp(funcDenovo, "n") == 0){
            system("cls");
            menuGereProduto();
        } else {
            printf("\nOpção Invalida! Tente novamente.\n");
            system("pause");
            system("cls");}

            } while (strcmp(funcDenovo, "S") != 0 && strcmp(funcDenovo, "s") != 0 &&
                   strcmp(funcDenovo, "N") != 0 && strcmp(funcDenovo, "n") != 0);

}

#endif // CADASTRARPRODUTO_H_INCLUDED
