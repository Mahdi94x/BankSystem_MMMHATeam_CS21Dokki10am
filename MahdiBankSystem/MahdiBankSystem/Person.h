#pragma once

#include <iostream>
#include <string>
#include "Validation.h"
#include <ctime>
#include <sstream>
#include <iomanip>
#include <limits>

using namespace std;

class Person
{
protected:
	// Attributes:
	int id;
	string name, password, phonenumber;

	// Protected Method
	// Time Method:
	string getCurrentTime() {
		time_t now = time(0); // Get current time
		tm ltm; // Local time structure
		localtime_s(&ltm, &now); // Safe version of localtime
		ostringstream oss;
		oss << put_time(&ltm, "%Y-%m-%d %H:%M:%S"); // Format time as YYYY-MM-DD HH:MM:SS
		return oss.str();
	}

public:
	//Constructors: // Mostafa
	Person() {
		this->id = 0;
	}

	Person(int id, string name, string password) { // business constructor
		setID(id);
		setName(name);
		setPassword(password);
	}

	Person(int id, string name, string password, string phonenumber) {
		setID(id);
		setName(name);
		setPassword(password);
		setPhoneNumber(phonenumber);
	}

	// Setters:
	void setID(int id) { // Mostafa
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
			if (attempt != 0) {
				cout << "Thank you for providing the modified name.\n";
			}
			this->name = name;
		}
		else {
			cout << "Max Attempts have been reached! => Setting name to default value.\n";
			cout << "Kindly Contact our support ASAP.\n";
			this->name = "default123.";

		}
	}
	void setPassword(string password) { // Amira
		int attempt{};
		const int maxattempts{ 3 };
		while (!(Validation::validatePassword(password)) && attempt < maxattempts) {
			cout << "Apologies! Invalid Password. Password must be with min size 8 and max size 20\n";
			attempt++;
			cout << "Attempt => (" << attempt << "/" << maxattempts << ")" << " Enter the modified password : ";
			cin >> password;
			// Clear the input buffer to avoid issues with getline or other input methods.
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if (Validation::validatePassword(password)) {
			if (attempt != 0) {
				cout << "Thank you for providing the modified password.\n";
			}
			this->password = password;
		}
		else {
			cout << "Max Attempts have been reached! => Setting password to default value.\n";
			cout << "Kindly Contact our support ASAP.\n";
			this->password = "****";

		}
	}
	void setPhoneNumber(string phonenumber) { // Mahdi
		int attempt{};
		const int maxattempts{ 3 };
		while (!(Validation::validatePhoneNumber(phonenumber)) && attempt < maxattempts) {
			cout << "Apologies! Invalid Phone number. Phone number must consist of 11 numbers.\n";
			attempt++;
			cout << "Attempt => (" << attempt << "/" << maxattempts << ")" << " Enter the modified phone number : ";
			cin >> phonenumber;
			// Clear the input buffer to avoid issues with getline or other input methods.
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if (Validation::validatePhoneNumber(phonenumber)) {
			if (attempt != 0) {
				cout << "Thank you for providing the modified phone number.\n";
			}
			this->phonenumber = phonenumber;
		}
		else {
			cout << "Max Attempts have been reached! => Setting phone number to default value.\n";
			cout << "Kindly Contact our support ASAP.\n";
			this->phonenumber = "0000";

		}
	}

	//Getters: // Helal
	int getID() {
		return this->id;
	}

	string getName() {
		return this->name;
	}

	string getPassword() {
		return this->password;
	}
	string getPhoneNumber() {
		return this->phonenumber;
	}

	// Methods: // Mahdi
	virtual void display() {
		cout << "Name:         " << getName() << endl;
		cout << "ID:           " << getID() << endl;
		cout << "Password:     " << getPassword() << endl;
		cout << "Phone Number: " << getPhoneNumber() << endl;
	}
};

