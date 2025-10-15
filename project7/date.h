#ifndef DATE_H
#define DATE_H
#include <string>

// class to represent a calendar date
class Date {
private:
    std::string dateString; // original date string
    int month{0};           // month
    int day{0};             // day
    int year{0};            // year

public:
    Date(); // default constructor
    void init(const std::string& dateStr); // initialize from string
    void printDate() const; // print the date
    std::string toLongString() const; // convert to long string
};
#endif // DATE_H