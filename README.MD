# yaicAbgi bison yacc (https://www.gnu.org/software/bison/manual/bison.html)

Yaicabgi bison yacc is a parser generator tool, commonly used in the field of compiler construction. It is a part of the GNU Project and is based on the well-known tool, Bison (Yacc is another name for Bison). The provided link (https://www.gnu.org/software/bison/manual/bison.html) directs to the official documentation of Bison, which includes a comprehensive manual on using Bison for creating parsers.

# Elisp code console yacc (https://www.gnu.org/software/emacs/manual/html_node/eintr/)

Elisp code console yacc is not a parser generator tool like yaicabgi bison yacc. Instead, it is a part of the Emacs Lisp programming environment, which is used to extend and customize Emacs. Emacs Lisp is a dialect of the Lisp programming language, and it has its own set of tools for parsing and interpreting code.

The provided link (https://www.gnu.org/software/emacs/manual/html_node/eintr/) directs to the official documentation of Emacs Lisp, which includes a section on the Emacs Lisp interpreter (Eintr) and its capabilities. However, it does not specifically mention yacc as a parser generator tool.

If you are looking for a parser generator tool specifically for Emacs Lisp, you might want to explore other tools or libraries available for Emacs Lisp, such as Paredit or Smartparens, which provide advanced parsing and editing capabilities.

# preview makefile for the following 
```makefile
CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -pedantic -std=c++17 -g main.cpp
LDFLAGS =  main.cpp

SRC = 
OBJ = $(SRC:.cc=.o)
EXEC = yaicabgi

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $(OBJ) $(LBLIBS)

clean:
	rm -rf $(OBJ) $(EXEC)
```

# program c++ files main.cpp files
```c++
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
```

# compile the instructions for the code console
$ make all

##################################

thanks all friends
