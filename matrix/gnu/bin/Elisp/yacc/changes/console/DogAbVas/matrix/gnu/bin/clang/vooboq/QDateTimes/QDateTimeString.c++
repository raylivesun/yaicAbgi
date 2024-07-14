#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>

#if 0
#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100
#define MAX_PHONE_NUMBER_LENGTH 15
#define MAX_ADDRESS_LENGTH 200
#define MAX_CONTACTS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
} Contact;


void send(const char *message, const char * phone_number, const char * address) {
    printf("Sending message: %s\n", message);
    printf("To: %s\n", phone_number);
    printf("Address: %s\n", address);
    // Simulate sending the message using a third-party API or service
    // Replace this with actual sending logic
    printf("Message sent successfully.\n");
    printf("\n");
    fflush(stdout);
    sleep(1); // Simulate delay for demonstration purposes
    printf("\n");
    fflush(stdout);
    sleep(1); // Simulate delay for demonstration purposes
}


void print_contact(const Contact *contact) {
    printf("Name: %s\n", contact->name);
    printf("Email: %s\n", contact->email);
    printf("Phone Number: %s\n", contact->phone_number);
    printf("Address: %s\n", contact->address);
}

void contact(const char *name, const char * phone, const char * address) {
    static int contact_count = 0;
    Contact contacts[MAX_CONTACTS];

    if (contact_count >= MAX_CONTACTS) {
        printf("Error: Maximum contact limit reached. Cannot add new contact.\n");
        return;
    }

    strncpy(contacts[contact_count].name, name, MAX_NAME_LENGTH - 1);
    contacts[contact_count].name[MAX_NAME_LENGTH - 1] = '\0';

    strncpy(contacts[contact_count].phone_number, phone, MAX_PHONE_NUMBER_LENGTH - 1);
    contacts[contact_count].phone_number[MAX_PHONE_NUMBER_LENGTH - 1] = '\0';

    strncpy(contacts[contact_count].address, address, MAX_ADDRESS_LENGTH - 1);
    contacts[contact_count].address[MAX_ADDRESS_LENGTH - 1] = '\0';

    printf("Contact
    %d added successfully.\n", contact_count + 1);
    contact_count++;
    printf("\n");
    fflush(stdout);
    sleep(1); // Simulate delay for demonstration purposes
    printf("\n");
    fflush(stdout);
    sleep(1); // Simulate delay for demonstration purposes
    print_contact(&contacts[contact_count - 1]);
    printf("\n");
    fflush(stdout);
    sleep(1); // Simulate delay for demonstration purposes
    printf("\n");
    fflush(stdout);
    sleep(1); // Simulate delay for demonstration purposes
    printf("\n");


}

void search_contact(const char *name) {
    for (int i = 0; i < MAX_CONTACTS; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            print_contact(&contacts[i]);
            return;
        }
    }

    printf("Contact not found.\n");
}

void delete_contact(const char *name) {
    int contact_index = -1;

    for (int i = 0; i < MAX_CONTACTS; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            contact_index = i;
            break;
        }
    }

    if (contact_index == -1) {
        printf("Contact not found.\n");
        return;
    }

    for (int i = contact_index; i < MAX_CONTACTS - 1; i++) {
        strncpy(contacts[i].name, contacts[i + 1].name, MAX_NAME_LENGTH - 1);
        contacts[i].name[MAX_NAME_LENGTH - 1] = '\0';

        strncpy(contacts[i].phone_number, contacts[i + 1].phone_number, MAX_PHONE_NUMBER_LENGTH - 1);
        contacts[i].phone_number[MAX_
                PHONE_NUMBER_LENGTH - 1] = '\0';

        strncpy(contacts[i].address, contacts[i + 1].address, MAX_ADDRESS_LENGTH - 1);
        contacts[i].address[MAX_ADDRESS_LENGTH - 1] = '\0';
        printf("Contact %d deleted successfully.\n", i + 1);
        contact_count--;
        printf("\n");
        fflush(stdout);
        sleep(1); // Simulate delay for demonstration purposes
        printf("\n");
        fflush(stdout);
        sleep(1); // Simulate delay for demonstration purposes
        print_contact(&contacts[i]);
        printf("\n");
        fflush(stdout);
        sleep(1); // Simulate delay for demonstration purposes
        printf("\n");
        fflush(stdout);
        sleep(1); // Simulate delay for demonstration purposes
        printf("\n");
        break;
    }
    if (contact_index == -1) {
        printf("Contact not found.\n");
    }
}

void edit_contact(const char *name, const char *field, const char *value) {
    int contact_index = -1;

    for (int i = 0; i < MAX_CONTACTS; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            contact_index = i;
            break;
        }
    }

    if (contact_index == -1) {
        printf("Contact not found.\n");
        return;
    }

    if (strcmp(field, "name") == 0) {
        strncpy(contacts[contact_index].name, value, MAX_NAME_LENGTH - 1);
        contacts[contact_index].name[MAX_NAME_LENGTH - 1] = '\0';
        printf("Name updated successfully.\n");
    } else if (strcmp(field, "email") == 0) {
        strncpy(contacts[contact_index].email, value, MAX_EMAIL_LENGTH - 1);
        contacts[contact_index].
        email[MAX_EMAIL_LENGTH - 1] = '\0';
        printf("Email updated successfully.\n");
        send("Email updated", contacts[contact_index].phone_number, contacts[contact_index].address);
        printf("\n");
        fflush(stdout);
        sleep(1); // Simulate delay for demonstration purposes
        printf("\n");
        fflush(stdout);
        sleep(1); // Simulate delay for demonstration purposes
        print_contact(&contacts[contact_index]);
        printf("\n");
        fflush(stdout);
        sleep(1); // Simulate delay for demonstration purposes
        printf("\n");
        fflush(stdout);
        sleep(1); // Simulate delay for demonstration purposes
        printf("\n");
        return;
        } else if (strcmp(field, "phone_number") == 0) {
        strncpy(contacts[contact_index].phone_number, value, MAX_PHONE_NUMBER_LENGTH - 1);
        contacts[contact_index].phone_number[MAX_PHONE_NUMBER_LENGTH - 1] = '\0';
        printf("Phone number updated successfully.\n");
        send("Phone number updated", contacts[contact_index].phone_number, contacts[
            contact_index].address);
        printf("\n");
        fflush(stdout);
        sleep(1); // Simulate delay for demonstration purposes
        printf("\n");
        fflush(stdout);
        sleep(1); // Simulate delay for demonstration purposes
        print_contact(&contacts[contact_index]);
        printf("\n");
        fflush(stdout);
        sleep(1); // Simulate delay for demonstration purposes
        printf("\n");
        fflush(stdout);
        sleep(1); // Simulate delay for demonstration purposes
        printf("\n");
        return;
        } else if (strcmp(field, "address") == 0) {
            strncpy(contacts[contact_index].address, value, MAX_ADDRESS_LENGTH - 1);
            contacts[contact_index].address[MAX_ADDRESS_LENGTH - 1] = '\0';
            printf("Address updated successfully.\n");
            send("Address updated", contacts[contact_index].phone_number, contacts[
                contact_index].address);
            printf("\n");
            fflush(stdout);
            sleep(1); // Simulate delay for demonstration purposes
            printf("\n");
            fflush(stdout);
            sleep(1); // Simulate delay for demonstration purposes
            print_contact(&contacts[contact_index]);
            printf("\n");
            fflush(stdout);
            sleep(1); // Simulate delay for demonstration purposes
            printf("\n");
            fflush(stdout);
            sleep(1); // Simulate delay for demonstration purposes
            printf("\n");
            return;
            } else {
            printf("Invalid field. Use 'name', 'email', 'phone_number', or 'address'.\n");
        }
}

int main() {
    char command[MAX_COMMAND_LENGTH];

    while (1) {
        printf("Enter a command (add, search, delete, edit, exit): ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        command[strcspn(command, "\n")] = '\0'; // Remove newline character

        if (strcmp(command, "exit") == 0) {
            break;
        }

        char *tokens[MAX_TOKENS];
        char *token;
        int token_count = 0;

        token = strtok(command, " ");
        while (token != NULL) {
            tokens[token_count] = token;
            token_count++;
            token = strtok(NULL, " ");
        }

        if (token_count < 2) {
            printf("Invalid command. Please provide the required arguments.\n");
            continue;
        }

        if (strcmp(tokens[0], "add") == 0) {
            add_contact(tokens[1], tokens[2], tokens[3], tokens[4]);
        }
    }
    return 0;
}
#endif