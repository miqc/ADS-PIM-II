#ifndef VENDAS_H_INCLUDED
#define VENDAS_H_INCLUDED

#define MAX_VENDAS 300
#define MAX_ITENS 100

typedef struct {
    char produto[30];
    char tipoVenda[10];
    float peso;
    int quantidade;
    float preco;
    float valorItem;
} ItemVenda;

typedef struct {
    ItemVenda itens[MAX_ITENS];
    int numItens;
    char formaPagamento[10];
    char dataHora[20];
    char precisaTroco;
    float valorEntrada;
    float troco;
    float valorTotal;
} Vendas;

extern Vendas venda[MAX_VENDAS];
extern int numVendas;

#endif // VENDAS_H_INCLUDED
