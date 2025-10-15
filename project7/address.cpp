#include "address.h" // include the header for Address class
#include <iostream>

// default constructor initializes all fields to empty strings
Address::Address() : street(""), city(""), state(""), zip("") {}
// set all address fields
void Address::init(const std::string& streetIn,
                   const std::string& cityIn,
                   const std::string& stateIn,
                   const std::string& zipIn) {
    street = streetIn;
    city   = cityIn;
    state  = stateIn;
    zip    = zipIn;
}
// print the address
void Address::printAddress() const {
    std::cout << street << std::endl;
    std::cout << city << " " << state << ", " << zip << std::endl;
}