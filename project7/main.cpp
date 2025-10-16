// main.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "address.h"
#include "date.h"
#include "student.h"

// declarations
void loadStudents(std::vector<Student*>& students, const std::string& filename);
void showStudentNames(const std::vector<Student*>& students);
void printStudents(const std::vector<Student*>& students);
void findStudent(const std::vector<Student*>& students); // exact last-name match
void delStudents(std::vector<Student*>& students);
std::string menu();
// main entry point
int main() {
    // holds all student objects
    std::vector<Student*> students;
    // load students.csv 
    loadStudents(students, "students.csv");
    // menu loop
    while (true) {
        std::string choice = menu();

    // handle user menu selection
    if (choice == "0") {
            break; // quit
        } else if (choice == "1") {
            showStudentNames(students);
        } else if (choice == "2") {
            printStudents(students);
        } else if (choice == "3") {
            findStudent(students); // ask for last name inside
        } else {
            std::cout << "Invalid choice. Please choose 0-3.\n";
        }
    }
    // free memory before exit
    delStudents(students);
    return 0;
}
// implementations
// reads student data from csv file
void loadStudents(std::vector<Student*>& students, const std::string& filename) {
    std::ifstream fin(filename);
    if (!fin) {
        std::cerr << "ERROR: Could not open file: " << filename << std::endl;
        return;
    }
    std::string line;
    while (std::getline(fin, line)) {
        if (line.empty()) continue;
        Student* s = new Student();
        s->init(line);
        students.push_back(s);
    }

    fin.close();
}
void showStudentNames(const std::vector<Student*>& students) {
    for (const Student* s : students) {
        std::cout << s->getLastFirst() << std::endl;
    }
}
void printStudents(const std::vector<Student*>& students) {
    for (const Student* s : students) {
        s->printStudent();
        std::cout << "____________________________________" << std::endl;
    }
}
// finds and prints student(s) by last name
void findStudent(const std::vector<Student*>& students) {
    std::cout << "last name of student: ";
    std::string last;
    std::getline(std::cin, last);
    if (last.empty()) return;

    bool foundAny = false;
    for (const Student* s : students) {
        if (s->getLastName() == last) { // exact match
            s->printStudent();
            std::cout << "____________________________________" << std::endl;
            foundAny = true;
        }
    }
    if (!foundAny) {
        std::cout << "No matches found.\n";
    }
}
void delStudents(std::vector<Student*>& students) {
    for (Student* s : students) {
        delete s;
    }
    students.clear();
}
std::string menu() {
    std::cout << "\n0) quit\n"
                 "1) print all student names\n"
                 "2) print all student data\n"
                 "3) find a student\n\n"
                 "please choose 0-3: ";
    std::string choice;
    std::getline(std::cin, choice);
    return choice;
}
