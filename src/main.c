#include <stdio.h>
#include "../include/mclients.h"
#include <stdlib.h>
#include <string.h>

int main()
{
    liste my_list;
    my_list.first = NULL;
    my_list.last = NULL;

    // Add some clients to the list
    push(&my_list, 1, "Smith", "John", "Engineer", "1234567890");
    push(&my_list, 2, "Johnson", "Jane", "Doctor", "9876543210");

    // Test modify function
    int client_id;
    printf("Enter the client ID: ");
    scanf("%d", &client_id);

    modify(&my_list, client_id);

    // Print the modified list
    client_data *ptr = my_list.first;
    while (ptr != NULL)
    {
        printf("ID: %d, Name: %s %s, Profession: %s, Phone: %s\n",
               ptr->Id_client, ptr->nom, ptr->prenom, ptr->profession, ptr->Num_tel);
        ptr = ptr->next;
    }

    return 0;
}
