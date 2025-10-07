#include "contact.h"
#include <ctype.h>

// Validate phone number (10 digits)
int validatePhone(const char *phone) {
    if (strlen(phone) != 10) return 0;
    for (int i = 0; i < 10; i++) {
        if (!isdigit(phone[i])) return 0;
    }
    return 1;
}

// Initialize address book
void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    loadDummyContacts(addressBook);
    loadContactsFromFile(addressBook);
}

// Create new contact with duplicate check
void createContact(AddressBook *addressBook) {
    if (addressBook->contactCount >= MAX_CONTACTS) {
        printf("Address book is full!\n");
        return;
    }

    Contact c;
    printf("Enter name: ");
    fgets(c.name, sizeof(c.name), stdin);
    c.name[strcspn(c.name, "\n")] = '\0';

    printf("Enter phone: ");
    fgets(c.phone, sizeof(c.phone), stdin);
    c.phone[strcspn(c.phone, "\n")] = '\0';
    if (!validatePhone(c.phone)) {
        printf("Invalid phone number.\n");
        return;
    }

    printf("Enter email: ");
    fgets(c.email, sizeof(c.email), stdin);
    c.email[strcspn(c.email, "\n")] = '\0';
    if (!validateEmail(c.email)) {
        printf("Invalid email format.\n");
        return;
    }

    // Check for duplicates
    for (int i = 0; i < addressBook->contactCount; i++) {
        if (strcmp(addressBook->contacts[i].name, c.name) == 0 &&
            strcmp(addressBook->contacts[i].phone, c.phone) == 0) {
            printf("Warning: Contact already exists! Not added.\n");
            return;
        }
    }

    // Add contact
    addressBook->contacts[addressBook->contactCount++] = c;
    printf("Contact added successfully!\n");
}

// List all contacts
void listContacts(AddressBook *addressBook) {
    if (addressBook->contactCount == 0) {
        printf("No contacts available.\n");
        return;
    }

    printf("\nNo  Name                 Phone           Email\n");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < addressBook->contactCount; i++) {
        printf("%-3d %-20s %-15s %-30s\n", i + 1,
               addressBook->contacts[i].name,
               addressBook->contacts[i].phone,
               addressBook->contacts[i].email);
    }
}

// Search contact
void searchContact(AddressBook *addressBook) {
    char query[50];
    int choice;
    printf("Search By:\n1. Name\n2. Phone\n3. Email\nEnter your choice: ");
    scanf("%d", &choice);
    getchar();

    printf("Enter value: ");
    fgets(query, sizeof(query), stdin);
    query[strcspn(query, "\n")] = '\0';

    for (int i = 0; i < addressBook->contactCount; i++) {
        if ((choice == 1 && strcmp(addressBook->contacts[i].name, query) == 0) ||
            (choice == 2 && strcmp(addressBook->contacts[i].phone, query) == 0) ||
            (choice == 3 && strcmp(addressBook->contacts[i].email, query) == 0)) {
            printf("Found: %s | %s | %s\n",
                   addressBook->contacts[i].name,
                   addressBook->contacts[i].phone,
                   addressBook->contacts[i].email);
            return;
        }
    }
    printf("Contact not found!\n");
}

// Edit contact
void editContact(AddressBook *addressBook) {
    char query[50];
    printf("Enter the name of the contact to edit: ");
    fgets(query, sizeof(query), stdin);
    query[strcspn(query, "\n")] = '\0';

    for (int i = 0; i < addressBook->contactCount; i++) {
        if (strcmp(addressBook->contacts[i].name, query) == 0) {
            char input[50];

            printf("Enter new name (leave blank to keep same): ");
            fgets(input, sizeof(input), stdin);
            if (strcmp(input, "\n") != 0) {
                input[strcspn(input, "\n")] = '\0';
                strcpy(addressBook->contacts[i].name, input);
            }

            printf("Enter new phone (leave blank to keep same): ");
            fgets(input, sizeof(input), stdin);
            if (strcmp(input, "\n") != 0) {
                input[strcspn(input, "\n")] = '\0';
                strcpy(addressBook->contacts[i].phone, input);
            }

            printf("Enter new email (leave blank to keep same): ");
            fgets(input, sizeof(input), stdin);
            if (strcmp(input, "\n") != 0) {
                input[strcspn(input, "\n")] = '\0';
                strcpy(addressBook->contacts[i].email, input);
            }

            printf("Contact updated successfully.\n");
            return;
        }
    }
    printf("Contact not found!\n");
}

// Delete contact
void deleteContact(AddressBook *addressBook) {
    char query[50];
    printf("Enter the name of the contact to delete: ");
    fgets(query, sizeof(query), stdin);
    query[strcspn(query, "\n")] = '\0';

    for (int i = 0; i < addressBook->contactCount; i++) {
        if (strcmp(addressBook->contacts[i].name, query) == 0) {
            for (int j = i; j < addressBook->contactCount - 1; j++) {
                addressBook->contacts[j] = addressBook->contacts[j + 1];
            }
            addressBook->contactCount--;
            printf("Contact deleted successfully.\n");
            return;
        }
    }
    printf("Contact not found!\n");
}

// Load contacts from file with duplicate check
void loadContactsFromFile(AddressBook *addressBook) {
    FILE *fp = fopen("contacts.csv", "r");
    if (!fp) return;

    char line[150];
    fgets(line, sizeof(line), fp); // skip header

    while (fgets(line, sizeof(line), fp)) {
        Contact c;
        char *token = strtok(line, ",");
        if (token) strcpy(c.name, token);

        token = strtok(NULL, ",");
        if (token) strcpy(c.phone, token);

        token = strtok(NULL, ",\n");
        if (token) strcpy(c.email, token);

        int exists = 0;
        for (int i = 0; i < addressBook->contactCount; i++) {
            if (strcmp(addressBook->contacts[i].name, c.name) == 0 &&
                strcmp(addressBook->contacts[i].phone, c.phone) == 0) {
                exists = 1;
                break;
            }
        }

        if (!exists && addressBook->contactCount < MAX_CONTACTS) {
            addressBook->contacts[addressBook->contactCount++] = c;
        }
    }
    fclose(fp);
}

// Save contacts to file
void saveContactsToFile(AddressBook *addressBook) {
    FILE *fp = fopen("contacts.csv", "w");
    if (!fp) {
        printf("Error saving contacts!\n");
        return;
    }

    fprintf(fp, "Name,Phone,Email\n");
    for (int i = 0; i < addressBook->contactCount; i++) {
        fprintf(fp, "%s,%s,%s\n",
                addressBook->contacts[i].name,
                addressBook->contacts[i].phone,
                addressBook->contacts[i].email);
    }

    fclose(fp);
    printf("Contacts saved to contacts.csv successfully!\n");
}
