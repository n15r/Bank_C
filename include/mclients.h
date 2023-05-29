#ifndef MCLIENTS_H
#define MCLIENTS_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../include/fclients.h"
#include <stdbool.h>

void MenuClients(liste *l)
{
    printf("-------------------------------------------\n");
    printf("          MENU GESTION DES COMPTES          \n");
    printf("-------------------------------------------\n");
    printf("1. Ajout Client\n");
    printf("2. Modification\n");
    printf("3. Suppression\n");
    printf("4. Recherche\n");
    printf("5. Quitter\n");
    printf("-------------------------------------------\n");
    printf("Entrez votre choix : ");
    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
    {
        system("cls");
        printf("-------------------------------------------\n");
        printf("          CREATION COMPTE                  \n");
        printf("-------------------------------------------\n");
        push(l);
        break;
    }
    case 2:
    {
        system("cls");
        printf("-------------------------------------------\n");
        printf("          MODIFIER COMPTE                  \n");
        printf("-------------------------------------------\n");
        modify(l);
        break;
    }
    case 3:
    {
        system("cls");
        printf("-------------------------------------------\n");
        printf("          SUPPRIMER COMPTE                 \n");
        printf("-------------------------------------------\n");
        deleteSpecific(l);
        break;
    }
    case 4:
    {

        system("cls");
        printf("-------------------------------------------\n");
        printf("    SUPPRIMER L'INTEGRALITE DES COMPTES    \n");
        printf("-------------------------------------------\n");
        EmptyList(l);
        break;
    }
    case 5:
    {
        system("cls");
        printf("-------------------------------------------\n");
        printf("    SUPPRIMER L'INTEGRALITE DES COMPTES    \n");
        printf("-------------------------------------------\n");
        deleteSpecific(l);
        break;
    }
    default:
        printf("Erreur");
    }
}
void RevenirMenu(liste *l)
{
    system("cls");
    printf("Appuyez sur Enter pour revenir au menu...");
    clearInputBuffer();
    getchar();
    printf("-------------------------------------------\n");
    system("cls");
    MenuClients(l);
}
#endif