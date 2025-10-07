#include "contact.h"
#include <stdlib.h>

int main() {
    AddressBook addressBook;
    initialize(&addressBook);

    int choice;
    while (1) {
        printf("\n===== Address Book =====\n");
        printf("1. Create Contact\n");
        printf("2. Edit Contact\n");
        printf("3. Delete Contact\n");
        printf("4. Search Contact\n");
        printf("5. List Contacts\n");
        printf("6. Save & Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1: createContact(&addressBook); break;
            case 2: editContact(&addressBook); break;
            case 3: deleteContact(&addressBook); break;
            case 4: searchContact(&addressBook); break;
            case 5: listContacts(&addressBook); break;
            case 6:
                saveContactsToFile(&addressBook);
                printf("Exiting...\n");
                exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
