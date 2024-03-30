/*void Color()
{
    int user = '\0';
    char x[15] = "color ";
    printf("Hello world!\n");
    x[6] = '\0';
    x[7] = '\0';

    fflush(stdin);

    printf("\n\n choose any color code for background ....");
    fflush(stdin);
    scanf("%c", &x[6]);
    while (x[7] == '\0')
    {
        x[7] = '0';
    }
    system(x);

    system("cls");
}
/*0 = Black       8 = Gray
    1 = Blue        9 = Light Blue
    2 = Green       A = Light Green
    3 = Aqua        B = Light Aqua
    4 = Red         C = Light Red
    5 = Purple      D = Light Purple
    6 = Yellow      E = Light Yellow
    7 = White       F = Bright White
*/
/*void push(liste *l) // normally only needs l
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
    system("CLS");
    gotoxy(24, 4);
    printf("\t\t\tCREATION DE COMPTE");
    clearInputBuffer();
    char nom[50];
    gotoxy(36, 8);
    printf("[1] . Entrer le nom du client:    ");
    scanf(" %[^\n]", nom);
    capitalizeFirstLetter(nom);
    strcpy(new_client->c.nom, nom);

    char prenom[50];
    gotoxy(36, 9);
    printf("[2] . Entrer le prenom du client: ");
    scanf(" %[^\n]", prenom);
    capitalizeFirstLetter(prenom);
    strcpy(new_client->c.prenom, prenom);

    char profession[50];
    gotoxy(36, 10);
    printf("[4] . Entrer la Profession du client: ");
    fgets(profession, sizeof(profession), stdin);
    if (strlen(profession) > 0 && profession[strlen(profession) - 1] == '\n')
        profession[strlen(profession) - 1] = '\0';
    strcpy(new_client->c.profession, profession);

    char Num_tel[20];
    gotoxy(36, 10);
    printf("[3] . Entrer le numero de telephone   : ");
    int isValid = 0; // Flag to track if the phone number is valid
    do
    {
        fgets(Num_tel, sizeof(Num_tel), stdin);
        if (strlen(Num_tel) > 0 && Num_tel[strlen(Num_tel) - 1] == '\n')
        {
            Num_tel[strlen(Num_tel) - 1] = '\0';

            // Check if the phone number starts with "+"
            if (Num_tel[0] == '+')
            {
                // Check if the remaining characters are digits
                int i;
                for (i = 1; i < strlen(Num_tel); i++)
                {
                    if (!isdigit(Num_tel[i]))
                    {
                        break;
                    }
                }
                // Check if the number after the country code is within the allowed range
                if (i - 1 <= 11)
                {
                    isValid = 1; // Set the flag to indicate a valid phone number
                }
            }
        }
        if (!isValid)
        {
            printf("Numero de telephone invalide. Veuillez entrer un numero de telephone valide avec le format international.\n");
            // Prompt the user to enter the phone number again
            printf("[3] . Entrer le numero de telephone   : ");
        }
    } while (!isValid);

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
    gotoxy(38, 17);
    printf("AJOUT DE CLIENT FAIT AVEC SUCCES");
    gotoxy(40, 22);
    printf("Press any key to return back to main menu. ");
    char z = getch();
    if (z == 13)
    {
        menu();
    }
}*/
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
/*void deleteSpecific(liste *l)
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
}*/
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