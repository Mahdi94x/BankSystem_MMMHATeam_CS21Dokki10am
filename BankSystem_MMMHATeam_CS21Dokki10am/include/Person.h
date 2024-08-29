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
        int attempt{};
        const int maxattempts{ 3 };
        while (!(Validation::validateName(name)) && attempt < maxattempts) {
            cout << "Apologies! Invalid Name. The Name must be alphabetic chars and min size 5 and max size 20\n";
            attempt++;
            cout << "Attempt => (" << attempt << "/" << maxattempts << ")" << " Enter the modified name : ";
            getline(cin, name);
        }

        if (Validation::validateName(name)) {
            this->name = name;
        }
        else {
            cout << "Max Attempts have been reached! => Setting name to default value\n";
            cout << "Kindly Contact our support ASAP.\n";
            this->name = "default.";
        }
}
    void setPassword(string password) { // Amira
        int attempt{};
        const int maxattempts{ 3 };
        while (!(Validation::validatePassword(password)) && attempt < maxattempts) {
            cout << "Apologies! Invalid Password. Password must be with min size 8 and max size 20\n";
            attempt++;
            cout << "Attempt => (" << attempt << "/" << maxattempts << ")" << " Enter the modified password : ";
            cin>>password;
            // Clear the input buffer to avoid issues with getline or other input methods.
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (Validation::validatePassword(password)) {
            this->password = password;
        }
        else {
            cout << "Max Attempts have been reached! => Setting password to default value\n";
            cout << "Kindly Contact our support ASAP.\n";
            this->password = "************";
        }
}
    void setPhoneNumber(string phonenumber) { // Mahdi
        int attempt{};
        const int maxattempts{ 3 };
        while (!(Validation::validatePhoneNumber(phonenumber)) && attempt < maxattempts) {
            cout << "Apologies! Invalid Phone number. Phone number must consist of 11 numbers.\n";
            attempt++;
            cout << "Attemp => (" << attempt << "/" << maxattempts << ")" << " Enter the modified phone number : ";
            cin >> phonenumber;
            // Clear the input buffer to avoid issues with getline or other input methods.
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (Validation::validatePhoneNumber(phonenumber)) {
            this->phonenumber = phonenumber;
        }
        else {
            cout << "Max Attemps have been reached! => Setting phone number to default value\n";
            cout << "Kindly Contact our support ASAP\n";
            this->phonenumber = "00000000000";
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
