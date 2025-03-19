#ifndef RELATORIOVENDAS_H_INCLUDED
#define RELATORIOVENDAS_H_INCLUDED

#include "vendas.h"

void relatorioVendas() {
   FILE *vendas = fopen("gerenciamentoDeVendas\\vendas.txt", "r");
    if (vendas == NULL) {
        printf("Erro ao abrir o arquivo para leitura\n");
        return;
    }

    char linha[256];
    system("cls");
    printf("---------- Lista de Vendas ----------\n\n");

    while (fgets(linha, sizeof(linha), vendas) != NULL) {
        printf("%s", linha);
    }

    fclose(vendas);
    printf("\n-------------------------------------------\n\n");
    system("pause");
}


#endif // RELATORIOVENDAS_H_INCLUDED
