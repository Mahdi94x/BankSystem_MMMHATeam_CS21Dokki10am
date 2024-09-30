#include "Admin.h"
#include "FileHelper.h"
#include "FileManager.h"

int Admin::countAdmins = 0;

Admin* Admin::superAdmin = nullptr;

//Mahdi
void Admin::addEmployee() {
	if (!isActive()) {
		return;
	}
	FileManager fm;
	int id = FileHelper::getLastID("EmployeeLastID.txt");
	string name, password, phoneNumber;
	double salary{};
	cout << "Enter the name of the employee: ";
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, name);
	cout << "Enter the password of the employee: ";
	cin >> password;
	cout << "Enter the phone number of the employee: ";
	cin >> phoneNumber;
	cout << "Enter the salary of the employee: ";
	cin >> salary;
	Employee eNew(id, name, password, phoneNumber, salary);
	fm.addEmployee(eNew);
	cout << "Employee added successfully.\n";
}

void Admin::editEmployee(int id, string name, string password, string phonenumber, double salary) {
	if (!isActive()) {
		return;
	}
	Employee* temp = searchEmployee(id);
	if (temp != nullptr) {
		FileManager fm;
		temp->setName(name);
		temp->setPassword(password);
		temp->setPhoneNumber(phonenumber);
		temp->setSalary(salary);
		cout << "Employee's ID: " << temp->getID() << " is Edited." << endl;
		fm.exportAllEmployees();
		temp->display();
		return;
	}
}

Employee Admin::reactivateEmployee(int id) {
	Employee* temp = searchEmployee(id);
	if (temp != nullptr) {
		FileManager fm;
		cout << "Employee's ID: " << id << " is Found." << endl;
		editEmployee(id, temp->getName(), temp->getPassword(), temp->getPhoneNumber(), temp->getSalary());
		cout << "Employee's ID " << id << " has been reactivated." << endl;
		fm.exportAllEmployees();
		return *temp;
	}
}