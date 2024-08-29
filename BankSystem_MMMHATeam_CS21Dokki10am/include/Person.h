#ifndef PERSON_H
#define PERSON_H
#include <iostream>
using namespace std;
#include "Validation.h"

class Person
{
protected:
    // Attributes:
    string name, password, id, phonenumber;

public:
    //Constructors: // Mostafa
    Person() {
}
    Person(string id, string name, string password) { // business constructor
	setID(id);
	setName(name);
	setPassword(password);
}
    Person(string id, string name, string password, string phonenumber) {
	setID(id);
	setName(name);
	setPassword(password);
	setPhoneNumber(phonenumber);
}
    // Setters:
    void setID(string id) { // Mostafa
        this->id = id;
}



    //Getters:
    int getID() {}

    string getName() {}

    string getPassword() {}

    // Methods:
	// Abstracted Pure Virtual Method
	virtual void display() = 0;

};

#endif // PERSON_H
