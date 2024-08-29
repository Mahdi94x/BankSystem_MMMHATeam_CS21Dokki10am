#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
using namespace std;
#include "Person.h"

class Employee : public Person
{
private:

	//Attributes:
	double salary;

public:
    //Attributes: //Amira
    static int countEmployees;

    //Constructors: // Amira
    Employee() {
        this->salary = 0;
        countEmployees++;
}
    Employee(string id, string name, string password) : Person(id, name, password) {
        this->salary = 0;
        countEmployees++;
}
    Employee(string id, string name, string password, string phonenumber, double salary) : Person(id, name, password, phonenumber) {
        setSalary(salary);
        countEmployees++;
}

	//Setters:
    void setSalary(double salary) {}

    //Getters:
    double getSalary() {}

    //Methods:
    virtual void display() {}
};

#endif // EMPLOYEE_H
