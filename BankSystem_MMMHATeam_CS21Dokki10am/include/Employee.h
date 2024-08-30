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
            if(attempt !=0){
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
        cout << "Name:         " << getName() << endl;
        cout << "ID:           " << getID() << endl;
        cout << "Password:     " << getPassword() << endl;
        cout << "Phone Number: " << getPhoneNumber() << endl;
        cout << "Salary:       " << getSalary() << endl;
        cout << "======================================\n";
}
};

#endif // EMPLOYEE_H
