// Definição das bibliotecas:
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>

// Menu
#include "login/menuLogin.h"
#include "menuPrincipal/menu.h"

// Gerenciamento de Produtos
#include "gerenciamentoDeProdutos/menuGereProduto.h"
#include "gerenciamentoDeProdutos/cadastrarProduto.h"
#include "gerenciamentoDeProdutos/editarProduto.h"
#include "gerenciamentoDeProdutos/listarProdutos.h"
#include "gerenciamentoDeProdutos/deletarProduto.h"

// Gerenciamento de Vendas
#include "gerenciamentoDeVendas/menuGereVendas.h"
#include "gerenciamentoDeVendas/cadastrarVenda.h"
#include "gerenciamentoDeVendas/relatorioVendas.h"
#include "gerenciamentoDeVendas/cancelarVenda.h"

// Gerenciamento de Fornecedores
#include "gerenciamentoDeFornecedores/menuGereFornecedores.h"
#include "gerenciamentoDeFornecedores/cadastrarFornecedor.h"
#include "gerenciamentoDeFornecedores/editarFornecedor.h"
#include "gerenciamentoDeFornecedores/listarFornecedores.h"

// Gerenciamento de Funcionários
#include "gerenciamentoDeFuncionarios/menuGereFuncionarios.h"
#include "gerenciamentoDeFuncionarios/cadastrarFuncionarios.h"
#include "gerenciamentoDeFuncionarios/editarFuncionario.h"
#include "gerenciamentoDeFuncionarios/listarFuncionarios.h"

// Função main:
int main()
{
    system("color 2f");
    setlocale(LC_ALL, "");
    menuLogin();
}

void pausaCurta() {
    for (int i = 0; i < 3; i++) {
        printf(".");
        fflush(stdout);
        sleep(1);
    }
    printf("\n");
}
