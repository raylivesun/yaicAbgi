#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Student {
    int age;
    double grade;
};

void QStringToString(const char QDateTime, int year, int month, int day, int hour, int minute, int second) {
    // Convert QDateTime to string
    char strDateTime[20];
    sprintf(strDateTime, "%04d-%02d-%02d %02d:%02d:%02d", year, month, day, hour, minute, second);

    // Convert string to Student struct
    Student student;
    sscanf(strDateTime, "%d-%d-%d %d:%d:%d", &student.age, &month, &day, &hour, &minute, &second);
    student.grade = (double)hour / 60.0 + (double)minute / 3600.0 + (double)second / 86400.0;

    // Print student details
    printf("Age: %d\n", student.age);
    printf("Grade: %.2f\n", student.grade);

}

int main() {
    QStringToString('Q', 2022, 12, 31, 23, 59, 59);
    return 0;
}
