# CS121 Project 7

```mermaid
classDiagram

class Date {
# string dateString
# int month
# int day
# int year
+ Date()
+ void init(dateString)
+ void printDate()
}
class Address {
# string street
# string city
# string state
# string zip
+ Address()
+ void init(street, city, state, zip)
+ void printAddress()
}
class Student {
# string studentString
# string firstName
# string lastName
# Address address
# Date dob
# Date grad
# int creditHours
+ Student()
+ -Student()
+ void init(getString)
+ void printStudent()
+ string getFirst()
+ string getLast
+ string getCredit
}
Student --> Address
Student --> Date
```

## Goal
* Normalize data with three classes (date, address, student).

## Input
* void init(dateString) splits on "/" and stores integer fields. toLongString() uses a month-name table to print an output like "January 27, 1997".
* void init(getString) splits the line by commas into 9 different types of data in this order: first, last, street, city, state, zip, dob, grad, credits.

## Printing
* address::printAddress() prints two lines
  * street
  * city state, zip
* printDate() prints 
  * month day, year
* printStudent() prints
  * first last
  * address (two lines)
  * DOB: dob
  * Grad: grad
  * Credits: credits
  * line of underscores
  * last, first
