#ifndef MCLIENTS_H
#define MCLIENTS_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct client_data client_data;
struct client_data
{
    int Id_client;
    char nom[50];
    char prenom[50];
    char profession[50];
    char Num_tel[20];
    client_data *next;
    client_data *prev;
};
struct Compte
{
    int Id_compte;
    int Id_client;
    float solde_de_base;
    char date_ouverture[20];
    struct Compte *next;
    struct Compte *prev;
};

struct liste
{
    client_data *first;
    client_data *last;
};
typedef struct liste liste;
void inititListe(liste *l)
{
    l->first = NULL;
    l->last = NULL;
}

void push(liste *l, int Id_client_n, char *nom_n, char *prenom_n, char *profession_n, char *Num_tel_n)
{
    client_data *new_client = (client_data *)malloc(sizeof(client_data));

    if (!new_client || !l)
        return;
    new_client->Id_client = Id_client_n;
    strcpy(new_client->nom, nom_n);
    strcpy(new_client->prenom, prenom_n);
    strcpy(new_client->profession, profession_n);
    strcpy(new_client->Num_tel, Num_tel_n);
    if (l->first == NULL)
    {
        l->first = new_client;
        l->last = new_client;
    }
    else
    {
        new_client->prev = l->last;
        l->last->next = new_client;
        l->last = new_client;
    }
}
void modify(liste *l, int Id_client_n)
{
    int choix;
    if (l->first == NULL)
        printf("Pas de comptes disponibles");
    else
    {
        client_data *ptr = l->first;
        while (ptr->next != NULL)
        {
            if (ptr->Id_client == Id_client_n)
            {
                printf("Client avec l'identifiant : %d est trouve/n ", ptr->Id_client);

                printf("Souhaitez vous changer:\n");
                printf("Souhaitez-vous changer :\n");
                printf("1. Le nom\n");
                printf("2. Le prénom\n");
                printf("3. La profession\n");
                printf("4. Le numéro de téléphone\n");
                printf("Choix : ");
                int choice;
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                {
                    char new_nom[50];
                    printf("Nouveau nom : ");
                    scanf("%s", new_nom);
                    strcpy(ptr->nom, new_nom);
                    printf("Nom modifié avec succès.\n");
                    break;
                }
                case 2:
                {
                    char new_prenom[50];
                    printf("Nouveau prenpm : ");
                    scanf("%s", new_prenom);
                    strcpy(ptr->prenom, new_prenom);
                    printf("Prenom modifié avec succès.\n");
                    break;
                }
                case 3:
                {
                    char new_profession[50];
                    printf("Nouvelle profession : ");
                    scanf("%s", new_profession);
                    strcpy(ptr->profession, new_profession);
                    printf("Profession modifiée avec succès.\n");
                    break;
                }
                case 4:
                {
                    char new_num_tel[15];
                    printf("Nouveau numéro de téléphone : ");
                    scanf("%s", new_num_tel);
                    strcpy(ptr->Num_tel, new_num_tel);
                    printf("Numéro de téléphone modifié avec succès.\n");
                    break;
                }
                default:
                {
                    printf("Choix invalide.\n");
                    break;
                }
                }
                return;
            }
            ptr = ptr->next;
        }

        printf("Client avec l'identifiant : %d n'est pas trouvé\n", Id_client_n);
    }
    void deleteSpecific(liste * l, int Id_client_n)
    {
        int choix;
        if (l->first == NULL)
            printf("Pas de comptes disponibles");
        else
        {
            client_data *ptr = l->first;
            while (ptr->next != NULL)
        }
#endif