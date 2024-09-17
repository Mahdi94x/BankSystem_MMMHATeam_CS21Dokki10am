#include "Employee.h"
#include "FileHelper.h"
#include "FileManager.h"

int Employee::countEmployees = 0;

//Mahdi
void Employee::addClient() {
	if (!isActive()) {
		return;
	}
	FileManager fm;
	int id = FileHelper::getLastID("ClientLastID.txt");
	string name, password, phoneNumber;
	double balance{};
	cout << "Enter the name of the client: ";
	cin.clear();
	getline(cin, name);
	cout << "Enter the password of the client: ";
	cin >> password;
	cout << "Enter the phone number of the client: ";
	cin >> phoneNumber;
	cout << "Enter the balance of the client: ";
	cin >> balance;
	Client cNew(id, name, password, phoneNumber, balance);
	fm.addClient(cNew);
	FileHelper::saveLastID("ClientLastID.txt", id);
	cout << "Client added successfully.\n";
}