
#ifndef ADDRESS_H
#define ADDRESS_H
#include <string>

// class to represent a mailing address
class Address {
private:
    std::string street; // street address
    std::string city;   // city name
    std::string state;  // state abbreviation
    std::string zip;    // zip code

public:
    Address(); // Default constructor
    void init(const std::string& streetIn,
              const std::string& cityIn,
              const std::string& stateIn,
              const std::string& zipIn); // set all fields
    void printAddress() const; // print the address
};
#endif // ADDRESS_H