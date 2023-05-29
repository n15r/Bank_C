#ifndef MCOMPTE_H // M IS MENU
#define MCOMPTE_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct compte compte;
struct compte
{
    int Id_compte_data;
    int Id_client;
    float solde_de_base;
    char date_ouverture[20];
};
typedef struct compte_data compte_data;
struct compte_data
{
    compte c;
    compte_data *next;
    compte_data *prev;
};
struct liste
{
    compte_data *first;
    compte_data *last;
};

#endif