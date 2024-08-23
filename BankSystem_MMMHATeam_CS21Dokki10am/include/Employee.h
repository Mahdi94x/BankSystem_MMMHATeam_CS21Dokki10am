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
    //Constructors:
	Employee() {}
	Employee(int id, string name, string password, double salary) {}

	//Setters:
    void setSalary(double salary) {}

    //Getters:
    double getSalary() {}

    //Methods:
    virtual void display() {}
};

#endif // EMPLOYEE_H
