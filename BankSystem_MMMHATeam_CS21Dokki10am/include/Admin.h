#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
using namespace std;
#include "Employee.h"

class Admin : public Employee // Mahdi
{
public:
	//Attributes:
	static int countAdmins;

	//Constructors:
	Admin(){
		countAdmins++;
	}
	Admin(string id, string name, string password) : Employee(id, name, password) {
		countAdmins++;
	}
	Admin(string id, string name, string password, string phonenumber, double salary):Employee(id, name, password, phonenumber, salary) {
		countAdmins++;
	}

	//Methods:
	void display() {
		cout << "Admin's Authority" << endl;
		Employee::display();
	}
};

#endif // ADMIN_H
