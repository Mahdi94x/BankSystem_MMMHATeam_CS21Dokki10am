#include "Admin.h"
#include "FileHelper.h"
#include "FileManager.h"

int Admin::countAdmins = 0;

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
	FileHelper::saveLastID("EmployeeLastID.txt", id);
	cout << "Employee added successfully.\n";
}