#include "Employee.h"
#include "FileHelper.h"
#include "FileManager.h"

int Employee::countEmployees = 0;
FileManager fm;

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
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, name);
	cout << "Enter the password of the client: ";
	cin >> password;
	cout << "Enter the phone number of the client: ";
	cin >> phoneNumber;
	cout << "Enter the balance of the client: ";
	cin >> balance;
	Client cNew(id, name, password, phoneNumber, balance);
	fm.addClient(cNew);
	cout << "Client added successfully.\n";
}

//Mahdi
void Employee::editClient(int id, string name, string password, string phonenumber, double balance) {
	if (!isActive()) {
		return;
	}
	Client* temp = searchClient(id);
	if (temp != nullptr) {
		FileManager fm;
		temp->setName(name);
		temp->setPassword(password);
		temp->setPhoneNumber(phonenumber);
		temp->setBalance(balance);
		cout << "Client's ID: " << temp->getID() << " is Edited." << endl;
		temp->display();
		fm.exportAllClients();
		return;
	}
}

Client Employee::reactivateClient(int id) {
	Client* temp = searchClient(id);
	if (temp != nullptr) {
		FileManager fm;
		cout << "Client's ID: " << id << " is Found." << endl;
		editClient(id, temp->getName(), temp->getPassword(), temp->getPhoneNumber(), temp->getBalance());
		cout << "Client with ID " << id << " has been reactivated." << endl;
		fm.exportAllClients();
		return *temp;
	}
}