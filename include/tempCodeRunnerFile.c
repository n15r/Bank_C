ch;
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