#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "fclients.h"
#include "fcomptes.h"
#include <stdbool.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#define MAX_PASSWORD_LENGTH 20

void admin();
void login();
int verify();
void option();
void menuAdmin();
void optionMenuAdmin();
void MenuAdmin_Clients();
void optionMenuAdmin_clients();
void view();
void edit();
void del();
void about();
liste *l;
liste2 *l2;
liste3 *l3;
void push();
void search_acc();
void search_name();
void delAll();
void pushCompte();
void optionMenuAdmin_comptes();
void MenuAdmin_Comptes();
void viewComptes();
void delCompte();
int chkaccCompte();
void delAllComptes();
void MenuAdmin_Operations();
void optionMenuAdmin_Operations();
void Retrait();
void Virement();
int IsBalanceEnough();
int AddToBalance();
void viewOperations();
void delAllOperations();
void MenuUser();
void optionMenuUser();
void ViewComptesUser();
void searchAccUser();
void Transfert();
void TransactionReceiver();
void TransactionSender();
int AddToBalance2();
int IsBalanceEnough2();

int i = 0;
COORD coord = {0, 0};
int m;
int r;
int stateMode = 0;
char id[20], password[15];
char input[50];
void gotoxy(int a, int b)
{
    coord.X = a;
    coord.Y = b;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int main()
{

    srand((unsigned)time(NULL));
    liste *l;
    liste *l2;
    LightSwitch();
    gotoxy(43, 4);
    printf(" BIENVENUE AU SYSTEME BANCAIRE ");
    gotoxy(50, 8);
    printf("TYPE DE COMPTE");
    gotoxy(44, 10);
    printf("[1] . ADMINISTRATEUR ");
    gotoxy(44, 11);
    printf("[2] . UTILISATEUR ");
    gotoxy(44, 12);
    printf("[3] . CHANGER VERS MODE NUIT / JOUR ");
    gotoxy(44, 15);
    printf("Enterez votre Choix .... ");
    fgets(input, sizeof(input), stdin);
    char *endptr;
    m = strtol(input, &endptr, 10);
    if (endptr == input || *endptr != '\n' || m < 0 || m >= 4)
    {

        gotoxy(43, 25);
        printf("Veuillez Choisir un entier entre 1 et 3");
        Sleep(2000);
        system("cls");
        main();
    }
    if (m == 3)
    {
        stateMode++;
        system("CLS");
        main();
    }
    system("CLS");
    admin();

    return 0;
}
void admin()
{
    LightSwitch();
    gotoxy(43, 4);
    printf(" BIENVENUE AU SYSTEME BANCAIRE BMCEISI");
    login();
    if (verify() == 1)
    {
        if (m == 1)

            menuAdmin();
        else
        {

            MenuUser();
        }
    }
    else if (verify() == 0)
    {
        system("CLS");
        gotoxy(43, 16);
        printf("l'Identifiant or mot de passe incorrect !!!!");
    }
}
void login()
{
    int i = 0;
    gotoxy(44, 10);
    printf("Entrer l'identifiant : ");
    scanf(" %[^\n]", id);
    gotoxy(44, 12);
    char ch;
    printf("Entrez le Mot de Passe : "); // NEED TO FIX THIS
    while (i < MAX_PASSWORD_LENGTH)
    {
        ch = _getch();
        if (ch == '\r') // Check for Enter key
            break;
        password[i] = ch;
        ++i;
        printf("*");
    }

    password[i] = '\0';
}
int verify()
{
    char a;
    if (m == 1)
    {
        if ((strcmp(id, "admin") == 0 && strcmp(password, "admin") == 0))
        {
            gotoxy(38, 16);
            printf("Vous etes Connectes avec succes en : \" %s \" ", id);
            gotoxy(36, 20);
            printf("Appuyez sur n'importe quelle touche pour continuer .... ");
            getch();
            return 1;
        }
        else
            return 0;
    }
    else if (m == 2)
    {
        if (strcmp(id, "user") == 0 && strcmp(password, "user") == 0)
        {
            gotoxy(38, 16);
            printf("Vous etes Connectes avec succes en : \" %s \" ", id);
            gotoxy(36, 20);
            printf("Appuyez sur n'importe quelle touche pour continuer .... ");
            getch();
            return 1;
        }
        else
            return 0;
    }
    return 0;
}
void menuAdmin()
{
    system("CLS");
    gotoxy(48, 4);
    printf("BIENVENUE AU MENU ADMINISTRATEUR");
    gotoxy(44, 8);
    printf("[1] . Gerer Clients");
    gotoxy(44, 9);
    printf("[2] . Gerer Comptes Bancaires");
    gotoxy(44, 10);
    printf("[3] . Gerer les Operations");
    gotoxy(44, 11);
    printf("[4] . Retour");
    gotoxy(43, 20);
    printf("Veuillez entrer votre Choix [1-4] : ");

    optionMenuAdmin();
}
void optionMenuAdmin()
{
    int w;
    if (scanf("%d", &w) != 1 || w < 0 || w > 4)
    {
        gotoxy(43, 25);
        printf("Erreur! Veuillez entrer un entier [1-4]\n");
        Sleep(2000);
        system("cls");
        menuAdmin();
    }
    switch (w)
    {
    case 1:
        system("cls");
        MenuAdmin_Clients();

        break;
    case 2:
        system("cls");
        MenuAdmin_Comptes();

        break;
    case 3:
        system("cls");
        MenuAdmin_Operations();

        break;
    case 4:
        system("cls");
        main();

        break;
    default:
        system("cls");
        optionMenuAdmin();

        break;
    }
}
void MenuAdmin_Clients()
{
    system("CLS");
    gotoxy(48, 4);
    printf("WELCOME TO MAIN MENU");
    gotoxy(44, 8);
    printf("[1] . Visionner les Clients");
    gotoxy(44, 9);
    printf("[2] . Ajouter un Client");
    gotoxy(44, 10);
    printf("[3] . Editer un Client");
    gotoxy(44, 11);
    printf("[4] . Supprimer un Client");
    gotoxy(44, 12);
    printf("[5] . Supprimer tous les Clients");
    gotoxy(44, 13);
    printf("[6] . Rechercher un client par ID");
    gotoxy(44, 14);
    printf("[7] . Rechercher un client par nom");
    gotoxy(44, 15);
    printf("[8] . Informations sur nous");
    gotoxy(44, 16);
    printf("[9] . Retour");
    gotoxy(44, 17);
    printf("[10] . Se deconnecter ");
    gotoxy(43, 21);
    printf("Please Enter Your Choice [1-10] : ");
    optionMenuAdmin_clients();
}
void optionMenuAdmin_clients()
{
    int w;
    if (scanf("%d", &w) != 1 || w < 0 || w > 10)
    {
        gotoxy(43, 25);
        printf("Erreur! Veuillez entrer un entier [1-10]\n");
        Sleep(2000);
        system("cls");
        MenuAdmin_Clients();
    }
    switch (w)
    {
    case 1:
        system("cls");
        view();

        break;
    case 2:
        system("cls");
        push(l);

        break;
    case 3:
        system("cls");
        edit();

        break;
    case 4:
        system("cls");
        del();
        break;
    case 5:
        system("cls");
        delAll();

    case 6:
        search_acc();
        break;
    case 7:
        search_name();
        break;
    case 8:
        about();
        break;
    case 9:
        menuAdmin();
    case 10:
        main();
        break;
    default:
        MenuAdmin_Clients(); // here again
    }
    system("cls");
}
long long IdCreate() // making sure that there is no id that ressembles this one beforehand
{
re:
    long long Id = CreationRandomId();
    FILE *f = fopen("record.bin", "rb");
    client_data temp;
    while (!feof(f))
    {
        fread(&temp, sizeof(client_data), 1, f);

        if (Id == temp.c.Id_client)
        {
            fclose(f);
            goto re;
        }
    }
    fclose(f);
    return Id;
}
void push(liste *l) // normally only needs l MAIN FUNCTION WRITE BINARY TING
{
    client *new_client = (client *)malloc(sizeof(client));
    char c;
    FILE *file = fopen("record.bin", "ab");

    long long randomId;

    do
    {
        srand((unsigned)time(NULL));
        system("CLS");
        gotoxy(24, 4);
        printf("\t\t\tCREATION DE COMPTE");
        new_client->Id_client = IdCreate();
        char nom[50];
        gotoxy(36, 8);
        printf("[1] . Entrer le nom du client:    ");
        scanf(" %[^\n]", nom);
        capitalizeFirstLetter(nom);
        strcpy(new_client->nom, nom);

        char prenom[50];
        gotoxy(36, 9);
        printf("[2] . Entrer le prenom du client: ");
        scanf(" %[^\n]", prenom);
        capitalizeFirstLetter(prenom);
        strcpy(new_client->prenom, prenom);

        char profession[50];
        gotoxy(36, 10);
        printf("[3] . Entrer la Profession du client: ");
        scanf(" %[^\n]", profession);
        strcpy(new_client->profession, profession);

        char Num_tel[13];
        gotoxy(36, 11);
        printf("[4] . Entrer le numero de telephone   : ");
        scanf(" %[^\n]", Num_tel);
        strcpy(new_client->Num_tel, Num_tel);
        client_data *new_node = (client_data *)malloc(sizeof(client_data));
        new_node->c = *new_client;
        fwrite(new_node, sizeof(client_data), 1, file);
        gotoxy(38, 17);
        printf("AJOUT DE CLIENT FAIT AVEC SUCCES");
        gotoxy(36, 19);

        printf("Voulez vous ajouter un nouveau client? (Y,n) : ");
        scanf(" %c", &c);

    } while (c == 'Y' || c == 'y');
    fclose(file);
    gotoxy(40, 22);
    printf("Appuyez sur n'importe quelle touche pour revenir au menu principal.");
    getch();
    MenuAdmin_Clients();
    char z = getch();
    if (z == 13)
    {
        main();
    }
}
int chkacc(long long a) // to check if a exists
{
    FILE *f;
    f = fopen("record.bin", "rb");
    if (f == NULL)
    {
        printf("Error opening file.\n");
        return 0;
    }

    client_data temp;

    while (fread(&temp, sizeof(client_data), 1, f) == 1)
    {
        if (a == temp.c.Id_client)
        {
            fclose(f);
            return 1;
        }
    }

    fclose(f);
    return 0;
}
void edit()
{
    FILE *x, *y;
    client_data *temp;
    temp = (client_data *)malloc(sizeof(client_data));
    long long a;
    int c;
re:

    gotoxy(48, 4);
    printf(" EDIT CUSTOMER ACCOUNT ");
    gotoxy(43, 7);
    printf("Enter Your Account Number To Edit : ");
    scanf("%lld", &a);
    if (chkacc(a) == 1)
    {
        x = fopen("record.bin", "rb");
        y = fopen("new.bin", "wb");
        while (fread(temp, sizeof(client_data), 1, x))
        {
            if (temp->c.Id_client != a)
                fwrite(temp, sizeof(client_data), 1, y);
            else if (a == temp->c.Id_client)
            {

                gotoxy(36, 8);
                printf("[1] . Entrer le nom du client:    ");
                scanf(" %[^\n]", temp->c.nom);
                capitalizeFirstLetter(temp->c.nom);

                gotoxy(36, 9);
                printf("[2] . Entrer le prenom du client: ");
                scanf(" %[^\n]", temp->c.prenom);
                capitalizeFirstLetter(temp->c.prenom);

                gotoxy(36, 10);
                printf("[3] . Entrer la Profession du client: ");
                scanf(" %[^\n]", temp->c.profession);

                gotoxy(36, 11);
                printf("[4] . Entrer le numero de telephone   : ");
                scanf(" %[^\n]", temp->c.Num_tel);
                fwrite(temp, sizeof(client_data), 1, y);
            }
        }
        fclose(x);
        fclose(y);
    }
    if (chkacc(a) == 0)
    {
        system("CLS");
        gotoxy(52, 21);
        printf("Account Doesn't Exist. ");
        goto re;
    }
    remove("record.bin");
    rename("new.bin", "record.bin");
    gotoxy(45, 21);
    printf("MISE A JOUR FAITE AVEC SUCCES");
    gotoxy(42, 24);
    printf("Appuyez sur n'importe quelle touche pour revenir au menu principal.");
    getch();
    menuAdmin();
}
void view()
{
    int i = 7;
    client_data temp;
    FILE *f;
    // rb = reading binary
    f = fopen("record.bin", "rb");
    gotoxy(40, 3);
    printf("CUSTOMERS LIST");
    gotoxy(1, 5);
    printf("ID");
    gotoxy(18, 5);
    printf("Nom");
    gotoxy(34, 5);
    printf("Prenom");
    gotoxy(46, 5);
    printf("Profession");
    gotoxy(65, 5);
    printf("Num Tel.");
    gotoxy(5, 6);
    while (fread(&temp, sizeof(client_data), 1, f))
    {
        gotoxy(1, i);
        printf("%lld", temp.c.Id_client);
        gotoxy(18, i);
        printf("%s", temp.c.nom);
        gotoxy(34, i);
        printf("%s", temp.c.prenom);
        gotoxy(46, i);
        printf("%s", temp.c.profession);
        gotoxy(65, i);
        printf("%s", temp.c.Num_tel);
        i++;
        i++;
    }

    fclose(f);
    int x;
    gotoxy(42, i + 5);
    printf("Appuyez sur [ENTRER] pour revenir au menu principal.");
    x = getch();
    if (x == 13)
    {
        MenuAdmin_Clients();
    }
    else
        view();
}
void del()
{
    FILE *x, *y;
    long long a;
    int c;
    client_data *temp;
    temp = (client_data *)malloc(sizeof(client_data)); // Allocate memory for temp

re:
    gotoxy(48, 4);
    printf(" DELETE CUSTOMER ACCOUNT ");
    gotoxy(41, 9);
    printf("Enter Your Account Number To Delete : ");
    scanf("%lld", &a);
    if (chkacc(a) == 1)
    {
        x = fopen("record.bin", "rb");
        y = fopen("new.bin", "wb");
        while (fread(temp, sizeof(client_data), 1, x))
        {
            if (temp->c.Id_client != a)
                fwrite(temp, sizeof(client_data), 1, y);
        }
        fclose(x);
        fclose(y);
        x = fopen("record.bin", "wb");
        y = fopen("new.bin", "rb");
        while (fread(temp, sizeof(client_data), 1, y))
            fwrite(temp, sizeof(client_data), 1, x);
        fclose(x);
        fclose(y);
        remove("new.bin"); // Remove the temporary file
        gotoxy(44, 15);
        printf("CLIENT SUPRIME AVEC SUCCES");
        gotoxy(42, 18);
        printf("Appuyez sur n'importe quelle touche pour revenir au menu principal.");
        getch();
        MenuAdmin_Clients();
    }
    else if (chkacc(a) == 0)
    {
        system("CLS");
        gotoxy(51, 15);
        printf("Compte n'existe pas");
        printf("Appuyez sur n'importe quelle touche pour reesaier");
        getch();
        goto re;
    }
    free(temp); // Free the allocated memory
    gotoxy(44, 15);
    printf("CLIENT SUPPRIMER AVEC SUCCES");
    gotoxy(42, 18);
    printf("Appuyez sur n'importe quelle touche pour revenir au menu principal.");
    getch();
    MenuAdmin_Clients();
}
int IsClientIdExistent(long long a)
{
    FILE *f;
    int x;
    client_data *temp;
    temp = (client_data *)malloc(sizeof(client_data));
    f = fopen("record.bin", "rb");
    while (fread(temp, sizeof(client_data), 1, f))
    {
        if (temp->c.Id_client == a)
        {
            fclose(f);
            free(temp);
            return 1;
        }
    }
    fclose(f);
    free(temp);
    return 0;
}

int IsCompteIdExistent(long long a)
{
    FILE *f;
    int x;
    compte_data *temp;
    temp = (compte_data *)malloc(sizeof(compte_data));
    f = fopen("record2.bin", "rb");
    while (fread(temp, sizeof(compte_data), 1, f))
    {
        if (temp->c.Id_compte_data == a)
        {
            fclose(f);
            free(temp);
            return 1;
        }
    }
    fclose(f);
    free(temp);
    return 0;
}

void search_acc()
{
    FILE *f;
    long long a;
    int x;
    client_data *temp;
    temp = (client_data *)malloc(sizeof(client_data));

re:
    gotoxy(48, 4);
    printf(" SEARCH CUSTOMER ACCOUNT ");
    gotoxy(43, 7);
    printf("Enter Your Account Number To Search : ");
    scanf("%lld", &a);
    if (chkacc(a) == 1)
    {
        f = fopen("record.bin", "rb");
        while (fread(temp, sizeof(client_data), 1, f))
        {
            if (temp->c.Id_client == a)
            {
                gotoxy(52, 21);
                printf("Account Number Matched. User is Active.");
                gotoxy(45, 10);
                printf("Detail Information of %s", strupr(temp->c.nom));
                gotoxy(37, 12);
                printf("[1] . Id compte      : %lld", temp->c.Id_client);
                gotoxy(37, 13);
                printf("[2] . Name           : %s %s", temp->c.nom, temp->c.prenom);
                gotoxy(37, 14);
                printf("[4] . Phone Number   : %s", temp->c.Num_tel);
                break;
            }
        }
        fclose(f);
    }
    if (chkacc(a) == 0)
    {
        system("CLS");
        gotoxy(52, 21);
        printf("Compte n'existe pas/Compte inactif ");
        goto re;
    }
    gotoxy(42, 24);
    printf("Appuyez sur [ENTRER] pour revenir au menu principal.");
    char z = getch();
    if (z == 13)
        MenuAdmin_Clients();
    else
        search_acc();
}
void search_name()
{
    int i = 0, b, x;
    char nom[30];
    char prenom[20];
    client_data *temp;
    temp = (client_data *)malloc(sizeof(client_data));
    gotoxy(48, 4);
    printf(" SEARCH CUSTOMER ACCOUNT ");
    gotoxy(43, 7);
    printf("Entrez votre Nom : ");
    scanf(" %[^\n]", nom);
    gotoxy(43, 10);
    printf("Entrez votre Prenom : ");
    scanf(" %[^\n]", prenom);
    FILE *f;
    f = fopen("record.bin", "rb");
    while (fread(temp, sizeof(client_data), 1, f))
    {
        b = 0;
        capitalizeFirstLetter(nom);
        capitalizeFirstLetter(prenom);
        if (strcmp(temp->c.nom, nom) == 0 && strcmp(temp->c.prenom, prenom) == 0)
        {
            gotoxy(52, 21);
            printf("Account Number Matched. User is Active.");
            gotoxy(45, 10);
            printf("Detail Information of %s", temp->c.nom);
            gotoxy(37, 12);
            printf("[1] . Account Number : %lld", temp->c.Id_client);
            gotoxy(37, 13);
            printf("[2] . Nom Complet    : %s %s", temp->c.nom, temp->c.prenom);
            gotoxy(37, 14);
            printf("[3] . Profession     :%s ", temp->c.profession);

            gotoxy(37, 15);
            printf("[4] . Numero de tel   : %s", temp->c.Num_tel);
            gotoxy(37, 16);
            // MAYBE ADD COMPTES BANCAIRES ASSOCIATED TO MY MAN
            break;
        }
        else
            b = 1;
    }
    fclose(f);
    if (b == 1)
    {
        system("cls");
        gotoxy(52, 21);
        printf("Compte N'existe pas");
        search_name();
    }
    gotoxy(42, 24);
    printf("Appuyez sur [ENTRER] pour revenir au menu principal.");
    char z = getch();
    if (z == 13)
        MenuAdmin_Clients();
    else
        search_name();
}
void delAll()
{
    char m;
    gotoxy(38, 5);
    printf("Etes vous sur supprimer tous les clients? (Y/n) : ");
    scanf(" %c", &m);
    if (m == 'y' || m == 'Y')
    {
        remove("record.bin");
        FILE *file = fopen("record.bin", "wb");
        fclose(file);
        rename("new_record.bin", "record.bin");
        gotoxy(44, 20);
        printf("Appuyez sur n'importe quelle touche pour revenir au menu principal. ");
        getch();
        MenuAdmin_Clients();
    }
    else if (m == 'n' || m == 'N')
    {
        gotoxy(44, 20);
        printf("Appuyez sur n'importe quelle touche pour revenir au menu principal.");
        getch();
        MenuAdmin_Clients();
    }
    else
    {

        gotoxy(44, 20);
        printf("Erreur,Veuillez reessayer");
        delAll();
    }
}

/*void file2list(liste *l)
{
  FILE *flist;
  ACCT d;
  flist=fopen("list.dat","rb");
  if(flist==NULL)
    return;
  if(p->st!=NULL)
    delAll(p);
  while(1)
  {
    fread(&d,sizeof(ACCT),1,flist);
     if(feof(flist))
         break;
      addEnd(p,d.acno,d.acnm,d.bal,d.pass,d.Ano,d.add,d.gender,d.mobno);
  }
  fclose(flist);
  return;
}


//fct list2file
void list2file(ELIST *p)
{
   FILE *flist;
   NODE *a=p->st;
   ACCT d;
   if(p->st==NULL)
      return;
   flist = fopen("list.dat","wb");
   while(a!=NULL)
   {
      d.acno=a->data.acno;
      strcpy(d.acnm,a->data.acnm);
      d.bal=a->data.bal;
      strcpy(d.pass,a->data.pass);
      strcpy(d.Ano,a->data.Ano);
      strcpy(d.add,a->data.add);
      d.gender=a->data.gender;
      strcpy(d.mobno,a->data.mobno);
      fwrite(&d,sizeof(ACCT),1,flist);
      a=a->next;
   }
   fclose(flist);
   return;
}
*/
void MenuAdmin_Comptes()
{
    system("CLS");
    gotoxy(48, 4);
    printf("WELCOME TO MAIN MENU");
    gotoxy(44, 8);
    printf("[1] . Consulter les Comptes");
    gotoxy(44, 9);
    printf("[2] . Ajouter un Compte Banquaire");
    gotoxy(44, 10);
    printf("[3] . Fermeture d'un Compte");
    gotoxy(44, 11);
    printf("[4] . Supprimer tous les Comptes");
    gotoxy(44, 12);
    printf("[5] . Retour ");
    gotoxy(44, 13);
    printf("[6] . Se deconnecter ");
    gotoxy(43, 20);
    printf("Please Enter Your Choice [1-6] : ");
    optionMenuAdmin_comptes();
}
void optionMenuAdmin_comptes()
{
    int w;
    if (scanf("%d", &w) != 1 || w < 0 || w > 6)
    {
        gotoxy(43, 25);
        printf("Erreur! Veuillez entrer un entier [1-4]\n");
        Sleep(2000);
        system("cls");
        MenuAdmin_Comptes();
    }
    system("cls");
    switch (w)
    {
    case 1:
        system("cls");
        viewComptes();
        break;
    case 2:
        system("cls");
        pushCompte(l2);

        break;
    case 3:
        system("cls");
        delCompte();
        break;
    case 4:
        system("cls");
        delAllComptes();
        break;
    case 5:
        system("cls");
        menuAdmin();
        break;
    case 6:
        system("cls");
        main();
        break;
    default:
        system("cls");
        MenuAdmin_Comptes(); // here again
    }
}
void pushCompte(liste2 *l2)
{
    long long idclient;
    compte *new_compte = (compte *)malloc(sizeof(compte));
    char c;
    FILE *file = fopen("record2.bin", "ab");
    long long randomId;
re:
    do
    {

        srand((unsigned)time(NULL));
        system("CLS");
        gotoxy(24, 4);
        printf("\t\t\tCREATION DE COMPTE");
        gotoxy(36, 8);
        printf("[1] . Entrer l'id du client:    ");
        scanf("%lld", &idclient);
        if (IsClientIdExistent(idclient) == 0)
        {
            gotoxy(50, 2);
            printf("Client Id errone");
            goto re;
        }
        else
        {
            new_compte->Id_compte_data = IdCreate();
            new_compte->Id_client = idclient;
            float solde;
            gotoxy(36, 9);
            printf("[2] . Entrer le solde de base: ");
            scanf(" %f", &solde);
            if (solde < 1000)
            {
                printf("Solde de base insuffisant (>1000)");
                goto re;
            }
            new_compte->solde_de_base = solde;
            new_compte->soldeNet = solde;
            int dd, mm, yy;
            char date[11];
            gotoxy(36, 10);
            printf("[3] . Entrer la date d'ouverture en Format (dd/mm/yy): ");
            scanf("%d/%d/%d", &dd, &mm, &yy);
            snprintf(date, sizeof(date), "%02d/%02d/%02d", dd, mm, yy); // concatenation
            gotoxy(50, 11);
            printf("Date: %s\n", date);
            strcpy(new_compte->date_ouverture, date);
            compte_data *new_node = (compte_data *)malloc(sizeof(compte_data));
            new_node->c = *new_compte;
            fwrite(new_node, sizeof(compte_data), 1, file);
            gotoxy(38, 17);
            printf("AJOUT DE CLIENT FAIT AVEC SUCCES");
            gotoxy(36, 19);
            printf("Voulez vous ajouter un nouveau client? (Y,n) : ");
            scanf(" %c", &c);
        }
    } while (c == 'Y' || c == 'y');
    fclose(file);
    gotoxy(40, 22);
    printf("Appuyez sur n'importe quelle touche pour revenir au menu principal.");
    getch();
    MenuAdmin_Comptes();
    char z = getch();
    if (z == 13)
    {
        main();
    }
}
void viewComptes()
{
    int i = 7;
    compte_data temp;
    FILE *f;
    // rb = reading binary
    f = fopen("record2.bin", "rb+");
    gotoxy(40, 3);
    printf("LISTE DE COMPTES");
    gotoxy(1, 5);
    printf("ID Compte");
    gotoxy(18, 5);
    printf("ID Client");
    gotoxy(34, 5);
    printf("Solde De base");
    gotoxy(90, 5);
    printf("Date Ouverture");
    // gotoxy(65, 5);
    //  printf("Operations");
    gotoxy(65, 5);
    printf("SoldeNet");

    gotoxy(5, 6);
    while (fread(&temp, sizeof(compte_data), 1, f))
    {
        gotoxy(1, i);
        printf("%lld", temp.c.Id_compte_data);
        gotoxy(18, i);
        printf("%lld", temp.c.Id_client);
        gotoxy(34, i);
        printf("%0.1f", temp.c.solde_de_base);
        gotoxy(90, i);
        printf("%s", temp.c.date_ouverture);
        gotoxy(65, i);
        printf("%0.1f", temp.c.soldeNet);
        i++;
        i++;
    }
    // close the file
    fclose(f);
    int x;
    gotoxy(42, i + 5);
    printf("Appuyez sur [ENTRER] pour revenir au menu principal.");
    x = getch();
    // 13 = '\r' i.e carriage return
    if (x == 13)
    {
        MenuAdmin_Comptes();
    }
    else
        viewComptes();
}
int chkaccCompte(long long a) // to check if a exists
{
    FILE *f;
    f = fopen("record2.bin", "rb");
    if (f == NULL)
    {
        printf("Error opening file.\n");
        return 0;
    }

    compte_data temp;

    while (fread(&temp, sizeof(compte_data), 1, f) == 1)
    {
        if (a == temp.c.Id_compte_data)
        {
            fclose(f);
            return 1;
        }
    }

    fclose(f);
    return 0;
}

void delCompte()
{
    FILE *x, *y;
    long long a;
    int c;
    compte_data *temp;
    temp = (compte_data *)malloc(sizeof(compte_data)); // Allocate memory for temp

re:
    system("CLS");
    gotoxy(48, 4);
    printf(" DELETE CUSTOMER ACCOUNT ");
    gotoxy(41, 9);
    printf("Enter Your Account Number To Delete : ");
    scanf("%lld", &a);
    if (chkaccCompte(a) == 1)
    {
        x = fopen("record2.bin", "rb");
        y = fopen("new2.bin", "wb");
        while (fread(temp, sizeof(compte_data), 1, x))
        {
            if (temp->c.Id_compte_data != a)
                fwrite(temp, sizeof(compte_data), 1, y);
        }
        fclose(x);
        fclose(y);
        x = fopen("record2.bin", "wb");
        y = fopen("new2.bin", "rb");
        while (fread(temp, sizeof(compte_data), 1, y))
            fwrite(temp, sizeof(compte_data), 1, x);
        fclose(x);
        fclose(y);
        remove("new2.bin"); // Remove the temporary file
        gotoxy(44, 15);
        printf("COMPTE SUPPRIME AVEC SUCCES");
        gotoxy(42, 18);
        printf("Appuyez sur n'importe quelle touche pour revenir au menu principal.");
        getch();
        MenuAdmin_Comptes();
    }
    else if (chkacc(a) == 0)
    {
        system("CLS");
        gotoxy(51, 15);
        printf("Compte n'existe pas");
        gotoxy(51, 16);
        printf("Appuyez sur n'importe quelle touche pour revenir reessaier");
        getch();
        goto re;
    }
    free(temp); // Free the allocated memory
    gotoxy(44, 15);
    printf("Compte supprime avec succes");
    gotoxy(42, 18);
    printf("Appuyez sur n'importe quelle touche pour revenir au menu principal.");
    getch();
    MenuAdmin_Comptes();
}
void delAllComptes()
{
    char m;
    gotoxy(38, 5);
    printf("Etes vous sur supprimer tous les clients? (Y/n) : ");
    scanf(" %c", &m);
    if (m == 'y' || m == 'Y')
    {
        remove("record2.bin");
        FILE *file = fopen("record2.bin", "wb");
        fclose(file);
        rename("new_record2.bin", "record2.bin");
        gotoxy(44, 20);
        printf("Appuyez sur n'importe quelle touche pour revenir au menu principal. ");
        getch();
        MenuAdmin_Comptes();
    }
    else if (m == 'n' || m == 'N')
    {
        gotoxy(44, 20);
        printf("Appuyez sur n'importe quelle touche pour revenir au menu principal.");
        getch();
        MenuAdmin_Comptes();
    }
    else
    {

        gotoxy(44, 20);
        printf("Erreur,Veuillez reessayer");
        delAll();
    }
}
void MenuAdmin_Operations()
{
    system("CLS");
    gotoxy(48, 4);
    printf("WELCOME TO MAIN MENU");
    gotoxy(44, 8);
    printf("[1] . Faire un Retrait");
    gotoxy(44, 9);
    printf("[2] . Faire un Virement");
    gotoxy(44, 10);
    printf("[3] . Historique des Operations");
    gotoxy(44, 11);
    printf("[4] . Vider l'Historique des Operations");
    gotoxy(44, 12);
    printf("[5] . Retour ");
    gotoxy(44, 13);
    printf("[6] . Se deconnecter ");
    gotoxy(43, 22);
    printf("Please Enter Your Choice [1-4] : ");
    optionMenuAdmin_Operations();
}
void optionMenuAdmin_Operations()
{
    int w;
    if (scanf("%d", &w) != 1 || w < 0 || w > 6)
    {
        gotoxy(43, 25);
        printf("Erreur! Veuillez entrer un entier [1-6]\n");
        Sleep(2000);
        system("cls");
        MenuAdmin_Operations();
    }
    system("cls");
    switch (w)
    {
    case 1:
        system("cls");
        Retrait();
        break;
    case 2:
        system("cls");
        Virement();
        break;
    case 3:
        system("cls");
        viewOperations();
        break;
    case 4:
        system("cls");
        delAllOperations();
    case 5:
        system("cls");
        menuAdmin();
        break;
    case 6:
        system("cls");
        main();
        break;

    default:
        MenuAdmin_Operations(); // here again
    }
}
int IsBalanceEnough(long long idcompte, long long montant) // also adds to balance if yes
{

    FILE *f, *f2;
    f = fopen("record2.bin", "rb");
    f2 = fopen("new2.bin", "wb"); // WE HERE WE FIXING THE NET BALANCE NOT CHANGING
    if (f == NULL)
    {
        printf("Error opening file.\n");
        return 0;
    }

    compte_data *temp;
    temp = (compte_data *)malloc(sizeof(compte_data));
    while (fread(temp, sizeof(compte_data), 1, f) == 1)
    {
        if (idcompte != temp->c.Id_compte_data)
        {
            fwrite(temp, sizeof(compte_data), 1, f2);
        }
        else if (idcompte == temp->c.Id_compte_data)
        {
            if (temp->c.soldeNet - montant == 0 || temp->c.soldeNet - montant <= 0)
            {
                printf("Veuillez inserer un montant valable");
                Sleep(1000);
                fclose(f);
                fclose(f2);
                Retrait(l3);
                return 0;
            }
            if (temp->c.soldeNet - montant > 0)
            {

                printf("%f", temp->c.soldeNet);
                temp->c.soldeNet = temp->c.soldeNet - (float)montant;
                gotoxy(2, 1);
                printf("%f", temp->c.soldeNet);
                fwrite(temp, sizeof(compte_data), 1, f2);
                fclose(f);
                fclose(f2);
                remove("record2.bin");
                rename("new2.bin", "record2.bin");
                gotoxy(45, 21);
                printf("RETRAIT PASSE");

                return 1;
            }
        }
    }
}
/*void RetraitExecution()
{
    FILE *x, *y;
    long long idcompte;
    int x;
    long long montant;
    compte_data *temp;
    temp = (compte_data *)malloc(sizeof(compte_data));
    if (IsBalanceEnough(idcompte, montant) == 1)
    {
        x = fopen("record2.bin", "rb");
        y = fopen("new2.bin", "wb");
        while ()
    }
}*/
void Retrait(liste3 *l3)
{
    operation *new_operation = (operation *)malloc(sizeof(operation));
    char c;
    FILE *file = fopen("record3.bin", "ab");
    long long idclient;
    long long idcompte;
    float montant;
re:
    do
    {

        system("CLS");
        gotoxy(24, 4);
        printf("\t\t\tENREGISTRER UN RETRAIT");
        gotoxy(36, 8);
        printf("[1] . Entrer l'id du client:    ");
        scanf("%lld", &idclient);
        gotoxy(36, 9);
        printf("[2] . Entrer l'id du compte:    ");
        scanf("%lld", &idcompte);
        if (IsCompteIdExistent(idcompte) == 0 || IsClientIdExistent(idclient) == 0)
        {
            gotoxy(48, 20);
            printf("Client Id ou compte id errone");
            Sleep(1000);
            goto re;
        }
        else
        {

            new_operation->id_compte = idcompte;
            new_operation->id_client = idclient;
            gotoxy(36, 10);
            long long montant;

            printf("[3] . Entrer le montant:        ");
            scanf("%lld", &montant);
            if (montant > 700)
            {
                printf("montant trop grand");
                goto re;
            }
            if (IsBalanceEnough(idcompte, montant) == 0)
            {
                gotoxy(48, 20);
                printf("Montant insuffisant");
                Sleep(1000);
                system("CLS");
                Retrait(l3);
            }
            else
            {
                new_operation->montant = -1 * montant;
                int dd, mm, yy;
                char date[11];

                gotoxy(36, 11);
                printf("[4] . Entrer la date de l'operation en Format (dd/mm/yy): ");
                scanf("%d/%d/%d", &dd, &mm, &yy);
                snprintf(date, sizeof(date), "%02d/%02d/%02d", dd, mm, yy); // concatenation
                gotoxy(50, 10);
                strcpy(new_operation->date, date);

                operation_data *new_node = (operation_data *)malloc(sizeof(operation_data));
                new_node->c = *new_operation;
                fwrite(new_node, sizeof(operation_data), 1, file);
                gotoxy(38, 17);
                printf("RETRAIT FAIT AVEC SUCCES");
                gotoxy(36, 19);
                printf("Voulez vous ajouter un nouveau retrait? (Y,n) : ");
                scanf(" %c", &c);
            }
        }
    } while (c == 'Y' || c == 'y');
    fclose(file);
    gotoxy(40, 22);
    printf("Appuyez sur n'importe quelle touche pour revenir au menu principal.");
    getch();
    MenuAdmin_Operations();
    char z = getch();
    if (z == 13)
    {
        main();
    }
}
int AddToBalance(long long idcompte, long long montant) // also adds to balance if yes
{

    FILE *f, *f2;
    f = fopen("record2.bin", "rb");
    f2 = fopen("new2.bin", "wb"); // WE HERE WE FIXING THE NET BALANCE NOT CHANGING
    if (f == NULL)
    {
        printf("Error opening file.\n");
        return 0;
    }

    compte_data *temp;
    temp = (compte_data *)malloc(sizeof(compte_data));
    while (fread(temp, sizeof(compte_data), 1, f) == 1)
    {
        if (idcompte != temp->c.Id_compte_data)
        {
            fwrite(temp, sizeof(compte_data), 1, f2);
        }
        else if (idcompte == temp->c.Id_compte_data)
        {
            if (temp->c.soldeNet + montant == 0 || temp->c.soldeNet + montant <= 0)
            {
                printf("Veuillez inserer un montant valable");
                Sleep(1000);
                fclose(f);
                fclose(f2);
                Retrait(l3);
                return 0;
            }
            if (temp->c.soldeNet + montant > 0)
            {

                printf("%f", temp->c.soldeNet);
                temp->c.soldeNet = temp->c.soldeNet + (float)montant;
                gotoxy(2, 1);
                printf("%f", temp->c.soldeNet);
                fwrite(temp, sizeof(compte_data), 1, f2);
                fclose(f);
                fclose(f2);
                remove("record2.bin");
                rename("new2.bin", "record2.bin");
                gotoxy(45, 21);
                printf("VIREMENT PASSE");

                return 1;
            }
        }
    }
}

void Virement()
{
    operation *new_operation = (operation *)malloc(sizeof(operation));
    char c;
    FILE *file = fopen("record3.bin", "ab");
    long long idclient;
    long long idcompte;
    float montant;
re:
    do
    {

        system("CLS");
        gotoxy(24, 4);
        printf("\t\t\tENREGISTRER UN VIREMENT");
        gotoxy(36, 8);
        printf("[1] . Entrer l'id du client:    ");
        scanf("%lld", &idclient);
        gotoxy(36, 9);
        printf("[2] . Entrer l'id du compte:    ");
        scanf("%lld", &idcompte);
        if (IsCompteIdExistent(idcompte) == 0 || IsClientIdExistent(idclient) == 0)
        {
            gotoxy(48, 20);
            printf("Client Id ou compte id errone");
            Sleep(1000);
            goto re;
        }
        else
        {

            new_operation->id_compte = idcompte;
            new_operation->id_client = idclient;
            gotoxy(36, 10);
            long long montant;

            printf("[3] . Entrer le montant:        ");
            scanf("%lld", &montant);
            if (AddToBalance(idcompte, montant) == 0)
            {
                gotoxy(48, 20);
                printf("Montant insuffisant");
                Sleep(1000);
                system("CLS");
                Virement(l3);
            }
            else
            {
                new_operation->montant = montant;
                int dd, mm, yy;
                char date[11];

                gotoxy(36, 11);
                printf("[4] . Entrer la date de l'operation en Format (dd/mm/yy): ");
                scanf("%d/%d/%d", &dd, &mm, &yy);
                snprintf(date, sizeof(date), "%02d/%02d/%02d", dd, mm, yy); // concatenation
                gotoxy(50, 10);
                strcpy(new_operation->date, date);

                operation_data *new_node = (operation_data *)malloc(sizeof(operation_data));
                new_node->c = *new_operation;
                fwrite(new_node, sizeof(operation_data), 1, file);
                gotoxy(38, 17);
                printf("VIREMENT FAIT AVEC SUCCES");
                gotoxy(36, 19);
                printf("Voulez vous ajouter un nouveau VIREMENT? (Y,n) : ");
                scanf(" %c", &c);
            }
        }
    } while (c == 'Y' || c == 'y');
    fclose(file);
    gotoxy(40, 22);
    printf("Appuyez sur n'importe quelle touche pour revenir au menu principal. ");
    getch();
    MenuAdmin_Operations();
    char z = getch();
    if (z == 13)
    {
        main();
    }
}
void viewOperations()
{
    int i = 7;
    operation_data temp;
    FILE *f;
    // rb = reading binary
    f = fopen("record3.bin", "rb");
    gotoxy(40, 3);
    printf("LISTE DE COMPTES");
    gotoxy(1, 5);
    printf("ID Compte");
    gotoxy(18, 5);
    printf("ID Client");
    gotoxy(34, 5);
    printf("Montant");
    gotoxy(65, 5);
    printf("Date");

    gotoxy(5, 6);
    while (fread(&temp, sizeof(operation_data), 1, f))
    {
        gotoxy(1, i);
        printf("%lld", temp.c.id_compte);
        gotoxy(18, i);
        printf("%lld", temp.c.id_client);
        gotoxy(34, i);
        printf("%0.1lld", temp.c.montant);
        gotoxy(65, i);
        printf("%s", temp.c.date);
        i++;
        i++;
    }
    // close the file
    fclose(f);
    int x;
    gotoxy(42, i + 5);
    printf("Appuyez sur n'importe quelle touche pour revenir au menu principal.");
    x = getch();

    if (x == 13)
    {
        MenuAdmin_Operations();
    }
    else
        viewOperations();
}
void delAllOperations()
{
    char m;
    gotoxy(38, 5);
    printf("Etes vous sur de vider l'Historique des Operations? (Y/n) : ");
    scanf(" %c", &m);
    if (m == 'y' || m == 'Y')
    {
        remove("record3.bin");
        FILE *file = fopen("record3.bin", "wb");
        fclose(file);
        rename("new_record3.bin", "record3.bin");
        gotoxy(44, 20);
        printf("Appuyez sur n'importe quelle touche pour revenir au menu principal.");
        getch();
        MenuAdmin_Operations();
    }
    else if (m == 'n' || m == 'N')
    {
        gotoxy(44, 20);
        printf("Appuyez sur n'importe quelle touche pour revenir au menu principal.");
        getch();
        MenuAdmin_Operations();
    }
    else
    {

        gotoxy(44, 20);
        printf("Erreur,Veuillez reessayer");
        delAllOperations();
    }
}
void MenuUser()
{
    system("CLS");
    gotoxy(48, 4);
    printf("BIENVENUE AU MENU CLIENTELE");
    gotoxy(44, 8);
    printf("[1] . Visionner mes comptes");
    gotoxy(44, 9);
    printf("[2] . Faire un transfert D'argent (PAS ENCORE DISPO)");
    gotoxy(44, 10);
    printf("[3] . Visionner mes informations");
    gotoxy(44, 11);
    printf("[4] . Se deconnecter");
    gotoxy(43, 21);
    printf("Veuillez entrer votre Choix [1-4] : ");

    optionMenuUser();
    // option(); need another option function
}
void optionMenuUser()
{
    int w;
    if (scanf("%d", &w) != 1 || w < 0 || w > 4)
    {
        gotoxy(43, 25);
        printf("Erreur! Veuillez entrer un entier [1-4]\n");
        Sleep(2000);
        system("cls");
        MenuUser();
    }
    system("cls");
    switch (w)
    {
    case 1:
        system("cls");
        ViewComptesUser();
        break;
    case 2:
        system("cls");
        Transfert();
        break;
    case 3:
        system("cls");
        searchAccUser();
        break;
    case 4:
        system("cls");
        main();
        break;
    default:
        system("cls");
        MenuUser();
    }
}
int j = 0;
void ViewComptesUser()
{
re:
    int i = 7;
    long long a;
    gotoxy(48, 4);
    printf(" SEARCH CUSTOMER ACCOUNT ");
    gotoxy(43, 7);
    printf("Veuillez entrer votre client id: ");
    scanf("%lld", &a);
    if (chkacc(a) == 0)
    {
        printf("client id errone ou n'existe pas");
        Sleep(2000);
        goto re;
    }
    else
    {
        system("cls");

        compte_data temp;
        FILE *f;
        // rb = reading binary
        f = fopen("record2.bin", "rb");
        gotoxy(40, 3);
        printf("LISTE DE COMPTES");
        gotoxy(1, 5);
        printf("ID Compte");
        gotoxy(18, 5);
        printf("ID Client");
        gotoxy(34, 5);
        printf("Solde De base");
        gotoxy(90, 5);
        printf("Date Ouverture");
        gotoxy(65, 5);
        printf("SoldeNet");

        gotoxy(5, 6);
        while (fread(&temp, sizeof(compte_data), 1, f) == 1)
        {
            if (temp.c.Id_client == a)
            {
                gotoxy(1, i);
                printf("%lld", temp.c.Id_compte_data);
                gotoxy(18, i);
                printf("%lld", temp.c.Id_client);
                gotoxy(34, i);
                printf("%0.1f", temp.c.solde_de_base);
                gotoxy(90, i);
                printf("%s", temp.c.date_ouverture);
                gotoxy(65, i);
                printf("%0.1f", temp.c.soldeNet);
                i++;
                i++;
            }
        }
        fclose(f);
    }
    gotoxy(42, i + 5);
    printf("Appuyez sur n'importe quelle touche pour revenir au menu principal.");
    int x;
    x = getch();
    // 13 = '\r' i.e carriage return
    if (x == 13)
    {
        MenuUser();
    }
    else
        viewOperations();
}
void searchAccUser()
{
    FILE *f;
    long long a;
    int x;
    client_data *temp;
    temp = (client_data *)malloc(sizeof(client_data));

re:
    gotoxy(48, 4);
    printf(" VOS DONNES ");
    gotoxy(43, 7);
    printf("Veuillez entrer votre client id : ");
    scanf("%lld", &a);
    if (chkacc(a) == 1)
    {
        f = fopen("record.bin", "rb");
        while (fread(temp, sizeof(client_data), 1, f))
        {
            if (temp->c.Id_client == a)
            {
                gotoxy(52, 21);
                printf("Compte Trouve.");
                gotoxy(45, 10);
                printf("Informations du compte de MR/MME %s", strupr(temp->c.nom));
                gotoxy(37, 12);
                printf("[1] . Id compte      : %lld", temp->c.Id_client);
                gotoxy(37, 13);
                printf("[2] . Nom Complet           : %s %s", temp->c.nom, temp->c.prenom);
                gotoxy(37, 14);
                printf("[3] . Numero de Telephone   : %s", temp->c.Num_tel);
                break;
            }
        }
        fclose(f);
    }
    if (chkacc(a) == 0)
    {
        system("CLS");
        gotoxy(52, 21);
        printf("Compte N'existe Pas/Pas actif ");
        goto re;
    }
    gotoxy(42, 24);
    printf("Appuyer sur [ENTER] pour returner au menu. ");
    char z = getch();
    if (z == 13)
        MenuUser();
    else
        searchAccUser();
}
void Transfert()
{
re:
    system("cls");
    long long idcompteReceiver, idclientReceiver, idcompteSender, idclientSender;
    float montant;
    gotoxy(24, 4);
    printf("\t\t\tTRANSFERT VERS CLIENT");
    gotoxy(36, 8);
    printf("[1] . Entrer votre client id:    ");
    scanf("%lld", &idclientSender);
    gotoxy(36, 9);
    printf("[2] . Entrer votre compte id:    ");
    scanf("%lld", &idcompteSender);
    gotoxy(36, 10);
    printf("[3] . Entrer le client id de la personne a qui vous voulez faire un virement:    ");
    scanf("%lld", &idcompteReceiver);
    gotoxy(36, 11);
    printf("[4] . Entrer leur compte id:");
    scanf("%lld", &idcompteReceiver);
    gotoxy(36, 12);
    printf("[6] . Entrer le montant :");
    scanf("%lld", &montant);
    FILE *f, *f2;
    f = fopen("record2.bin", "rb");
    f2 = fopen("new2.bin", "wb"); // WE HERE WE FIXING THE NET BALANCE NOT CHANGING
    if (f == NULL)
    {
        printf("Error opening file.\n");
        Sleep(10000);
        Transfert();
    }

    compte_data *temp;
    temp = (compte_data *)malloc(sizeof(compte_data));
    if (IsCompteIdExistent(idcompteSender) == 0 || IsClientIdExistent(idclientSender) == 0)
    {
        gotoxy(48, 20);
        printf("Votre client Id ou compte id errone");
        Sleep(1000);
        goto re;
    }
    else
    {
        if (IsBalanceEnough2(idcompteSender, montant) == 0)
        {
            gotoxy(48, 20);
            printf("Montant insuffisant");
            Sleep(1000);
            system("CLS");
            Transfert();
        }
        else
        {

            gotoxy(38, 17);
            printf("RETRAIT FAIT AVEC SUCCES");
        }
    }
    AddToBalance2(idcompteReceiver, idclientReceiver, montant);
    gotoxy(40, 22);
    printf("Appuyez sur n'importe quelle touche pour revenir au menu principal.");
    getch();
    MenuUser();
    char z = getch();
    if (z == 13)
    {
        main();
    }
}
int AddToBalance2(long long idcompte, long long idclient, long long montant) // also adds to balance if yes
{

    FILE *f, *f2;
    f = fopen("record2.bin", "rb");
    f2 = fopen("new2.bin", "wb"); // WE HERE WE FIXING THE NET BALANCE NOT CHANGING
    if (f == NULL)
    {
        printf("Error opening file.\n");
        return 0;
    }
    if (IsCompteIdExistent(idcompte) == 0 || IsClientIdExistent(idclient) == 0)
    {
        gotoxy(48, 20);
        printf("Client Id ou compte id errone");
        Sleep(1000);
        Transfert();
    }
    else
    {

        compte_data *temp;
        temp = (compte_data *)malloc(sizeof(compte_data));
        while (fread(temp, sizeof(compte_data), 1, f) == 1)
        {
            if (idcompte != temp->c.Id_compte_data)
            {
                fwrite(temp, sizeof(compte_data), 1, f2);
            }
            else if (idcompte == temp->c.Id_compte_data)
            {
                if (temp->c.soldeNet + montant == 0 || temp->c.soldeNet + montant <= 0)
                {
                    system("cls");
                    printf("Veuillez inserer un montant valable");
                    Sleep(1000);
                    fclose(f);
                    fclose(f2);
                    Transfert();
                    return 0;
                }
                if (temp->c.soldeNet + montant > 0)
                {

                    printf("%f", temp->c.soldeNet);
                    temp->c.soldeNet = temp->c.soldeNet + (float)montant;
                    gotoxy(2, 1);
                    printf("%f", temp->c.soldeNet);
                    fwrite(temp, sizeof(compte_data), 1, f2);
                    fclose(f);
                    fclose(f2);
                    remove("record2.bin");
                    rename("new2.bin", "record2.bin");
                    gotoxy(45, 21);
                    printf("VIREMENT PASSE");

                    return 1;
                }
            }
        }
    }
}
int IsBalanceEnough2(long long idcompte, long long montant) // also adds to balance if yes
{

    FILE *f, *f2;
    f = fopen("record2.bin", "rb");
    f2 = fopen("new2.bin", "wb"); // WE HERE WE FIXING THE NET BALANCE NOT CHANGING
    if (f == NULL)
    {
        printf("Error opening file.\n");
        return 0;
    }

    compte_data *temp;
    temp = (compte_data *)malloc(sizeof(compte_data));
    while (fread(temp, sizeof(compte_data), 1, f) == 1)
    {
        if (idcompte != temp->c.Id_compte_data)
        {
            fwrite(temp, sizeof(compte_data), 1, f2);
        }
        else if (idcompte == temp->c.Id_compte_data)
        {
            if (temp->c.soldeNet - montant == 0 || temp->c.soldeNet - montant <= 0)
            {
                printf("Veuillez inserer un montant valable");
                Sleep(1000);
                fclose(f);
                fclose(f2);
                Transfert();
                return 0;
            }
            if (temp->c.soldeNet - montant > 0)
            {

                printf("%f", temp->c.soldeNet);
                temp->c.soldeNet = temp->c.soldeNet - (float)montant;
                gotoxy(2, 1);
                printf("%f", temp->c.soldeNet);
                fwrite(temp, sizeof(compte_data), 1, f2);
                fclose(f);
                fclose(f2);
                remove("record2.bin");
                rename("new2.bin", "record2.bin");
                gotoxy(45, 21);
                printf("RETRAIT PASSE");

                return 1;
            }
        }
    }
}
void about()
{
    system("cls");
    gotoxy(48, 5);
    printf("!!!SUR NOUS!!!");
    gotoxy(32, 7);
    printf("Ce projet a ete realise par Nassim Lachkar et co");
    gotoxy(10, 8);
    printf("Il s'agit d'un projet simple de gestion bancaire pour mon quatrieme semestre base ");
    gotoxy(32, 9);
    printf("sur le langage de programmation C.");
    gotoxy(40, 20);
    printf("Appuyez sur n'importe quelle touche pour revenir au menu principal.");
    char z = getch();
    if (z == 13)
        main();
}
