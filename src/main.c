#include <stdio.h>
#include "../include/fclients.h"
#include "../include/mclients.h"
#include <stdlib.h>
#include <string.h>

int main()
{
    srand(time(NULL));
    liste *l;     // liste_co *l2; liste comptes
    initListe(l); // MainMenu(l,l2);
    MenuClients(l);
    RevenirMenu(l);
    return 0;
}
