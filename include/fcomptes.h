#ifndef MCOMPTE_H // M IS MENU
#define MCOMPTE_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct compte compte;
struct compte
{
    long long Id_compte_data;
    long long Id_client;
    float solde_de_base;
    char date_ouverture[20];
    float soldeNet;
};
typedef struct compte_data compte_data;
struct compte_data
{
    compte c;
    compte_data *next;
    compte_data *prev;
};
typedef struct liste2 liste2;
struct liste2
{
    compte_data *first;
    compte_data *last;
};
typedef struct operation operation;
struct operation
{
    long long id_compte;
    long long id_client;
    long long montant;
    char date[11];
};
typedef struct operation_data operation_data;
struct operation_data
{
    operation c;
    operation_data *next;
    operation_data *prev;
};
typedef struct liste3 liste3;
struct liste3
{
    operation_data *first;
    operation_data *last;
};

#endif