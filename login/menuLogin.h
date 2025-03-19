#ifndef MENULOGIN_H_INCLUDED
#define MENULOGIN_H_INCLUDED

void menuLogin();
void menu();

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>


void senhaComAsteriscos(char* senha) {
    int i = 0;
    char ch;

    printf("Digite a senha: ");
    while((ch = getch()) != '\r') {
        if (ch == '\b') {
            if (i > 0) {
                i--;
                printf("\b \b");
            }
        } else {
            senha[i++] = ch;
            printf("*");
        }
    }
    senha[i] = '\0';
}

char login[10], senha[10];

void menuLogin() {
    printf("---------- Login de Usu�rio ----------\n");
    printf("\nDigite o seu login: ");
    scanf("%s", login);
    if (strcmp(login, "admin") == 0) {
        senhaComAsteriscos(senha);
        if (strcmp(senha, "secreta") != 0) {
            printf("\n\nErro: Senha de usu�rio incorreta.\n");
            system("pause");
            system("cls");
            menuLogin();
        } else {
            system("cls");
            menu();
        }
    } else if (strcmp(login, "caixa") == 0) {
        senhaComAsteriscos(senha);
        if (strcmp(senha, "secreto") != 0) {
            printf("\n\nErro: Senha de usu�rio incorreta.\n");
            system("pause");
            system("cls");
            menuLogin();
        } else {
            system("cls");
            menu();
        }
    } else {
        printf("\nErro: Nome de usu�rio invalido.\n");
        system("pause");
        system("cls");
        menuLogin();
    }
}

#endif // MENULOGIN_H_INCLUDED
