#ifndef STUDENT_H
// header guard
#define STUDENT_H

#include <string>
// include dependencies
#include "address.h"
#include "date.h"

// student class definition
class Student {
private:
    // member variables
    std::string firstName;
    std::string lastName;
    Address address;
    Date birthDate;
    Date gradDate;
    int credits{0};

public:
    // constructor and main methods
    Student(); // default

    // initialize from csv line
    void init(const std::string& csvLine);

    // printing
    // print student info
    void printStudent() const;
    // get last, first format
    std::string getLastFirst() const;

    // getters used by menu/sort/search
    const std::string& getFirstName() const { return firstName; }
    const std::string& getLastName()  const { return lastName;  }
    int getCredits() const { return credits; }
};

#endif // STUDENT_H