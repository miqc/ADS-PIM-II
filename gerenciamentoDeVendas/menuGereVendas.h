#ifndef MENUGEREVENDAS_H_INCLUDED
#define MENUGEREVENDAS_H_INCLUDED

void menuGereVendas() {
    int menuVenSele;

    while (1) {
        system("cls");
        printf("---------- Gerenciamento de Vendas ----------\n");
        printf("\n... 1 - Vender Produto\n");
        printf("\n... 2 - Relatório de Vendas\n");
        printf("\n... 3 - Cancelar Venda\n");
        printf("\n... 4 - Voltar\n");
        printf("\nEscolha uma opção: ");
        scanf("%d", &menuVenSele);

        switch (menuVenSele) {
            case 1:
                venderProduto();
                break;
            case 2:
                relatorioVendas();
                break;
            case 3:
                cancelarVenda();
                break;
            case 4:
                return;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
                system("pause");
                break;
        }
    }
}

#endif // MENUGEREVENDAS_H_INCLUDED
