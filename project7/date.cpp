
#include "date.h" 
#include <iostream>
#include <vector>

// const array
static const char* MONTH_NAMES[13] = {
    "", "January","February","March","April","May","June",
    "July","August","September","October","November","December"
};
// default constructor initializes date
Date::Date() : dateString(""), month(0), day(0), year(0) {}
// initialize date in mm/dd/yyyy format
void Date::init(const std::string& dateStr) {
    dateString = dateStr;
    int firstSlash = static_cast<int>(dateStr.find('/'));
    int secondSlash = static_cast<int>(dateStr.find('/', firstSlash + 1));
    if (firstSlash == std::string::npos || secondSlash == std::string::npos) {
        month = day = year = 0;
        return;
    }
    std::string mm = dateStr.substr(0, firstSlash);
    std::string dd = dateStr.substr(firstSlash + 1, secondSlash - (firstSlash + 1));
    std::string yyyy = dateStr.substr(secondSlash + 1);
    try {
        month = std::stoi(mm);
        day   = std::stoi(dd);
        year  = std::stoi(yyyy);
    } catch (...) {
        month = day = year = 0;
    }
}
// convert date to a long string
std::string Date::toLongString() const {
    if (month < 1 || month > 12 || year == 0) return dateString; // fallback
    return std::string(MONTH_NAMES[month]) + " " + std::to_string(day) + ", " + std::to_string(year);
}
// print the date in long string format
void Date::printDate() const {
    std::cout << toLongString() << std::endl;
} // end date