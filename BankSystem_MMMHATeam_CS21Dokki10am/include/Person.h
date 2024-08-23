#ifndef PERSON_H
#define PERSON_H
#include <iostream>
using namespace std;
#include "Validation.h"

class Person
{
protected:
    // Attributes:
    int id;
    string name, password;

public:
    //Constructors:
    Person() {}

    Person(int id, string name, string password) {}

    // Setters:
    void setID(int id) {}
    void setName(string name) {}

    void setPassword(string password) {}

    //Getters:
    int getID() {}

    string getName() {}

    string getPassword() {}

    //Methods:
	// Abstracted Pure Virtual Method
	virtual void display() = 0;

};

#endif // PERSON_H
