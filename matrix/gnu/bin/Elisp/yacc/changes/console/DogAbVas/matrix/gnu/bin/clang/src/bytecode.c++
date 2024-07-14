#if 0
#include <iostream>
#include <vector>
#include <algorithm>

struct Student {
    std::string name;
    int age;
    double grade;
};

bool compareStudentsByAge(const Student& a, const Student& b) {
    return a.age < b.age;
}

bool compareStudentsByGrade(const Student& a, const Student& b) {
    return a.grade > b.grade;
}

int main() {
    std::vector<Student> students = {
        {"Alice", 18, 85.5},
        {"Bob", 17, 92.0},
        {"Charlie", 19, 78.0},
        {"David", 16, 90.0}
    };

    std::sort(students.begin(), students.end(), compareStudentsByAge);
    std::cout << "Sorted by age:" << std::endl;
    for (const auto& student : students) {
        std::cout << student.name << ", " << student.age << ", " << student.grade << std::endl;
    }

    std::sort(students.begin(), students.end(), compareStudentsByGrade);
    std::cout << "Sorted by grade:" << std::endl;
    for (const auto& student : students) {
        std::cout << student.name << ", " << student.age
        << ", " << student.grade << std::endl;
    }

    return 0;
#endif