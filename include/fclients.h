#ifndef FCLIENTS_H
#define FCLIENTS_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
typedef struct client client;
struct client
{
    long long Id_client;
    char nom[50];
    char prenom[50];
    char profession[50];
    char Num_tel[20];
};
long long CreationRandomId()
{
    long long min = pow(10, 8);
    long long max = pow(10, 9) - 1;
    return max + rand() % min;
}
void capitalizeFirstLetter(char *name)
{ // look into this later
    if (name != NULL && name[0] != '\0')
    {
        name[0] = toupper(name[0]);
    }
}

typedef struct client_data client_data;
struct client_data
{
    client c;
    client_data *next;
    client_data *prev;
};
struct liste
{
    client_data *first;
    client_data *last;
};
typedef struct liste liste;
void initListe(liste *l)
{
    l->first = NULL;
    l->last = NULL;
}
void clearInputBuffer()
{ // to fix stdin not working we just wipe the input buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

void push(liste *l) // normally only needs l
{
    client_data *new_client = (client_data *)malloc(sizeof(client_data));

    if (!new_client || !l)
        return;
    long long randomId;
    client_data *ptr;
    do
    {
        ptr = l->first;
        randomId = CreationRandomId();
        while (ptr != NULL)
        {
            if (ptr->c.Id_client == randomId)
            {
                randomId = CreationRandomId();
                ptr = l->first;
            }
            else
            {
                ptr = ptr->next;
            }
        }
    } while (ptr != NULL);
    new_client->c.Id_client = randomId;
    clearInputBuffer();
    char nom[50];
    printf("Entrer votre Nom:\n");
    fgets(nom, sizeof(nom), stdin);
    if (strlen(nom) > 0 && nom[strlen(nom) - 1] == '\n') // mesures de securite
        nom[strlen(nom) - 1] = '\0';
    strcpy(new_client->c.nom, nom);

    char prenom[50];
    printf("Entrer cotre Prenom:\n");
    fgets(prenom, sizeof(prenom), stdin);
    if (strlen(prenom) > 0 && prenom[strlen(prenom) - 1] == '\n')
        prenom[strlen(prenom) - 1] = '\0';
    strcpy(new_client->c.prenom, prenom);

    char profession[50];
    printf("Enter votre Profession:\n");
    fgets(profession, sizeof(profession), stdin);
    if (strlen(profession) > 0 && profession[strlen(profession) - 1] == '\n')
        profession[strlen(profession) - 1] = '\0';
    strcpy(new_client->c.profession, profession);

    char Num_tel[20];
    printf("Enter votre numero de telephone:\n");
    fgets(Num_tel, sizeof(Num_tel), stdin);
    if (strlen(Num_tel) > 0 && Num_tel[strlen(Num_tel) - 1] == '\n')
        Num_tel[strlen(Num_tel) - 1] = '\0';
    strcpy(new_client->c.Num_tel, Num_tel);
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
void modify(liste *l)
{
    char nomC[50];
    printf("Entrer le Nom du client:\n");
    clearInputBuffer();
    fgets(nomC, sizeof(nomC), stdin);
    if (strlen(nomC) > 0 && nomC[strlen(nomC) - 1] == '\n') // mesures de securite
        nomC[strlen(nomC) - 1] = '\0';

    if (l->first == NULL)
        printf("Pas de comptes disponibles");
    else
    {
        client_data *ptr = l->first;
        int c = 0;
        while (ptr != NULL)
        {
            if (strcmp(ptr->c.nom, nomC) == 0)
                c++;
            ptr = ptr->next;
        }

        if (c == 0)
        {
            printf("Client %s n'est pas trouvé\n", nomC);
            return;
        }
        else if (c == 1)
        {
            ptr = l->first;
            while (ptr != NULL)
            {
                if (strcmp(ptr->c.nom, nomC) == 1)
                {
                    printf("Client avec l'identifiant : %lld est trouvé\n", ptr->c.Id_client);
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
                        strcpy(ptr->c.nom, new_nom);
                        printf("Nom modifié avec succès.\n");
                        break;
                    }
                    case 2:
                    {
                        char new_prenom[50];
                        printf("Nouveau prénom : ");
                        scanf("%s", new_prenom);
                        strcpy(ptr->c.prenom, new_prenom);
                        printf("Prénom modifié avec succès.\n");
                        break;
                    }
                    case 3:
                    {
                        char new_profession[50];
                        printf("Nouvelle profession : ");
                        scanf("%s", new_profession);
                        strcpy(ptr->c.profession, new_profession);
                        printf("Profession modifiée avec succès.\n");
                        break;
                    }
                    case 4:
                    {
                        char new_num_tel[15];
                        printf("Nouveau numéro de téléphone : ");
                        scanf("%s", new_num_tel);
                        strcpy(ptr->c.Num_tel, new_num_tel);
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
        }
        else
        {
            char prenomC[50];
            printf("Il y a plusieurs clients avec le nom \"%s\".\n", nomC);
            printf("Veuillez entrer le prénom du client :\n");
            clearInputBuffer();
            fgets(prenomC, sizeof(prenomC), stdin);
            if (strlen(prenomC) > 0 && prenomC[strlen(prenomC) - 1] == '\n') // mesures de sécurité
                prenomC[strlen(prenomC) - 1] = '\0';

            ptr = l->first;
            while (ptr != NULL)
            {
                if (strcmp(ptr->c.nom, nomC) == 0 && strcmp(ptr->c.prenom, prenomC) == 0)
                {
                    printf("Client avec l'identifiant : %lld est trouvé\n", ptr->c.Id_client);
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
                        strcpy(ptr->c.nom, new_nom);
                        printf("Nom modifié avec succès.\n");
                        break;
                    }
                    case 2:
                    {
                        char new_prenom[50];
                        printf("Nouveau prénom : ");
                        scanf("%s", new_prenom);
                        strcpy(ptr->c.prenom, new_prenom);
                        printf("Prénom modifié avec succès.\n");
                        break;
                    }
                    case 3:
                    {
                        char new_profession[50];
                        printf("Nouvelle profession : ");
                        scanf("%s", new_profession);
                        strcpy(ptr->c.profession, new_profession);
                        printf("Profession modifiée avec succès.\n");
                        break;
                    }
                    case 4:
                    {
                        char new_num_tel[15];
                        printf("Nouveau numéro de téléphone : ");
                        scanf("%s", new_num_tel);
                        strcpy(ptr->c.Num_tel, new_num_tel);
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
            printf("Client avec le nom \"%s\" et le prénom \"%s\" n'est pas trouvé\n", nomC, prenomC);
        }
    }
}
void deleteSpecific(liste *l)
{
    char nomC[50];
    printf("Entrer le Nom du client:\n");
    clearInputBuffer();
    fgets(nomC, sizeof(nomC), stdin);
    if (strlen(nomC) > 0 && nomC[strlen(nomC) - 1] == '\n') // mesures de securite
        nomC[strlen(nomC) - 1] = '\0';

    if (l->first == NULL)
    {
        printf("Pas de comptes disponibles");
        return;
    }
    else
    {
        client_data *ptr = l->first;
        int c = 0;
        while (ptr != NULL)
        {
            if (strcmp(ptr->c.nom, nomC) == 0)
                c++;
            ptr = ptr->next;
        }

        if (c == 0)
        {
            printf("Client %s n'est pas trouvé\n", nomC);
            return;
        }
        else if (c == 1)
        {
            if (strcmp(ptr->c.nom, nomC) == 0)
            {

                printf("Le client %s %s avec l'identifiant : %d est trouve/n, etes vous sure de le supprimer (Y,n)? ", ptr->c.prenom, ptr->c.nom, ptr->c.Id_client);
                char choice[1];
                scanf("%d", &choice);
                if (strcmp(choice, "n") == 1) // cases to make sure user wants to delete
                {
                    return;
                }
                else if (strcmp(choice, "n") == 0 && (strcmp(choice, "Y") == 0))
                {
                    return;
                }
                else if (strcmp(choice, "Y") == 1) // start of pop last operation
                {
                    if (ptr == l->first && ptr->next != NULL) // pop first with element landing on first one and table having more than 1 (so usual pop first)
                    {
                        if (ptr->next != NULL)
                        {
                            l->first = ptr->next;
                            ptr->next->prev = NULL;
                        }
                        else
                        {
                            l->last = NULL;
                        }

                        return;
                    }
                    else if (ptr->next != NULL && ptr->prev != NULL) // pop mid normal
                    {
                        ptr->prev->next = ptr->next;
                        ptr->next->prev = ptr->prev;

                        return;
                    }
                    else if (ptr == l->last)
                    {
                        ptr->prev->next = NULL;
                    }
                    free(ptr);
                }
            }
        }
        else
        {
            char prenomC[50];
            printf("Il y a plusieurs clients avec le nom \"%s\".\n", nomC);
            printf("Veuillez entrer le prénom du client :\n");
            clearInputBuffer();
            fgets(prenomC, sizeof(prenomC), stdin);
            if (strlen(prenomC) > 0 && prenomC[strlen(prenomC) - 1] == '\n') // mesures de sécurité
                prenomC[strlen(prenomC) - 1] = '\0';

            ptr = l->first;
            while (ptr != NULL)
            {
                if (strcmp(ptr->c.nom, nomC) == 0 && strcmp(ptr->c.prenom, prenomC) == 0)
                {
                    printf("Client avec l'identifiant : %lld est trouvé\n", ptr->c.Id_client);
                    printf("Le client %s %s avec l'identifiant : %d est trouve/n, etes vous sure de le supprimer (Y,n)? ", ptr->c.prenom, ptr->c.nom, ptr->c.Id_client);
                    char choice[1];
                    scanf("%d", &choice);
                    if (strcmp(choice, "n") == 1) // cases to make sure user wants to delete
                    {
                        system("cls");
                        printf("Retour au menu");
                        return;
                    }
                    else if (strcmp(choice, "n") == 0 && (strcmp(choice, "Y") == 0))
                    {
                        system("cls");
                        printf("Retour au menu");

                        return;
                    }
                    else if (strcmp(choice, "Y") == 1) // start of pop last operation
                    {
                        if (ptr == l->first && ptr->next != NULL) // pop first with element landing on first one and table having more than 1 (so usual pop first)
                        {
                            if (ptr->next != NULL)
                            {
                                l->first = ptr->next;
                                ptr->next->prev = NULL;
                            }
                            else
                            {
                                l->last = NULL;
                            }

                            return;
                        }
                        else if (ptr->next != NULL && ptr->prev != NULL) // pop mid normal
                        {
                            ptr->prev->next = ptr->next;
                            ptr->next->prev = ptr->prev;

                            return;
                        }
                        else if (ptr == l->last)
                        {
                            ptr->prev->next = NULL;
                        }
                        free(ptr);
                    }
                }
            }
            printf("Client avec le nom \"%s\" et le prénom \"%s\" n'est pas trouvé\n", nomC, prenomC);
        }
    }
}
void EmptyList(liste *l)
{
    client_data *ptr = l->first;
    printf("Etes vous sure de le vider la liste (Y,n)? ");
    char choice[1];
    scanf("%1s", &choice);
    if (strcmp(choice, "n") == 0) // cases to make sure user wants to delete
    {
        return;
    }
    else
    {
        while (ptr != NULL)
        {
            client_data *ptr2 = ptr->prev;
            ptr2->next = NULL;
            free(ptr2);
            ptr->prev = NULL;
            ptr = ptr->next;
        }
        initListe(l);
    }
}
void searchByName(liste l)
{
    char name[50];
    printf("Enter le nom du client: ");
    scanf("%s", name);

    client_data *ptr = l.first;
    int found = 0;

    while (ptr != NULL)
    {
        if (strcmp(ptr->c.nom, name) == 0)
        {
            printf("Client trouve!\n");
            printf("ID: %d, Name: %s %s, Profession: %s, Phone: %s\n",
                   ptr->c.Id_client, ptr->c.nom, ptr->c.prenom,
                   ptr->c.profession, ptr->c.Num_tel);
            found = 1;
        }
        ptr = ptr->next;
    }

    if (!found)
    {
        printf("Client pas trouve.\n");
    }
}

// Search for client by id ig
void searchById(liste l)
{
    int id;
    printf("Enter l'id du client: ");
    scanf("%d", &id);

    client_data *ptr = l.first;
    int found = 0;

    while (ptr != NULL)
    {
        if (ptr->c.Id_client == id)
        {
            printf("Client trouve!\n");
            printf("ID: %d, Name: %s %s, Profession: %s, Phone: %s\n",
                   ptr->c.Id_client, ptr->c.nom, ptr->c.prenom,
                   ptr->c.profession, ptr->c.Num_tel);
            found = 1;
        }
        ptr = ptr->next;
    }

    if (!found)
    {
        printf("Client pas trouve\n");
    }
}

void searchMenu(liste l)
{
    int option;
    printf("Rechercher client par:\n");
    printf("1. Nom\n");
    printf("2. ID\n");
    printf("Entrer votre option: ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        searchByName(l);
        break;
    case 2:
        searchById(l);
        break;
    default:
        printf("Option Invalide\n");
        break;
    }
}
#endif