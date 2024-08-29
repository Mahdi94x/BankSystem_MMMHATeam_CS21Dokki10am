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

    void setName(string name) { // Hadeer
        int attemps{};
        const int maxAttemps{ 3 };
        while (!(Validation::validateName(name)) && attemps < maxAttemps) {
            cout << "Apologies! Invalid Name. The Name must be alphabetic chars and min size 5 and max size 20\n";
            attemps++;
            cout << "Attemp => (" << attemps << "/" << maxAttemps << ")" << " Enter the modified name : ";
            getline(cin, name);
        }

        if (Validation::validateName(name)) {
            this->name = name;
        }
        else {
            cout << "Max Attemps have been reached! => Setting name to default value\n";
            cout << "Kindly Contact our support ASAP.\n";
            this->name = "default.";
        }
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
