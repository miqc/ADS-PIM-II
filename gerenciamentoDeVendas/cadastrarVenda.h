#ifndef CADASTRARVENDA_H_INCLUDED
#define CADASTRARVENDA_H_INCLUDED

#include "vendas.h"

#define MAX_VENDAS 300

Vendas venda[MAX_VENDAS];
int numVendas = 0;

void venderProduto() {
    system("cls");

    if (numVendas >= MAX_VENDAS) {
        printf("Limite de vendas atingido!\n");
        return;
    }

    Vendas novaVenda;
    char concluir;
    float falta;
    int continuarAdicionando = 1;

    novaVenda.valorTotal = 0.0;
    novaVenda.numItens = 0;

    int itemIndex = 0;

    while (continuarAdicionando && itemIndex < MAX_ITENS) {

        printf("\n... - Digite o nome do produto: ");
        scanf(" %[^\n]", novaVenda.itens[novaVenda.numItens].produto);

        if (strcmp(novaVenda.itens[novaVenda.numItens].produto, "exit") == 0) {
            return;
        }

        do {
            printf("\n... - O produto será vendido por kg ou unidade? (Digite 'kg' ou 'un'): ");
            scanf("%s", novaVenda.itens[novaVenda.numItens].tipoVenda);

            if (strcmp(novaVenda.itens[novaVenda.numItens].tipoVenda, "kg") == 0) {
                printf("\n... - Digite o peso do produto em kg: ");
                scanf("%f", &novaVenda.itens[novaVenda.numItens].peso);
                printf("\n... - Digite o preço por kg: ");
                scanf("%f", &novaVenda.itens[novaVenda.numItens].preco);
                novaVenda.itens[novaVenda.numItens].valorItem = novaVenda.itens[novaVenda.numItens].peso * novaVenda.itens[novaVenda.numItens].preco;
            } else if (strcmp(novaVenda.itens[novaVenda.numItens].tipoVenda, "un") == 0) {
                printf("\n... - Digite a quantidade: ");
                scanf("%d", &novaVenda.itens[novaVenda.numItens].quantidade);
                printf("\n... - Digite o preço por unidade: ");
                scanf("%f", &novaVenda.itens[novaVenda.numItens].preco);
                novaVenda.itens[novaVenda.numItens].valorItem = novaVenda.itens[novaVenda.numItens].quantidade * novaVenda.itens[novaVenda.numItens].preco;
            } else {
                printf("\n... - Tipo inválido! Tente novamente.\n");
                continue;
            }

            novaVenda.valorTotal += novaVenda.itens[novaVenda.numItens].valorItem;
            novaVenda.numItens++;
            itemIndex++;
            break;
        } while (1);

        printf("\n... - Deseja adicionar mais itens? (Digite 1 para Sim, 0 para Não): ");
        scanf("%d", &continuarAdicionando);
    }


    while (1) {
        printf("\n... - Digite a forma de pagamento (1 para Débito, 2 para Crédito, 3 para Pix, 4 para Dinheiro): ");
        scanf("%s", novaVenda.formaPagamento);

        if (strcmp(novaVenda.formaPagamento, "4") == 0) {
            printf("\n... - Será necessário troco? (Digite 's' para sim ou 'n' para não): ");
            scanf(" %c", &novaVenda.precisaTroco);

            if (novaVenda.precisaTroco == 's') {
                printf("\n... - Digite o valor recebido: ");
                scanf("%f", &novaVenda.valorEntrada);

                if (novaVenda.valorEntrada >= novaVenda.valorTotal) {
                    novaVenda.troco = novaVenda.valorEntrada - novaVenda.valorTotal;
                    printf("\n... - O troco é: R$%.2f\n", novaVenda.troco);
                    system("pause");
                } else {
                    printf("\n... - Valor recebido é insuficiente.\n");
                    return;
                }
            }
        }
        break;
    }

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    snprintf(novaVenda.dataHora, sizeof(novaVenda.dataHora), "%02d/%02d/%d %02d:%02d:%02d",
             tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);


    venda[numVendas] = novaVenda;
    numVendas++;

  FILE *vendas = fopen("gerenciamentoDeVendas/vendas.txt", "a");
    if (vendas == NULL) {
        printf("... - Erro ao abrir o arquivo de vendas.\n");
        return;
    }

    fprintf(vendas, "---------- Nota Fiscal ----------\n");
    fprintf(vendas, "Data e Hora: %s\n", novaVenda.dataHora);

    for (int i = 0; i < novaVenda.numItens; i++) {
        fprintf(vendas, "Produto: %s\n", novaVenda.itens[i].produto);
        fprintf(vendas, "Tipo de venda: %s\n", novaVenda.itens[i].tipoVenda);

        if (strcmp(novaVenda.itens[i].tipoVenda, "kg") == 0 || strcmp(novaVenda.itens[i].tipoVenda, "Kg") == 0) {
            fprintf(vendas, "Peso: %.2fkg\n", novaVenda.itens[i].peso);
            fprintf(vendas, "Preço por kg: R$%.2f\n", novaVenda.itens[i].preco);
        } else if (strcmp(novaVenda.itens[i].tipoVenda, "un") == 0 || strcmp(novaVenda.itens[i].tipoVenda, "Un") == 0) {
            fprintf(vendas, "Quantidade: %d\n", novaVenda.itens[i].quantidade);
            fprintf(vendas, "Preço por unidade: R$%.2f\n", novaVenda.itens[i].preco);
        }

        fprintf(vendas, "Valor do item: R$%.2f\n\n", novaVenda.itens[i].valorItem);
    }

    fprintf(vendas, "Valor Total da Compra: R$%.2f\n", novaVenda.valorTotal);

    if (strcmp(novaVenda.formaPagamento, "1") == 0) {
        fprintf(vendas, "Forma de Pagamento: Débito\n");
    } else if (strcmp(novaVenda.formaPagamento, "2") == 0) {
        fprintf(vendas, "Forma de Pagamento: Crédito\n");
    } else if (strcmp(novaVenda.formaPagamento, "3") == 0) {
        fprintf(vendas, "Forma de Pagamento: Pix\n");
    } else if (strcmp(novaVenda.formaPagamento, "4") == 0) {
        fprintf(vendas, "Forma de Pagamento: Dinheiro\n");
    } else {
        fprintf(vendas, "Forma de Pagamento: Desconhecida\n");
    }

    if (novaVenda.precisaTroco == 's') {
        fprintf(vendas, "Valor Recebido: R$%.2f\n", novaVenda.valorEntrada);
        fprintf(vendas, "Troco: R$%.2f\n", novaVenda.troco);
    }
    fprintf(vendas, "---------------------------------\n\n");
    fclose(vendas);
    system("cls");
    pausaCurta();
   notaFiscal(novaVenda, novaVenda.valorTotal);
}


void notaFiscal(Vendas venda) {
    system("cls");

    printf("\nVenda registrada com sucesso!\n");
    printf("\n---------- Cupom Fiscal ----------\n\n");

    float valorTotalVenda = 0.0;

    for (int i = 0; i < venda.numItens; i++) {
        printf("Produto: %s\n", venda.itens[i].produto);

        if (strcmp(venda.itens[i].tipoVenda, "kg") == 0) {
            printf("Peso: %.2f kg\n", venda.itens[i].peso);
            printf("Preço por kg: R$ %.2f\n", venda.itens[i].preco);
        } else {
            printf("Quantidade: %d unidade(s)\n", venda.itens[i].quantidade);
            printf("Preço por unidade: R$ %.2f\n", venda.itens[i].preco);
        }

        printf("Valor do item: R$ %.2f\n\n", venda.itens[i].valorItem);
        valorTotalVenda += venda.itens[i].valorItem;
    }

    printf("Valor total da compra: R$ %.2f\n", valorTotalVenda);

    if (strcmp(venda.formaPagamento, "1") == 0) {
        printf("\nForma de pagamento: Débito\n");
    } else if (strcmp(venda.formaPagamento, "2") == 0) {
        printf("\nForma de pagamento: Crédito\n");
    } else if (strcmp(venda.formaPagamento, "3") == 0) {
        printf("\nForma de pagamento: Pix\n");
    } else if (strcmp(venda.formaPagamento, "4") == 0) {
        printf("\nForma de pagamento: Dinheiro\n");
        if (venda.precisaTroco == 's') {
            printf("\nValor recebido: R$ %.2f\n", venda.valorEntrada);
            printf("Troco: R$ %.2f\n", venda.troco);
        }
    } else {
        printf("\nForma de pagamento não selecionada\n");
        return;
    }

    printf("\nData e Hora da Venda: %s\n\n", venda.dataHora);
    system("pause");
}


#endif // CADASTRARVENDA_H_INCLUDED
