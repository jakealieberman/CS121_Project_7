#ifndef STUDENT_H
#define STUDENT_H

#include <string>
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
    Student(); 

    // initialize from csv line
    void init(const std::string& csvLine);

    // printing
    void printStudent() const;
    // get last, first 
    std::string getLastFirst() const;

    // getters
    const std::string& getFirstName() const { return firstName; }
    const std::string& getLastName()  const { return lastName;  }
    int getCredits() const { return credits; }
};

#endif // STUDENT_H
