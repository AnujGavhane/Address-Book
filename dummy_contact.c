#include "contact.h"

// Dummy contact data
Contact dummyContacts[] = {
    {"John Doe", "1234567890", "john@example.com"},
    {"Alice Smith", "0987654321", "alice@example.com"},
    {"Bob Johnson", "1112223333", "bob@company.com"},
    {"Carol White", "4445556666", "carol@company.com"},
    {"David Brown", "7778889999", "david@example.com"},
    {"Eve Davis", "6665554444", "eve@example.com"},
    {"Frank Miller", "3334445555", "frank@example.com"},
    {"Grace Wilson", "2223334444", "grace@example.com"},
    {"Hannah Clark", "5556667777", "hannah@example.com"},
    {"Ian Lewis", "8889990000", "ian@example.com"}
};

// Load dummy contacts without duplicates
void loadDummyContacts(AddressBook *addressBook) {
    for (int i = 0; i < 10 && addressBook->contactCount < MAX_CONTACTS; i++) {
        int exists = 0;
        for (int j = 0; j < addressBook->contactCount; j++) {
            if (strcmp(addressBook->contacts[j].name, dummyContacts[i].name) == 0 &&
                strcmp(addressBook->contacts[j].phone, dummyContacts[i].phone) == 0) {
                exists = 1;
                break;
            }
        }
        if (!exists) {
            addressBook->contacts[addressBook->contactCount++] = dummyContacts[i];
        }
    }
}

// Simple email validation
int validateEmail(const char *email) {
    if (email == NULL) return 0;
    const char *at = strchr(email, '@');
    const char *dot = strrchr(email, '.');
    return (at && dot && at < dot);  // '@' must appear before last '.'
}
