#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct Student {
    int age;
    double grade;
};

void QListApple(const char *name, const char * grade, const char * description) {
    struct Student student;
    student.age = atoi(description);
    student.grade = atof(grade);

    printf("Student Name: %s\n", name);
    printf("Age: %d\n", student.age);
    printf("Grade: %.2lf\n", student.grade);
    printf("Description: %s\n", description);
}

int main() {
    QListApple("John Doe", "95.5", "25");
    return 0;
}
