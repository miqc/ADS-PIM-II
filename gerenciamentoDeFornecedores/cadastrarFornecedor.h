#ifndef CADASTRARFORNECEDOR_H_INCLUDED
#define CADASTRARFORNECEDOR_H_INCLUDED

struct Fornecedores {


char idFornecedor[10];
char nomeFornecedor[50];
char cnpj[19];
char telFornecedor[12];};

int idJaExisteFornecedor(const char *id) {
    FILE *arqFornecedor = fopen("gerenciamentoDeFornecedores\\fornecedores.txt", "r");
    if (arqFornecedor == NULL) {
        printf("Erro ao abrir o arquivo para leitura\n");
        return 0;
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), arqFornecedor) != NULL) {
        char idExistenteFornecedor[10];
        if (sscanf(linha, " ID: %s", idExistenteFornecedor) == 1) {
            if (strcmp(idExistenteFornecedor, id) == 0) {
                fclose(arqFornecedor);
                return 1;
            }
        }
    }
    fclose(arqFornecedor);
    return 0;
}


void cadastrarFornecedor(){

    struct Fornecedores fornecedor;
    int idValida = 0;

    while(!idValida){
        system("cls");
        printf("---------- Cadastro de Fornecedor ----------\n");
        printf("\n... - Digite [exit] para sair\n");

        printf("\n... - Digite o ID do fornecedor: ");
        scanf("%s", fornecedor.idFornecedor);

        if (strcmp(fornecedor.idFornecedor, "exit") == 0){
            menuGereFornecedores();}

    if (!validarIdNumerico(fornecedor.idFornecedor)) {
        printf("\nErro: o ID deve conter apenas números. Tente novamente.\n");
        system("pause");
        continue;
        }

    int entradaValida = 0;
    if (idJaExisteFornecedor(fornecedor.idFornecedor)){
        printf("\nErro: o ID %s já  existe. Tente outro.\n", fornecedor.idFornecedor);
        system("pause");
        cadastrarFornecedor();
    } else {
        idValida = 1;
        }
    }

        printf("... - Digite o nome do fornecedor: ");
        getchar();
        fgets(fornecedor.nomeFornecedor, sizeof(fornecedor.nomeFornecedor), stdin);
        fornecedor.nomeFornecedor[strcspn(fornecedor.nomeFornecedor, "\n")] = 0;

        if (strcmp(fornecedor.nomeFornecedor, "exit") == 0){
            menuGereFornecedores();}

        printf("... - Digite o CNPJ do fornecedor: ");
        fgets(fornecedor.cnpj, sizeof(fornecedor.cnpj), stdin);
        fornecedor.cnpj[strcspn(fornecedor.cnpj, "\n")] = 0;

        if (strcmp(fornecedor.cnpj, "exit") == 0){
            menuGereFornecedores();}

        printf("... - Digite o telefone do fornecedor: ");
        fgets(fornecedor.telFornecedor, sizeof(fornecedor.telFornecedor), stdin);
        fornecedor.telFornecedor[strcspn(fornecedor.telFornecedor, "\n")] = 0;

        if (strcmp(fornecedor.telFornecedor, "exit") == 0){
            menuGereFornecedores();}


    FILE *arqFornecedor = fopen("gerenciamentoDeFornecedores\\fornecedores.txt", "a");
        if (arqFornecedor == NULL){
        printf("Bom, n o era pra isso estar acontecendo..");
        return;
    }


    fprintf(arqFornecedor, " ID: %s\n Nome: %s\n CNPJ: %s\n Telefone: %s\n\n",
        fornecedor.idFornecedor,
        fornecedor.nomeFornecedor,
        fornecedor.cnpj,
        fornecedor.telFornecedor);

    fclose(arqFornecedor);
    system("cls");
    pausaCurta();
    printf("\nFornecedor cadastrado com sucesso!\n");


    char funcDenovo[2];
    do {
        printf("Deseja cadastrar outro fornecedor? (s/n) ");
        scanf("%s", funcDenovo);

        if (strcmp(funcDenovo, "S") == 0 || strcmp(funcDenovo, "s") == 0){
            cadastrarFornecedor();
        } else if (strcmp(funcDenovo, "N") == 0 || strcmp(funcDenovo, "n") == 0){
            menuGereFornecedores();
        } else {
            printf("\nOp  o Invalida! Tente novamente.\n");
            system("pause");}
            system("cls");}

            while (strcmp(funcDenovo, "S") != 0 && strcmp(funcDenovo, "s") != 0 &&
                   strcmp(funcDenovo, "N") != 0 && strcmp(funcDenovo, "n") != 0);
        }

#endif // CADASTRARFORNECEDOR_H_INCLUDED
