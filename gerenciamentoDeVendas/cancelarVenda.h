#ifndef CANCELARVENDA_H_INCLUDED
#define CANCELARVENDA_H_INCLUDED

#include "vendas.h"

void cancelarVenda() {
    system("cls");

    int numCancel;
    printf("---------- Cancelamento de Venda ----------\n");
    printf("Digite o número da venda que deseja cancelar: ");
    scanf("%d", &numCancel);

    FILE *vendas = fopen("gerenciamentoDeVendas\\vendas.txt", "r");
    if (vendas == NULL) {
        printf("Erro ao abrir o arquivo de vendas!\n");
        return;
    }

    FILE *temp = fopen("gerenciamentoDeVendas\\temp_vendas.txt", "w");
    if (temp == NULL) {
        printf("Erro ao criar o arquivo temporário!\n");
        fclose(vendas);
        return;
    }

    int linhaAtual = 1;
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), vendas) != NULL) {
        if (strstr(buffer, "Data e Hora:") && linhaAtual == numCancel) {
            fprintf(temp, "VENDA CANCELADA!\n");
            while (fgets(buffer, sizeof(buffer), vendas) != NULL && !strstr(buffer, "Data e Hora:")) {
                fputs(buffer, temp);
            }
            if (!feof(vendas)) {
                fputs(buffer, temp);
            }
            linhaAtual++;
        } else {
            fputs(buffer, temp);
        }
        if (strstr(buffer, "Data e Hora:")) {
            linhaAtual++;
        }
    }
    fclose(vendas);
    fclose(temp);

    remove("gerenciamentoDeVendas\\vendas.txt");
    rename("gerenciamentoDeVendas\\temp_vendas.txt", "gerenciamentoDeVendas\\vendas.txt");

    printf("Venda cancelada com sucesso!\n");
    system("pause");
}

#endif // CANCELARVENDA_H_INCLUDED
