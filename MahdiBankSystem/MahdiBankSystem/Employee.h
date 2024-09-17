#pragma once

#include <string>
#include "Client.h"
using namespace std;
extern vector <Client> clientsVector;

class Employee : public Person
{
protected:

	//Attributes:
	double salary;

	//Methods:
	virtual bool isActive() {
		if (Validation::isAccountActive(getName(), getPassword(), getPhoneNumber(), getSalary(), false)) {
			return true;
		}
		else {
			cout << "Account is frozen. Kindly Contact your Admin ASAP for more information.\n";
			return false;
		}
	}

public:
	//Attributes: //Amira
	static int countEmployees;

	//Constructors: // Amira
	Employee() :Person() {
		this->salary = 0;
		countEmployees++;
	}
	Employee(int id, string name, string password) : Person(id, name, password) {
		this->salary = 0;
		countEmployees++;
	}
	Employee(int id, string name, string password, string phonenumber, double salary) : Person(id, name, password, phonenumber) {
		setSalary(salary);
		countEmployees++;
	}

	//Setters:
	void setSalary(double salary) { // Mostafa
		int attempt{};
		const int maxattempts{ 3 };
		while (!(Validation::validateSalary(salary)) && attempt < maxattempts) {
			cout << "Apologies! Invalid salary. The salary must be equal to or higher than 5000.\n";
			attempt++;
			cout << "Attempt => (" << attempt << "/" << maxattempts << ")" << " Enter the modified salary : ";
			cin >> salary;
			// Clear the input buffer to avoid issues with getline or other input methods.
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if (Validation::validateSalary(salary)) {
			if (attempt != 0) {
				cout << "Thank you for providing the modified salary.\n";
			}
			this->salary = salary;
		}
		else {
			cout << "Max Attempts have been reached! => Setting salary to default value.\n";
			cout << "Kindly Contact our support ASAP.\n";
			this->salary = 0;
		}
	}

	//Getters:
	double getSalary() { // Hadeer
		return this->salary;
	}
	

	//Methods:
	

	virtual void display() { // Helal
		Person::display();
		cout << "Salary:       " << getSalary() << endl;
		cout << "======================================\n";
	}

	//Mahdi
	void addClient(); // Declaration only duo to circular dependency

	//Mahdi
	Client* searchClient(int id) {
		if (!isActive()) {
			throw "Account is frozen. Kindly Contact your Admin ASAP for more information.\n";
		}
		Client* temp = nullptr;
		for (int i = 0; i < clientsVector.size(); i++) {
			if (clientsVector[i].getID() == id) {
				temp = &clientsVector[i];
				return temp;
			}
		}
		cout << "Client's ID not found.\n";
		temp = nullptr;
		return temp;
	}

	//Mahdi
	void listClient() {
		if (!isActive()) {
			return;
		}
		for (int i = 0; i < clientsVector.size(); i++) {
			clientsVector[i].display();
		}
	}

	//Mahdi
	void editClient(int id,string name,string password,string phonenumber, double balance) {
		if (!isActive()) {
			return;
		}
		Client* temp = searchClient(id);
		if (temp != nullptr) {
			cout << "Client's ID: " << id << " is Found." << endl;
			temp->setName(name);
			temp->setPassword(password);
			temp->setPhoneNumber(phonenumber);
			temp->setBalance(balance);
			cout << "Client's ID: " << temp->getID() << " is Edited." << endl;
			temp->display();
			return;
		}
	}

	//Mahdi
	Client reactivateClient(int id) {
		Client* temp = searchClient(id);
		if (temp != nullptr) {
			editClient(id, temp->getName(), temp->getPassword(), temp->getPhoneNumber(), temp->getBalance());
			cout << "Client with ID " << id << " has been reactivated." << endl;
			return *temp;
		}
	}
};

