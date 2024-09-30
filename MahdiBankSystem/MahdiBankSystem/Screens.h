#pragma once

#include <iostream>
#include "AdminManager.h"
#include "FileManager.h"
#include <chrono> 
#include <thread>
using namespace std;

class Screens
{
public:

	static void bankName() { // Mohammed
		cout << "\t\tWelcome to C21 Route Bank System" << endl;
	}

	static void welcome() { // Mohammed
		bankName();
		this_thread::sleep_for(chrono::seconds(4));
		system("cls");
	}

	static void loginOptions() { // Hadeer
		cout << "1. Login as Client" << endl;
		cout << "2. Login as Employee" << endl;
		cout << "3. Login as Admin" << endl;
		cout << "4. Exit" << endl;
		cout << "Please select an option: ";
	}

	static void invalid(int c) { // Mohammed
		cout << "Apologies! Invalid Option." << endl;
	}

	static void logout() { // Hadeer
		cout << "\t\tThank you for using C21 Route Bank System" << endl;
		cout << "Logging out...";
		this_thread::sleep_for(chrono::seconds(4));
		system("cls");
		return;
	}

	static int loginAs() { // Hadeer
		int option;
		cin >> option;
		if (option < 1 || option > 4) {
			invalid(option);
			return 0;
		}
		system("cls");
		return option;
	}

	static void loginScreen(int c) {

		int id{};
		string password;
		bool flag = true;

		switch (c) {

		case 1: { // Helal 
			cout << "Dear Client, Please Enter your ID: ";
			cin >> id;
			system("cls");
			cout << "Please Enter your Password: ";
			cin >> password;
			system("cls");

			Client* client = ClientManager::login(id, password);
			int attempt = 0, maxattempts = 3;
			if (client != nullptr) {
				do {
					int choice = ClientManager::printClientMenu();
					// Start of failSafe for invalid choice
					while ((choice < 1 || choice > 7) && attempt < maxattempts) {
						attempt++;
						cout << "Invalid choice! Please choose a number between 1 and 7." << endl;
						system("pause");
						system("cls");
						cout << "Attempt => (" << attempt << "/" << maxattempts << ")" << endl;
						choice = ClientManager::printClientMenu();
						if (attempt == maxattempts) {
							cout << "Max Attempts have been reached! => Logging out..." << endl;
							system("pause");
							system("cls");
							logout();
							return; // Exit the failsafe block
						}
					}
					// End of failSafe for invalid choice
					attempt = 0;
					flag = ClientManager::clientOptions(client, choice);
					system("pause");
					system("cls");
				} while (flag);
				logout();
			}
			else {
				cout << "Apologies! Client is not included in the system." << endl;
				system("pause");
				system("cls");
				logout();
			}
			break;
		}

		case 2: { // Mostafa
			cout << "Dear Employee, Please Enter your ID: ";
			cin >> id;
			system("cls");
			cout << "Please Enter your Password: ";
			cin >> password;
			system("cls");

			Employee* employee = EmployeeManager::login(id, password);
			int attempt = 0, maxattempts = 3;
			if (employee != nullptr) {
				do {
					int choice = EmployeeManager::printEmployeeMenu();
					// Start of failSafe for invalid choice
					while ((choice < 1 || choice > 9) && attempt < maxattempts) {
						attempt++;
						cout << "Invalid choice! Please choose a number between 1 and 9." << endl;
						system("pause");
						system("cls");
						cout << "Attempt => (" << attempt << "/" << maxattempts << ")" << endl;
						choice = EmployeeManager::printEmployeeMenu();
						if (attempt == maxattempts) {
							cout << "Max Attempts have been reached! => Logging out..." << endl;
							system("pause");
							system("cls");
							logout();
							return; // Exit the failsafe block
						}
					}
					// End of failSafe for invalid choice
					attempt = 0;
					flag = EmployeeManager::employeeOptions(employee, choice);
					system("pause");
					system("cls");
				} while (flag);
				logout();
			}
			else {
				cout << "Apologies! Employee is not included in the system." << endl;
				system("pause");
				system("cls");
				logout();
			}
			break;
		}

		case 3: { // Amira
			cout << "Dear Admin, Please Enter your ID: ";
			cin >> id;
			system("cls");
			cout << "Please Enter your Password: ";
			cin >> password;
			system("cls");

			Admin* admin = AdminManager::login(id, password);
			int attempt = 0, maxattempts = 3;
			if (admin != nullptr) {
				do {
					int choice = AdminManager::printAdminMenu();
					// Start of failSafe for invalid choice
					while ((choice < 1 || choice > 14) && attempt < maxattempts) {
						attempt++;
						cout << "Invalid choice! Please choose a number between 1 and 14." << endl;
						system("pause");
						system("cls");
						cout << "Attempt => (" << attempt << "/" << maxattempts << ")" << endl;
						choice = AdminManager::printAdminMenu();
						if (attempt == maxattempts) {
							cout << "Max Attempts have been reached! => Logging out..." << endl;
							system("pause");
							system("cls");
							logout();
							return; // Exit the failsafe block
						}
					}
					// End of failSafe for invalid choice
					attempt = 0;
					flag = AdminManager::adminOptions(admin, choice);
					system("pause");
					system("cls");
				} while (flag);
				logout();
			}
			else {
				cout << "Apologies! Admin is not included in the system." << endl;
				system("pause");
				system("cls");
				logout();
			}
			break;
		}

		case 4: // Mahdi
			logout();
			break;

		default: // Mahdi
			invalid(c);
			break;
		}
	}

	static void runApp() { // Mahdi
		FileManager fm;
		fm.getAllClients();
		fm.getAllEmployees();
		fm.getAllAdmins();
		welcome();
		loginOptions();
		loginScreen(loginAs());
		fm.exportAllAdmins();
		fm.exportAllClients();
		fm.exportAllEmployees();
	}
};

