#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_STUDENTS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    float grade;
} Student;

void swapStudents(Student* a, Student* b) {
    Student temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].grade < students[j + 1].grade) {
                swapStudents(&students[j], &students[j + 1]);
            }
        }
    }
}

void printStudents(Student students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Name: %s\nAge: %d\nGrade: %.2f\n\n", students[i].name, students[i].age, students[i].grade);
    }
}

int main() {
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    if (numStudents <= 0 || numStudents > MAX_STUDENTS) {
        printf("Invalid number of students. Please enter a value between 1 and %d.\n", MAX_STUDENTS);
        return 0;
    }

    Student students[MAX_STUDENTS];

    printf("Enter student information (name, age, grade):\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        scanf("%s %d %f", students[i].name, &students[i].age, &students[i].grade);
    }

    bubbleSort(students, numStudents);

    printf("\nSorted Students:\n");
    printStudents(students, numStudents);

    return 0;
}
