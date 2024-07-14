#include <string.h>
#include <stdio.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 200

typedef struct {
    char name[MAX_NAME_LENGTH + 1];
    char email[MAX_EMAIL_LENGTH + 1];
} Yacc;

void sort_console(Yacc console[], int num_console) {
    for (int i = 0; i < num_console - 1; i++) {
        for (int j = 0; j < num_console - i - 1; j++) {
            if (strcmp(console[j].name, console[j + 1].name) > 0) {
                Yacc temp = console[j];
                console[j] = console[j + 1];
                console[j + 1] = temp;
            }
        }
    }
}

void print_console(Yacc console[], int num_console) {
    for (int i = 0; i < num_console; i++) {
        printf("Name: %s\nEmail: %s\n", console[i].name, console[i].email);
    }
}

int main() {
    int num_console;
    printf("Enter the number of console: ");
    scanf("%d", &num_console);

    Yacc console[num_console];

    for (int i = 0; i < num_console; i++) {
        printf("Enter name for Yacc %d: ", i + 1);
        scanf("%s", console[i].name);
        printf("Enter email for Yacc %d: ", i + 1);
        scanf("%s", console[i].email);
    }

    sort_console(console, num_console);
    printf("\nSorted console:\n");
    print_console(console, num_console);

    return 0;
}
