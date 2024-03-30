#ifndef FCLIENTS_H
#define FCLIENTS_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <windows.h>
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
    time_t t;
    srand((unsigned)time(&t));
    long long min = pow(10, 1);
    long long max = pow(10, 2) - 1;
    return min + rand() % max;
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
};
typedef struct liste liste;
void initListe(liste *l)
{
    l->first = NULL;
}
void clearInputBuffer()
{ // to fix stdin not working we just wipe the input buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}
int stateMode;
void LightSwitch()
{
    if (abs(stateMode) % 2 == 0)
        system("color F4");
    if (abs(stateMode) % 2 != 0)
        system("color 0f");
}
#endif