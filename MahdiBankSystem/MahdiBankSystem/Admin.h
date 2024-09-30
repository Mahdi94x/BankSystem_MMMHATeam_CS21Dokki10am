#pragma once

#include <iostream>
#include "Employee.h"
#include <string>
using namespace std;

extern vector <Employee> employeesVector;

class Admin : public Employee // Mahdi
{
private:
	// Private Methods:
	bool isActive() {
		if (Validation::isAccountActive(getName(), getPassword(), getPhoneNumber(), salary, false)) {
			return true;
		}
		else {
			cout << "Account is frozen. Kindly Contact your IT Manager ASAP for more information.\n";
			return false;
		}
	}

	// Private Constructor:
	Admin(int id, string name, string password, string phonenumber, double salary) :Employee(id, name, password, phonenumber, salary) {
		countAdmins++;
	}

	// Private Static Object
	static Admin* superAdmin; // Attribute must be initialized to nullptr in the cpp file

public:

	//Attributes:
	static int countAdmins;

	//Methods:

	// public Static getInstance Method
	static Admin* getInstance(int id = 0, string name = "", string password = "", string phonenumber = "", double salary = 0) {
		if (superAdmin == nullptr) {
			superAdmin = new Admin(id, name, password, phonenumber, salary);
		}
		return superAdmin;
	}

	void display() {
		cout << "Admin's Authority" << endl;
		Employee::display();
	}

	//Mahdi // Declaration only duo to circular dependency
	void addEmployee();
	Employee reactivateEmployee(int id);
	void editEmployee(int id, string name, string password, string phonenumber, double salary);


	//Mahdi
	Employee* searchEmployee(int id) {
		if (!isActive()) {
			throw "Account is frozen. Kindly Contact your IT Manager ASAP for more information.\n";
		}
		Employee* temp = nullptr;
		for (int i = 0; i < employeesVector.size(); i++) {
			if (employeesVector[i].getID() == id) {
				temp = &employeesVector[i];
				return temp;
			}
		}
		cout << "Employee's ID not found.\n";
		temp = nullptr;
		return temp;
	}

	//Mahdi
	void listEmployee() {
		if (!isActive()) {
			return;
		}
		for (int i = 0; i < employeesVector.size(); i++) {
			employeesVector[i].display();
		}
	}

	void displayEmployee(int id) {
		if (!isActive()) {
			return;
		}
		Employee* temp = searchEmployee(id);
		if (temp != nullptr) {
			temp->display();
		}
	}

	void checkSalary() {
		cout << "Current Salary of Admin's ID: " << getID() << " is => " << getSalary() << " EGP." << endl;
	}
};

