#pragma once
#include "Admin.h"
#include "Vectors.h"
#include "EmployeeManager.h"


class AdminManager
{
public:
	static int printAdminMenu() { // Amira
		cout << "Please choose one of the following options:" << endl;
		cout << "1.  Check Salary" << endl;
		cout << "2.  Display Information" << endl;
		cout << "3.  Update Password" << endl;
		cout << "4.  Add Client" << endl;
		cout << "5.  List All Clients" << endl;
		cout << "6.  Search and Display Client" << endl;
		cout << "7.  Edit Client Info" << endl;
		cout << "8.  Reactivate Client" << endl;
		cout << "9.  Add Employee" << endl;
		cout << "10. List All Employees" << endl;
		cout << "11. Search and Display Employee" << endl;
		cout << "12. Edit Employee Info" << endl;
		cout << "13. Reactivate Employee" << endl;
		cout << "14. Exit" << endl;

		int choice;
		cout << "Please, Choose an Option: ";
		cin >> choice;
		return choice;
	}

	static void newEmployee(Admin* a) { // Amira
		a->addEmployee();
	}

	static void listAllEmployees(Admin* a) { // Amira
		a->listEmployee();
	}

	static void searchForEmployee(Admin* a) { // Hadeer
		int id;
		cout << "Enter the ID of the Employee you want to search for: ";
		cin >> id;
		if (a->searchEmployee(id)) {
			cout << "Employee with ID: " << id << " is found!" << endl;
			a->displayEmployee(id);
		}
	}

	static void editEmployeeInfo(Admin* a) { // Hadeer
		int id;
		cout << "Enter the ID of the employee you want to edit: ";
		cin >> id;
		if (a->searchEmployee(id)) {
			cout << "Employee's ID: " << id << " is Found." << endl;
			string name;
			cout << "Enter the name of the employee: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, name);
			cout << "Enter the password of the employee: ";
			string password;
			cin >> password;
			cout << "Enter the phone number of the employee: ";
			string phoneNumber;
			cin >> phoneNumber;
			cout << "Enter the salary of the employee: ";
			double salary;
			cin >> salary;
			a->editEmployee(id, name, password, phoneNumber, salary);
		}
	}

	static Admin* login(int id, string password) { // Hadeer
		for (Admin& a : adminsVector) {
			if (a.getID() == id && a.getPassword() == password) {
				return &a;
			}
		}
		cout << "Invalid ID or Password!" << endl;
		return nullptr;
	}

	static bool adminOptions(Admin* a, int choice) {

		switch (choice) {
		case 1: // Mohammed
			a->checkSalary();
			break;

		case 2: // Mohammed
			a->display();
			break;

		case 3: // Mohammed
			ClientManager::updatePassword(a);
			break;

		case 4: // Mohammed
			EmployeeManager::newClient(a);
			break;

		case 5: // Mohammed
			EmployeeManager::listAllClients(a);
			break;

		case 6: // Mohammed
			EmployeeManager::searchForClient(a);
			break;

		case 7: // Mohammed
			EmployeeManager::editClientInfo(a);
			break;

		case 8: //Helal
			int idc;
			cout << "Enter the ID of the client you want to reactivate: ";
			cin >> idc;
			a->reactivateClient(idc);
			break;

		case 9: //Helal
			newEmployee(a);
			break;

		case 10: //Helal
			listAllEmployees(a);
			break;

		case 11: //Helal
			searchForEmployee(a);
			break;

		case 12: //Mostafa
			editEmployeeInfo(a);
			break;

		case 13: //Mostafa
			int ide;
			cout << "Enter the ID of the employee you want to reactivate: ";
			cin >> ide;
			a->reactivateEmployee(ide);
			break;

		case 14: //Mostafa
			return false;

		default: //Mostafa
			cout << "Invalid choice! Please choose a number between 1 and 14." << endl;
		}
		return true;
	}
};

