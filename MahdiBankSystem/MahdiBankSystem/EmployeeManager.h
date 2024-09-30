#pragma once
#include "Employee.h"
#include "Vectors.h"
#include "ClientManager.h"


class EmployeeManager
{
public:
	static int printEmployeeMenu() { // Mohammed
		cout << "Please choose one of the following options:" << endl;
		cout << "1.  Check Salary" << endl;
		cout << "2.  Display Information" << endl;
		cout << "3.  Update Password" << endl;
		cout << "4.  Add Client" << endl;
		cout << "5.  List All Clients" << endl;
		cout << "6.  Search and Display Client" << endl;
		cout << "7.  Edit Client Info" << endl;
		cout << "8.  Reactivate Client" << endl;
		cout << "9.  Exit" << endl;

		int choice;
		cout << "Please, Choose an Option: ";
		cin >> choice;
		return choice;
	}

	static void newClient(Employee* e) { // Mohammed
		e->addClient();
	}

	static void listAllClients(Employee* e) { // Mohammed
		e->listClient();
	}

	static void searchForClient(Employee* e) { // Mohammed
		int id;
		cout << "Enter the ID of the client you want to search for: ";
		cin >> id;
		if (e->searchClient(id)) {
			cout << "Client's ID: " << id << " is Found." << endl;
			e->displayClient(id);
		}
	}

	static void editClientInfo(Employee* e) { // Helal
		int id;
		cout << "Enter the ID of the client you want to edit: ";
		cin >> id;
		if (e->searchClient(id)) {
			cout << "Client's ID: " << id << " is Found." << endl;
			string name;
			cout << "Enter the name of the client: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, name);
			cout << "Enter the password of the client: ";
			string password;
			cin >> password;
			cout << "Enter the phone number of the client: ";
			string phoneNumber;
			cin >> phoneNumber;
			cout << "Enter the balance of the client: ";
			double balance;
			cin >> balance;
			e->editClient(id, name, password, phoneNumber, balance);
		}
	}

	static Employee* login(int id, string password) { // Mostafa
		for (Employee& e : employeesVector) {
			if (e.getID() == id && e.getPassword() == password) {
				return &e;
			}
		}
		cout << "Invalid ID or Password!" << endl;
		return nullptr;
	}

	static bool employeeOptions(Employee* e, int choice) {

		switch (choice) {
		case 1: // Mostafa
			e->checkSalary();
			break;

		case 2: // Mostafa
			e->display();
			break;

		case 3: // Mostafa
			ClientManager::updatePassword(e);
			break;

		case 4: //Hadeer
			newClient(e);
			break;

		case 5: //Hadeer
			listAllClients(e);
			break;

		case 6: //Hadeer
			searchForClient(e);
			break;

		case 7: // Amira
			editClientInfo(e);
			break;

		case 8: // Amira
			int id1;
			cout << "Enter the ID of the client you want to reactivate: ";
			cin >> id1;
			e->reactivateClient(id1);
			break;

		case 9: // Amira
			return false;

		default: // Amira
			cout << "Invalid choice! Please choose a number between 1 and 9." << endl;
		}
		return true;
	}
};

