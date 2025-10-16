#include "student.h"
#include <sstream>
#include <iostream>
#include <vector>

// default constructor
Student::Student() = default;

// splits a csv line into fields
static std::vector<std::string> splitCSV(const std::string& s, char delim = ',') {
    std::vector<std::string> out;
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        out.push_back(item);
    }
    return out;
}

// initializes student object from csv line
void Student::init(const std::string& csvLine) {
    // 0 first, 1 last, 2 street, 3 city, 4 state, 5 zip, 6 birth, 7 grad, 8 credits
    auto t = splitCSV(csvLine);
    if (t.size() != 9) {
        std::cerr << "[Student::init] ERROR: Expected 9 fields, got " << t.size() << "\n";
        return;
    }
    // trims whitespace from a string
    auto Trim = [](const std::string& s) {
        size_t start = 0;
        while (start < s.size() && (s[start] == ' ' || s[start] == '\t' || s[start] == '\n' || s[start] == '\r')) {
            ++start;
        }
        size_t end = s.size();
        while (end > start && (s[end - 1] == ' ' || s[end - 1] == '\t' || s[end - 1] == '\n' || s[end - 1] == '\r')) {
            --end;
        }
        return s.substr(start, end - start);
    };
    firstName = Trim(t[0]);
    lastName  = Trim(t[1]);

    // initialize address and dates
    address.init(t[2], t[3], t[4], t[5]);
    birthDate.init(t[6]);
    gradDate.init(t[7]);

    // convert credits to integer
    try {
        credits = std::stoi(t[8]);
    } catch (...) {
        credits = 0;
    }
}

// prints all student information
void Student::printStudent() const {
    std::cout << firstName << " " << lastName << std::endl;
    address.printAddress();
    std::cout << "DOB: "  << birthDate.toLongString() << std::endl;
    std::cout << "Grad: " << gradDate.toLongString() << std::endl;
    std::cout << "Credits: " << credits << std::endl;
}

// returns last, first format
std::string Student::getLastFirst() const {
    return lastName + ", " + firstName;
}